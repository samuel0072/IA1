Para compilar:</br>
  make all</br>

Resposta do algoritmo:</br>
  (3, 3) -> (2, 2) -> (1, 1) -> (0, 0)</br>
  no comeco tem 3 missionarios e 3 canibais</br>
  leva 1 missionario e 1 canibal</br>
  leva 1 missionario e 1 canibal</br>
  leva 1 missionario e 1 canibal</br>
  achou a solução</br>

Um estado é dado por:</br>
  Quantidade de missionarios do lado inicial(esquerdo), quantidade de canibais do lado inicial(esquerdo), </br>
  a profundidade do estado(na busca),</br>
  o estado pai, os filhos.</br>

A raiz é um estado com 3 missionarios, 3 canibais, profundidade 0, sem pai, sem filhos</br>

-algoritmo da bfs:</br>
 -colocar a raiz na fila.</br>
 -repetir para sempre:</br>
  -fronteira <-  próximo estado a ser desenfileirado</br>
  -se fronteira é solução:</br>
    -retorna fronteira</br>
  -gerar_filhos(fronteira)</br>
  -para cada filho de fronteira:</br>
    -se filho for estado valido:</br>
      -enfileirar(filho)</br>
      
      
Para gerar os filhos de um estado é gerado as seguintes combinações baseado em quantos missionarios e canibais o estado possui:</br>
 levar um canibal</br>
 levar um missionario</br>
 levar dois canibais</br>
 levar dois missionarios</br>
 levar um canibal e um missionario</br>
 trazer um canibal</br>
 trazer um missionario</br>
 trazer dois canibais</br>
 trazer dois missionarios</br>
 trazer um de cada</br>
Logo, um estado possui 10 filhos.</br>
