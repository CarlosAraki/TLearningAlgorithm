#include "predeclaracoes.c"
#include "funcoes.c"
#include "matrizes.c"
#include "arquivos.c"
#include "Teacherphase.c"
#include "Learnerphase.c"
//criarei arquivos fechados para leitura

int main()
{
	srand(time(NULL));//usa meu horário para gerar numeros aleatórios
	clock_t tempoInicial, tempoFinal;
   	double tempoGasto;
   	tempoInicial = clock();
	int pop=1000,var=2; //populçao e variaveis de design
	char sol[]="fmatriz",func[]="ffuncao",media[]="fmedia";
	char th[]="teachermat",fth[]="teachervet";
	construo_minha_matriz_random(sol,func,media,pop,var);
		//printo_arquivo_matriz(sol,func,pop,var);
	construo_minha_matriz_teacher(sol,func,media,pop,var);
	//printo_arquivo_matriz(sol,func,pop,var);
	//crio_arq_funcao(th,fth,pop,var);
	atualiza_matriz_solucao(sol,th,func,fth,pop,var);
	//printo_arquivo_matriz(sol,func,pop,var);


	crio_geracoes(sol,func,pop,var,1);
	//printo_arquivo_matriz(sol,func,pop,var);


	
	printa_o_menor_valor_fx(sol,func,pop,var);

	tempoFinal = clock();
   	tempoGasto =((tempoFinal-tempoInicial)/CLOCKS_PER_SEC);
   	printf("Tempo em segundos: %f\n", tempoGasto);
	return 0;
}