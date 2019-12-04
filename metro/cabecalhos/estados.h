typedef struct estado estado;

#define E1 0
#define E2 1
#define E3 2
#define E4 3
#define E5 4
#define E6 5
#define E7 6
#define E8 7
#define E9 8
#define E10 9
#define E11 10
#define E12 11
#define E13 12
#define E14 13

#define VELOCIDADE 30
#define T_TROCA_H 0.6667
#define ESTACOES 14

estado* criar_estado(int estacao,int custo, estado* pai);

estado** gerar_filhos(no*** estacoes, int** distancias, int destino, estado* est);