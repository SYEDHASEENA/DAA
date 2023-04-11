#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int num_solutions = 0;


void print_solution(int board[], int n);
void solve(int board[], int col, int n);
bool is_safe(int board[], int row, int col, int n);

int main() {
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);

    int board[n];
    solve(board, 0, n);

    if (num_solutions == 0) {
        printf("No solutions found.\n");
    } else {
        printf("%d solution(s) found.\n", num_solutions);
    }

    return 0;
}

bool is_safe(int board[], int row, int col, int n) {
    for (int i = 0; i < col; i++) {
        if (board[i] == row || board[i] == row - col + i || board[i] == row + col - i) {
            return false;
        }
    }
    return true;
}
void solve(int board[], int col, int n) {
    if (col == n) {
        print_solution(board, n);
        num_solutions++;
        return;
    }

    for (int row = 0; row < n; row++) {
        if (is_safe(board, row, col, n)) {
            board[col] = row;
            solve(board, col+1, n);
        }
    }
}

void print_solution(int board[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[j] == i) {
                printf("Q ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}


