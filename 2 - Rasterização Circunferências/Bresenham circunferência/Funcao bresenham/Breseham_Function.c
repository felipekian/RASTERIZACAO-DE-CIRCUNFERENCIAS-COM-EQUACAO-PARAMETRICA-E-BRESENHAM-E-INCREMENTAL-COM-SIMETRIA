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
