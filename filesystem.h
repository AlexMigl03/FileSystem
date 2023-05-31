#ifndef FILESYSTEM_2_FILESYSTEM_H
#define FILESYSTEM_2_FILESYSTEM_H
#include <stdlib.h>
#include <string.h>


#endif //FILESYSTEM_2_FILESYSTEM_H

typedef struct _file* file;
typedef struct _direct* directory;
typedef struct _filesystem* filesystem;

filesystem creaFileSystem(char[]);
//- F0. Creare un nuovo filesystem. Un filesystem è caratterizzato da un'etichetta ("es: prova") e contiene, di default, una cartella root ("/").

char* get_fsLabel(filesystem);
directory aggiungiCartella(directory, char[]);
//- F1. Aggiungere una sottocartella in una data cartella.
directory get_fsRoot(filesystem);

char* get_DirLabel(directory);

//- F2. Aggiungere un file in una data cartella, con uno specifico contenuto.
file aggiungiFile(directory, char [], char[]);

//- F3. Accedere al contenuto di un file specificato.
char* get_fileContent(file);

//- F4. Stampare il percorso di un file o di una cartella.
void printFilePath(file);
void printDirPath(directory);

//- F5. Elencare i file e le cartelle presenti in una data cartella.
void stampaElencoFile(directory);
void stampaElencoCartelle(directory);

//- F6. Decidere autonomamente una funzionalità da implementare in questo contesto (e descriverla).




void printAllPaths(filesystem);