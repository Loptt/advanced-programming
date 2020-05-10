#include <stdio.h>
#include "Conversion.h"

int main() {
    char *binary = "1001011";
    char *hex = "CACA";
    char *doub = "213.222";

    printf("Binary number: %d\n", asciiBinaryToInt(binary));
    printf("Hex number: %d\n", asciiHEXToInt(hex));
    printf("double number: %lf\n", asciiToDouble(doub));
}
