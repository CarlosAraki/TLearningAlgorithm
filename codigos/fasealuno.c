#include <stdio.h>//biblioteca básica
#include <stdlib.h>//biblioteca para poteiros
#include <math.h>//funções de matemática bpasica
#include <time.h>// para gerar numeros aleatórios


//0&1 1&3 2&4  3&0 4&2
//r1 =.081 for X1 & r2 =0.92 for X2

/*
observacoes:

ele utiliza a matriz em cross como input do learner
há um erro na interação 5 & 3 X1=-110,34	X2=27,28 * nao altera o final 
pois o valor continua sendo maior que a linha anterior da tabela
há um erro na atualizacao da tabela solução nas linhas 3 e 4 as função com maiores
soluções continuam na tabela *nao altera no valor final pois todos são maiores que 830
9:49 10:04
não é possivel haver uma população de 1, visto que o algoritmo é necessário interagir com outra linha 
que nao seja ela mesma



*/

/*
Funcao para indice aleatório entre learners
*/

int indice_aleatorio(int naopdser,int linhas)
{	
	int r = rand()%linhas;
	if (r==naopdser)
		return indice_aleatorio(naopdser,linhas);
	else{
		return r;
	} 
}


/*
indice aleatório para video
*/


int indice_aleatorio2(int naopdser,int linhas) //para video
{
	switch(naopdser)
	{
		case 0:
			return 1;
			break;
		case 1:
			return 3;
			break;
		case 2:
			return 4;
			break;
		case 3:
			return 0;
			break;
		case 4:
			return 2;
			break;
	}
}


/*
interaçao entre aprendizes numa populacao
*/


void learnerphase(int linhas,int colunas,float *vetfxth,float **mat,float **lemat,float *vetfxle)
{
	int i,indinteracao,j;
	float r;
	for (j = 0; j < colunas; j++)
	{
		r=rand();
		r=r/RAND_MAX;
		if (j==0) //para video
			r=0.81; //para video
		else{ //para video
			r=0.92;	//para video
		} //para video
		for (i = 0; i < linhas; i++)
		{
			//indinteracao = indice_aleatorio(i,linhas);
			indinteracao = indice_aleatorio2(i,linhas);//para video 
			//printf("%d\n",indinteracao );

			if (vetfxth[i]<vetfxth[indinteracao])
				lemat[i][j]=mat[i][j] +(r*(mat[i][j] - mat[indinteracao][j]));
			else{
				lemat[i][j]=mat[i][j] +(r*(mat[indinteracao][j] - mat[i][j]));
			}
		}
		
	}
	funcao(lemat,linhas,colunas,vetfxle);
}


/*
numero de vezes que ocorre essa interação
*/


void interatividadeaprendiz(int linhas,int colunas,float **mat,float **lemat,float **matth,float *vetfxle,float *vetfx,float *vetfxth,float *vetmedia,FILE * arq)
{
	int inte=1,j,i;
	//inte = 1; //para video
//	scanf("\n numero de interacoes -> %d",&inte);
	while(inte!=0)
	{	
		learnerphase(linhas,colunas,vetfxth,mat,lemat,vetfxle);
		inte--;
	}
	compara_matrizes_e_troca_promenor(mat,linhas,colunas,vetfx,lemat,vetfxle);
	funcao(mat,linhas,colunas,vetfx);
	mediavetor(mat,linhas,colunas,vetmedia);
	fprintf(arq, "~~Início Matriz Learners ja interada\n");
	coloconoarquivo(arq,linhas,colunas,lemat,vetfxle);
	fprintf(arq, "\n~~Fim Matriz Learners ja interada\n");
}


/*
busca e printa na tela os menores valores
*/


void printa_os_menores_paramentros(float **mat,int linhas,int colunas,float *vetfx,FILE *arq)
{
	int i,ind = indice_da_linha_minimo(vetfx,linhas);
	for ( i = 0; i < colunas; i++)
	{
		printf("%f  ",mat[ind][i]);
		fprintf(arq, "%f  ",mat[ind][i]);
	}
	printf("|  %f \n",vetfx[ind]);
	fprintf(arq, "%f  \nEND",vetfx[ind]);

}