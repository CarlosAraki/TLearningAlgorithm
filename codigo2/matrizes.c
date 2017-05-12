/*
cria um vetor do tipo float zera ele e retorna
*/

float *cria_vetor(int tam)
{
	int i;
	float *vetorfx = malloc(tam * sizeof(float));
	for ( i = 0; i < tam; i++)
	{
		vetorfx[i]=0;
	}
	return vetorfx;
}

/*
printo valores de um vetor na tela com um certo tamanho
*/

void printo_vetor(float *vet,int tam)
{
	int i;
	for (i = 0; i < tam; i++)
	{
		printf("%f ",vet[i]);
	}
}

/*
cria uma matriz float e a retorna
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
constroe uma matriz de numeros aleatórios 
*/

void construo_minha_matriz_random(char *url,char *urlfunc,char *urlmedia,int linhas,int colunas)
{
	FILE *arq = fopen(url,"w");
	int i,j;
	float r;
	for (i = 0; i < linhas; i++)
	{
		//fprintf(arq,"%d : ",i);
		for (j = 0; j < colunas;j++)
		{
			r=randomnum();
			fprintf(arq,"%f ",r);
		}
		fprintf(arq,"\n");
	}
	fclose(arq);
	crio_arq_funcao(url,urlfunc,linhas,colunas);
	crio_arq_media(url,urlmedia,linhas,colunas);
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
			mat[i][j] = 0;
		}
	}
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
mostra a matriz com a media
*/

void mostra_matriz(float **mat,int linhas,int colunas)
{
	int i,j;
	for (i = 0; i < linhas; i++)
	{
		for (j = 0; j < colunas;j++)
		{
			printf("%f ",mat[i][j]);
		}
		printf("\n");
	}
}

/*
cria uma matriz RAM a partir de endereço em HD
*/

float **cria_matriz_por_url(char *url,int linhas,int colunas)
{
	FILE *arq = fopen(url,"r");
	float **mat = cria_matriz(linhas,colunas);
	int i,j;
	for (i = 0; i < linhas; i++)
	{
		for (j = 0; j < colunas; j++)
		{
			fscanf(arq,"%f ",&mat[i][j]);
		}	
		fscanf(arq,"\n");
	}
	fclose(arq);
	return mat;
}

/*
valor numa matriz HD por linha x e coluna y
*/

float valor_por_coordenada(char *url,int colunas,int x,int y)
{
	FILE *arq = fopen(url,"r");
	float *vet = cria_vetor(colunas),aux;
	int i=0,j;
	x++;
	while(i!= x)
	{
		for (j = 0; j < colunas; j++)
		{
			fscanf(arq,"%f ",&vet[j]);
		}
		fscanf(arq,"\n");
		i++;
	}
	fclose(arq);
	aux = vet[y];
	free(vet);
	return aux;
}

/*
inverto a matriz e coloco em arquivo
*/

void inverto_matriz(char *url,int linhas,int colunas)
{
	float **mat = cria_matriz_por_url(url,linhas,colunas);
	FILE *arq = fopen(url,"w");
	int i,j;
	for (i = 0; i < colunas; i++)
	{
		for (j = 0; j < linhas; j++)
		{
			fprintf(arq, "%f ", mat[j][i] );
		}
		fprintf(arq, "\n");
	}
	freematriz(mat,linhas);
	fclose(arq);
}