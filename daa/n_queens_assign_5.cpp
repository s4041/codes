#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<char>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "------------------------------" << endl;
}

bool isSafe(vector<vector<char>> &board, int row, int col)
{
    for (int i = row - 1; i >= 0; i--)
    {
        if (board[i][col] == 'Q')
        {
            return false;
        }
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); i--, j++)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }
    return true;
}

void nQueen(vector<vector<char>> &board, int row)
{
    if (row == board.size())
    {
        print(board);
        return;
    }
    for (int j = 0; j < board.size(); j++)
    {
        if (isSafe(board, row, j))
        {
            board[row][j] = 'Q';
            nQueen(board, row + 1);
            board[row][j] = 'X';
        }
    }
}

int main()
{
    int n;
    cout << "enter number of queens ";
    cin >> n;
    vector<vector<char>> board(n, vector<char>(n, 'X'));

    nQueen(board, 0);

    return 0;
}
