#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void) {
    srand(time(NULL));
    printf("%d\n", rand());
    return 0;
}
