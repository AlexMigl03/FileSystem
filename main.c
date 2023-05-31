#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filesystem.h"


void main(){
    filesystem fs = creaFileSystem("FileSystem");
    directory root = get_fsRoot(fs);
    puts(get_fsLabel(fs));

    directory c1 = aggiungiCartella(root, "cartella1");
    printf("%s", get_DirLabel(c1));
    directory c2 = aggiungiCartella(root, "cartella2");
    printf("%s", get_DirLabel(c2));
    directory c3 = aggiungiCartella(root, "cartella3");
    printf("%s", get_DirLabel(c3));
    directory c4 = aggiungiCartella(root, "cartella4");
    printf("%s", get_DirLabel(c3));
    directory c5 = aggiungiCartella(root, "cartella5");
    printf("%s", get_DirLabel(c3));

    printf("\nElenco ROOT: ");
    stampaElencoCartelle(root);
    printf("\nElenco C1: ");
    stampaElencoCartelle(c1);

    file f1 = aggiungiFile(c5, "pippo.txt", "Prova Contenuto File");
    printf("\nElenco file C1");
    stampaElencoFile(c1);

    printf("\n\nContenuto File 'F1': %s", get_fileContent(f1));
    printf("\nPercorso file: ");
    printFilePath(f1);
};