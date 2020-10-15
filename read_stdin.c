#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "globals.h"

void read_stdin(){

    char line[4096]; int ptr=0;
    while(fgets(line, 4096, stdin)!=NULL){
    // allocate 100 adjacents for each node
    int cnt=0, a=0;

        char* word = strtok(line," \n");
        if( strcmp(word, "\n") == 0 ) word=NULL;

        while( word != NULL ){

            if(cnt==0){     // word is the country color
                strcpy(adjlist[ptr].country_color, word);
                if( strcmp(word, "nocolor") != 0 ) partly=1;
            }
            if(cnt==1){     // word is the country name
                strcpy(adjlist[ptr].country_name, word);
            }
            if(cnt>=2){     // word is a country adjacent
                strcpy(adjlist[ptr].adjacents[a], word); a++; // a=adjacent counter.
            }

            cnt++;  // word counter++
            word = strtok(NULL," \n"); 
        
        }

        degree[ptr]=a;
        ptr++; // line counter++
    }

    N=ptr;

}