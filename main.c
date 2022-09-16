#include <stdio.h>

#include <string.h>

int main() {
    int player, plX, curMarked, count, l, c, jogada, biss, winX = 0, winO = 0, veia = 0;
    char boardScr[3][3], vez, compara;
    char playerOne[20], playerTwo[20], playerX[20], playerO[20];
    printf("Insira o nome do jogador 1: ");
    fgets(playerOne, 19, stdin);
    printf("Insira o nome do jogador 2: ");
    fgets(playerTwo, 19, stdin);
    do {
      count = 0;
      player = 1;
      jogada = 0;
      boardScr[0][0] = ' ', boardScr[0][1] = ' ', boardScr[0][2] = ' ',
        boardScr[1][0] = ' ', boardScr[1][1] = ' ', boardScr[1][2] = ' ',
        boardScr[2][0] = ' ', boardScr[2][1] = ' ', boardScr[2][2] = ' ';
      do {
        printf("\nQual jogador sera o jogador X? [1/2]: ");
        scanf("%i", & plX);
        if (plX == 1) {
          printf("O usuario %s foi definido como jogador 'X' e o usuario %s foi
            definido como 'O'.\n ", playerOne, playerTwo);
          }
          else if (plX == 2) {
            printf("O usuario %s foi definido como jogador 'X' \ne o usuario %s foi
              definido como 'O'.\n ", playerTwo, playerOne);
            }
            else {
              printf("Insercao invalida! \n");
            }
          }
          while (plX != 1 && plX != 2);
          do {
            printf("\n\tTabela de jogo: Coordenadas:\n\n");
            printf("\t %c | %c | %c 1 | 2 | 3\n", boardScr[0][0], boardScr[0][1],
              boardScr[0][2]);
            printf(" ------------- -------------\n");
            printf("\t %c | %c | %c 4 | 5 | 6\n", boardScr[1][0], boardScr[1][1],
              boardScr[1][2]);
            printf(" ------------- -------------\n");
            printf("\t %c | %c | %c 7 | 8 | 9\n", boardScr[2][0], boardScr[2][1],
              boardScr[2][2]);
            do {
              if (player == 1)
                vez = 'X';
              else
                vez = 'O';
              printf("\nJogador %c informe sua jogada: ", vez);
              scanf("%d", & curMarked);
              if (curMarked == 1) {
                l = 0;
                c = 0;
                compara = ' ';
              } else if (curMarked == 2) {
                l = 0;
                c = 1;
                compara = ' ';
              } else if (curMarked == 3) {
                l = 0;
                c = 2;
                compara = ' ';
              } else if (curMarked == 4) {
                l = 1;
                c = 0;
                compara = ' ';
              } else if (curMarked == 5) {
                l = 1;
                c = 1;
                compara = ' ';
              } else if (curMarked == 6) {
                l = 1;
                c = 2;
                compara = ' ';
              } else if (curMarked == 7) {
                l = 2;
                c = 0;
                compara = ' ';
              } else if (curMarked == 8) {
                l = 2;
                c = 1;
                compara = ' ';
              } else if (curMarked == 9) {
                l = 2;
                c = 2;
                compara = ' ';
              }
            } while (curMarked > 9 || boardScr[l][c] != compara);
            printf("\n----------------------------------");
            if (player == 1) {
              if (curMarked == 1)
                boardScr[0][0] = 'X';
              else if (curMarked == 2)
                boardScr[0][1] = 'X';
              else if (curMarked == 3)
                boardScr[0][2] = 'X';
              else if (curMarked == 4)
                boardScr[1][0] = 'X';
              else if (curMarked == 5)
                boardScr[1][1] = 'X';
              else if (curMarked == 6)
                boardScr[1][2] = 'X';
              else if (curMarked == 7)
                boardScr[2][0] = 'X';
              else if (curMarked == 8)
                boardScr[2][1] = 'X';
              else if (curMarked == 9)
                boardScr[2][2] = 'X';
              else
                printf("\nJogada invalida\n");
              player++;
            } else {
              if (curMarked == 1)
                boardScr[0][0] = 'O';
              else if (curMarked == 2)
                boardScr[0][1] = 'O';
              else if (curMarked == 3)
                boardScr[0][2] = 'O';
              else if (curMarked == 4)
                boardScr[1][0] = 'O';
              else if (curMarked == 5)
                boardScr[1][1] = 'O';
              else if (curMarked == 6)
                boardScr[1][2] = 'O';
              else if (curMarked == 7)
                boardScr[2][0] = 'O';
              else if (curMarked == 8)
                boardScr[2][1] = 'O';
              else if (curMarked == 9)
                boardScr[2][2] = 'O';
              else
                printf("\nJogada invalida\n");
              player = 1;
            }
            jogada++;
            //ganhou por linha
            if (boardScr[0][0] == 'X' && boardScr[0][1] == 'X' && boardScr[0][2] == 'X' ||
              boardScr[1][0] == 'X' && boardScr[1][1] == 'X' && boardScr[1][2] == 'X' ||
              boardScr[2][0] == 'X' && boardScr[2][1] == 'X' && boardScr[2][2] == 'X') {
              printf("\nParabens!! O jogador 'X' venceu esta partida\n");
              count = 1;
              winX++;
            }
            if (boardScr[0][0] == 'O' && boardScr[0][1] == 'O' && boardScr[0][2] == 'O' ||
              boardScr[1][0] == 'O' && boardScr[1][1] == 'O' && boardScr[1][2] == 'O' ||
              boardScr[2][0] == 'O' && boardScr[2][1] == 'O' && boardScr[2][2] == 'O') {
              printf("\nParabens!! O jogador 'O' venceu esta partida\n");
              count = 1;
              winO++;
            }
            //ganhou por coluna
            if (boardScr[0][0] == 'X' && boardScr[1][0] == 'X' && boardScr[2][0] == 'X' ||
              boardScr[0][1] == 'X' && boardScr[1][1] == 'X' && boardScr[2][1] == 'X' ||
              boardScr[0][2] == 'X' && boardScr[1][2] == 'X' && boardScr[2][2] == 'X') {
              printf("\nParabens!! O jogador 'X' venceu esta partida\n");
              count = 1;
              winX++;
            }
            if (boardScr[0][0] == 'O' && boardScr[1][0] == 'O' && boardScr[2][0] == 'O' ||
              boardScr[0][1] == 'O' && boardScr[1][1] == 'O' && boardScr[2][1] == 'O' ||
              boardScr[0][2] == 'O' && boardScr[1][2] == 'O' && boardScr[2][2] == 'O') {
              printf("\nParabens!! O jogador 'O' venceu esta partida\n");
              count = 1;
              winO++;
            }
            //ganhou na diagonal principal
            if (boardScr[0][0] == 'X' && boardScr[1][1] == 'X' && boardScr[2][2] == 'X') {
              printf("\nParabens!! O jogador 'X' venceu esta partida\n");
              count = 1;
              winX++;
            }
            if (boardScr[0][0] == 'O' && boardScr[1][1] == 'O' && boardScr[2][2] == 'O') {
              printf("\nParabens!! O jogador 'O' venceu esta partida\n");
              count = 1;
              winO++;
            }
            //ganhou na diagonal secundaria
            if (boardScr[0][2] == 'X' && boardScr[1][1] == 'X' && boardScr[2][0] == 'X') {
              printf("\nParabens!! O jogador 'X' venceu esta partida\n");
              count = 1;
              winX++;
            }
            if (boardScr[0][2] == 'O' && boardScr[1][1] == 'O' && boardScr[2][0] == 'O') {
              printf("\nParabens!! O jogador 'O' venceu esta partida\n");
              count = 1;
              winO++;
            }
          } while (count == 0 && jogada < 9);
          if (count == 0) {
            printf("\nDeu velha kkkkkkkkkkkk\n");
            veia++;
          }
          printf("\n *** Resultado ***\n\n");
          printf("\t%c | %c | %c\n", boardScr[0][0], boardScr[0][1], boardScr[0][2]);
          printf(" -------------\n");
          printf("\t%c | %c | %c\n", boardScr[1][0], boardScr[1][1], boardScr[1][2]);
          printf(" -------------\n");
          printf("\t%c | %c | %c\n", boardScr[2][0], boardScr[2][1], boardScr[2][2]);
          printf("\nDesejam jogar novamente? Se sim, digite 1, caso contrario 2: ");
          scanf("%d", & biss);
        }
        while (biss == 1);
        printf("\nO jogador 'X' ganhou %i vez(es)\n", winX);
        printf("O jogador 'O' ganhou %i vez(es)\n", winO);
        printf("%i vez(es) foi/foram empate\n", veia);
        return 0;
      }