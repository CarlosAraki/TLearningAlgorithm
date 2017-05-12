/*
cria um arquivo sobre as funções das variaveis
*/

void crio_arq_funcao(char *urlmatriz,char *urlfuncao,int linhas,int colunas)
{
	FILE *arq = fopen(urlfuncao,"w");
	int i,j;
	float func,*vet;
	for ( i = 0; i < linhas; i++)
	{
		func = 0;
		vet = leio_uma_linha_do_arquivo(urlmatriz,i,colunas);
		//for (j = 0; j < colunas; j++)
		//{
		func = pow(vet[0],2) + 6*vet[0];
		//}
		fprintf(arq,"%d : %f\n",i,func);
	}
	free(vet);
	fclose(arq);
}

/*
cria arquivo de média a partir das colunas da matriz solução
*/

void crio_arq_media(char *urlmatriz,char *urlmedia,int linhas,int colunas)
{
	FILE *arq = fopen(urlmedia,"w");
	int i,j;
	float func;
	fprintf(arq, "M : ");
	for ( i = 0; i < colunas; i++)
	{
		func = 0;
		func = leio_uma_coluna_do_arquivo(urlmatriz,linhas,colunas,i);
		func = func/linhas;
		fprintf(arq,"%f ",func);
	}
	fprintf(arq, "\n");
	fclose(arq);
}

/*
retorna um valor aleatório negativo ou positivo
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
quantidade de vezes q acontecerá uma interação entre os learners
*/

void crio_geracoes(char *url,char *fx,int linhas,int colunas,int g)
{
	//int g=500;
	while(g!=0)
	{
	codigo_learner(url,fx,linhas,colunas);
	g--;
	}
}