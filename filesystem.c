#include "filesystem.h"

#include <stdio.h>

#define DIM_NOME 50
#define DIM_CONT 500

struct _file{
    char nome[DIM_NOME];
    char content[DIM_CONT];
    int dim;
    struct _file* succ;
    directory parent;
};

struct _direct{
    char nome[DIM_NOME];
    file fileList;
    struct _direct* dirList;
    struct _direct* parent;
    struct _direct* succ;
    int numFiles;
    int numDirs;
};

struct _filesystem{
    char nome[DIM_NOME];
    directory root;
};

file creaListaFile(char nome[]){
    file fileList = (struct _file*) malloc(sizeof(struct _file));
    fileList->succ = NULL;
    strcpy(fileList->nome, nome);
    return fileList;
}

directory creaListaDir(char nome[]){
    directory dirList = (struct _direct*) malloc(sizeof(struct _direct));
    dirList->fileList = NULL;
    dirList->numFiles = 0;
    dirList->numDirs = 0;
    dirList->dirList = NULL;
    dirList->succ= NULL;
    strcpy(dirList->nome, nome);
    return dirList;
}

filesystem creaFileSystem(char nome[]){
    filesystem fs = (struct _filesystem*) malloc(sizeof(struct _filesystem));
    strcpy(fs->nome, nome);
    fs->root = creaListaDir("root");
    fs->root->parent = NULL;
    return fs;
}

char* get_fsLabel(filesystem fs){
    return fs->nome;
};

directory aggiungiCartella(directory d, char nome[]){
    directory d2 = creaListaDir(nome);
    if(d->numDirs == 0){
        d->dirList = d2;
    }else{
        directory dP = d->dirList;
        while(dP->succ != NULL){
            dP = dP->succ;
        }
        dP->succ = d2;
    }
    d2->parent = d;
    d->numDirs++;
    return d2;
};

void stampaElencoCartelle(directory d) {
    directory d1 = d->dirList;
    if(d->numDirs == 0)
    {
        printf("\nNessuna cartella trovata");
    }else{
        while(d1 != NULL){
            printf("\n%s", d1->nome);
            d1 = d1->succ;
        }
    }
}

file aggiungiFile(directory d, char nome[], char content[]){
    file f = creaListaFile(nome);
    if(d->numFiles == 0){
        d->fileList = f;
        f->parent = d;
    }else{
        file fp = d->fileList;
        while(fp->succ != NULL){
            fp = fp->succ;
        }
        fp->succ = f;
    }
    strcpy(f->content, content);
    d->numFiles++;
    return f;
};

void stampaElencoFile(directory d) {
    file f = d->fileList;
    if(d->numFiles == 0)
    {
        printf("\nNessun file trovato");
    }else{
        while(f != NULL){
            printf("\n%s [%s]", f->nome, f->content);
            f = f->succ;
        }
    }
}

directory get_fsRoot(filesystem fs){
    return fs->root;
};

char* get_DirLabel(directory d){
    return d->nome;
};

char* get_fileContent(file f){
    return f->content;
}

void recursiveSearch(directory d){
    if(d->parent != NULL){
        d = d->parent;
        recursiveSearch(d);
    }
    else{
        return;
    }
    printf("/%s", d->nome);
}

void printFilePath(file f){
    directory d = f->parent;
    recursiveSearch(d);
    printf("/%s/%s", f->parent, f->nome);
}

void printDirPath(directory d){;
    recursiveSearch(d);
    printf("/%s", d->nome);
}

void verificaPresenzaFile(directory dP){
    if(dP->numFiles != 0)
    {
        file f1 = dP->fileList;

        while(f1 != NULL){
            printf("\n");
            printFilePath(f1);
            f1 = f1->succ;
        }
    }
    return;
}

void printAllPaths(filesystem fs){
    directory dP = fs->root;
    printf("\nStampa dei percorsi di tutti i file: ");
    while(dP != NULL)
    {
        verificaPresenzaFile(dP);
        if(dP->numDirs!=0)
        {
            directory dP1 = dP->dirList;
            while(dP1 != NULL){
                //printf("\nStampa dei percorsi di tutti i file: ");
                verificaPresenzaFile(dP1);
                dP1 = dP1->succ;
            }
        }
        dP = dP->dirList;
    }
}
