#include <stdio.h>//biblioteca básica
#include <stdlib.h>//biblioteca para poteiros
#include <math.h>//funções de matemática bpasica
#include <time.h>// para gerar numeros aleatórios

/*
calcula a média da matriz e coloca no vetor media
*/

void mediavetor(float **mat,int linhas,int colunas,float *vetormedia)
{
	float aux1;
	int i,j;
	for (j = 0; j < colunas; j++)
	{
		aux1 =0;
		for (i = 0; i < linhas; i++)
		{
			aux1 = aux1+mat[i][j];
		}

		vetormedia[j]=aux1/linhas;
		
	}	
}

/*
encontra o indice da linha com menor valor de função
*/

int indice_da_linha_minimo(float *vetorfx ,int linhas)
{
	int i;
	float aux=vetorfx[0]; 
	for (i = 0; i < linhas; i++)
	{
		if (aux>=vetorfx[i])
			aux = vetorfx[i];
	}
	for (i = 0; i < linhas; i++)
	{
		if (aux==vetorfx[i])
			return i;
	}

}


/*
cria um vetor zera ele e retorna
*/

float *cria_vetor(int linhas)
{
	int i;
	float *vetorfx = malloc(linhas * sizeof(float));
	for ( i = 0; i < linhas; i++)
	{
		vetorfx[i]=0;
	}
	return vetorfx;
}


/*
cria uma matriz e a retorna
*/

float **cria_matriz(int linhas,int colunas)
{
	int i;
	float **p = malloc(linhas * sizeof(float*));
	for ( i = 0; i < linhas; i++)
	{
		p[i] = malloc(colunas * sizeof(float));
	}
	return p;
}


/*
zera todos elementos da matriz
*/

void zeramatriz(float **mat,int linhas,int colunas)
{
	int i,j;
	for (i = 0; i < linhas; i++)
	{
		for (j = 0; j < colunas;j++)
		{
			mat[i][j] =0;
		}
	}
}


/*
mostra a matriz sem a média
*/

void mostra_matriz1(float **mat,int linhas,int colunas,float *vetorfx)
{
	int i,j;
	funcao(mat,linhas,colunas,vetorfx);
	for (i = 0; i < linhas; i++)
	{
		for (j = 0; j < colunas;j++)
		{
			printf("%f ",mat[i][j]);
		}
		printf("  ||  %f\n",vetorfx[i] );
	}

}


/*
mostra a matriz com a media
*/

void mostra_matriz(float **mat,int linhas,int colunas,float *vetorfx,float *vetmedia)
{
	int i,j;
	funcao(mat,linhas,colunas,vetorfx);
	mediavetor(mat,linhas,colunas,vetmedia);
	for (i = 0; i < linhas; i++)
	{
		for (j = 0; j < colunas;j++)
		{
			printf("%f ",mat[i][j]);
		}
		printf("  ||  %f\n",vetorfx[i] );
	}
	for (j = 0; j < colunas; j++)
	{
		printf("%f ",vetmedia[j] );
	}
	printf("\n");
}

/*
constroe uma matriz por interacao de usuário
*/

void construo_minha_matriz(float **mat,int linhas,int colunas,float *vetorfx,float *vetmedia)
{
	int i,j;
	float cont;
	for (i = 0; i < linhas; i++)
	{
		for (j = 0; j < colunas;j++)
		{
			printf("a%d%d ->",i,j);
			scanf("%f", &cont);
			mat[i][j] = cont;
		}
	}
	funcao(mat,linhas,colunas,vetorfx);
	mediavetor(mat,linhas,colunas,vetmedia);
}


/*
constroe matriz para os valores do vídeo
*/

void construo_minha_matriz2(float **mat,int linhas,int colunas,float *vetorfx,float *vetmedia) //para video
{
	mat[0][0]= -55;
	mat[1][0]= 0;
	mat[2][0]= 96;
	mat[3][0]= -64;
	mat[4][0]= -18;
	mat[0][1]= 36;
	mat[1][1]= 41;
	mat[2][1]= -86;
	mat[3][1]= 31;
	mat[4][1]= -27;
	funcao(mat,linhas,colunas,vetorfx);
	mediavetor(mat,linhas,colunas,vetmedia);

}

/*
coloca os valores no arquivo de texto
*/


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


/*
constroe uma matriz de numeros aleatórios 
*/

void construo_minha_matriz_random(float **mat,int linhas,int colunas,float *vetorfx,float *vetmedia,FILE *arq)
{
	int i,j,rest;
	fprintf(arq, "---Inicio Matriz Random \n");
	for (i = 0; i < linhas; i++)
	{
		rest = 1;
		while(rest != 0)
		{
			for (j = 0; j < colunas;j++)
			{
				mat[i][j] = randomnum();				
			}
			rest = restringe(mat,linhas,i);
			
		}
	}
	funcao(mat,linhas,colunas,vetorfx);
	mediavetor(mat,linhas,colunas,vetmedia);
	coloconoarquivo(arq,linhas,colunas,mat,vetorfx);
	for (j = 0; j < colunas; j++)
	{
		fprintf(arq,"   [ %f ]",vetmedia[j] );
	}
	fprintf(arq, "\n---Fim Matriz Random \n");

}

/*
desaloca a matriz
*/

void freematriz(float **mat,int linhas)
{
	int i,j;
	for (i = 0; i < linhas; i++)
	{
		free(mat[i]);		
	}
	free(mat);
}


/*
encontra as coordenadas de um elemente na matriz
*/


void busca_na_matriz(float **mat,int linhas,int colunas)
{
	printf("digite o valor para mandarmos suas coordenadas\n");
	float var;
	scanf("%f",&var);
	int i,j;
	for (i = 0; i < linhas; i++)
	{
		for (j = 0; j < colunas;j++)
		{
			if(mat[i][j]==var)
				printf("coordenadas são linha:%d coluna:%d \n",i,j);
		}
	}
}


/*
altera valor de uma coordenada especifica na matriz
*/


void alterar_na_matriz_por_coordenada(float **mat,int linhas,int colunas)
{
	int coordlinha,coordcol;
	printf("digite as coordenadas\n");
	scanf("%d %d",&coordlinha,&coordcol);
	if (coordcol>colunas-1 || coordlinha>linhas-1)
		printf("não existe essa posição na matriz\n");
	else{
		printf("novo valor de a%d%d\n->",coordlinha,coordcol);
		float var;
		scanf("%f",&var);
		mat[coordlinha][coordcol] = var; 
	}
}
