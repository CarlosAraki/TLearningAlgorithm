/*
t é fixo para toda teacher phase
*/ 

int variavelteacher()
{
	int t = rand()%2 + 1; 
	return t;
}

/*
calcula a diferença 
*/

float diferenca(float media,float menorpara,int t)
{
	float r = rand();
	r = r/RAND_MAX;
	//t=1; //para video
	//r=0.58; //para video
	float dif = r *(menorpara - (t*media));
	//printf("r:%f menor:%f t:%d media:%f dif:%f\n",r,menorpara,t,media,dif );
	return dif;
}

/*
retorna indice que tem a menor função 
*/

int indice_da_linha_minimo(char *urlfx ,int linhas)
{
	FILE *arq = fopen(urlfx,"r");
	float aux,valor=0;
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
	fclose(arq);
	return val;
}

/*
contruo a matriz teacher 
*/

void construo_minha_matriz_teacher(char *urlsol,char *urlfx,char *urlmedia,int linhas,int colunas)
{
	int j,i, ind = indice_da_linha_minimo(urlfx,linhas),t = variavelteacher();
	float dif,media,valor,th;
	//printf("%d\n", ind );
	char urlth[] = "teachermat",urlvtth[] = "teachervet";
	FILE *arq = fopen(urlth,"w");
	for (j = 0; j < colunas; j++)
	{	
		//if (j==0)  //para video
		//{  //para video
			media = media_por_coluna(urlmedia,j);
			valor = valor_por_coordenada(urlsol,colunas,ind,j);
			dif = diferenca(media,valor,t);
		//}  //para video
	//	else {  //para video
	//		dif = diferenca2(vetormedia[j],mat[ind][j]);  //para video
	//	}	//para video
		for (i = 0; i < linhas; i++)
		{
			th = valor_por_coordenada(urlsol,colunas,i,j) + dif;
			fprintf(arq, "%f ", th);
		}
		fprintf(arq, "\n");
	}
	fclose(arq);
	inverto_matriz(urlth,linhas,colunas);
	crio_arq_funcao(urlth,urlvtth,linhas,colunas);
}

/*
verifica funcao é menor entre dua matrizes
*/

int qual_menor(char *fx,char *fxth,int i,int linhas)
{
	FILE *arq = fopen(fx,"r"), *arq2 = fopen(fxth,"r");
	int aux,j;
	float *vet = cria_vetor(linhas), *vet2 = cria_vetor(linhas),aux1,aux2;
	for (j = 0; j < linhas; j++)
	{
		fscanf(arq,"%d : %f\n",&aux,&vet[j]);
		fscanf(arq2,"%d : %f\n",&aux,&vet2[j]);
	}
	aux1 = vet[i];
	aux2 = vet2[i];
	free(vet);
	free(vet2);
	fclose(arq);
	fclose(arq2);
	if (aux1>=aux2)
		return 1;
	else
	{
		return 0;
	} 
}

/*
atualiza a matriz de menor tamanho
*/

void atualiza_matriz_solucao(char *url,char *urlth,char *fx,char *fxth,int linhas,int colunas)
{
	int i,j,fxmenor;
	float *linhavet = cria_vetor(colunas);
	char mataux[]="aux";
	FILE *aux = fopen(mataux,"w"),*arq1 = fopen(url,"r"),*arq2 = fopen(urlth,"r");

	for (i = 0; i < linhas; i++)
	{
		fxmenor = qual_menor(fx,fxth,i,linhas);
		if (fxmenor == 1)
		{
			linhavet = leio_uma_linha_do_arquivo(urlth,i,colunas);
			for (j = 0; j < colunas; j++)
			{
				fprintf(aux, "%f ", linhavet[j]);
			}
			fprintf(aux, "\n");
		}
		else
		{
			linhavet = leio_uma_linha_do_arquivo(url,i,colunas);
			for (j = 0; j < colunas; j++)
			{
				fprintf(aux, "%f ", linhavet[j]);
			}
			fprintf(aux, "\n");
		}
	}
	free(linhavet);
	fclose(aux);
	troca_valores_matrizes(url,mataux,linhas,colunas);
	crio_arq_funcao(url,fx,linhas,colunas);
}