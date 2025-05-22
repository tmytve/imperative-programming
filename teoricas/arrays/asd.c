/*
sizeof(array): #de bytes que ocupa el array
sizeof(type): #de bytes que ocupa una componente

#De elementos de un array:  sizeof(array) / sizeof(array[0])

*/
#define SIZE ('Z'-'A'+1)
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int
main(void)
{
    int c, count[SIZE] = {0};

    while ( (c = getchar()) != EOF) {
        c = toupper(c);
        if (isalpha(c))
            count[c - 'A']++;
    }
    for (int i = 0; i<SIZE; i++)
        printf("Cant. de %c= %d\n", i + 'A', count[i]);

    return 0;
}
