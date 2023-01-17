# <span style="color:;"> Rapport :

##  <span style="color:pink;"> Introduction :
Le nichoir est conçu pour mesurer le poids des oiseaux qui visitent le nichoir, en utilisant une balance intégrée. Les données de poids sont ensuite transmises à un ordinateur ou à un appareil mobile via une connexion sans fil, telle que LoRa.

Notre nichoir connecté est équipé d'une carte électronique LoRa pour la communication sans fil, d'une puce STM32 pour la gestion de l'alimentation et la logique de commande, ainsi qu'un capteur de poids HX711 pour mesurer le poids des oiseaux. Il est également équipé d'une boîte pour protéger les composants électroniques et un capteur de mouvement pour détecter les entrées et les sorties des oiseaux.

Avec notre nichoir connecté, les utilisateurs peuvent suivre les tendances de poids des oiseaux au fil du temps, surveiller les oiseaux qui fréquentent le nichoir, et collecter des données scientifiques utiles pour la recherche sur la faune. Il peut également être utilisé pour surveiller les populations d'oiseaux dans des zones sauvages et pour aider à la conservation des espèces.

Notre nichoir connecté est conçu pour être facile à utiliser et à entretenir, il est également robuste pour résister aux intempéries et aux conditions extérieures. Il est également accessible pour les particuliers qui souhaitent en apprendre davantage sur les oiseaux qui visitent leur jardin.

##  <span style="color:pink;"> Analyse du marché et des produits commérciaux :
Il existe plusieurs produits concurrents dans le marché des niches connectées. Ces nichoirs comprennent des caractéristiques variées telles que : 

- La surveillance à distance
- L'automatisation de la nourriture et de l'eau 
- La personnalisation de l'environnement de niche
- La possibilité de diffuser de la musique ou de la vidéo.

Certains des principaux acteurs sur ce marché comprennent : 
- **PetSafe** : PetSafe est l'une des marques les plus reconnues dans l'industrie des produits pour animaux de compagnie, et ils proposent une large gamme de produits pour les animaux domestiques, notamment les clôtures électroniques, les niches connectées, les distributeurs automatiques de nourriture et d'eau, les jouets pour animaux, les colliers anti-aboiements et plus encore. Ils ont une grande présence dans le marché, particulièrement en Amérique du Nord.

- **SureFlap** : SureFlap est une entreprise basée au Royaume-Uni qui fabrique des produits pour animaux de compagnie connectés, tels que des niches connectées, des distributeurs automatiques de nourriture et d'eau, et des clôtures électroniques. Les niches connectées de SureFlap permettent aux propriétaires d'animaux de surveiller et de contrôler la température, l'environnement et les niveaux de nourriture et d'eau de leur animal à distance, grâce à une application mobile. Les niches connectées de SureFlap sont équipées d'un système de verrouillage électronique qui permet aux propriétaires de limiter l'accès à la niche aux seuls animaux qui portent un collier émetteur. Cette fonctionnalité permet de protéger les animaux de compagnie contre les prédateurs et de limiter les fuites accidentelles. 

- **Petnet** :  est une entreprise qui développe des produits et des services pour les propriétaires d'animaux de compagnie. Ils ont créé un système automatisé pour nourrir les animaux de compagnie à distance via une application mobile, appelée Smart Feeder. Il permet aux propriétaires de contrôler à distance la nourriture de leur animal de compagnie, de programmer des repas et de suivre la consommation de nourriture de leur animal. Petnet propose également d'autres produits tels que des distributeurs automatiques de croquettes et des colliers GPS pour les chiens. Leur objectif est de faciliter la vie des propriétaires d'animaux de compagnie en leur offrant des solutions technologiques pour mieux prendre soin de leurs animaux

Les prix varient considérablement, allant de quelques dizaines à plusieurs centaines d’euros, en fonction des fonctionnalités et de la taille de la niche. Il existe également des niches connectées qui sont spécifiques à certains types d'animaux, comme les chats, les oiseaux ou les petits animaux de compagnie.


## <span style="color:pink;">  Architecture globale du système d'un nichoir connecté utilisant lora e5 et capteur hx711 : 

Notre système de nichoir connecté utilisant LoRa E5 et un capteur HX711 a une architecture globale comme suit:
- Le capteur HX711 est installé à l'intérieur du nichoir pour peser les oiseaux qui entrent et sortent. Il peut être connecté à un support ou à une plate-forme pour assurer une précision de pesée.

- La carte de développement LoRa E5 est installée à l'intérieur du nichoir, elle est connectée au capteur HX711 via les broches de données et d'horloge. La carte LoRa E5 permet la transmission des données de pesée des oiseaux entrant et sortant du nichoir.

- Pour la gestion de notre LoRA, on utilise ChirpStack. ChirpStack est un système open-source pour la gestion de réseaux LoRaWAN. Il permet de gérer les appareils connectés, de collecter et de traiter les données récoltées par ces appareils, et de les envoyer vers des applications ou des services tiers. Il est utilisé pour la création de réseaux de capteurs pour une variété d'applications.
Un utilisateur peut accéder aux données de pesée en temps réel via un site Web ChirpStack pour suivre l'utilisation du nichoir et les activités des oiseaux.

## <span style="color:pink;"> La sécurité globale (clé de chiffrage) :

Pour la sécurité globale de notre nichoir connecté utilisant LoRa E5 on a pris un ensemble de mesures de sécurité pour protéger les données et les communications transmises par la nichoir connectée. On a inclus le chiffrement de bout en bout. 

La clé de chiffrement est un élément clé de la sécurité globale d'une nichoire connectée utilisant LoRa E5. Il s'agit d'un code utilisé pour chiffrer les données transmises, de sorte qu'elles ne peuvent être lues que par les parties autorisées. La clé de chiffrement doit être créée et gérée de manière sécurisée pour assurer la sécurité des communications.

## <span style="color:pink;"> Le respect de la vie privée du service (RGPD) : lister les risques d’atteinte au respect de la vie privée : 

Le Règlement général sur la protection des données (RGPD) est une réglementation de l'Union Européenne qui a pour but de protéger les données personnelles des individus en garantissant leur confidentialité et leur sécurité. Il s'applique à toutes les entreprises qui traitent des données personnelles de personnes résidant dans l'Union Européenne, quelle que soit leur localisation.
Les risques d'atteinte au respect de la vie privée liés à la mise en place d'un service comprennent :
- La collecte, le stockage et l'utilisation non autorisés de données personnelles.
- La perte ou la divulgation accidentelle de données personnelles.
- Les attaques informatiques visant à accéder ou à voler des données personnelles.
- La mauvaise gestion des données personnelles, entraînant des erreurs ou des incohérences.
- La non-conformité aux exigences réglementaires, entraînant des sanctions financières et/ou des poursuites judiciaires.
- Le non-respect des droits des personnes concernées par les données (droit d'accès, de rectification, d'effacement, de limitation de traitement, de portabilité, de ne pas faire l'objet d'une décision individuelle automatisée,..)

## <span style="color:pink;"> Définir l’architecture matérielle de la nichoire :

Pour concevoir notre nichoir connecté, nous avons utilisé le matériel suivant :

- **Dev Board LoRa E5**: Il s'agit d'un module électronique qui permet de connecter les dispositifs à un réseau LoRaWAN. Il comprend un transceiver LoRa et un microcontrôleur qui gère les communications avec le réseau. Il peut également inclure des interfaces pour connecter des capteurs et des actionneurs. 

- **Capteur HX711**: Il s'agit d'un capteur de pesage qui permet de mesurer la masse d'un objet. Il est utilisé pour mesurer la masse des oiseaux qui entrent et sortent de la nichoir. Il est connecté au Dev Board LoRa E5 via une interface appropriée, comme un port I2C ou SPI.

Notre capteur, au début, était non assemblé (voir figure ci-dessous).

![Capteur](https://github.com/Hibaben00/IOT/blob/test/Images/pic2.jpg)

Pour l’assemblé, on s’est basé sur la documentation technique ci dessous.
 
![Datasheet](https://github.com/Hibaben00/IOT/blob/test/Images/pic3.png)

On obtient, au final, un produit qui ressemble à ceci. 

![Capteur_asse](https://github.com/Hibaben00/IOT/blob/test/Images/pic4.jpg)

- **STM Discovery**: Il s'agit d'un module électronique qui permet de développer des applications pour des microcontrôleurs STM32. Il est utilisé pour flasher notre LoRA. Il est connecté au Dev Board LoRa E5 via une interface appropriée, comme un port UART ou USB.

Voici un schéma global de la liaison des différents composants de notre système: 

![schema](https://github.com/Hibaben00/IOT/blob/test/Images/pic5.png)


Cette architecture matérielle permet de connecter les capteurs de la nichoir connectée à un réseau LoRaWAN à l'aide du Dev Board LoRa E5, pour transmettre les données de capteurs vers un serveur ou une application pour analyse et stockage. Le STM Discovery est utilisé pour stocker le code de l'application de la nichoir connectée, permettant de contrôler les différents composants de la nichoir connectée notamment le capteur HX711 et de prendre des décisions en fonction des données reçues.

Voici une description  de liaison des pins des différents composants : 

- La connexion LoRa e5 et STM32L Discovery :

1. Connectez l'interface SPI de l'e5 LoRa à l'interface SPI du STM32L Discovery.

    On se base sur cette figure pour lier les différents pins de notre carte STM.

![doc](https://github.com/Hibaben00/IOT/blob/test/Images/pic6.png)

2. Connectez les pins de l’horloge et de données de LoRa e5 au STM32L Discovery (SWDIO, SWCLK).
3. Connectez les pins de masse de LoRa e5 au STM32L Discovery (GND).

![pins](https://github.com/Hibaben00/IOT/blob/test/Images/pic7.png)

- La connexion HX711 et LoRa E5:
1. Connectez les pins de données et clock de HX711 au LoRa E5.
2. Connectez les pins d' alimentation de HX711 au STM32L Discovery.

![STM](https://github.com/Hibaben00/IOT/blob/test/Images/pic8.png)


## <span style="color: pink;"> Estimation du coût de la BOM de notre produit pour 5000 unités produites :

Les coûts potentiels des composants pour une nichoir connectée:
- La lora e5 dev board peut coûter entre **20€** et **30€** en fonction du fournisseur et des quantités achetées. 
- Le capteur HX711 peut coûter entre **1€** et **3€**.
- La Stm32L discovery peut coûter entre **10€** et **15€**.
- Les piles pour Lora :  **2€** pour chacune (on en a besoin de 2).
- Un boîtier sous forme de nid pour héberger notre protocole peut coûter entre **3€** et **12€**.

Une nichoire connecté peut nous couter au maximum:
**64€** 

Pour la production de 5000 unités : **320 000€** 

## <span style="color: pink;"> Estimer le coût de certification ETSI du produit, le coût de certification LoRa Alliance du produit … : 
 
Le coût de certification ETSI pour un produit peut varier en fonction de plusieurs facteurs  on peut toutefois estimer un coût de certification d'environ 5000 à 10000€ pour un produit standard.

Concernant les coûts de certification Lora Alliance, on peut estimer à environ 2500€ la certification. 

 ## <span style="color:pink;"> Les fonctionnalités prévues pour un nichoir connecté :
 
 Les fonctionnalités prévues pour un nichoir connecté peuvent inclure :
 
- La surveillance vidéo en direct de l'intérieur du nichoir, permettant de suivre les activités des oiseaux qui y nichent.
- La possibilité de diffuser de la musique ou des sons naturels pour attirer les oiseaux dans le nichoir.
- La capacité de contrôler l'éclairage et la température à l'intérieur du nichoir pour maintenir un environnement confortable pour les oiseaux.
- La possibilité de recevoir des notifications lorsque des oiseaux entrent ou sortent du nichoir.
- La possibilité de partager les images et vidéos capturées avec d'autres utilisateurs.
- La compatibilité avec des applications pour smartphones ou tablettes pour accéder à distance aux fonctionnalités du nichoir connecté.
- La possibilité de recevoir des informations sur les oiseaux qui nichent dans le nichoir.
 
 
## <span style="color: pink;"> Une implémentation du logiciel embarqué de l’objet défini :

Notre implémentation du logiciel embarqué pour une nichoir connectée utilisant une lora e5 ev board, un capteur HX711 et une STM se compose de : 
1. Initialisation du système:
- Configuration de la communication LoRa avec l'utilisation de la bibliothèque LoRa correspondante pour la Lora E5 dev board.

- Initialisation des capteurs HX711 et de la STM

- Mise en place d'un système de gestion d'erreur pour détecter les erreurs éventuelles dans la communication avec le capteur ou la STM

2. Boucle principale:
- Lecture des données du capteur de poids.

- Traitement des données pour assurer la qualité des données.

- Envoi des données vers le réseau LoRa via la Lora e5 dev board.

3. Gestion des erreurs:
- Gestion des erreurs éventuelles dans la communication avec les capteurs ou la STM.

- Envoi d'alertes à l'utilisateur en cas d'erreur grave (peut être ajouté ultérieurement )

## <span style="color: pink;"> Le logiciel embarqué de l’objet :

Le logiciel embarqué d'une nichoir connectée est le logiciel qu’on a intégré à la partie matérielle de la nichoir. Dans notre cas, une carte électronique utilisant une lora E5 ev board, un capteur HX711 et une STM (microcontrôleur) line discovery. Il permet à la nichoir de fonctionner de manière autonome et de communiquer avec d'autres dispositifs connectés, tels que des smartphones ou des ordinateurs. Il peut inclure des fonctions telles que :
- La gestion de la communication radio LoRa pour envoyer et recevoir des données à travers le réseau LoRa

- La gestion de la communication avec les capteurs HX711 et la STM pour récupérer les données de poids.

- La gestion de la mise en réseau pour envoyer les données recueillies à un serveur ou un stockage en nuage via une interface de programmation d'application (API)

- La gestion de l'interface utilisateur pour permettre à l'utilisateur de configurer et de surveiller la nichoir connectée.

En somme, le logiciel embarqué de la nichoir connectée est ce qui permet à la nichoir de se connecter au réseau LoRa et de communiquer avec les capteurs pour récupérer les données de poids et de les envoyer à un serveur ou un stockage en nuage, ainsi que de permettre à l'utilisateur de configurer et de surveiller la nichoir connectée.

 ## <span style="color: pink;"> Les métriques du logiciel embarqué (nombre de lignes de code, taille du binaire du firmware ie le fichier .bin) : 
 
Pour réaliser notre projet, on s'est basé sur un exemple de LoRaWan fourni par RIOT qui est composé de plusieurs nombres de fichiers.
En ce qui concerne notre propre code, nous avons modifié dans le main pour ajouter le code du capteur HX711. On a obtenu un main de **383 lignes**.
Pour optimiser le main, on a pensé à programmer en C++ et de créer une classe de **HX711.h**.
Néanmoins, on n’ a pas eu suffisamment le temps pour mettre au propre nos idées et nos codes. On s'est contenté de le faire en commentaire.

## <span style="color: pink;"> Avantages/inconvénients des produits concurrents
| Produit concurrent       | Avantages                 | inconvénients                 |
|--------------------------|---------------------------|-------------------------------|
| PetSafe                  |  - Surveillance en temps réel des oiseaux via une application mobile - Envoi automatique des données sur les oiseaux à un serveur ou un stockage en nuage - Design esthétique et élégant | - Coût élevé par rapport aux nichoirs classiques - Nécessite une connexion internet pour fonctionner - Installation et configuration peuvent être complexes|
| SureFlap                  | - Contrôle de l'accès à la nichoir via une application mobile - Suivi en temps réel des oiseaux via une application mobile - Design esthétique et élégant |- Installation et configuration peuvent être complexes - Nécessite une connexion internet pour fonctionner- - Coût élevé par rapport aux nichoirs classiques |
|Petnet                  | - Surveillance en temps réel des oiseaux via une application mobile - Envoi automatique des données sur les oiseaux à un serveur ou un stockage en nuage - Design esthétique et élégant | - Installation et configuration peuvent être complexes - Nécessite une connexion internet pour fonctionner - Coût élevé par rapport aux nichoirs classiques|

 
  ## <span style="color: pink;"> Conclusion : 
Au cours de ces séances du projet "Nichoir Connecté", nous avons eu l'occasion de mettre en oeuvre notre savoir faire concernant la communication par LoRa. Concevoir un système de A à Z ( soudure, assembler et connecter les différents composants, code..) était une belle aventure malgré les obstacles rencontrés. Malheureusement, le temps n'était pas en notre faveur pour aboutir un projet compliqué.

