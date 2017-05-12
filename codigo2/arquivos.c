/*
tranforma uma matriz RAM em HD
*/
void coloca_matriz_em_arq(char *url,float **mat,int linhas,int colunas)
{
	FILE *arq = fopen(url,"w");
	int i,j;
	for (i = 0; i < linhas; i++)
	{
		//fprintf(arq,"%d : ",i);
		for (j = 0; j < colunas;j++)
		{
			fprintf(arq,"%f ",mat[i][j]);
		}
		fprintf(arq,"\n");
	}
	fclose(arq);
}

/*
printo o valor da funcao em uma linha
*/

void printo_arquivo_vetor(char *url,int linha)
{
	FILE *arq2 = fopen(url,"r");
	int l,i;
	float aux;
	for (i = 0; i <= linha;i++)
	{
		fscanf(arq2,"%d : %f\n",&l,&aux);
	}
	printf("| %f\n", aux);
	fclose(arq2);
}

/*
printo a matriz inteira na tela
*/

void printo_arquivo_matriz(char *url,char *urlfunc,int linhas,int colunas)
{
	FILE *arq = fopen(url,"r");
	int i,j,aux;
	float *vet = cria_vetor(colunas);
	for (i = 0; i < linhas; i++)
	{
		//fscanf(arq,"%d :",&aux);
		printf("%d :",i );
		for (j = 0; j < colunas;j++)
		{
			fscanf(arq,"%f ",&vet[j]);
		}
		printo_vetor(vet,colunas);
		printo_arquivo_vetor(urlfunc,i);
		fscanf(arq,"\n");	
	}
	free(vet);
	fclose(arq);
}

/*
le uma linha inteira num arquivo e retorna um vetor
*/

float *leio_uma_linha_do_arquivo(char *url,int linha,int colunas)
{
	FILE *arq = fopen(url,"r");
	float *vet = cria_vetor(colunas);
	int i=0,j,aux;
	linha++;
	while(i!= linha)
	{
		//fscanf(arq,"%d :",&aux);
		for (j = 0; j < colunas; j++)
		{
			fscanf(arq,"%f ",&vet[j]);
		}
		fscanf(arq,"\n");
		i++;
	}
	fclose(arq);
	return vet;
}

/*
leio uma coluna nun arquivo e somo *feito para media
*/

float leio_uma_coluna_do_arquivo(char *url,int linhas,int colunas,int coluna)
{
	float **mat = cria_matriz_por_url(url,linhas,colunas),aux=0;
	int i;
	for (i = 0; i < linhas; i++)
	{
		aux = aux + mat[i][coluna];
	}
	freematriz(mat,linhas);
	return aux;
}

/*
procura o menor valor de fx e printa o menor
*/

void printa_o_menor_valor_fx(char *urlmat,char *url,int linhas,int colunas)
{
	FILE *arq = fopen(url,"r");
	float aux,valor=0,*aux1;
	int i,aux2,val=0;
	for ( i = 0; i < linhas; i++)
	{
		fscanf(arq,"%d : %f\n",&aux2,&aux);
		if (aux <= valor)
		{
			valor = aux;
			val = aux2;
		}
	}
	aux1 = leio_uma_linha_do_arquivo(urlmat,val,colunas);
	printf("%d : ",val);
	printo_vetor(aux1,colunas);
	printf(" : %f\n",valor );
	free(aux1); 
	fclose(arq);
}

/*
retorna a média por coluna de arquivo
*/

float media_por_coluna(char *urlmedia,int coluna)
{
	FILE *arq= fopen(urlmedia,"r");
	float media;
	int i=-1;
	fscanf(arq,"M : ");
	do
	{
		fscanf(arq,"%f ",&media);
		i++;
	}while(i!=coluna);
	fclose(arq);
	return media;
}

/*
troca valores de dois arquivos matrizes
*/

void troca_valores_matrizes(char *url1,char *url2,int linhas,int colunas)
{
	FILE *arq = fopen(url1,"w");
	int i,j;
	float *linhavet = cria_vetor(colunas);	
	for ( i = 0; i < linhas; i++)
	{
		linhavet = leio_uma_linha_do_arquivo(url2,i,colunas);
		for (j = 0; j < colunas; j++)
		{
			fprintf(arq, "%f ",linhavet[j] );
		}
		fprintf(arq, "\n" );
	}
	free(linhavet);
	fclose(arq);
}