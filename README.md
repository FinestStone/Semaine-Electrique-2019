<div>
  <a href="http://folietechnique.com/">
  <img src="http://folietechnique.com/sites/folietechnique2.amigow.polymtl.ca/files/logo-folietechnique.png">
  </a>
</div>

# Semaine Électrique 2019

Bienvenue sur le répertoire GitHub de la semaine électrique 2019 pour le camp scientifique [Folie Technique](http://folietechnique.com/) !

## Par où commencer ?

Sur cette page, vous pourrez trouver l'ensemble des scripts et des schémas de circuits nécessaires pour reproduire les activités présentées dans le cadre de cette semaine. Ceux-ci sont respectivement regroupés dans les dossiers « Circuits » et « Scripts » du dossier de l'activité correspondante.

> Par exemple, dans l'archive [Construction d'une Radio FM](TODO), vous pourrez trouver dans le dossier « Circuits » les diagrammes, classées dans l'ordre, des étapes pour réaliser le circuit. Le dossier « Scripts » contient plutôt le code à installer sur le microcontrôleur, soit le [Arduino Nano](https://store.arduino.cc/usa/arduino-nano).

Avant d'entreprendre quoique ce soit, assurez-vous d'avoir installé l'éditeur de code (IDE) officiel d'Arduino. Pour l'installer, cliquez sur le lien correspondant au système d'exploitation de votre ordinateur :
* [Windows](https://www.arduino.cc/en/Guide/Windows);
* [Mac OS X](https://www.arduino.cc/en/Guide/MacOSX);
* [Linux](https://www.arduino.cc/en/Guide/Linux).

Pour la suite, vous aurez besoin d'un câble de type Micro-USB ([par exemple](https://www.staples.ca/fr/Câble-1M-Micro-USB-couleurs-variées/product_1883474_1-CA_2_20001)).

Dans l'IDE, cliquez sur Outils -> Type de carte -> Arduino Nano. Aussi, sélectionnez Outils -> Processor -> ATmega168. Finalement, choisissez Outils -> Port -> (Choisir un des ports proposés). Pour valider que tout est fonctionnel, branchez votre Arduino à votre ordinateur et sélectionnez Fichier -> Exemples -> 01.Basics -> Blink. Téléverser le code de la fenêtre qui vient de s'ouvrir, soit en appuyant sur le bouton avec la flèche (Téléverser). Si tout se déroule correctement, on devrait pouvoir lire après quelques secondes, dans le bas de la fenêtre, "Téléversement terminé" et la DEL rouge de votre Arduino devrait s'allumer et s'éteindre chaque seconde.

Si vous éprouvez des difficultés, vous pouvez consulter ce [lien](https://www.arduino.cc/en/Guide/Troubleshooting#upload) ou encore consulter le [guide de démarrage officiel d'Arduino](https://www.arduino.cc/en/Guide/ArduinoNano). Il est à noter que pour les utilisateurs de Linux, il peut s'avérer nécessaire de modifier certaines permissions liées à l'utilisation du port USB. Si c'est le cas, voici [ce qu'il faut faire](https://www.youtube.com/watch?v=MKS1vVDXiU0).

## Pour réaliser un des projets

Si vous n'avez pas rencontré de problème jusqu'à présent, félicitations ! Si vous souhaitez reproduire les projets de la semaine, il vous suffit de cliquer sur le bouton vert "Clone or Download" (dans le haut de la page) et sélectionnez "Download ZIP".

Après avoir extrait le fichier ZIP, vous pourez consulter le code et les schémas des différentes activités. Les projets peuvent toujours être réalisés selon la séquence suivante :

1. Commencer par transférer le code de l'activité sur votre Arduino Nano.  
  1.1. Connectez l'Arduino Nano à votre ordinateur avec le câble Micro-USB.  
  1.2. Trouvez le script (fichier .ino) de l'activité et double-cliquez dessus (l'IDE devrait s'ouvrir).  
  1.3. Appuyer sur le bouton de téléversement (la flêche) dans l'IDE.  
  1.4. Débrancher votre Arduino.  
2. Réalisez le circuit, en suivant les étapes présentées dans les images.  
3. Alimentez le circuit (avec une batterie 9V ou en branchant votre Arduino à votre ordinateur).  
4. Amusez-vous !

> Pour le projet radio, il vous sera nécessaire d'installer trois librairies. Téléchargez d'abord le fichier .ZIP de la [Si4703_Breakout](https://cdn.sparkfun.com/assets/learn_tutorials/2/7/4/Si4703_Breakout.zip), ensuite celui de la [LCD5110_Graph](http://www.rinkydinkelectronics.com/library.php?id=47) et finalement celui de la [Keypad](https://www.arduinolibraries.info/libraries/keypad). Pour terminer, dans l'IDE, cliquez sur Croquis -> Inclure une bibliothèque -> Ajouter bibliothèque .ZIP... et ajouter les trois fichiers .ZIP téléchargés.
