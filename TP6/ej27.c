#define CHARS_DIM 256
#include <stdio.h>
int pertenece(char chars[], char c);
void eliminoRepetidos(char text[], char chars[]);
void ordenaPorAscii(char chars[]);
void analize(char text[], char chars[]);
int main(void) {
    char chars[CHARS_DIM];
    analize("El zorro mete la cola, Pero no la pata!", chars);
    printf("%s\n", chars); //debe imprimir: " !,EPacelmnoprtz" (sin las comillas)
    return 0;
}

//Primero elimino caracteres repetidos (una funcion aux)
//Luego ordeno ascendentemente los caracteres segun su valor ascii (otra funcion aux)
void analize(char text[], char chars[]){
    eliminoRepetidos(text, chars);
    ordenaPorAscii(chars);
}
 
void ordenaPorAscii(char chars[]){
    for (int i = 0; chars[i] != '\0'; i++){
        for (int j = i+1; chars[j] != '\0'; j++){
            if (chars[i] > chars[j]){
                char aux = chars[i];
                chars[i] = chars[j];
                chars[j] = aux;
            }
        }
    }
}


void eliminoRepetidos(char text[], char chars[]){
    int w = 0;
    for (int i = 0; text[i] != '\0'; i++){
        if (!pertenece(chars, text[i])){
            chars[w++] = text[i];
        }    
    }
    chars[w] = '\0';
}

int pertenece(char text[], char c){
    for (int i = 0; text[i] != '\0'; i++){
        if (text[i] == c){
            return 1;
        }
    }
    return 0;
}



//Forma MUCHO MAS EFICIENTE:

#define MAX 256

void eliminaCeros(char * s) {
int i, j=0;
  for(i=0; i < MAX; i++)
     if ( s[i] )
        s[j++] = s[i];
  
  s[j] = 0;

}

void analize(const char * text, char * chars) {
  // Inicializamos en cero
  for(int i=0; i < MAX; i++)
    chars[i]=0;

  
  //para cada caracter en text, ejemplo Si text contiene 'a', entonces chars['a'] = 'a'.
  //Entonces ordena por ascii directamente
  for(int i=0; text[i]; i++)
    chars[text[i]] = text[i];

  eliminaCeros(chars);
}