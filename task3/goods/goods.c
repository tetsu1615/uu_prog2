#include "goods.h"

void registration(struct goods* item, char* name, int value) {
    strcpy_s(item->name, sizeof(item->name), name);
    item->value = value;
}

void print(struct goods item) {
    printf("•i–¼:%s\n", item.name);
    printf("‰¿Ši:%d\n", item.value);
}