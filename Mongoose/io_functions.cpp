#include "io_functions.h"
#include <EEPROM.h>
#include <Arduino.h>
#include "my_globals.h"

void load(int addr, void *buf, size_t len){
  uint8_t *p = (uint8_t *) buf;
  while (len--) *p++ = EEPROM.read(addr++);
}

void save(int addr, const void *buf, size_t len){
  uint8_t *p = (uint8_t *) buf;
  while (len--){
    EEPROM.write(addr++, *p++);
  } 
  EEPROM.commit();
}
