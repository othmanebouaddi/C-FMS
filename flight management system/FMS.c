#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "flight.c"
#include "staf.c"
#include "Passengers.c"
#include "read.c"
#include "pile.c"
#include "file.c"
//Include for socket
#include "socketCS.c"
#include "socketCA.c"
#include "locationC.c"



//Var
int fuel = 100;
int *fuelP = &fuel;
int hydrolic = 50;
int *hydrolicP = &hydrolic;
//there is  just one lift off 
int liftOff = 0;
// For not to reapeat allocation memory.
char res[1] = "O";
int flag = 1;



//FMS menu 
int menu()
{
    int choix = 0;

        printf("\n*********************************\n");
        if(!liftOff) printf("0 :  lift-off\n");
        printf("1 :  Engine and electric state\n");
        printf("2 :  Fuel and hydrolic state\n");
        printf("3 :  Route planning\n");
        printf("4 :  Autopilote\n");
        printf("5 :  AIRAC\n");
        printf("6 :  Current position\n");
        printf("7 :  Current time\n");
        printf("8 :  landing\n");
        printf("9 :  Enter staf\n");
        printf("10 : Staf state\n");
        printf("11 : Passengers\n");
        printf("12 : Enter situation\n");
        printf("13 : Diplay All situations\n");
        printf("14 : Call the General Quarter\n");
        printf("15 : Exit\n");
        printf("Votre choix ? ");
        scanf("%d", &choix);
        printf("*********************************\n");    
    
    return choix;
}



int engine()
{
    int temperature = 25;
    int pressure = 100  ;
    int speed = 1000 ;

    printf("\nThe engines parameters : %d degre %d bar %d kms.", temperature, pressure, speed);

    if ( temperature < 30 && temperature > 18 && pressure > 90 && pressure < 110 && speed > 300 && speed < 1300)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


void setFuel()
{
    *fuelP -= 10;
    *hydrolicP -=5;
}



int main(int argc, char *argv[])
{
    //Exit from the application
    int exit = 1;
    time_t current_time;
    setFuel();
    Flight flightOne;
    Flight *flightOneP = &flightOne;
    char string[100];
    Pile pile;
    Pile *pileP = &pile;


	// stock the initial data
	printf("Flight Management Systems :\n\nComputer system which help pilotes to manage their flight from start to finish\n\n\n");
    
	printf("The flight name?  ");
    read(flightOneP->flightName, 20);
	//scanf("%s", flightOneP->flightName);

	printf("Where are you come from?  ");
    read(flightOneP->from, 20);
	//scanf("%s", flightOneP->from);

	printf("Where are you going?  ");
    read(flightOneP->destination, 20);
	//scanf("%s", flightOneP->destination);

    printf("How many time take this flight? ");
    //read(&flightOneP->duration, 20);
    scanf("%d", &flightOneP->duration);
	

	


	//Display menu of FMS
    do{
        switch (menu())
        {
            case 0:
                liftOff = 1;
                printf("\n\nThe flight name is : %s\n", flightOneP->flightName);
                printf("You come from : %s station\n", flightOneP->from);
                printf("You are going to : %s station\n", flightOneP->destination);
                time (&flightOneP->timeDeparture);
                printf("The time of departure is : %s ", ctime(&flightOneP->timeDeparture));
                printf("The time to arrival is : %d hours \n\n", flightOneP->duration );
                break;
            case 1:
                switch (engine())
                {   
                    case 1 :
                        printf("\nThe engines and the electric are in good shape\n\n");
                        break;
                    case 0 :
                        printf("\nAlarme : The engines are in a bad state!");
                        break;
                    
                }
                break;
            case 2:
                printf("\nThe remain fuel is %d galon: ", *fuelP);
                printf("\nThe remain hydrolic is %d galon: \n\n", *hydrolicP);
                break;
            case 3:
                printf("\nOur Route planning is from %s station to %s station\n\n", flightOneP->from, flightOneP->destination );
                break;
            case 4:
                socketCA();
                //printf("\nThe autopilote is active, please stay focus on alarms!\n\n");
                break;
            case 5:
                printf("There is no information so far! \n");
                break;
            case 6:
                printf("\nThe location is : \n\n");
                location(argv[1]);
                break;
            case 7:
                time (&current_time);
                printf("\nThe time is : %s\n\n", ctime(&current_time) );
                break;
            case 8:
                printf("\nWe are landing.");
                printf("\n\nThe flight name is : %s\n", flightOneP->flightName);
                printf("You come from : %s station\n", flightOneP->from);
                printf("You are going to : %s station\n", flightOneP->destination);
                printf("The time of departure is : %s  \n", ctime(&flightOneP->timeDeparture));
                time (&flightOneP->timeArrival);
                printf("The landing time is : %s\n\n", ctime(&flightOneP->timeArrival) );
                liftOff = 0;
                //loadData();
                FILE* file2 = NULL;
                file2 = fopen("files/file2.txt","a+");

                if(file2 != NULL)
                {
                    fprintf(file2,"\nThe flight name is : %s\n", flightOneP->flightName);
                    fprintf(file2,"You come from : %s station\n", flightOneP->from);
                    fprintf(file2,"You are going to : %s station\n", flightOneP->destination);
                    fprintf(file2,"The time of departure is : %s ", ctime(&flightOneP->timeDeparture));
                    fprintf(file2,"The time to arrival is : %d hours \n", flightOneP->duration );
                    fprintf(file2,"The landing time is : %s\n", ctime(&flightOneP->timeArrival) );
                         
                    fprintf(file2,"The staf member are :\n");
                    for (i = 0 ; i < stafMembers ; i++)
                    {
                        fprintf(file2, "%s\n", stafName[i]);
                    }

                    fprintf(file2,"\nThe passengers are :\n");
                    for (i = 0 ; i < passengersNumber ; i++)
                    {
                        fprintf(file2, "%s\n", passengersName[i]);
                    }
                }

                break;
            case 9 :
                if( stafMembers > 0)
                {
                    printf("There are already staf, do you wana update your staf? O/N\n");
                    scanf("%s", res);
                }
                if( strcmp(res, "O") == 0)
                {
                    //We start by free our memory
                    for (i = 0 ; i < stafMembers ; i++)
                    {
                        free(stafName[i]);
                    }
                    // We free the array root of staf name;
                    free(stafName);

                    // OWe ask about the number of staf
                    printf("\nHow many staf in the plane ? ");
                    scanf("%d", &stafMembers);
                    EnterStafName();
                }
                break;
            case 10:
                printf("\nThe staf members are :\n");
                for (i = 0 ; i < stafMembers ; i++)
                {
                    printf("%s\n", stafName[i]);
                }
                break;
            case 11:
                // if we have alredy read the file we have to
                // scape this function.
                if(flag) passenger();
                printf("The passengers are :\n");
    
                for (i = 0 ; i < passengersNumber ; i++)
                {
                    printf("%s\n", passengersName[i]);
                }
                flag = 0;
                break;
            // case 12:
            //     printf("\nEnter your situation : ");
            //     scanf("%s", string);
            //     //read(string, 100);
            //     //printf("%s\n", string );
            //     // empiler(pileP, string);
            //     break;
            // case 13:
            //     printf("\nSituations are  : ");
            //     // afficherPile(pileP);
            //     break;
            case 14:
                socketCS();
                break;
            case 15:
                // We free the array of staf name;
                for (i = 0 ; i < stafMembers ; i++)
                {
                    free(stafName[i]);
                }
                // We free the array root of staf name;
                free(stafName);
                for (i = 0 ; i < passengersNumber ; i++)
                {
                    free(passengersName[i]);
                }
                // We free the array root of staf name;
                free(passengersName);
                exit = 0;

                //free memory pile
                ElementP *elementActuel = pileP->premier;
                ElementP *elementSuivant;
                while (elementActuel != NULL)
                {
                    elementSuivant = elementActuel;
                    elementActuel = elementActuel->suivant;
                    free(elementSuivant);
                }
                free(pileP);
                break;
            default:
                printf("\nWrong choice\n\n");
                break;    
        }
    }while(exit);



	return 0;
}