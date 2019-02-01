//pile.c


typedef struct ElementP ElementP;
struct ElementP
{
    char *string;
    ElementP *suivant;
};


typedef struct Pile Pile;
struct Pile
{
    ElementP *premier;
};


void empiler(Pile *pile, char* nvString)
{
    ElementP *nouveau = malloc(sizeof(*nouveau));
    if (pile == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    nouveau->string = nvString;
    nouveau->suivant = pile->premier;
    pile->premier = nouveau;
}


char* depiler(Pile *pile)
{
    if (pile == NULL)
    {
        exit(EXIT_FAILURE);
    }

    char* nombreDepile = NULL;
    ElementP *elementDepile = pile->premier;

    if (pile != NULL && pile->premier != NULL)
    {
        nombreDepile = elementDepile->string;
        pile->premier = elementDepile->suivant;
        free(elementDepile);
    }

    return nombreDepile;
}

void afficherPile(Pile *pile)
{
    if (pile == NULL)
    {
        exit(EXIT_FAILURE);
    }
    ElementP *actuel = pile->premier;

    while (actuel != NULL)
    {
        printf("%s\n", actuel->string);
        actuel = actuel->suivant;
    }

    printf("\n");
}







