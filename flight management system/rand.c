#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Ne pas oublier d'inclure le fichier time.h

int main(void){
	int i = 0;
	int nombre_aleatoire = 0;
	srand(time(NULL)); // initialisation de rand
	for(i=0; i<5; i++){
		nombre_aleatoire = rand();
		printf("%d ",nombre_aleatoire);
	}

int* init_sans_doublons(int a, int b){
	int taille = b-a;
	int* resultat=malloc((taille)*sizeof (int));
	int i=0;
	// On remplit le tableau de manière à ce qu'il soit trié
	for(i = 0; i< taille; i++){
		resultat[i]=i+a;
	}
	return resultat;
}
void melanger(int* tableau, int taille){
	int i=0;
	int nombre_tire=0;
	int temp=0;
	
	for(i = 0; i< taille;i++){
		nombre_tire=rand_a_b(0,taille);
		// On échange les contenus des cases i et nombre_tire
		temp = tableau[i];
		tableau[i] = tableau[nombre_tire];
		tableau[nombre_tire]=temp;
	}
}

	return 0;
}



int main(){
        // A ne pas oublier !
        srand(time(NULL));
        int a=0;
        int b=0;
        int i =0;
        int* t=NULL; // Va contenir le tableau de nombres
        
        do{
                printf("Rentrez le premier nombre : ");
                scanf("%d",&a);
                printf("Rentrez le second, plus grand que le premier : ");
                scanf("%d",&b);
        }while(b<=a);
        
        // On commence pour de vrai ici :
        t=init_sans_doublons(a,b);
        melanger(t,b-a);
        
        printf("La suite aléatoire est : ");
        for(i=0; i<b-a; i++){
                printf("%d ",t[i]);
        }
        printf("\n");
        
        // Ne pas oublier de libérer le tableau
        free(t);
        return 0;
}






