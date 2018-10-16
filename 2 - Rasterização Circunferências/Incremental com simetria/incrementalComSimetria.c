#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAM_MATRIX 30
#define BORDA 1

void plotarMatrix(int matrix[TAM_MATRIX][TAM_MATRIX], int x,int y, int xc, int yc);
void incrementalComSimetria(int matrix[TAM_MATRIX][TAM_MATRIX], int xc, int yc, int raio);
void imprimirMatrix(int matrix[TAM_MATRIX][TAM_MATRIX]);

int main (){

	int matrix[TAM_MATRIX][TAM_MATRIX]={0}, xc, yc, raio;

	printf("\n\t\tAlgoritmo Incremental com Simetria\n\n");
	printf("\t\tOBS. Tamanho da matrix %dx%d\n\n",TAM_MATRIX,TAM_MATRIX);

	printf("Informe o Xc:\n>> ");
	scanf("%d", &xc);
	printf("Informe o Yc:\n>> ");
	scanf("%d", &yc);
	printf("Informe o Raio:\n>> ");
	scanf("%d", &raio);

	incrementalComSimetria(matrix,xc,yc,raio);
	imprimirMatrix(matrix);

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

/*
void incrementalComSimetria(int matrix[TAM_MATRIX][TAM_MATRIX], int xc, int yc, int raio){

	int x,y;
	x = 0;
	y = raio;
	double p = (5/4)-raio; //ou p = 1-r;

    	plotarMatrix(matrix, x,y,xc,yc);

	while(x<y){
        x++;
        if(p<0){
            p = p+2*x+1;
        }else{
            y--;
            p = p+2*x+1-2*y;
        }
        plotarMatrix(matrix, x,y,xc,yc);
	}

}

*/

void incrementalComSimetria(int matrix[TAM_MATRIX][TAM_MATRIX], int xc, int yc, int raio){
	double teta = (double) 1/raio;
	double cosseno = cos(teta);
	double seno = sin(teta);

	//printf("Seno = %lf\nCosseno = %lf\n",seno,cosseno);

	double x =  raio;
	double y = 0.0;

	//printf("X = %lf\nY = %lf\n",x,y );

	while(y<=x){
		plotarMatrix(matrix, round(x), round(y), xc, yc);
		x = (double)(x*cosseno)-(y*seno);
		y = (double)(y*cosseno)+(x*seno);
	}
}

void imprimirMatrix(int matrix[TAM_MATRIX][TAM_MATRIX]){
	int i,j;
	printf("\n\n\tImprimindo matrix gerada apos o algoritmo...\n\n");
	for(i=0;i<TAM_MATRIX;i++){
		printf("\t\t");
		for(j=0;j<TAM_MATRIX;j++){
			printf("%d", matrix[i][j]);
		}
		printf("\n");
	}
}
