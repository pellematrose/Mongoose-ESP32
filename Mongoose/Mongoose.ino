#include "WiFi.h"
#include <EEPROM.h>
#include "wifi_manager.h"
#include "setup_pins.h"
#include "mg_functions.h"

#include "src/mongoose_glue.h"

// - timing
uint32_t now = 0;
uint32_t last1min = 0;
uint32_t delta1min = 1000;

void setup() {
  Serial.begin(115200);

  setup_pins();

  EEPROM.begin(512); // oder eine andere Größe, je nach Bedarf

  // Set logging function to serial print
  mg_log_set_fn([](char ch, void *) { Serial.print(ch); }, NULL);
  mg_log_set(MG_LL_DEBUG);

  connect_wifi();

  mongoose_init();
  mongoose_set_http_handlers("wifi", my_get_wifi, my_set_wifi);
}

void loop() {
  mongoose_poll();

  now = millis();

  // time loop one
  if(now - last1min > delta1min){
    last1min = now;
  
    /*
    * User Code here
    */

  }  
}

extern "C" int lwip_hook_ip6_input(struct pbuf *p, struct netif *inp) __attribute__((weak));
extern "C" int lwip_hook_ip6_input(struct pbuf *p, struct netif *inp) {
  if (ip6_addr_isany_val(inp->ip6_addr[0].u_addr.ip6)) {
    pbuf_free(p);
    return 1;
  }
  return 0;
}
