#include "demineur.h"






int main (int argc, int** argv) {
  

    int rejoue = 0 ;
    do{

    int grid = difficulté();
    case_de_jeu** tableau_de_jeu;

    /*! allocation de la memoire */
    tableau_de_jeu = (case_de_jeu**)malloc(grid*sizeof(case_de_jeu*));

    if (tableau_de_jeu == NULL) {
        printf("Error: Unable to allocate memory for tableau_de_jeu.\n");
    }

    for(int i = 0 ; i< grid ; i++){
       tableau_de_jeu[i] = (case_de_jeu*)malloc(grid*sizeof(case_de_jeu));
       if (tableau_de_jeu[i] == NULL) {
           printf("Error: Unable to allocate memory for tableau_de_jeu[%d].\n",i);
       }
    }

    lencement(tableau_de_jeu,grid);
    int int_win =0;
    int resultat ;
    int int_avencement =1;
    
    while(int_avencement == 1 && int_win == 0){
        affichage(tableau_de_jeu,grid);
        int action =0 ;
        next_move();
        do{
        scanf("%d",&action);
        }while(action>2 || action<1);
        tour_de_jeu(tableau_de_jeu,grid,action);
        int_avencement = CheckAvencement(tableau_de_jeu,grid);
        int_win = win(tableau_de_jeu,grid);
    }
    if(int_avencement == 0){
    printf("\nBooooom!!!\nLa partie est terminée. :(\n");
    affichage_fin(tableau_de_jeu,grid);
    }else if(int_win == 1){
        printf("\nFélicitation vous avez gagné. :)\n");
        affichage_fin(tableau_de_jeu,grid);
    }

    for(int i = 0 ; i< grid ; i++){
        free(tableau_de_jeu[i]); 
    }
    free(tableau_de_jeu);


    printf("\nvoulez vous ressayer tapez 1 pour oui et 0 pour quitter");
    scanf("%d" ,&rejoue);
    

    
    }while(rejoue == 1);
}