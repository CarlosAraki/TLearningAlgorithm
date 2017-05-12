/*
define qual indice aleatóriamente sofrerá a interação
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
verifica qual das linhas tem menor valor de funcao retorna 1 se primeira linha é menor
*/

int qual_e_menor(char *fx,int i,int ind,int linhas)
{
	FILE *arq = fopen(fx,"r");
	float *vet = cria_vetor(linhas),aux1,aux2;
	int aux,j;
	for (j = 0; j < linhas; j++)
	{
		fscanf(arq,"%d : %f\n",&aux,&vet[j]);
	}
	aux1 = vet[i];
	aux2 = vet[ind];
	fclose(arq);
	free(vet);
	if (aux1<aux2)
		return 1;
	else
	{
		return 0;
	} 
}

/*
atualiza a matriz solução 
*/

void atualiza_matriz_solucao2(char *url,char *aux,char *fx,int linhas,int colunas)
{
	FILE *arq = fopen(url,"w");
	int i,j;
	float *aux1;
	for ( i = 0; i < linhas; i++)
	{
		aux1 = leio_uma_linha_do_arquivo(aux,i,colunas);
		for (j = 0; j < colunas; j++)
		{
			fprintf(arq, "%f ", aux1[j]);
		}
		fprintf(arq, "\n" );
	}
	free(aux1);
	fclose(arq);
}

/*
interação de learners entre si
*/

void codigo_learner(char *url,char *fx,int linhas,int  colunas)
{
	int i,ind,menorfx,j;
	char mataux[]="aux";
	FILE *aux = fopen(mataux,"w");
	float *aux1,*aux2,r,a,b;
	for (i = 0; i < linhas; i++)
	{
		r = rand()/RAND_MAX;

		ind = indice_aleatorio(i,linhas);
		aux1 = leio_uma_linha_do_arquivo(url,i,colunas);
		aux2 = leio_uma_linha_do_arquivo(url,ind,colunas);
		menorfx = qual_e_menor(fx,i,ind,linhas);
		for (j = 0; j < colunas; j++)
		{
			a = aux1[j];
			b =aux2 [j];
			if (menorfx==1)
			{

				a = a + r*(a - b);
				fprintf(aux, "%f ", a);
			}
			else
			{
				a = a + r*(b - a);
				fprintf(aux, "%f ", a);
			}
			fprintf(aux, "\n" );
		}
		free(aux1);
		free(aux2);
	}
	fclose(aux);
	atualiza_matriz_solucao2(url,mataux,fx,linhas,colunas);
	crio_arq_funcao(url,fx,linhas,colunas);
}