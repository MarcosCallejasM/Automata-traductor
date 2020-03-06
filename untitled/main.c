#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main() {

    FILE *myFile;


    int estados=0;
    int TamAlfabeto=0;
    int numFinales=0;
    char caux; //Para leer desde el fichero
    char auxS[1024];

    myFile = fopen("C:\\Users\\marco\\CLionProjects\\untitled\\lenguaje.txt", "r");
    if (myFile == NULL)
    {
        printf("Can't open file for reading.\n");
    }

        // leemos el numero de estados Q
        fgets(auxS,1024,myFile);
        estados= auxS[0] -'0';
        // leemos el tamaño del alfabeto
        fgets(auxS,1024,myFile);
        TamAlfabeto= auxS[0] -'0';
        //Inicializamos el array con los caracteres del alfabeto E
        char *alfabeto[TamAlfabeto][100];
        int num =0 ;
    for (int i = 0; i < TamAlfabeto; i++) {
        fgets(auxS,1024,myFile);
        strcpy(alfabeto[i], auxS);

    }
    //leemos el numero de estados finales
    fgets(auxS,1024,myFile);
    numFinales= auxS[0] - '0';

    //Inicializamos el array de estados finales F
    fgets(auxS,1024,myFile);
    int estadosFinales[numFinales];
    for (int i  = 0; i  < numFinales ; ++i )
        estadosFinales[i]=auxS[i] - '0';
    //Inicializamos la matriz de transicciones
    char *transicciones[estados][TamAlfabeto][100];
    for (int i = 0; i < estados ; ++i) {
        for (int j = 0; j < TamAlfabeto; ++j) {
            fgets(auxS,1024,myFile);
            strcpy(transicciones[i][j], auxS);
        }

    }
    //Inicializamos la matriz de traducciones
    char *traducciones[estados][TamAlfabeto][100];
    for (int i = 0; i < estados ; ++i) {
        for (int j = 0; j < TamAlfabeto; ++j) {
            fgets(auxS,1024,myFile);
            strcpy(traducciones[i][j], auxS);
        }

    }
    /*
    for (int i = 0; i < estados ; ++i) {
        for (int j = 0; j < TamAlfabeto; ++j) {
         printf("%s",traducciones[i][j]);
        }
        printf("\n");
    }
*/
    int TCadena;
    fgets(auxS,1024,myFile);
    TCadena= auxS[0] - '0';
    char *cadena[TCadena][100];
    for (int i = 0; i < TCadena ; i++) {
        fgets(auxS,1024,myFile);
        strcpy(cadena[i],auxS);
    }
    for (int j = 0; j < TCadena; j++) {
        printf("%s",cadena[j]);
    }

   //Comenzamos el automata
    char *TraduccionFinal[TCadena][100];
    int estadoActual=0;
    int posAlfabeto=99;
    for (int i = 0; i < TCadena ; i++) {
        for (int j = 0; j < TamAlfabeto ; ++j) {
            if(strcmp(cadena[i],alfabeto[j]) ==1)
                posAlfabeto=j;
        }
        if(posAlfabeto!=99)
            if(transicciones[estadoActual][posAlfabeto] != '-'){
                TraduccionFinal[i][100]=transicciones[estadoActual][posAlfabeto];
                estadoActual=transicciones[estadoActual][posAlfabeto] - '0';
            }

    }



    fclose(myFile);

    return 0;
}



