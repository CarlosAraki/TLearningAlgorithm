#include <stdio.h>//biblioteca básica
#include <stdlib.h>//biblioteca para poteiros
#include <math.h>//funções de matemática bpasica
#include <time.h>// para gerar numeros aleatórios


float randomnum()
{
	float r;
	double x;
	x = ((double)rand() / ((double)RAND_MAX + 1) * 2) - 1.0; //numeros aleatórios negativos
	r = rand()%100	;//%intervalo q vc quer;
	r = r * x;
	return r;
}

void funcao(float **mat,int linhas,int colunas,float *vetorfx)
{
// exemplo q ele usa é x^2 +x^2 =fx
	int i,j;
	float aux1,aux2;
	for (i = 0; i < linhas; i++)
	{
		aux1=mat[i][0];
		aux2=mat[i][0];
		aux1 = pow(aux1,2);
		//aux2 = pow(aux2,2);
		//aux1 = aux1*aux1;
		//aux2 = aux2*aux2;0
		vetorfx[i] = 3*aux1 + 7*aux2+9;
	}
}

void coloconoarquivo(FILE *arq,int linhas,int colunas,float **mat,float *vetorfx)
{
	int i,j;
	for (i = 0; i < linhas; i++)
	{
		fprintf(arq, "%d :",i );
		for (j = 0; j < colunas;j++)
		{
			fprintf(arq,"[ %f ] ",mat[i][j]);
		}
		fprintf(arq,"  ||  %f\n",vetorfx[i] );
	}
}