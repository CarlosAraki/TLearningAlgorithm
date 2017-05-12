#include <stdio.h>//biblioteca básica
#include <stdlib.h>//biblioteca para poteiros
#include <math.h>//funções de matemática bpasica
#include <time.h>// para gerar numeros aleatórios

/* tem um pequeno erro no vídeo 6:33 em que o calculo da segunda variável está errado 
era para ser negativo -12.74

*/

/*
diferença de meio
*/


float diferenca(float media,float menorpara)
{

	int t = rand()%2 +1; // coloco entre 1 ou 2 ... perguntar para professor
	float r = rand();
	r = r/RAND_MAX;
	t=1; //para video
	r=0.58; //para video
	float dif = r *(menorpara - (t*media));
	//printf("T=%d r=%f dif=%f\n",t,r,dif);
	return dif;
}


/*
diferenca de meio para video
*/

float diferenca2(float media,float menorpara)//para exemplo
{
	float r = rand();
	int t = rand()%2 +1; // coloco entre 1 ou 2 ... perguntar para professor
	r = r/RAND_MAX;
	t=1;  //para video
	r=0.49; //para video
	float dif = r *(menorpara - (t*media));
	printf("%f\n",dif);
	return dif;
}


/*
construo matriz teacher
*/


void construo_minha_matriz_teacher(float **mat,float **matth,int linhas,int colunas,float *vetorfx,float *vetormedia,float *vetorfxth,float *vetmediath,FILE *arq)
{
	int j,i, ind = indice_da_linha_minimo(vetorfx,linhas);
	float dif;
	//printf("%d\n", ind );
	fprintf(arq, "^^Inicio Matriz teacher \n");
	for (j = 0; j < colunas; j++)
	{	
		if (j==0)  //para video
			dif = diferenca(vetormedia[j],mat[ind][j]);
		else {  //para video
			dif = diferenca2(vetormedia[j],mat[ind][j]);  //para video
		}	//para video
		for (i = 0; i < linhas; i++)
		{
			matth[i][j] = mat[i][j] + dif;
		}
	}
	funcao(matth,linhas,colunas,vetorfxth);
	mediavetor(matth,linhas,colunas,vetmediath);
	coloconoarquivo(arq,linhas,colunas,matth,vetorfxth);
	for (j = 0; j < colunas; j++)
	{
		fprintf(arq,"   [ %f ]",vetmediath[j] );
	}
	fprintf(arq, "\n^^Fim Matriz teacher\n");
}


/*
comparo e coloco o menor valor para matriz mat de solução
*/

void compara_matrizes_e_troca_promenor(float **mat,int linhas,int colunas,float *vetfx,float **matTeacher,float *vetfxth)
{
	int i,j;
	for (i = 0; i < linhas; i++)
	{
		if (vetfxth[i]<vetfx[i])
		{
			for (j = 0; j < colunas; j++)
			{
				mat[i][j]=matTeacher[i][j];
			}

		}
	}


}