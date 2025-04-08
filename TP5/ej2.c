//Decir, sin necesidad de ejecutar el código, qué imprime cada uno de los siguientes fragmentos de código, asumiendo que la variable i es de tipo int, la variable x es de tipo double y que se incluyeron los archivos de encabezado que corresponden.

// a)

for( i = 46; i <= 'H'; i++){
      printf("%d %c %c\t", i, i, tolower(i));   // 46 ... 72 , caracteres ascii desde . hasta H
      printf("%s ", isalnum(i)? "si" : "no");   // 
      printf("%s ", isalpha(i)? "si" : "no");
      printf("%s ", isdigit(i)? "si" : "no");
      printf("%s ", islower(i)? "si" : "no");
      printf("%s ", isupper(i)? "si" : "no");
      printf("%s ", isxdigit(i)? "si" : "no");
      printf("%s ", iscntrl(i)? "si" : "no");
      printf("%s \n", ispunct(i)? "si" : "no");
}
