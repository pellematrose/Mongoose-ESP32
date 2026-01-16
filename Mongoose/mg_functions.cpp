#include "mg_functions.h"
#include <EEPROM.h>
#include <Arduino.h>
#include "my_globals.h"

void my_get_wifi(struct wifi *data) {
  // Read from EEPROM
  load(WIFI_ADDRESS, data, sizeof(*data));
}
void my_set_wifi(struct wifi *data) {
  // Write to EEPROM
  save(WIFI_ADDRESS, data, sizeof(*data));
}