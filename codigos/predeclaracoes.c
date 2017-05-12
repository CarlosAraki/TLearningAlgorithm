#include <stdio.h>//biblioteca básica
#include <stdlib.h>//biblioteca para poteiros
#include <math.h>//funções de matemática bpasica
#include <time.h>// para gerar numeros aleatórios

// funcaoealeta.c
/*
Gera Números Aleatórios negativos
*/

float randomnum();

/*
restringe a função
*/

int restringe(float **mat,int linhas, int i);

/*
coloca valores da função no vetor funcao
*/

void funcao(float **mat,int linhas,int colunas,float *vetorfx);

// criavetorematriz.c

/*
calcula a média da matriz e coloca no vetor media
*/

void mediavetor(float **mat,int linhas,int colunas,float *vetormedia);

/*
encontra o indice da linha com menor valor de função
*/

int indice_da_linha_minimo(float *vetorfx ,int linhas);

/*
cria um vetor zera ele e retorna
*/

float *cria_vetor(int linhas);

/*
cria uma matriz e a retorna
*/

float **cria_matriz(int linhas,int colunas);

/*
zera todos elementos da matriz
*/

void zeramatriz(float **mat,int linhas,int colunas);

/*
mostra a matriz sem a média
*/

void mostra_matriz1(float **mat,int linhas,int colunas,float *vetorfx);

/*
mostra a matriz com a media
*/

void mostra_matriz(float **mat,int linhas,int colunas,float *vetorfx,float *vetmedia);

/*
constroe uma matriz por interacao de usuário
*/

void construo_minha_matriz(float **mat,int linhas,int colunas,float *vetorfx,float *vetmedia);

/*
constroe matriz para os valores do vídeo
*/

void construo_minha_matriz2(float **mat,int linhas,int colunas,float *vetorfx,float *vetmedia); //para video

/*
coloca os valores no arquivo de texto
*/


void coloconoarquivo(FILE *arq,int linhas,int colunas,float **mat,float *vetorfx);
/*
constroe uma matriz de numeros aleatórios 
*/

void construo_minha_matriz_random(float **mat,int linhas,int colunas,float *vetorfx,float *vetmedia,FILE *arq);

/*
desaloca a matriz
*/

void freematriz(float **mat,int linhas);


/*
encontra as coordenadas de um elemente na matriz
*/


void busca_na_matriz(float **mat,int linhas,int colunas);

/*
altera valor de uma coordenada especifica na matriz
*/


void alterar_na_matriz_por_coordenada(float **mat,int linhas,int colunas);

//faseprof.c

/*
diferença de meio
*/


float diferenca(float media,float menorpara);

/*
diferenca de meio para video
*/

float diferenca2(float media,float menorpara);//para exemplo

/*
construo matriz teacher
*/


void construo_minha_matriz_teacher(float **mat,float **matth,int linhas,int colunas,float *vetorfx,float *vetormedia,float *vetorfxth,float *vetmediath,FILE *arq);

/*
comparo e coloco o menor valor para matriz mat de solução
*/

void compara_matrizes_e_troca_promenor(float **mat,int linhas,int colunas,float *vetfx,float **matTeacher,float *vetfxth);

//fasealuno.c

/*
Funcao para indice aleatório entre learners
*/

int indice_aleatorio(int naopdser,int linhas);

/*
indice aleatório para video
*/


int indice_aleatorio2(int naopdser,int linhas); //para video

/*
interaçao entre aprendizes numa populacao
*/


void learnerphase(int linhas,int colunas,float *vetfxth,float **mat,float **lemat,float *vetfxle);

/*
numero de vezes que ocorre essa interação
*/


void interatividadeaprendiz(int linhas,int colunas,float **mat,float **lemat,float **matth,float *vetfxle,float *vetfx,float *vetfxth,float *vetmedia,FILE * arq);

/*
busca e printa na tela os menores valores
*/


void printa_os_menores_paramentros(float **mat,int linhas,int colunas,float *vetfx,FILE *arq);

//main

// menu para interação de usuário

int menu(float **mat,int linhas, int colunas,float *vetfx,float *vetmedia,float **matTeacher,float *vetfxth,float *vetmediath,float **lemat,float *vetle,FILE *arq);