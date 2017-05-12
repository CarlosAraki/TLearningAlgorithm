#include <stdio.h>//biblioteca básica
#include <stdlib.h>//biblioteca para poteiros
#include <math.h>//funções de matemática bpasica
#include <time.h>// para gerar numeros aleatórios

/*
Gera Números Aleatórios negativos
*/

float randomnum()
{
	float r;
	double x;
	x = ((double)rand() / ((double)RAND_MAX + 1) * 2) - 1.0; //numeros aleatórios negativos
	r = rand()%100	;//%intervalo q vc quer;
	r = r * x;
	return r;
}

/*
restringe a função
*/

int restringe(float **mat,int linhas, int i)
{
	float x1,x2,x3,x4,x5,x6,x7,x8,x9,x10;
	float aux1,aux2,aux3,aux4;
	x1=mat[i][0];
	x2=mat[i][1];
	//x3=mat[i][2];
	//x4=mat[i][3];
	//x5=mat[i][4];
	//x6=mat[i][5];
	//x7=mat[i][6];
	//x8=mat[i][7];
	//x9=mat[i][8];
	//x10=mat[i][9];
	//aux1=  -127 + 2*pow(x1,2) + 3*pow(x2,4) + x3 + 4*pow(x4,2) + 5*x5;
	//aux2= -282 + 7*x1 + 3*x2 + 10*pow(x3,2) + x4-x5;
	//aux3 =-196 + 23*x1 + pow(x2,2) +6*pow(x6,2) - 8*x7;
	//aux4 =4*pow(x1,2) + pow(x2,2) - 3*x1*x2 +2*pow(x3,2) + 5*x6 - 11*x7;
	if (40*x2 >= (pow(x1,2)+6*x1 ) )	//aux1 <= 0 && aux2 <= 0 && aux3 <= 0 && aux4 <= 0)	
	{
		return 0;
	}
	
	else
	{
		return 1;
	}
}
/*
coloca valores da função no vetor funcao
*/

void funcao(float **mat,int linhas,int colunas,float *vetorfx)
{
	int i,j;
	float x1,x2,x3,x4,x5,x6,x7,x8,x9,x10;
	for (i = 0; i < linhas; i++)
	{
		x1=mat[i][0];
		x2=mat[i][1];
		/*
		x3=mat[i][2];
		x4=mat[i][3];
		x5=mat[i][4];
		x6=mat[i][5];
		x7=mat[i][6];*/
		//x8=mat[i][7];
		//x9=mat[i][8];
		//x10=mat[i][9];
		//aux1 = pow(aux1,2);
		//aux2 = pow(aux2,2);
		vetorfx[i] = pow(x1,2) +pow(x2,2);//pow(x1-10,2) + 5*pow(x2-12,2) + pow(x3,4) + 3*pow(x4 -11,2) + 10*pow(x5,6) +7*pow(x6,2) + pow(x7,4) - 4*x6*x7 -10*x6 - 8*x7;
	}
}

