#include <stdio.h>

int main(void) {
    int n = 4;
    int x = 0;
    for (int i = 1; i < n; i++)
        for (int j = 1; j <= i; j++)
            x = x + 1;
        
}
