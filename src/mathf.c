#include "mathf.h"

int mathf_random_between(int min, int max) {
    return rand() % (max + 1 - min) + min;
}
