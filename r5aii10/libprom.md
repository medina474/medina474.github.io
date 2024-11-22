---
title: libprom
---

```shell
sudo apt install libmicrohttpd-dev

sudo apt install git
git clone https://github.com/jelmd/libprom.git
cd libprom

sudo apt install cmake
make

cd prom/build
sudo make install
cd promhttp/build
sudo make install
```

### Exemple fonctionnel

```c
#include <stdio.h>
#include <stdlib.h>
#include "libprom/prom.h"
#include "libprom/promhttp.h"
 #include <signal.h>

static int running = 1;

void handle_signal(int signal) {
    running = 0;
}

prom_counter_t *my_counter;
 
void foo_metric_init(void) {
  my_counter = prom_counter_new("my_counter", "counts things", 0, NULL);
  if (my_counter != NULL && pcr_register_metric(my_counter)) {
    printf("metric my_counter registered.\n");
  }

 
}
 

int main() {

  // prefix all metric names with "myapp_" and report the overall scrape time
  if (pcr_default_init()) {
    //printf("pcr_init");
    foo_metric_init();
  }

  my_counter = prom_counter_new("my_counter", "counts things", 0, NULL);
  pcr_register_metric(my_counter);
  //prom_gauge_t *gpio_status = prom_gauge_new("gpio_status", "Status des GPIO", 0, NULL);
  //prom_collector_registry_register_metric(prom_collector_registry_default(), gpio_status);


  promhttp_set_active_collector_registry(NULL);
 
  struct MHD_Daemon *server = promhttp_start_daemon(MHD_USE_SELECT_INTERNALLY, 8099, NULL, NULL);
  if (server == NULL)
  {
    printf("Impossible de démarrer le serveur HTTP\n");
    return 1;
  }

  signal(SIGINT, handle_signal);

  while(1) {
    fputc('.', stdout); fflush(stdout);
    prom_counter_inc(my_counter, (const char**) { "bar", "bang" });
    //prom_gauge_set(gpio_status, 1.0,"f"); // Exemple : GPIO actif
		sleep(1);
    /*
     int key=getchar();
    if (key==27)
    {
        break;
    }*/
  }

  pcr_destroy(PROM_COLLECTOR_REGISTRY);
  promhttp_stop_daemon(server);
}
```
