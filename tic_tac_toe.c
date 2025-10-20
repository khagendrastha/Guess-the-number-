#include <stdio.h>
#include <stdlib.h>

void printboard(); 
int checkwin();
void resetboard();

char board[10];  // 0 to 9 will be used

int main() {
    char choice;

    do {
        resetboard();
        int player = 1, input, status = -1;

        // Print the board once at the start
        printf("\033[H\033[J"); // Clear screen
        printboard();

        while (status == -1) {
            player = (player % 2 == 0) ? 2 : 1;
            char mark = (player == 1) ? 'X' : 'O';

            printf("Player %d (%c), enter your move (1-9): ", player, mark);
            scanf("%d", &input);

            if (input < 1 || input > 9 || board[input] == 'X' || board[input] == 'O') {
                printf("Invalid move, try again.\n");
                continue;
            }

            board[input] = mark;

            
            printf("\033[H\033[J");  
            printboard();

            status = checkwin();

            if (status == 1) {
                printf("Player %d wins!\n", player);
                break;
            } else if (status == 0) {
                printf("Game Draw!\n");
                break;
            }

            player++;
        }

        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("\nThanks for playing Tic Tac Toe! 👋\n");
    return 0;
}

void printboard() {
    printf("## TIC TAC TOE ##\n\n");
    printf("    |    |      \n");
    printf(" %c  |  %c |  %c   \n", board[1], board[2], board[3]);
    printf("____|____|____  \n");
    printf("    |    |      \n");
    printf(" %c  |  %c |  %c   \n", board[4], board[5], board[6]);
    printf("____|____|____  \n");
    printf("    |    |      \n");
    printf(" %c  |  %c |  %c   \n", board[7], board[8], board[9]);
    printf("    |    |      \n\n");
}

int checkwin() {
    if (board[1]==board[2] && board[2]==board[3]) return 1;
    if (board[4]==board[5] && board[5]==board[6]) return 1;
    if (board[7]==board[8] && board[8]==board[9]) return 1;
    if (board[1]==board[4] && board[4]==board[7]) return 1;
    if (board[2]==board[5] && board[5]==board[8]) return 1;
    if (board[3]==board[6] && board[6]==board[9]) return 1;
    if (board[1]==board[5] && board[5]==board[9]) return 1;
    if (board[3]==board[5] && board[5]==board[7]) return 1;

    int count = 0;
    for (int i = 1; i <= 9; i++) {
        if (board[i] == 'X' || board[i] == 'O') count++;
    }
    if (count == 9) return 0;

    return -1;
}

void resetboard() {
    for (int i = 1; i <= 9; i++) {
        board[i] = '0' + i;
    }
}

