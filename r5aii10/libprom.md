---
title: libprom
---


libprom est une librairie c qui fournit des bibliothèques partagées pour l'instrumentation des logiciels et l'exposition des métriques au format texte tel que défini par le format d'exposition Prometheus (voir https://prometheus.io/docs/instrumenting/exposition_formats/ pour plus de détails). libprom fournit l'implémentation de l'API principale et libpromhttp, un gestionnaire Web simple pour exposer les métriques pour le scraping.


```shell
# 1. La librairie microhttp (un micro serveur web en C)
sudo apt install libmicrohttpd-dev

#2. Récupérer les sources du projet libprom
# github : serveur de projet, stocke les sources des programmes
# git : programme qui permet de télécharger et envoyer les 
# sources vers github
sudo apt install git
git clone https://github.com/jelmd/libprom.git

# Entrer dans le dossier libprom
cd libprom

# Installation de l'outil d'automatisation de compilation de projet
sudo apt install cmake
# compiler l'ensemble du projet
make

# installer les librairies compilées dans le système (sudo car modification du système)
cd prom/build
sudo make install

cd ../..

cd promhttp/build
sudo make install
```

### Exemple fonctionnel

```c
#include <stdio.h>
#include <stdlib.h>
#include "libprom/prom.h"
#include "libprom/promhttp.h"

prom_counter_t *my_counter;
 
int main() {

  int result = pcr_init(0,"geii_");

  my_counter = prom_counter_new("my_counter", "counts things", 0, NULL);
  pcr_register_metric(my_counter);

  promhttp_set_active_collector_registry(NULL);
 
  // Serveur web
  struct MHD_Daemon *server = promhttp_start_daemon(MHD_USE_SELECT_INTERNALLY, 8099, NULL, NULL);
  if (server == NULL)
  {
    printf("Impossible de démarrer le serveur HTTP\n");
    return 1;
  }

  // Boucle infinie
  while(1) {
    fputc('.', stdout); fflush(stdout);
    prom_counter_inc(my_counter, NULL);
		sleep(1);
  }

  puts("Fin du programme");
  pcr_destroy(PROM_COLLECTOR_REGISTRY);
  promhttp_stop_daemon(server);
}
```
Librarie d'affichage semi graphique

```shell
sudo apt-get install libncurses-dev
```
