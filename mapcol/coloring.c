#include <stdbool.h>
#include <string.h>
#include "globals.h"
#include "toolkit.h"

bool coloring(int v){

    if (v==N) return 1;
    for(int c=0; c<numofcolors; c++){
        if(strcmp(adjlist[v].country_color, "nocolor")!=0){ 
            if(coloring(v+1)) return 1;
        }
        else 
        if(isok(v, c) == true){        
            if(coloring(v+1)) return 1;
            strcpy(adjlist[v].country_color, "nocolor");
        }
    }
    
    return 0;

}