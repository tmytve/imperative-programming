#include <stdio.h>

int main(void) {
    printf("n\t10*n\t100*n\t1000*n\n");
    for (int i = 1; i < 21; i++)
    {
        printf("%d\t%d\t%d\t%d\n", i, i*10, i*100, i*1000);
    }
}
