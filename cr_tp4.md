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

---
### Analyse et compréhension du sujet

Dans un premier temps, une analyse approfondie de l’énoncé du TP a été réalisée afin d’identifier les objectifs attendus, les contraintes techniques ainsi que les concepts clés à mettre en œuvre. Cette étappe a été l'étape clé qui nous a permis d'aligner notre compréhension du sujet et de pouvoir opérer des choix de conception.

---
### Définition des classes importantes

À partir de cette analyse, une réflexion collective a été menée afin de définir les classes principales du programme. En effet, en suivant le libellé du sujet, on est arrivé à clairement identifier les classes importantes comme la classe de base quu'est la classe point à partir de laquelle, on définit la classe Polygone qui elle permet de définir la classe Parcelle. L'ensemble des attributs et des méthodes de ces classes étant déjà défini dans le sujet, nous avons pu reprendre la meme définition. L'étape centrale concernait les classes suivantes et de leur relations entre elles. Nous avons identifié celle-ci:
* ZoneNaturelle
* ZoneAgricole
* ZoneUrbaine
* ZoneaUrbanier
* Constructible
* Carte

Une fois l'identificatoiion des différentes classes faites, nous sommes occupés de trouver les relations qu'il pouvait y 'avoir entre eux afin de nous faciliter la conception. 
---

### Choix de conception
Les choix de conception ont été guidés par la volonté de respecter les principes de la programmation orientée objet et d’assurer une architecture claire et maintenable. L’utilisation de l’héritage permet de factoriser les attributs et comportements communs au sein d’une classe mère, tout en spécialisant les fonctionnalités dans les classes dérivées.
En effet, on pouvait répartir les classes, en dehors de Point2D, Polygone et Parcelle, en trois grands ensembles.
* Le premier concerne les ZA, ZU, ZAU et ZN qui sont, en fait des parcelles avec certaines particularités.
* Le deuxième concernant la classe Constructible permettant de catégoriser plus finement
* Le troisième, la classe Carte dérivant de Parcelle.

Le premier ensemble étant constitué d'éléments de Parcelle, nous pourrions tout simplement procéder à plusieurs héritages simples. Ceci ne représenterait alors qucune finesse dans notre analyse du sujets. En effet, Nous avons décidé de faire 3 héritages simples (ZN, ZU, ZAU) depuis Parcelle. ZA étant une zone naturelle particulière, nous l'avons fait dériver de la classe ZN du fait que les ZA ne sont pas constructibles et que néanmoins un exploitant pouveait y construire un batiment. Cela nous a un peu embrouillé au début mais finalement nous avons procédé comme tel. Les ZU et ZAU étant constructibles par défaut, elles sont donc des dérivées de Constructible. Ce qui nous permet dons de mettre en oeuvre le mécanisme d'héritage multiple pour ces deux classes. Enfin, la classe Carte qui hérite tout simplement de Parcelle.

Ci-dessous la traduction des nos choix de conception via un diagramme de classe.
<img width="751" height="674" alt="image" src="https://github.com/user-attachments/assets/794d0fb6-02a8-48f4-90aa-f229bf05abcd" />

A ce stade, l'organisation de notre projet est clair et nous sommes donc répartis les différentes taches à faire. Nous avons procédé à une répartition par classe.

### Organisation et répartition du travail

| Membre | Classe |
|-----------------|---------|
|André-Louis                 |Zone Urbaine et Zone à urbaniser         |
|Yanis                 |Parcelle et Carte         |
|Sophia                 |Polygone         |
|Laurène                 |Point2D         |
|Diarra                 |Constructible, Zone Agricole et Zone Naturelle         |


---
# Conclusion

À travers ce TP, nous avons approfondi notre compréhension des mécanismes avancés du langage C++, en particulier l’héritage, l’utilisation des templates et la gestion des constructeurs dans une hiérarchie de classes. Le travail d’analyse et de conception réalisé en amont a permis de structurer efficacement le projet et d’anticiper les contraintes techniques. Les choix de conception effectués ont contribué à garantir une initialisation correcte des objets et une meilleure réutilisabilité du code, rendant l’implémentation plus fiable et plus rapide. 
Le travail mené en groupe s’est déroulé de manière fluide et efficace, l’ensemble des membres étant aligné sur les objectifs et les choix de conception. Cette bonne coordination a permis de respecter les délais sans difficulté et de produire une solution cohérente, robuste et conforme aux attentes de l’énoncé.


 
