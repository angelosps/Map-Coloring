#include <stdbool.h>
#include <string.h>
#include "globals.h"

/* Sort the countries (variables) in order of their degree and alphabetically by their name */
void sort(){
    bool sorted=0;
    while(!sorted){
        sorted=1;
        for(long i=0; i<N-1; i++){
            if(degree[i]<degree[i+1] || (degree[i]==degree[i+1] && (strcmp(adjlist[i].country_name, adjlist[i+1].country_name) < 0))){
                sorted=0;
                long tmp=degree[i];
                degree[i]=degree[i+1];
                degree[i+1]=tmp;
                struct node t=adjlist[i];    
                adjlist[i]=adjlist[i+1];
                adjlist[i+1]=t;    
            }
        }
    }
}

/* Sort the countries according to their degree but mind the already colored countries */
void partlySort(){
    bool sorted=0;
    while(!sorted){
        sorted=1;
        for(long i=0; i<N-1; i++){
            long a,b,c,d;
            a=strcmp(adjlist[i].country_color, "nocolor");
            b=strcmp(adjlist[i+1].country_color, "nocolor");
            int case1=(a==0 && b==0 && (degree[i] < degree[i+1]));
            int case2=(a!=0 && b!=0 && (degree[i] < degree[i+1]));
            int case3=(a==0 && b!=0);
            if(case3 || case1 || case2){
                sorted=0;
                long tmp=degree[i];
                degree[i]=degree[i+1];
                degree[i+1]=tmp;
                struct node t=adjlist[i];    
                adjlist[i]=adjlist[i+1];
                adjlist[i+1]=t;    
            }
        }
    }
}