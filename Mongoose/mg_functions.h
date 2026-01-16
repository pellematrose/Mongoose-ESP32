#include <Arduino.h>
#include <stddef.h>
#include <stdbool.h>
#include "src/mongoose_glue.h"

#ifdef __cplusplus
extern "C" {
#endif

void load(int addr, void *buf, size_t len);
void save(int addr, const void *buf, size_t len);

void my_get_wifi(struct wifi *data);
void my_set_wifi(struct wifi *data);

#ifdef __cplusplus
}
#endif