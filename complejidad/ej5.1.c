#include <stdio.h>

int main(void) {
    int x = 0;
    int n = 4;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                x = x + 1;
}

// complejidad O(n^3)