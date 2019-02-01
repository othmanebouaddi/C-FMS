//staf.c
#include <string.h>
// #include "read.c"

// A array to clean the stream in.
char carbage[20];
int stafMembers = 0, i = 0;
char user_input[20];
char** stafName = NULL; // Ce pointeur va servir de tableau après l'appel du malloc





void EnterStafName()
{
    if (stafMembers > 0) // Il faut qu'il ait au moins un ami (je le plains un peu sinon :p)
    {
        stafName = malloc(stafMembers * sizeof(char*)); // On alloue de la mémoire pour le tableau
        if (stafName == NULL) // On vérifie si l'allocation a marché ou non
        {
            exit(0); // We kill the application
        }

        for(int i = 0; i < stafMembers; i++) {
            stafName[i] = malloc( 10 * sizeof(char) );
        }
        for(int i = 0; i < stafMembers; i++) {
            if(stafName[i] == NULL) exit(0);
        }
        fgets(carbage, 20, stdin);
        //We ask about the staf names
        for (i = 0 ; i < stafMembers ; i++)
        {
            printf("what is the name of the staf number %d ? ", i + 1);
            //read(user_input, 20);
            fgets(user_input, 10, stdin);
            user_input[strlen(user_input) -1] = '\0';
            strcpy(stafName[i], user_input);
        }

        // On affiche les âges stockés un à un
    }
}







