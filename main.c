#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filesystem.h"


void main(){
    filesystem fs = creaFileSystem("FileSystem");
    directory root = get_fsRoot(fs);
    int scelta;
    puts(get_fsLabel(fs));

    directory c1 = aggiungiCartella(root, "cartella1");
    printf("%s", get_DirLabel(c1));
    directory c2 = aggiungiCartella(c1, "cartella2");
    printf("%s", get_DirLabel(c2));
    directory c3 = aggiungiCartella(c2, "cartella3");
    printf("%s", get_DirLabel(c3));
    directory c4 = aggiungiCartella(c3, "cartella4");
    printf("%s", get_DirLabel(c3));
    directory c5 = aggiungiCartella(c4, "cartella5");
    printf("%s", get_DirLabel(c3));

    printf("\nElenco ROOT: ");
    stampaElencoCartelle(root);
    printf("\nElenco C1: ");
    stampaElencoCartelle(c1);

    file f1 = aggiungiFile(root, "pippo.txt", "Prova Contenuto File");
    file f2 = aggiungiFile(c5, "pippo.txt", "Prova Contenuto File");
    file f3 = aggiungiFile(c5, "aaaa.txt", "Prova Contenuto File");

    printf("\nElenco file C1");
    stampaElencoFile(c1);

    printf("\n\nContenuto File 'F1': %s", get_fileContent(f1));
    printf("\nPercorso file: ");
    printFilePath(f1);
    printf("\nPercorso cartella: ");
    printDirPath(c5);

    do{
        printf("\n\nSCEGLIERE L'OPERAZIONE DA ESEGUIRE: \n");
        printf("\n1. Stampare i percorsi di tutti i file presenti nel filesystem.\n"
               "2. Stampare il contenuto testuale di un file dato in input il suo percorso.\n"
               "3. Stampare tutti i file e le cartelle all'interno di una cartella (specificata attraverso il suo percorso).\n"
               "4. Esecuzione della funzionalità F6 (decidere autonomamente come deve avvenire l'interazione con il sistema).\n"
               "0. Esci dal menu");
        printf("\nScelta: ");
        scanf("%d", &scelta);
        fflush(stdin);
        switch(scelta){
            case 1:
                printAllPaths(fs);
        }
        printf("\n"); system("pause");
    }while(scelta != 0);
};