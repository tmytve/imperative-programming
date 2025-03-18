int
main(void)
{
    /*Esto es un primer comentario
    */
   \*Que buen comentario! *\
   /* Es valido /* o no */ este comentario? */
   \    * Esto es un ultimo comentario */
return 0
}

//Errores al compilar:
// ej1.c:6:4: error: expected expression
//    6 |    \*Que buen comentario! *\
      |    ^
//ej1.c:7:17: warning: '/*' within block comment [-Wcomment]
//    7 |    /* Es valido /* o no */ este comentario? */
//      |                 ^
//ej1.c:10:2: warning: no newline at end of file [-Wnewline-eof]
//   10 | }