#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "gestor.h"

int main()
{
    setlocale(LC_CTYPE,"Portuguese");
    gestorInit();
    return 0;
}
