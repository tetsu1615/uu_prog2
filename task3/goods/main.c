#include <stdlib.h>
#include "goods.h"

int main(void) {
    int i;
    struct goods item[3];

    registration(&item[0], "book", 1000);
    registration(&item[1], "DVD", 3000);
    registration(&item[2], "pen", 100);

    for (i = 0; i < 3; ++i) {
        print(item[i]);
    }

    return EXIT_SUCCESS;
}
