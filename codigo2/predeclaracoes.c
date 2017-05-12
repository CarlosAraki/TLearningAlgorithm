#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/* matrizes .c*/

float *cria_vetor(int linhas);

void printo_vetor(float *vet,int tam);

float **cria_matriz(int linhas,int colunas);

void construo_minha_matriz_random(char *url,char *urlfunc,char *urlmedia,int linhas,int colunas);

void zeramatriz(float **mat,int linhas,int colunas);

void freematriz(float **mat,int linhas);

void mostra_matriz(float **mat,int linhas,int colunas);

float **cria_matriz_por_url(char *url,int linhas,int colunas);

float valor_por_coordenada(char *url,int colunas,int x,int y);

void inverto_matriz(char *url,int linhas,int colunas);

/* arquivos .c*/

void coloca_matriz_em_arq(char *url,float **mat,int linhas,int colunas);

void printo_arquivo_vetor(char *url,int linha);

void printo_arquivo_matriz(char *url,char *urlfunc,int linhas,int colunas);

float *leio_uma_linha_do_arquivo(char *url,int linha,int colunas);

float leio_uma_coluna_do_arquivo(char *url,int linhas,int colunas,int coluna);

void printa_o_menor_valor_fx(char *urlmat,char *url,int linhas,int colunas);

float media_por_coluna(char *urlmedia,int coluna);

void troca_valores_matrizes(char *url1,char *url2,int linhas,int colunas);

/* funcoes .c*/

void crio_arq_funcao(char *urlmatriz,char *urlfuncao,int linhas,int colunas);

void crio_arq_media(char *urlmatriz,char *urlmedia,int linhas,int colunas);

float randomnum();

void crio_geracoes(char *url,char *fx,int linhas,int colunas,int g);

/* Teacherphase .c*/

int variavelteacher();// ela a fixa para toda teacher phase 

float diferenca(float media,float menorpara,int t);

int indice_da_linha_minimo(char *urlfx ,int linhas);

void construo_minha_matriz_teacher(char *urlsol,char *urlfx,char *urlmedia,int linhas,int colunas);

int qual_menor(char *fx,char *fxth,int i,int linhas);

void atualiza_matriz_solucao(char *url,char *urlth,char *fx,char *fxth,int linhas,int colunas);

/* Learnerphase .c*/

int indice_aleatorio(int naopdser,int linhas);

int qual_e_menor(char *fx,int i,int ind,int linhas);

void atualiza_matriz_solucao2(char *url,char *aux,char *fx,int linhas,int colunas);

void codigo_learner(char *url,char *fx,int linhas,int  colunas);
