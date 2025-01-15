---
title: Distribution Linux
---

> Une distribution Linux est un système d'exploitation basé sur le noyau Linux, qui est le cœur du système. Ce noyau est ensuite complété par divers logiciels, outils et bibliothèques pour former un système d'exploitation complet et fonctionnel. 
{:.definition}

Voici quelques éléments clés qui composent une distribution Linux :

1. **Noyau Linux** : C'est le cœur du système. Développé par Linus Torvalds et par la communauté open source, il gère les ressources matérielles et les communications entre le matériel et les logiciels.

2. **Gestionnaire de paquets** : Un outil pour installer, mettre à jour et supprimer les logiciels du système. L'inventaire inclut APT (Debian, Ubuntu et dérivés), YUM/DNF (REHL, CentOS, Fedora et dérivés), Pacman (Arch Linux), ZYpp (OpenSUSE) et emerge (Gentoo).

3. **Environnement de bureau** : Une interface graphique pour interagir avec le système des distributions de bureau. Les distributions serveurs n'ont généralement pas de bureau et se pilotent par le terminal et à distance. L'inventaire inclut GNOME, KDE, XFCE, LXDE, Cinnamon, Mate, Enlightment et Unity.

4. **Applications et outils de base** : Les distributions Linux incluent souvent un ensemble d'applications et d'outils de base tels que des navigateurs web, des éditeurs de texte, des lecteurs multimédia, des outils de gestion de fichiers, une suite burautique etc.

5. **Scripts et utilitaires système** : Des outils pour la configuration et la gestion du système, comme les scripts d'initialisation (init scripts) et les gestionnaires de services comme systemd.

6. **Documentation et support** : Des guides, des manuels et des forums communautaires pour aider les utilisateurs à résoudre des problèmes et à tirer le meilleur parti de leur distribution.

### Quelques distributions Linux

- **Debian** : Connue pour sa stabilité et son large dépôt de logiciels. La sécurité est une priorité pour Debian. Le projet dispose d'une équipe de sécurité dédiée qui surveille les vulnérabilités et publie des mises à jour de sécurité pour les logiciels inclus dans la distribution.
  - **Ubuntu** : Une distribution populaire basée sur Debian, connue pour sa facilité d'utilisation et son support étendu.
- **REHL** : Red Hat Enterprise Linux est une distribution commerciale développée par Red Hat pour les environnements d'entreprise. Elle est conçue pour fournir un système d'exploitation stable, sécurisé et performant.
  - **Fedora** : Distribution communautaire soutenus par Red Hat. Elle est connue pour être à la pointe de l'innovation en intégrant rapidement les dernières technologies et logiciels du monde Linux. Fedora sert souvent de banc d'essai pour les fonctionnalités qui peuvent être incluses plus tard dans RHEL.
  - **CentOS Steam** : Distribution qui sert de branche de développement continue à RHEL. Elle se situe entre Fedora, qui est plus en amont et innovant, et RHEL, qui est plus en aval et stable. CentOS Stream offre aux développeurs et aux utilisateurs un aperçu des futures versions de RHEL, permettant ainsi de tester et de contribuer aux versions de RHEL avant leur sortie officielle.
  - **Rocky Linux** : Distribution Linux communautaire qui se veut un clone gratuit de RHEL
- **Arch Linux** : Conçue pour les utilisateurs avancés qui veulent un contrôle total sur leur système.
- **SUSE** : SUSE Linux est une distribution Linux développée par la société SUSE, connue pour ses solutions destinées aux entreprises. Il existe plusieurs versions de SUSE Linux, notamment openSUSE, une version communautaire, et SUSE Linux Enterprise, une version commerciale destinée aux environnements professionnels
- **Mandriva** : Distribution Linux développée par la société française Mandriva.
- **Gentoo**: Distribution dont les paquets sont compilés à partir du code source, ce qui permet d'optimiser les logiciels pour le matériel spécifique de l'utilisateur et de choisir les fonctionnalités à inclure ou exclure.

Chaque distribution Linux a ses propres caractéristiques et objectifs, permettant aux utilisateurs de choisir celle qui répond le mieux à leurs besoins. Mais au final ce sont quand même les mêmes applications qui seront utilisées ...

+ [Installer Debian 12](debian)
+ [Installer Rocky Linux](rocky)

### Installer des paquets logigicels

+ Utiliser [APT](paquet/apt)


### Utiliser le [système de fichiers](fs)

+ Connaitre l'[organisation](fs/organisation) et l'arborescence des dossiers
+ Renommer, déplacer, copier et supprimer des fichiers.
+ Supprimer des dossiers.

### Éditer des fichier avec [nano](nano)

### Gérer les [utilisateurs](utilisateurs)
+ Attribuer des [droits](utilisateurs/droits)
+ [Accès à distance par ssh](utilisateurs/ssh)

### Gérer les [réseaux](network)

### Gérer les [services](services)

### [Observer](observer/uptime)

## Commandes utiles

Éteindre (utilisateur `root` ou `sudo`).

```shell
$ shutdown -h now
```

ou

```shell
$ halt
```

Redémarrer (utilisateur `root` ou `sudo`).

```shell
$ shutdown -r now
```

ou

```shell
$ reboot
```

wget
curl -OL http://
O output
L suivre les redirectiosn
