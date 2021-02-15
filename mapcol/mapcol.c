#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "globals.h"
#include "toolkit.h"
#include "sorts.h"
#include "read_data.h"

int main(int argc, char *argv[]){
    numofcolors=4; // by default we color the map using 4 colors. 
    bool tocheck=0, fromfile=0;
    char *fname;

    for(int i=1; i<argc; i++){
        if(strcmp(argv[i], "-c")==0) tocheck=1;
        if(strcmp(argv[i], "-n")==0) numofcolors=atoi(argv[i+1]);
        if(strcmp(argv[i], "-i")==0) {
            fromfile=1; 
            fname=malloc(strlen(argv[i+1]) * sizeof(char));
            strcpy(fname, argv[i+1]);
        }
    }

    adjlist = malloc(MAX_COUNTRIES * sizeof(struct node));
    degree = malloc(MAX_COUNTRIES * sizeof(int));
    for(int i=0; i<MAX_COUNTRIES; i++){
        for(int j=0; j<MAX_COUNTRIES; j++) adjlist[i].adjacents=malloc(MAX_COUNTRIES * sizeof(char *)); 
            for(int k=0; k<MAX_COUNTRIES; k++) adjlist[i].adjacents[k]=malloc(32 * sizeof(char));
    }

    (fromfile) ? fileRead(fname) : stdinRead();
    adjlist=realloc(adjlist, N * sizeof(struct node));
    degree=realloc(degree, N * sizeof(int));
    
    if(tocheck){ 
        check(); 
        return 1;
    }
    
    (partly) ? partlySort() : sort();

    if(!coloring(0)){
        printf("Sorry can't color the given map\n"); 
        return 2;
    }

    /* printing the (colored) map */
    for(int i=0; i<N; i++){
        printf("%s %s ", adjlist[i].country_color, adjlist[i].country_name);
        for(int j=0; j<degree[i]; j++)
            printf("%s ", adjlist[i].adjacents[j]);
        printf("\n");
    }

    return 0;
}
