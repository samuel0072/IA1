Para compilar:
  make all

Resposta do algoritmo:
  (3, 3) -> (2, 2) -> (1, 1) -> (0, 0)
  no comeco tem 3 missionarios e 3 canibais
  leva 1 missionario e 1 canibal
  leva 1 missionario e 1 canibal
  leva 1 missionario e 1 canibal
  achou a solução

Um estado é dado por:
  Quantidade de missionarios do lado inicial(esquerdo), quantidade de canibais do lado inicial(esquerdo), 
  a profundidade do estado(na busca),
  o estado pai, os filhos.

A raiz é um estado com 3 missionarios, 3 canibais, profundidade 0, sem pai, sem filhos

algoritmo da bfs:
 colocar a raiz na fila.
 repetir para sempre:
  fronteira <-  próximo estado a ser desenfileirado
  se fronteira é solução:
    retorna fronteira
  gerar_filhos(fronteira)
  para cada filho de fronteira:
    se filho for estado valido:
      enfileirar(filho)
      
      
Para gerar os filhos de um estado é gerado as seguintes combinações baseado em quantos missionarios e canibais o estado possui:
 levar um canibal
 levar um missionario
 levar dois canibais
 levar dois missionarios
 levar um canibal e um missionario
 trazer um canibal
 trazer um missionario
 trazer dois canibais
 trazer dois missionarios
 trazer um de cada
Logo, um estado possui 10 filhos.
