#define MAX_COUNTRIES 200 // max num of countries

struct node{
    char country_color[32];
    char country_name[32];
    char **adjacents;
};

struct node *adjlist;
int **domain;
int *degree;
int N, numofcolors;
bool partly;