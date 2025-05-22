//Escribir una versión recursiva para la función strlen
int strlenRecursiva(char arr[]){
    //caso base: arr[i] = '\0'
    if(arr[0] == '\0')
        return 0;

    //paso inductivo:
    return 1 + strlenRecursiva(arr + 1);
}

