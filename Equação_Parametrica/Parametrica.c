#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14
#define TAM_MATRIX 30
#define BORDA 1

void equacaoParametrica(int matrix[TAM_MATRIX][TAM_MATRIX], int xc, int yc, int raio);
void imprimirCirculo(int matrix[TAM_MATRIX][TAM_MATRIX]);

void pause(){
	getchar();
	getchar();
}

int main(){
	while(1){
	    int m[TAM_MATRIX][TAM_MATRIX]={0};
	    int yc, xc, r;
	
	    printf("\tEquacao Parametrica Circunferencia.\n\n");
	    printf("\t>>>OBS. tamanho da matrix %dx%d\n\n",TAM_MATRIX,TAM_MATRIX);
	    printf("Informe o Xc:\n>>");
	    scanf("%d", &xc);
	    printf("Informe o Yc:\n>>");
	    scanf("%d", &yc);
	    printf("Informe o Raio:\n>>");
	    scanf("%d", &r);
	
	    equacaoParametrica(m, xc, yc, r);
	    imprimirCirculo(m);
	    
	    pause();
	    system("cls");
	
	}
    return 0;
}

void equacaoParametrica(int matrix[TAM_MATRIX][TAM_MATRIX], int xc, int yc, int raio){

    int x,y,i;
    x = xc + raio;
    y = yc;

    for(i=0 ; i<360 ; i++){
        matrix[x][y] = BORDA;
        x = xc + raio * cos( (PI * i) / 180);
        y = yc + raio * sin( (PI * i) / 180);
    }
}

void imprimirCirculo(int matrix[TAM_MATRIX][TAM_MATRIX]){
    int i,j;
    printf("\n\nImprimindo Circunferencia..\n\n");
    for(i=0;i<TAM_MATRIX;i++){        
        for(j=0;j<TAM_MATRIX;j++){
        	if(matrix[i][j]==0){
				printf("  ");
			}else{
				printf(". ");
			}            
        }
        printf("\n");
    }
}
