#include <stdio.h>
#include <stdlib.h>

#define TAM_MATRIX 30
#define BORDA 1

void Bresenham_circunferencia(int matrix[TAM_MATRIX][TAM_MATRIX], int xc, int yc, int raio);
void imprimeCirculo(int matrix[TAM_MATRIX][TAM_MATRIX]);

int main(){

    int m[TAM_MATRIX][TAM_MATRIX]={0}, xc=0, yc=0, r=0;

    printf("\t\tAlgoritmo de Bresenham para Circunferencia\n\n>>>OBS: Tamanho da matriz %dx%d\n\n", TAM_MATRIX,TAM_MATRIX);
    printf("Informe o Xc da circunferencia:\n>> ");
    scanf("%d", &xc);
    printf("Informe o Yc da circunferencia:\n>> ");
    scanf("%d", &yc);
    printf("Informe o Raio da circunferencia:\n>> ");
    scanf("%d", &r);

    Bresenham_circunferencia(m, xc,yc,r);
    imprimeCirculo(m);

    return 0;
}

void imprimeCirculo(int matrix[TAM_MATRIX][TAM_MATRIX]){
	//************************ imprime na tela *****************************************
    printf("\n\nImprimindo a circunferencia\n\n");
    int i,j;
    for(i=0;i<TAM_MATRIX;i++){
        for(j=0;j<TAM_MATRIX;j++){
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }
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


void Bresenham_circunferencia(int matrix[TAM_MATRIX][TAM_MATRIX], int xc, int yc, int raio){

	int x,y;
	x = 0;
	y = raio;
	double p = 1-raio; //ou p = 1-raio ou (5/4)-raio;

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
