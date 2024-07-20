#include <bits/stdc++.h>
#define N 4
using namespace std;

void printBoard(int board[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            if (board[i][j])
                cout << "Q ";
            else 
                cout << ". ";
        cout << "\n";
    }
}

bool canPlace(int board[N][N], int row, int col)
{
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solve(int board[N][N], int col)
{
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++) {
        if (canPlace(board, i, col)) {
            board[i][col] = 1;
            if (solve(board, col + 1))
                return true;
            board[i][col] = 0; // BACKTRACK
        }
    }

    return false;
}

bool fixQuuen()
{
    int board[N][N] = { { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 } };

    if (solve(board, 0) == false) {
        cout << "No solution";
        return false;
    }

    printBoard(board);
    return true;
}

int main()
{
    fixQuuen();
    return 0;
}
