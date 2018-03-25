#include <stdio.h>
#include "utilidades.h"
void flush_in() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}
