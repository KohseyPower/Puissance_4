#include <stdio.h>
#include <string.h>
#define TAILLE 7
int integerOnly();

int main(void) {
	int i, j, jeton, tour, partie, jetonTrouve;
	char tab[TAILLE][TAILLE], joueur1[50], joueur2[50];
	tour = 1;
	partie = 1;
	jetonTrouve = 0;
	/* Initialisation de la grille */
	for(i=0;i<TAILLE;i++) {
		for(j=0;j<TAILLE;j++) {
			tab[i][j] = ' ';
		}
	}
	/* Demande de pseudo des joueurs */
	printf("Quel est le pseudo du premier joueur (O) ? ");
	scanf("%49s", joueur1);
	printf("Quel est le pseudo du premier joueur (X) ? ");
	scanf("%49s", joueur2);
	/* puissance4 */
	do {
		/* Affichage du tour en cours */
		printf("\033[1;1H\e[2J");
		for (i=0;i<TAILLE;i++) {
			for(j=0;j<TAILLE;j++) {
				printf("+---");
			}
			printf("+\n");
			for(j=0;j<TAILLE;j++) {
				printf("| ");
				if(tab[i][j] == 'X') {
					printf("\033[93m%c\033[m ", tab[i][j]);
				}else if(tab[i][j] == 'O'){
					printf("\033[91m%c\033[m ", tab[i][j]);
				}else{
					printf("  ");
				}
			}
			printf("|\n");	
		}
		for(i=0;i<TAILLE;i++) {
			printf("+---");
		}
		printf("+\n");
		for(i=0;i<TAILLE;i++) {
			printf("%3d ",i+1);	
		}
		printf("\n");
			/* A qui le tour de jouer */
		do {
			if(tour%2 != 0) {
				printf("Tour de %s (O): ", joueur1);
				jeton = integerOnly();
				}else{
				printf("Tour de %s (X): ", joueur2);
				jeton = integerOnly();
			}
		}while((jeton>TAILLE)||(jeton<=0));
		tour++;
	
		/* Placement du jeton dans la grille */
		i = TAILLE-1;
		while((jetonTrouve==0)) {
			if(tab[i][jeton-1] == ' '){
				if(tour%2 != 0) {
					tab[i][jeton-1] = 'X';
					jetonTrouve = 1;
				} else {
					tab[i][jeton-1] = 'O';
					jetonTrouve = 1;
				}
			}
			i--;
		}
		jetonTrouve = 0;
		/* Regarde s'il y a un gagnant en ligne */
		for(i=0;i<TAILLE;i++) {
			for(j=0;j<TAILLE-3;j++) {
				if((tab[i][j] == tab[i][j+1]) && (tab[i][j+2] == tab[i][j+3]) && (tab[i][j+1] == tab[i][j+2])) { 
					if((tab[i][j] == 'X')||(tab[i][j] == 'O')) {
						partie=0;
					}
				}	
			}
			
		}
		/* Regarde s'il y a un gagnant en colonne */	
		for(j=0;j<TAILLE;j++) {
			for(i=0;i<TAILLE-3;i++) {
				if((tab[i][j] == tab[i+1][j]) && (tab[i+2][j] == tab[i+3][j]) && (tab[i+1][j] == tab[i+2][j])) { 
					if((tab[i][j] == 'X')||(tab[i][j] == 'O')) {
						partie=0;
					}
				}	
			}
		}
			
		/* Regarde s'il y a un gagnant en diagonal gauche-droite */	
		for(j=0;j<TAILLE-3;j++) {
			for(i=0;i<TAILLE-3;i++) {
				if((tab[i][j] == tab[i+1][j+1]) && (tab[i+2][j+2] == tab[i+3][j+3]) && (tab[i+1][j+1] == tab[i+2][j+2])) { 
					if((tab[i][j] == 'X')||(tab[i][j] == 'O')) {
						partie=0;
					}
				}	
			}
		}
		

		/* Regarde s'il y a un gagnant en diagonal droite-gauche */	
		for(j=0;j<TAILLE-3;j++) {
			for(i=0;i<TAILLE-3;i++) {
				if((tab[i][j+3] == tab[i+1][j+2]) && (tab[i+2][j+1] == tab[i+3][j]) && (tab[i+3][j] == tab[i+1][j+2])) { 
					if((tab[i][j+3] == 'X')||(tab[i][j+3] == 'O')) {
						partie=0;
					}
				}	
			}
		}
			
	}while(partie==1);

	/* Affichage du dernier tour */

	printf("\033[1;1H\e[2J");
	for (i=0;i<TAILLE;i++) {
		for(j=0;j<TAILLE;j++) {
			printf("+---");
		}
		printf("+\n");
		for(j=0;j<TAILLE;j++) {
			printf("| ");
			if(tab[i][j] == 'X') {
				printf("\033[93m%c\033[m ", tab[i][j]);
			}else if(tab[i][j] == 'O'){
				printf("\033[91m%c\033[m ", tab[i][j]);
			}else{
				printf("  ");
			}
		}
		printf("|\n");	
	}
	for(i=0;i<TAILLE;i++) {
		printf("+---");
	}
	printf("+\n");
	for(i=0;i<TAILLE;i++) {
		printf("%3d ",i+1);	
	}
	printf("\n");

	/* Resultat */
	if((tour-1)%2 != 0) {
		printf("%s a gagné !\n", joueur1);
	} else {
		printf("%s a gagné\n", joueur2);
	}	
	return 0;
	       
}

int integerOnly(){
	int x;
	char c;
	do {
		scanf("%c", &c);
		if(c >= 48 && c<=57) {
			x = c - 48;
		}
		if(c == '\n') {
			break;
		}
	}while(1);
	return x;
}
