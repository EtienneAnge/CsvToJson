# include <stdlib.h>
# include <stdio.h>
# include <string.h> 
# define N 1000

int main(){
	FILE* filecsv = NULL;
	FILE* filejson = NULL;
	filecsv = fopen("mesFringues.csv", "r");
	filejson = fopen("mesFringues.json", "w");
	
	char ligne[N];
	int nbLignesLues = 0;
	int nbColonnesLues = 0;
	char* laLigne;
	laLigne = malloc(sizeof(char) * N);
	char** tab;
	tab = malloc(sizeof(char*) * 5);
	for(int i = 0; i<5; i++){
		tab[i] = malloc(sizeof(char) * N);
		
		}
	int i=0;
	int k=0;
	if (filecsv == NULL) {
    printf("Erreur ouverture fichier csv \n");
    k=1;
	}
	if (filejson == NULL) {
	printf("Erreur ouverture fichoer json \n");
	k=1;
	}
	fprintf(filejson,"[\n");
	
	if(k==0){
    while(fgets(ligne, N, filecsv) !=NULL){
		laLigne = strtok(ligne,";");
		printf("ligne %d\n", nbLignesLues+1);
		
      i=0;
      while (laLigne != NULL){
        printf("colonne N°%d => %s \n", nbColonnesLues,laLigne);
		tab[i] = laLigne;
		i++;
        
        
        laLigne = strtok(NULL, ";");
        nbColonnesLues++;
      }
      printf("\n");
      fprintf(filejson,"{\n");
      i=0;
      fprintf(filejson, "'id': '%s',\n", tab[i]);
      i++;
      fprintf(filejson, "'appelation': '%s',\n", tab[i]);
      i++;
      fprintf(filejson, "'taille': '%s',\n", tab[i]);
      i++;
      fprintf(filejson, "'prix': '%s',\n", tab[i]);
      i++;
      
      fprintf(filejson,"},\n");
      nbColonnesLues=0;
      nbLignesLues++;
    }
    fprintf(filejson,"]");
    fclose(filecsv);
    fclose(filejson);
  }
	
	
	return 0;
	}
