/*
 * Copyright (C) 2018 Inria
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     examples
 * @{
 *
 * @file
 * @brief       Example demonstrating the use of LoRaWAN with RIOT
 *
 * @author      Alexandre Abadie <alexandre.abadie@inria.fr>
 *
 * @}
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


#include "msg.h"
#include "thread.h"
#include "fmt.h"

#if IS_USED(MODULE_PERIPH_RTC)
#include "periph/rtc.h"
#else
#include "timex.h"
#include "ztimer.h"
#endif

#include "net/loramac.h"
#include "semtech_loramac.h"

#if IS_USED(MODULE_SX127X)
#include "sx127x.h"
#include "sx127x_netdev.h"
#include "sx127x_params.h"
#endif

#if IS_USED(MODULE_SX126X)
#include "sx126x.h"
#include "sx126x_netdev.h"
#include "sx126x_params.h"
#endif

// #include"HX711.h"

/* Messages are sent every 20s to respect the duty cycle on each channel */
#define PERIOD_S            (20U)

#define SENDER_PRIO         (THREAD_PRIORITY_MAIN - 1)
static kernel_pid_t sender_pid;
static char sender_stack[THREAD_STACKSIZE_MAIN / 2];

static semtech_loramac_t loramac;
#if IS_USED(MODULE_SX127X)
static sx127x_t sx127x;
#endif
#if IS_USED(MODULE_SX126X)
static sx126x_t sx126x;
#endif
#if !IS_USED(MODULE_PERIPH_RTC)
static ztimer_t timer;
#endif

static const char *message = "This is Bird House";

static uint8_t deveui[LORAMAC_DEVEUI_LEN];
static uint8_t appeui[LORAMAC_APPEUI_LEN];
static uint8_t appkey[LORAMAC_APPKEY_LEN];

static void _alarm_cb(void *arg)
{
    (void) arg;
    msg_t msg;
    msg_send(&msg, sender_pid);
}

static void _prepare_next_alarm(void)
{
#if IS_USED(MODULE_PERIPH_RTC)
    struct tm time;
    rtc_get_time(&time);
    /* set initial alarm */
    time.tm_sec += PERIOD_S;
    mktime(&time);
    rtc_set_alarm(&time, _alarm_cb, NULL);
#else
    timer.callback = _alarm_cb;
    ztimer_set(ZTIMER_MSEC, &timer, PERIOD_S * MS_PER_SEC);
#endif
}

static void _send_message(void)
{
    printf("Sending: %s\n", message);
    /* Try to send the message */
    uint8_t ret = semtech_loramac_send(&loramac,
                                       (uint8_t *)message, strlen(message));
    if (ret != SEMTECH_LORAMAC_TX_DONE)  {
        printf("Cannot send message '%s', ret code: %d\n", message, ret);
        return;
    }
}

static void *sender(void *arg)
{
    (void)arg;

    msg_t msg;
    msg_t msg_queue[8];
    msg_init_queue(msg_queue, 8);

    while (1) {
        msg_receive(&msg);

        /* Trigger the message send */
        _send_message();

        /* Schedule the next wake-up alarm */
        _prepare_next_alarm();
    }

    /* this should never be reached */
    return NULL;
}

/*""""""""""""""""""""""""""""""""""""""""""""""""""""HX711""""""""""""""""""""""""""""""""""""""""""""""""""""""""*/
/*static struct hx711_gain_to_scale hx711_gain_to_scale[HX711_GAIN_MAX] = {
    { 128, 1, 0, 0 },
    {  32, 2, 0, 1 },
    {  64, 3, 0, 0 }
};
 
static int hx711_get_gain_to_pulse(int gain)
{
    int i;
    for (i = 0; i < HX711_GAIN_MAX; i++)
        if (hx711_gain_to_scale[i].gain == gain)
            return hx711_gain_to_scale[i].gain_pulse;
    return 1;
}
 
 
static int hx711_get_gain_to_scale(int gain)
{
    int i;
    for (i = 0; i < HX711_GAIN_MAX; i++)
        if (hx711_gain_to_scale[i].gain == gain)
            return hx711_gain_to_scale[i].scale;
    return 0;
}
 
 
struct hx711_data {
    struct device       *dev;
    struct gpio_desc    *gpiod_pd_sck;
    struct gpio_desc    *gpiod_dout;
    struct regulator    *reg_avdd;
    int         gain_set;   /* gain set on device */
/*  int         gain_chan_a;    /* gain for channel A */
/*  struct mutex        lock;
    /*
     * triggered buffer
     * 2x32-bit channel + 64-bit naturally aligned timestamp
     */
    /*u32           buffer[4] __aligned(8);
    /*
     * delay after a rising edge on SCK until the data is ready DOUT
     * this is dependent on the hx711 where the datasheet tells a
     * maximum value of 100 ns
     * but also on potential parasitic capacities on the wiring
     */
/*  u32         data_ready_delay_ns;
    u32         clock_frequency;
};
 
 
 
static int hx711_read(struct hx711_data *hx711_data)
{
    int i, ret;
    int value = 0;
    int val = gpiod_get_value(hx711_data->gpiod_dout);
    /* we double check if it's really down */
/*  if (val)
        return -1;
    for (i = 0; i < 24; i++) {
        value <<= 1;
        ret = hx711_cycle(hx711_data);
        if (ret)
            value++;
    }
    value ^= 0x800000;
    for (i = 0; i < hx711_get_gain_to_pulse(hx711_data->gain_set); i++)
        hx711_cycle(hx711_data);
    return value;
}
 
 
static int hx711_wait_for_ready(struct hx711_data *hx711_data)
{
    int i, val;
    /*
     * in some rare cases the reset takes quite a long time
     * especially when the channel is changed.
     * Allow up to one second for it
     */
/*  for (i = 0; i < 100; i++) {
        val = gpiod_get_value(hx711_data->gpiod_dout);
        if (!val)
            break;
        /* sleep at least 10 ms */
/*      msleep(10);
    }
    if (val)
        return -1;
    return 0;
}
 
 
static int hx711_reset(struct hx711_data *hx711_data)
{
    int val = hx711_wait_for_ready(hx711_data);
    if (val) {
        /*
         * an examination with the oszilloscope indicated
         * that the first value read after the reset is not stable
         * if we reset too short;
         * the shorter the reset cycle
         * the less reliable the first value after reset is;
         * there were no problems encountered with a value
         * of 10 ms or higher
         */
/*      gpiod_set_value(hx711_data->gpiod_pd_sck, 1);
        msleep(10);
        gpiod_set_value(hx711_data->gpiod_pd_sck, 0);
        val = hx711_wait_for_ready(hx711_data);
        /* after a reset the gain is 128 */
/*      hx711_data->gain_set = HX711_RESET_GAIN;
    }
    return val;
}
 
 
static int hx711_set_gain_for_channel(struct hx711_data *hx711_data, int chan)
{
    int ret;
    if (chan == 0) {
        if (hx711_data->gain_set == 32) {
            hx711_data->gain_set = hx711_data->gain_chan_a;
            ret = hx711_read(hx711_data);
            if (ret < 0)
                return ret;
            ret = hx711_wait_for_ready(hx711_data);
            if (ret)
                return ret;
        }
    } else {
        if (hx711_data->gain_set != 32) {
            hx711_data->gain_set = 32;
            ret = hx711_read(hx711_data);
            if (ret < 0)
                return ret;
            ret = hx711_wait_for_ready(hx711_data);
            if (ret)
                return ret;
        }
    }
    return 0;
}
 
 
static int hx711_reset_read(struct hx711_data *hx711_data, int chan)
{
    int ret;
    int val;
    /*
     * hx711_reset() must be called from here
     * because it could be calling hx711_read() by itself
     */
/*  if (hx711_reset(hx711_data)) {
        dev_err(hx711_data->dev, "reset failed!");
        return -1;
    }
    ret = hx711_set_gain_for_channel(hx711_data, chan);
    if (ret < 0)
        return ret;
    val = hx711_read(hx711_data);
    return val;
}
 
 
/*""""""""""""""""""""""""""""""""""""""""""""""""""""HX711""""""""""""""""""""""""""""""""""""""""""""""""""""""""*/


int main(void)
{
    puts("LoRaWAN Class A low-power application");
    puts("=====================================");

    /* Convert identifiers and application key */
    fmt_hex_bytes(deveui, CONFIG_LORAMAC_DEV_EUI_DEFAULT);
    fmt_hex_bytes(appeui, CONFIG_LORAMAC_APP_EUI_DEFAULT);
    fmt_hex_bytes(appkey, CONFIG_LORAMAC_APP_KEY_DEFAULT);

    /* Initialize the radio driver */
#if IS_USED(MODULE_SX127X)
    sx127x_setup(&sx127x, &sx127x_params[0], 0);
    loramac.netdev = &sx127x.netdev;
    loramac.netdev->driver = &sx127x_driver;
#endif

#if IS_USED(MODULE_SX126X)
    sx126x_setup(&sx126x, &sx126x_params[0], 0);
    loramac.netdev = &sx126x.netdev;
    loramac.netdev->driver = &sx126x_driver;
#endif

    /* Initialize the loramac stack */
    semtech_loramac_init(&loramac);
    semtech_loramac_set_deveui(&loramac, deveui);
    semtech_loramac_set_appeui(&loramac, appeui);
    semtech_loramac_set_appkey(&loramac, appkey);

    /* Use a fast datarate, e.g. BW125/SF7 in EU868 */
    semtech_loramac_set_dr(&loramac, LORAMAC_DR_5);


/************************************TEST**********************************************/
   /*HX711*/
    /*
    
    hx711_data hx711{HX711,11,12}

  
    if(hx711_wait_for_ready(hx711)){
        int a=hx711_read(hx711);
        
    
    }
    message = uint8_t(a);
    uint8_t ret = semtech_loramac_send(&loramac,(uint8_t *)message, strlen(message));
    if (ret != SEMTECH_LORAMAC_TX_DONE)  {
        printf("Cannot send message '%s', ret code: %d\n", message, ret);
    HX711.power_down();*/
 
 
 
/************************************TEST**********************************************/






    /* Start the Over-The-Air Activation (OTAA) procedure to retrieve the
     * generated device address and to get the network and application session
     * keys.
     */
    puts("Starting join procedure");
    if (semtech_loramac_join(&loramac, LORAMAC_JOIN_OTAA) != SEMTECH_LORAMAC_JOIN_SUCCEEDED) {
        puts("Join procedure failed");
        return 1;
    }
    puts("Join procedure succeeded");

    /* start the sender thread */
    sender_pid = thread_create(sender_stack, sizeof(sender_stack),
                               SENDER_PRIO, 0, sender, NULL, "sender");

    /* trigger the first send */
    msg_t msg;
    msg_send(&msg, sender_pid);
    return 0;
}
