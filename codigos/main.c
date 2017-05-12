#include "predeclaracoes.c"
#include "funcaoealeta.c"
#include "criavetorematriz.c"
#include "faseprof.c"
#include "fasealuno.c"
/* Precisamos dividir o código em 3 partes ... a de reconhecimento  de parâmetros , Teacher phase e learner phase
reconhecimento de parâmetros é uma matriz q depende apenas da população e a quantidade de parâmetros de design

otimizar 
melhorar funcao para captar qualqeur funcao

compilar o programa gcc nome.c -lm -o nome.exe
floor( )	arredonda para baixo
ceil( )	arredonda para cima
sqrt( )	Calcula raiz quadrada
pow(variável, expoente)	potenciação
sin( )	seno
cos( )	cosseno
tan( )	Tangente
log( )	logaritmo natural
log10( )	logaritmo base 10

// preciso modulo diferenciso e integral

*/



int menu(float **mat,int linhas, int colunas,float *vetfx,float *vetmedia,float **matTeacher,float *vetfxth,float *vetmediath,float **lemat,float *vetle,FILE *arq)
{
	printf("deseja:\n");
	printf("1->visualizar a matriz\n");
	printf("2->encontrar coordenadas\n");
	printf("3->alterar todos valores\n");
	printf("4->alterar uma coordenada específica\n");
	printf("5->Mostra Matriz Teacher\n");
	printf("6->fazer matriz de numeros random\n");
	printf("7->Teacher Phase\n");
	printf("8->compara matriz teacher\n");
	printf("9->learnerphase\n");
	printf("10->menores parâmetros\n");
	printf("11->matriz learner\n");
	int var = 42;
	scanf("%d",&var);
	switch(var)
	{
		case 1: mostra_matriz(mat,linhas,colunas,vetfx,vetmedia);
			return 0;
			break;
		case 2: busca_na_matriz(mat,linhas,colunas);
			return 0;
			break;
		case 3: //construo_minha_matriz(mat,linhas,colunas,vetfx,vetmedia); 
				construo_minha_matriz2(mat,linhas,colunas,vetfx,vetmedia); //para video 
			return 0;	
			break;
		case 4: alterar_na_matriz_por_coordenada(mat,linhas,colunas);
			return 0;
			break;
		case 5:mostra_matriz(matTeacher,linhas,colunas,vetfxth,vetmediath);
			return 0;
			break;
		case 6: construo_minha_matriz_random(mat,linhas,colunas,vetfx,vetmedia,arq);
			return 0;
			break; 
		case 7: construo_minha_matriz_teacher(mat,matTeacher,linhas,colunas,vetfx,vetmedia,vetfxth,vetmediath,arq);
			return 0;
			break;
		case 8:compara_matrizes_e_troca_promenor(mat,linhas,colunas,vetfx,matTeacher,vetfxth);
			return 0;	
			break;
		case 9: interatividadeaprendiz(linhas,colunas,mat,lemat,matTeacher,vetle,vetfx,vetfxth,vetmedia,arq);
			return 0;
			break;
		case 10: printa_os_menores_paramentros(mat,linhas,colunas,vetfx,arq);
			return 0;
			break;
		case 11: mostra_matriz1(lemat,linhas,colunas,vetle);
			return 0;
			break;
		case 42:
			construo_minha_matriz_random(mat,linhas,colunas,vetfx,vetmedia,arq);
			construo_minha_matriz_teacher(mat,matTeacher,linhas,colunas,vetfx,vetmedia,vetfxth,vetmediath,arq);
			compara_matrizes_e_troca_promenor(mat,linhas,colunas,vetfx,matTeacher,vetfxth);
			interatividadeaprendiz(linhas,colunas,mat,lemat,matTeacher,vetle,vetfx,vetfxth,vetmedia,arq);
			printa_os_menores_paramentros(mat,linhas,colunas,vetfx,arq);
			return 1;
			break;
		default:
			return 1;
			break;
	}
}

int main()
{
	srand(time(NULL));//usa meu horário para gerar numeros aleatórios
	clock_t tempoInicial, tempoFinal;
   	double tempoGasto;
   	tempoInicial = clock();
	char url[]="memoria.txt";
	FILE *arq;
	arq = fopen(url, "w");
	if(arq == NULL)
			printf("Erro, nao foi possivel abrir o arquivo\n");
	else{
		int pop=5, num_de_var=2,loop=0;
		//pop=5; //para video 
		//scanf("%d %d", &pop,&num_de_var);
		float **matvalue = cria_matriz(pop,num_de_var);
		float **maTeacher = cria_matriz(pop,num_de_var);
		float **matlearner = cria_matriz(pop,num_de_var);
		float *vetfx = cria_vetor(pop);
		float *vetmedia = cria_vetor(num_de_var);
		float *vetfxth = cria_vetor(pop);
		float *vetmediath = cria_vetor(num_de_var);
		float *vetle = cria_vetor(pop);
		zeramatriz(matvalue,pop,num_de_var);
		while(loop==0){
			loop = menu(matvalue,pop,num_de_var,vetfx,vetmedia,maTeacher,vetfxth,vetmediath,matlearner,vetle,arq);
		}
		freematriz(matvalue,pop);
		freematriz(maTeacher,pop);
		freematriz(matlearner,pop);
		free(vetfx);
		free(vetfxth);
		free(vetle);
		free(vetmedia);
		free(vetmediath);
	}
	fclose(arq);
	tempoFinal = clock();
   	tempoGasto =((tempoFinal-tempoInicial)/CLOCKS_PER_SEC);
   	printf("Tempo em segundos: %f\n", tempoGasto);
	return 0;
}