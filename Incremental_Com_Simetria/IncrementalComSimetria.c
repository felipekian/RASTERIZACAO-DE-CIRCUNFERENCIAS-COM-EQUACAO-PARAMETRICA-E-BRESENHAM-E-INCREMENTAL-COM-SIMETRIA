#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAM_MATRIX 30
#define BORDA 1

void plotarMatrix(int matrix[TAM_MATRIX][TAM_MATRIX], int x,int y, int xc, int yc);
void incrementalComSimetria(int matrix[TAM_MATRIX][TAM_MATRIX], int xc, int yc, int raio);
void imprimirMatrix(int matrix[TAM_MATRIX][TAM_MATRIX]);

void pause(){
	getchar();
	getchar();
}

int main (){
	while(1)
	{
		int matrix[TAM_MATRIX][TAM_MATRIX]={0}, xc, yc, raio;

		printf("\n\tAlgoritmo Incremental com Simetria\n\n");
		printf("OBS. Tamanho da matrix %dx%d\n\n",TAM_MATRIX,TAM_MATRIX);
	
		printf("Informe o Xc:\n>> ");
		scanf("%d", &xc);
		printf("Informe o Yc:\n>> ");
		scanf("%d", &yc);
		printf("Informe o Raio:\n>> ");
		scanf("%d", &raio);
	
		incrementalComSimetria(matrix,xc,yc,raio);
		imprimirMatrix(matrix);
		
		pause();
		system("cls");
	}
	
	return 0;
}

void plotarMatrix(int matrix[TAM_MATRIX][TAM_MATRIX], int x,int y, int xc, int yc){
    matrix[y+yc][x+xc]   = BORDA;
    matrix[x+xc][y+yc]   = BORDA;
    matrix[x+xc][-y+yc]  = BORDA;
    matrix[y+yc][-x+xc]  = BORDA;
    matrix[-y+yc][-x+xc] = BORDA;
    matrix[-x+xc][-y+yc] = BORDA;
    matrix[-x+xc][y+yc]  = BORDA;
    matrix[-y+yc][x+xc]  = BORDA;
    return;
}


void incrementalComSimetria(int matrix[TAM_MATRIX][TAM_MATRIX], int xc, int yc, int raio){
	double teta = (double) 1/raio;
	double cosseno = cos(teta);
	double seno = sin(teta);

	double x =  raio;
	double y = 0.0;	

	while(y<=x){
		plotarMatrix(matrix, round(x), round(y), xc, yc);
		x = (double)(x*cosseno)-(y*seno);
		y = (double)(y*cosseno)+(x*seno);
	}
}

void imprimirMatrix(int matrix[TAM_MATRIX][TAM_MATRIX]){
	int i,j;
	printf("\n\nImprimindo matrix\n\n");
	for(i=0;i<TAM_MATRIX;i++){		
		for(j=0;j<TAM_MATRIX;j++){
			if(matrix[i][j]==1){
				printf(". ");	
			}
			else{
				printf("  ");	
			}			
		}
		printf("\n");
	}
}
