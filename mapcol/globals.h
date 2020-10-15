#define n 1000
struct node{
    char country_color[32];
    char country_name[32];
    char **adjacents;
};

extern struct node *adjlist;
extern char *colors[];
extern int *degree;
extern int **domain;
extern int N, numofcolors;
extern bool partly;