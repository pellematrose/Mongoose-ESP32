#include <Arduino.h>
#include <stddef.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

void load(int addr, void *buf, size_t len);
void save(int addr, const void *buf, size_t len);

#ifdef __cplusplus
}
#endif