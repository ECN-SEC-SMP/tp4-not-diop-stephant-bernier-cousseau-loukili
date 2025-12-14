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



### Organisation et répartition du travail

A ce stade, l'organisation de notre projet est clair et nous sommes donc répartis les différentes taches à faire. Nous avons procédé à une répartition par classe.

| Membre | Classe |
|-----------------|---------|
|André-Louis                 |Zone Urbaine et Zone à urbaniser         |
|Yanis                 |Parcelle et Carte         |
|Sophia                 |Polygone         |
|Laurène                 |Point2D         |
|Diarra                 |Constructible, Zone Agricole et Zone Naturelle         |

### Gestion de la Compilation

La compilation du projet est gérée par le système **CMake**, qui est utilisé pour générer les fichiers de construction natifs (Makefiles, projets Visual Studio, etc.). L'utilisation de CMake assure la portabilité du code sur différents systèmes d'exploitation.

Le fichier `CMakeLists.txt` est configuré pour compiler le projet avec la norme C++ 14 (plus récente que la norme par défaut).
L'utilisation de CMake nous a aussi permi d'avoir un fichier plus simple à maintenir qu'un makefile.

### Intégration de Doxygen

L'intégration de la génération de documentation a été ajoutée au `CMakeLists.txt` via le module standard `FindDoxygen`.

* Si l'outil **Doxygen** est détecté sur le système, une cible de compilation nommée `doxygen_doc` est automatiquement créée.
* Cette cible permet aux utilisateurs de générer la documentation technique du code source commenté en utilisant la commande `cmake --build build --target doxygen_doc` (ou `make doxygen_doc`).

Cependant la présence de Doxygen sur le système est tout à fait optionnelle. En effet, si Doxygen n'est pas détecté l'étape de génération de la documentation sera simplement sautée.

---

## Classe `Parcelle

### Conception et Rôle d'Encapsulation

La classe `Parcelle` est la fondation de l'arborescence des différentes zones. Elle contient les données communes à tous les types de parcelles: le **numéro**, le **propriétaire**, et la **forme géométrique** stockée sous l'attribut `Polygone<int> forme`.

Afin de garantir que seules les classes filles spécialisées puissent être instanciées, le constructeur de la classe `Parcelle` a été déclaré comme `protected`. Ce choix empêche l'instanciation directe d'une parcelle générique qui n'aurait aucun sens.

### Polymorphisme et Affichage

L'affichage des informations d'une parcelle est géré par un *pattern* "Virtual Print" :
1. L'opérateur de flux global (`operator<<`) prend un pointeur `Parcelle*`.
2. Il délègue l'opération d'impression à la méthode virtuelle `void print(std::ostream& os) const override` implémentée dans chaque classe dérivée.

Cette approche garantit que les informations spécifiques à chaque type de zone (ZU, ZAU, etc.) sont correctement affichées dynamiquement lors de l'itération à travers la liste des parcelles.

***

## Classe `ZoneUrbaine` (ZU)

### Double Héritage et Implémentation

La `ZoneUrbaine` représente une parcelle dont une partie de la surface est déjà construite. Elle met en œuvre le **double héritage** :
* Elle hérite de **`Parcelle`** pour les propriétés cadastrales de base.
* Elle hérite de l'interface abstraite **`Constructible`** pour respecter le contrat d'implémentation de la constructibilité.

Son attribut spécifique, `float surfaceConstruite`, enregistre la surface déjà occupée par des infrastructures.

### Calcul du Potentiel Constructible

La méthode clé `float surfaceConstructible()` est surchargée pour renvoyer le potentiel constructible **restant** sur la parcelle.

$$
\text{Surface Constructible Restante} = \text{Surface Totale} - \text{Surface Déjà Construite}
$$

Cette formule est essentielle pour déterminer la limite légale des constructions futures sur les parcelles ZU.

***

## Classe `ZoneAUrbaniser` (ZAU)

### Choix de Conception d'Héritage

La `ZoneAUrbaniser` modélise une parcelle non encore urbanisée, mais destinée à l'être, avec un potentiel constructible prédéfini.

L'implémentation a opté pour une dérivation à partir de **`ZoneUrbaine`** (au lieu de `Parcelle` et `Constructible`). Ce choix a été réalisé en initialisant la `surfaceConstruite` à zéro dans l'appel au constructeur de la classe mère, permettant une réutilisation du code de base de la ZU.

### Définition du Potentiel

La ZAU est caractérisée par son attribut privé `float constructible`. Contrairement à la ZU, ce potentiel n'est pas calculé par soustraction, mais représente une **valeur fixe** (en $m^2$) dictée par les règlements du PLU.

Sa méthode `float surfaceConstructible()` se contente de retourner directement la valeur de cet attribut, affirmant que le potentiel d'urbanisation est une donnée d'entrée pour ce type de zone.

***

## Classe `Carte` (Gestion Globale du Cadastre)

### Structure de Données et Polymorphisme

La classe `Carte` sert de conteneur principal pour le système cadastral. Elle gère toutes les parcelles via un `std::vector<Parcelle*> listeParcelles`.

L'utilisation de pointeurs vers la classe de base `Parcelle` permet le **stockage polymorphique** : une seule liste peut contenir des objets concrets de types `ZU`, `ZAU`, `ZN`, etc., tout en garantissant un accès uniforme aux méthodes de base et un comportement spécialisé via les fonctions virtuelles.

### Gestion de la Mémoire et Chargement

Le constructeur `Carte(std::string& nomFichier)` est déclaré pour gérer l'opération de **désérialisation** : lecture des données d'un fichier, identification du type de zone, et instanciation dynamique de l'objet de la classe fille appropriée (`new ZoneUrbaine`, `new ZoneAgricole`, etc.).

Étant donné que les objets sont alloués dynamiquement, un **destructeur (`~Carte()`)** est implémenté. Ce destructeur parcourt la `listeParcelles` et appelle `delete` sur chaque pointeur, assurant ainsi une libération propre de la mémoire et prévenant les fuites de ressources.

### Points de Non-Conformité au Sujet

L'implémentation de la classe `Carte` est également incomplète :
1. **Fonctionnalité Manquante :** L'exigence de pouvoir **sauvegarder** l'état de la carte (sérialisation des données) vers un fichier n'est pas implémentée.
2. **Attribut Manquant :** L'attribut `surfaceTotale` (qui devrait représenter la surface cumulée de toutes les parcelles) n'est pas déclaré dans l'en-tête de la classe.

# Conclusion

À travers ce TP, nous avons approfondi notre compréhension des mécanismes avancés du langage C++, en particulier l’héritage, l’utilisation des templates et la gestion des constructeurs dans une hiérarchie de classes. Le travail d’analyse et de conception réalisé en amont a permis de structurer efficacement le projet et d’anticiper les contraintes techniques. Les choix de conception effectués ont contribué à garantir une initialisation correcte des objets et une meilleure réutilisabilité du code, rendant l’implémentation plus fiable et plus rapide. 
Le travail mené en groupe s’est déroulé de manière fluide et efficace, l’ensemble des membres étant aligné sur les objectifs et les choix de conception. Cette bonne coordination a permis de respecter les délais sans difficulté et de produire une solution cohérente, robuste et conforme aux attentes de l’énoncé.


 
