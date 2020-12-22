/* Functions for reading a map from stdin or from file */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "globals.h"

/* Read data from stdin */

void stdinRead(){
    char line[4096]; int ptr=0;
    while(fgets(line, 4096, stdin)!=NULL){
        int cnt=0, a=0;
        char* word = strtok(line," \n");
        if(strcmp(word, "\n") == 0) word=NULL;

        while(word != NULL){
            if(cnt==0){     // word is the country color
                strcpy(adjlist[ptr].country_color, word);
                if( strcmp(word, "nocolor") != 0 ) partly=1;
            }
            if(cnt==1){     // word is the country name
                strcpy(adjlist[ptr].country_name, word);
            }
            if(cnt>=2){     // word is a country adjacent
                strcpy(adjlist[ptr].adjacents[a], word); 
                a++;        // adjacent counter.
            }
            cnt++;          // word counter
            word = strtok(NULL," \n"); 
        }
        degree[ptr]=a;
        ptr++;              // line counter
    }
    N=ptr;
}

/* Reading data from file */

void fileRead(char *fname){
    int ptr=0;
    char line[4096];
    FILE *fptr;
    fptr=fopen(fname, "r");

    while(fgets(line, 4096, fptr)!=NULL){
        int cnt=0, a=0;
        char* word = strtok(line," \n");
        if(strcmp(word, "\n") == 0) word=NULL;
        while(word != NULL){
            if(cnt==0){     // word is the country color
                strcpy(adjlist[ptr].country_color, word);
                if( strcmp(word, "nocolor") != 0 ) partly=1;
            }
            if(cnt==1){     // word is the country name
                strcpy(adjlist[ptr].country_name, word);
            }
            if(cnt>=2){     // word is a country's neighbor   
                strcpy(adjlist[ptr].adjacents[a], word); 
                a++;        // adjacent counter (Number of neighbors)
            }
            cnt++;          // word counter
            word = strtok(NULL," \n"); 
        }
        degree[ptr]=a;
        ptr++;              // line counter
    }
    N=ptr;
    fclose(fptr);
}