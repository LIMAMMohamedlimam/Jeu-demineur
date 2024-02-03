#include "demineur.h"








int checkNumber(int num, int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            return 0; // number already exists
        }
    }
    return 1; // number doesn't exist
}






int difficulté(){
    printf("Pour un test rapide tapez 1\nPour une difficulté Facile tapez 2\nPour une partie difficile tapez 3\n");
    int a = 0 ;
    int grid = 0;
    do{
        scanf("%d",&a);
    } while (a != 1 && a != 2 && a!=3); 

    if(a == 2){
        grid = fac;
    }else if(a==3){
        grid = dif;
    }else{
        grid = 3;
    }

    return grid;
}


void SetMine (case_de_jeu** tableau_de_jeu , int grid){
    srand(time(0));
    int numbers[grid];
    int index = 0;

    while (index < grid) {
        int randomNum = rand() % (grid*grid);
        if (checkNumber(randomNum, numbers, index)) {
            numbers[index] = randomNum;
            index++;
        }
    }
    int nbre_mines =0 ;
    for(int i =0 ; i< grid ; i++){
        int k = grid;
        int a = numbers[i];
        int j = 0;
        while  (a >= grid){
            j++ ;
            a = a - grid ;
        }
        nbre_mines++;
        tableau_de_jeu[i][j].est_mine = true;
   }  
   printf("dans cette partie il ya %d mines\n",nbre_mines);     
}




void initialisation(case_de_jeu** tableau_de_jeu, int grid){
    for(int i =0; i<grid ; i++){
        for(int j =0; j<grid ; j++){
            tableau_de_jeu[i][j].case_number = (i*grid) + j +1;
        }
    }




    //setting defaults values every case is not discovered and not marked
    for (int i = 0 ; i<grid ; i++){
        for (int j = 0 ; j<grid ; j++){
            tableau_de_jeu[i][j].ete_decouverte = false;
            tableau_de_jeu[i][j].est_marqué_drap = false;

            //setting value for case that are not mines 
            if (!tableau_de_jeu[i][j].est_mine)
            {
                tableau_de_jeu[i][j].est_mine = false;
            }
        }
    }

            // counting and setting the number of near mines


    for(int i =0; i<grid ;i++){
        for(int j =0; j <grid ; j++){
            int cpt =0;
            if(i==0){
                if(j==0){
                    for(int l =0; l<2 ;l++){
                        for(int k =0; k <2 ; k++){
                            if(tableau_de_jeu[l][k].est_mine){
                                if(l!=0 ||k!=0){
                                cpt++;
                                }
                            } 
                        }
                    }
                }else if(j == (grid-1)){
                    for(int l =0; l<2 ;l++){
                        for(int k =-1; k <1 ; k++){
                            if(tableau_de_jeu[l][j+k].est_mine){
                                if(l!=0 ||k!=0){
                                cpt++;
                                }
                            }
                        }
                    }   
                }else{
                    for(int l=0;l<2;l++){
                        for(int k =-1 ; k<2;k++){
                            if(tableau_de_jeu[i+l][j+k].est_mine ){
                                if(l!=0 ||k!=0){
                                cpt++;
                                }
                            }
                        }
                    }
                }

            }else if(i == (grid-1)){
                if(j == 0){
                    for(int l =-1; l<1 ;l++){
                        for(int k =0; k <2 ; k++){
                            if(tableau_de_jeu[i+l][j+k].est_mine ){
                                if(l!=0 ||k!=0){
                                cpt++;
                                }
                            }
                        }
                    }
                }else if(j == (grid-1)){
                    for(int l =-1; l<1 ;l++){
                        for(int k =-1; k <1 ; k++){
                            if(tableau_de_jeu[i+l][j+k].est_mine ){
                                if(l!=0 ||k!=0){
                                cpt++;
                                }
                            }
                        }
                    }
                }else{
                    for(int l =-1; l<1 ;l++){
                        for(int k =-1; k <2 ; k++){
                            if(tableau_de_jeu[i+l][j+k].est_mine ){
                                if(l!=0 ||k!=0){
                                cpt++;
                                }
                            }
                        }
                    }
                }
            }else if( j == 0 && i!=0 && i!= (grid-1)){

                for(int l =-1; l<2 ;l++){
                    for(int k =0; k <2 ; k++){
                        if(tableau_de_jeu[i+l][k].est_mine ){
                            if(l!=0 ||k!=0){
                            cpt++;
                            }
                        } 
                    }
                }
            }else if( j == (grid-1) && i != 0 && i != (grid-1)){
                for(int l =-1; l<2 ;l++){
                    for(int k =-1; k <1 ; k++){
                        if(tableau_de_jeu[i+l][j+k].est_mine ){
                            if(l!=0 ||k!=0){
                                cpt++;
                            }
                        }
                    }
                }
            }else{
                for(int l = -1 ; l<2;l++){
                    for(int k =-1;k<2;k++){
                        if(l!=0||k!=0){
                             if(tableau_de_jeu[i+l][j+k].est_mine){
                                cpt++;
                            }
                        }
                    }
                }
               
            }
            tableau_de_jeu[i][j].nbre_mine_voisin = cpt;
        }
    }
    int choix_arrbitraire_i = 0;
    int choix_arrbitraire_j = 0;
    do{
    choix_arrbitraire_i = rand()%grid;
    choix_arrbitraire_j = rand()%grid;
    }while(tableau_de_jeu[choix_arrbitraire_i][choix_arrbitraire_j].est_mine);

    tableau_de_jeu[choix_arrbitraire_i][choix_arrbitraire_j].ete_decouverte = true ;

}
    



void lencement(case_de_jeu** tableau_de_jeu , int grid){
    
    //tableau_de_jeu = (case_de_jeu**)malloc(grid*sizeof(case_de_jeu*));
//
    //if (tableau_de_jeu == NULL) {
    //    printf("Error: Unable to allocate memory for tableau_de_jeu.\n");
    //}
//
    //for(int i = 0 ; i< grid ; i++){
    //   tableau_de_jeu[i] = (case_de_jeu*)malloc(grid*sizeof(case_de_jeu));
    //   if (tableau_de_jeu[i] == NULL) {
    //       printf("Error: Unable to allocate memory for tableau_de_jeu[%d].\n", i);
    //   }
    //}

    SetMine(tableau_de_jeu, grid);

    initialisation(tableau_de_jeu,grid);
    //
    //            
//
    //for(int i = 0 ; i< grid ; i++){
    //   free(tableau_de_jeu[i]); 
    //}
    //free(tableau_de_jeu); 

}


int CheckAvencement(case_de_jeu** tableau_de_jeu,int grid){
for(int i =0; i<grid ; i++){
        for(int j =0; j<grid ; j++){
            if(tableau_de_jeu[i][j].ete_decouverte && tableau_de_jeu[i][j].est_mine){
                return 0;
            }
        }
    }
    return 1;

   
}


int win(case_de_jeu** tableau_de_jeu , int grid){
    int cpt_decouverte =0;
    int cpt_marque =0 ;
    for (int i = 0 ; i<grid ; i++){
        for (int j = 0 ; j<grid ; j++){
            if(tableau_de_jeu[i][j].ete_decouverte){
                cpt_decouverte++;
            }else if (tableau_de_jeu[i][j].est_marqué_drap){
                cpt_marque++;
            }
            
        }
    }
    //printf("cpt_decouverte = %d\n", cpt_decouverte);
    if((cpt_decouverte+cpt_marque) == (grid*grid)){
        //printf("demineur c line 242");
        return 1;
    
    }
    //printf("line 246 demineur c");
    return 0;
}



void where_and_play(int action,case_de_jeu ** tableau_de_jeu,int grid){
    int num_case ;
    printf("donner le numero du case où vous voulez jouée: ");
    scanf("%d",&num_case);
    printf("\n");
   // printf("num_case = %d",num_case);
    int nbre_drapeau =0 ;
    switch (action)
    {
    case 1:
    //printf("ligne 260 demineur c");
        for(int i =0; i<grid ; i++){
            for(int j =0; j<grid ; j++){
                //printf("tableau_de_jeu[%d][%d].case_number = %d\n", i,j,tableau_de_jeu[i][j].case_number);
                if(tableau_de_jeu[i][j].case_number == num_case){ //printf("ligne 263 demin c ");
                    if(tableau_de_jeu[i][j].ete_decouverte){
                       // printf("ligne 265 demin c");
                    printf("la case %d deja decouverte\n",num_case);
                    break;
                    }else if(tableau_de_jeu[i][j].est_marqué_drap){
                       // printf("ligne 268 demin c");
                        printf("la case %d est deja marquée par un drapeau\n",num_case);
                        break;
                    }else{
                       // printf("ligne 271 demineur c");
                        tableau_de_jeu[i][j].ete_decouverte =true ;
                    }
                }
            }
        }
        break;


        
    
    case 2:
        for(int i =0; i<grid ; i++){
            for(int j =0; j<grid ; j++){
                if(tableau_de_jeu[i][j].case_number == num_case){
                    if(tableau_de_jeu[i][j].est_marqué_drap || tableau_de_jeu[i][j].ete_decouverte){
                        printf("la case %d deja marquer\n",num_case);
                        break;
                    }else if(tableau_de_jeu[i][j].ete_decouverte){
                        printf("la case %d deja decouverte\n",num_case);
                        break;
                    }else{
                            if(nbre_drapeau<=grid){
                                nbre_drapeau++;
                                tableau_de_jeu[i][j].est_marqué_drap =true;
                                break;
                            }else{
                                printf("le nombre maximal de drapeau est %d\n",grid);
                            }
                        }
                }
            }
        }
        break;
    }

}






void next_move(){
    printf("\nchoisissez votre action:\n");
    printf("pour decouvrire le case tapez 1\n");
    printf("pour marquer le case tapez 2\n");
    
}



void tour_de_jeu (case_de_jeu** tableau_de_jeu,int grid,int action){
 
    where_and_play(action,tableau_de_jeu,grid);

}



void affichage(case_de_jeu** tableau_de_jeu, int grid){
    for (int i = 0 ; i<grid ; i++){
        int k =0;
        while (k<grid-1){
            printf("+--");
            k++;
        }
        printf("+--+\n");
        for (int j = 0 ; j<grid ; j++){
            int num_case = (i*grid) +j +1 ;
            if(tableau_de_jeu[i][j].ete_decouverte  || tableau_de_jeu[i][j].est_marqué_drap){
                if(tableau_de_jeu[i][j].est_marqué_drap){
                    printf("|DR");
                }else if(tableau_de_jeu[i][j].est_mine){
                    printf("|MM");
                }else{
                    if(tableau_de_jeu[i][j].nbre_mine_voisin != 0){
                    printf("|%dM",tableau_de_jeu[i][j].nbre_mine_voisin);
                    }else{
                        printf("|  ");
                    }
                }
            }else{
                if(num_case>9){
                    printf("|%d",num_case);
                }else{
                    printf("|0%d",num_case);
                }
            }
        }
        printf("|\n");
        
    }
    int k =0;
        while (k<grid-1){
            printf("+--");
            k++;
        }
        printf("+--+\n");
}













int cpt_drapeau();//fonction qui gere le nombre de drappeau dont le joueur peut utiliser



void affichage_fin(case_de_jeu** tableau_de_jeu,int grid){
    for(int i =0;i<grid;i++){
        int k =0;
        while (k<grid-1){
            printf("+--");
            k++;
        }
        printf("+--+\n");
        for(int j =0;j <grid;j++){
            if(tableau_de_jeu[i][j].est_mine){
                printf("|MM");
            }else{
                if(tableau_de_jeu[i][j].nbre_mine_voisin != 0){
                printf("|%dM",tableau_de_jeu[i][j].nbre_mine_voisin);
                }else{
                    printf("|  ");
                }
            }
        }
        printf("|\n");

    }
    int k =0;
        while (k<grid-1){
            printf("+--");
            k++;
        }
        printf("+--+\n");
}











