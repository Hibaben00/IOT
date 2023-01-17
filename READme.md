# Nichoir connecté :

Vous trouverez ci-joint tous nos fichiers (présentation, flyer, rapport) ainsi que nos codes pour le projet : Nichoir Connecté.

Afin d'executer et compiler notre projet, il est impératif de télécharger d'abord le projet RIOT, et de remplacer ensuite les fichiers existant dans le dossier examples/lorawan par les fichiers qui se trouve dans notre répértoire Git.

Pour compiler, voilà la commande : 

**make BOARD=lora-e5-dev DRIVER=sx126x_stm32wl DEVEUI=0123456789ABCDEFAPPEUI=000000000000000 APPKEY=11112222333344441111222233334444 -j 8**
