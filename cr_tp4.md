# TP projet : Programmation orienté objet
---

## Participants au projet

* Yanis Cousseau
* Mame Diarra DIOP
* Sophia Loukili
* Laurène Bernier
* André-Louis Stéphant
---

##  Description du projet

Le but de ce projet est de créer un ensemble de classes permettant à une communauté de communes de gérer un PLU simplifié et plus particulièrement lui permettant d’implanter un nouveau SI pour gérer son cadastre de manière adéquate en incluant les nouvelles directives du PLU.

---

##  Objectifs pédagogiques

L’objectif de ce TP est de comprendre et de mettre en pratique le mécanisme d’héritage en C++ à travers la conception d’une hiérarchie de classes. Ce travail permet également de renforcer la compréhension de l’initialisation correcte des attributs. Il vise également à introduire et utiliser les templates afin de généraliser certaines structures ou comportements, permettant ainsi une programmation plus flexible et réutilisable.

---
## Travail réalisé

### Analyse et compréhension du sujet

Dans un premier temps, une analyse approfondie de l’énoncé du TP a été réalisée afin d’identifier les objectifs attendus, les contraintes techniques ainsi que les concepts clés à mettre en œuvre. Cette étappe a été l'étape clé qui nous a permis d'aligner notre compréhension du sujet et de pouvoir opérer des choix de conception.

### Définition des classes importantes

À partir de cette analyse, une réflexion collective a été menée afin de définir les classes principales du programme. En effet, en suivant le libellé du sujet, on est arrivé à clairement identifier les classes importantes comme la classe de base quu'est la classe point à partir de laquelle, on définit la classe Polygone qui elle permet de définir la classe Parcelle. L'ensemble des attributs et des méthodes de ces classes étant déjà défini dans le sujet, nous avons pu reprendre la meme définition. L'étape centrale concernait les classes suivantes et de leur relations entre elles. Nous avons identifié celle-ci:
* ZoneNaturelle
* ZoneAgricole
* ZoneUrbaine
* ZoneaUrbanier
* Constructible
* Carte

Une fois l'identificatoiion des différentes classes faites, nous sommes occupés de trouver les relations qu'il pouvait y 'avoir entre eux afin de nous faciliter la conception. 

### Choix de conception
Ci-dessous la traduction des nos choix de conception via un diagramme de classe.
<img width="751" height="674" alt="image" src="https://github.com/user-attachments/assets/794d0fb6-02a8-48f4-90aa-f229bf05abcd" />



### Organisation et répartition du travail

On a d'abord initié un diagramme de classe partagée. Ensuite, on s'est répaassigné rtit les classes ainsi :
- AL : Zone Urbaine et Zone à urbaniser
- Yanis : Parcelle et Carte
- Sophia : Polygone
- Laurène : Point2D
- Diarra : Constructible, Zone Agricole et Zone Naturelle


---
# Conclusion



 
