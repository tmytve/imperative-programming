#include <stdio.h>
#include <assert.h>
#include <string.h>
int comprimeCar(char s[], char c, int vec[], int maxDim);
// Sólo para testing
static void assertArrayEquals(const int * e, const int * a, size_t d);
 
int
main(void) {
    int vec[10];
 
    char s1[20] = "Aaa, bb aaaa cc aaa";
    int dim = comprimeCar(s1, 'a', vec, 10);
    assert(strcmp(s1, "Aa, bb a cc a") == 0);
    assert(dim == 3);
    int expectedS1[] = {1,3,2};
    assertArrayEquals(expectedS1, vec, dim);
    comprimeCar(s1, 'a', vec, 10);
    char s2[20] = "Aaa bb aaaa cc aaa";
    dim = comprimeCar(s2, 'a', vec, 2);
    assert(strcmp(s2, "Aa bb a cc aaa") == 0);
    assert(dim == 2);
    int expectedS2[] = {1,3};
    assertArrayEquals(expectedS2, vec, dim);
 
    char s3[] = "Aaaaa babaaa aaaaaa";
    dim = comprimeCar(s3, 'a', vec, 5);
    assert(strcmp(s3, "Aa baba a") == 0);
    assert(dim == 4);
    int expectedS3[] = {3,0,2,5};
    assertArrayEquals(expectedS3, vec, dim);
 
    char s4[] = "Aaaaa babaaa aaaaaa";
    dim = comprimeCar(s4, 'a', vec, 2);
    assert(strcmp(s4, "Aa babaaa aaaaaa") == 0);
    assert(dim == 2);
    int expectedS4[] = {3,0};
    assertArrayEquals(expectedS4, vec, dim);
 
    // Sin el caracter a comprimir
    char s5[] = "Aaaaa babaaa aaaaaa";
    dim = comprimeCar(s5, 'z', vec, 2);
    assert(strcmp(s5, "Aaaaa babaaa aaaaaa") == 0);
    assert(dim == 0);
 
    // Con el caracter pero sin tamaño
    char s6[] = "Aaaaa babaaa aaaaaa";
    dim = comprimeCar(s6, 'a', vec, 0);
    assert(strcmp(s6, "Aaaaa babaaa aaaaaa") == 0);
    assert(dim == 0);
 
    char s7[] = "";
    dim = comprimeCar(s7, 'a', vec, 10);
    assert(strcmp(s7, "") == 0);
    assert(dim == 0);
 
    printf("OK!\n");
    return 0;
}
 
// Sólo para testing
static void
assertArrayEquals(const int * expected, const int * actual, size_t dim) {
    for(int i = 0; i < dim; i++) {
        assert(expected[i] == actual[i]);
    }
}



int comprimeCar(char s[], char c, int vec[], int maxDim){
    int w = 0, j = 0, r = 0;  
    while(s[r] != '\0'){
        if (s[r] == c && j < maxDim){
            int count = 0;
            while (s[r] == c){
                count++;
                r++;
            }
            s[w++] = c;
            vec[j++] = count - 1;
        }else{
            s[w++] = s[r++];
        }
        
    }
    s[w] = '\0';
    return j;

    for (int i = 0; i < maxDim; i++)
    {
        printf("%d", vec[i]);
    }
    
}