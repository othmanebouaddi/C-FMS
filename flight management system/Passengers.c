//Passengers.c

FILE* file1 = NULL;
char line[20];
int passengersNumber = 0;

// vvr for allocation memory.
char user_input[20];
char** passengersName = NULL;

void passenger()
{
	



	file1 = fopen("Files/file1.txt","r");

	if(file1 != NULL)
	{
		while( fgets(line, 20, file1) != NULL)
		{
			passengersNumber++;
		}
	}
	rewind(file1);
	//
	if( passengersNumber > 0 )
	{
		passengersName = malloc(passengersNumber * sizeof(char*)); // On alloue de la mémoire pour le tableau
        if (passengersName == NULL) // On vérifie si l'allocation a marché ou non
        {
            exit(0); // We kill the application
        }

        for(int i = 0; i < passengersNumber; i++) {
            passengersName[i] = malloc( 10 * sizeof(char) );
        }

        for(int i = 0; i < passengersNumber; i++) {
            if(passengersName[i] == NULL) exit(0);
        }

        //We take the passengers names
        for (i = 0 ; i < passengersNumber ; i++)
        {
            fgets(user_input, 20, file1);
            user_input[strlen(user_input) -1] = '\0';
            strcpy(passengersName[i], user_input);
        }
	}


	fclose(file1);
}