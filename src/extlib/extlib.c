#include <stdio.h>
#include "extlib.h"

LIB_API long __stdcall hello(char * what) {
    printf("from library: %s\n",what);
    return 1;
}