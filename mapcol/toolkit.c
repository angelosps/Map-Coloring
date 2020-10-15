#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "globals.h"

int colcnt(long x){

    for(int j=0; j<10; j++)
        if(strcmp(adjlist[x].country_color, colors[j]) == 0) 
            return j;
    return 0;

}

bool checktheadj(int i, int j){

    for(int k=0; k<N; k++)
        if(strcmp(adjlist[k].country_name, adjlist[i].adjacents[j])==0){
            if(strcmp(adjlist[i].country_color, adjlist[k].country_color)==0) return 1;
            else return 0;
        }
    return 0;

}

void check(){

    int cnt=0;
    for(int i=0; i<N; i++){
        if(strcmp(adjlist[i].country_color, "nocolor")==0) {
            printf("Please, color the map first\n"); return;
        }   
        int col=colcnt(i);
        if(strcmp(colors[col], "-1")!=0){
            cnt++;
            colors[col]="-1";
        }
        if(cnt>numofcolors) {
            printf("More than %d colors used\n", numofcolors);
            return;
        }
        for(int j=0; j<degree[i]; j++) 
            if(checktheadj(i,j)) printf("%s - %s : Should have different color\n", 
            adjlist[i].country_name, adjlist[i].adjacents[j]);
    }

}

bool isok(int i, int c){

    //check if any of my neughbours use the same color
    strcpy(adjlist[i].country_color, colors[c]);
    for(int j=0; j<degree[i]; j++){
        if(checktheadj(i, j)) {
            strcpy(adjlist[i].country_color, "nocolor");
            return 0;
        }
    }
    return 1;

}

