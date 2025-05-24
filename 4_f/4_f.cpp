#include <iostream>
#include <vector>

using namespace std;

int M, N;

void click(char ball_number, int b, int k, int &score, vector<vector<char>> &board)
{
    if (b < 0 || b == M)
        return;

    if (k < 0 || k == N)
        return;

    if (board[b][k] != ball_number)
        return;

    score++;
    board[b][k] = '.';
    click(ball_number, b + 1, k, score, board);
    click(ball_number, b, k + 1, score, board);
    click(ball_number, b - 1, k, score, board);
    click(ball_number, b, k - 1, score, board);
}

int main(int argc, char const *argv[])
{
    cin >> M >> N;

    vector<vector<char>> board(M, vector<char>(N));
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    vector<vector<char>> board_copy(M, vector<char>(N));
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            board_copy[i][j] = board[i][j];

    char ball_number;
    int b, k, score = 0, max_score = 0;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
        {
            ball_number = board_copy[i][j];
            if (ball_number == '.')
                continue;

            score = 0;
            click(ball_number, i, j, score, board_copy);

            if (score > max_score)
            {
                max_score = score;
                b = i;
                k = j;
            }
        }

    ball_number = board[b][k];
    score = 0;
    click(ball_number, b, k, score, board);

    for (int i = k; i < N; i++)
        for (int j = M - 2; j >= 0; j--)
        {
            if (board[j][i] == '.')
                continue;

            int k = j + 1;
            while (k < M && board[k][i] == '.')
            {
                swap(board[k][i], board[k - 1][i]);
                k++;
            }
        }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N - 1; j++)
            cout << board[i][j] << " ";
        cout << board[i][N - 1] << endl;
    }

    return 0;
}
