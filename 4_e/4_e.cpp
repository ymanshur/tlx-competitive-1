#include <iostream>
#include <vector>

using namespace std;

int M, N;
int ans = 0;

void click(int ball_number, int b, int k, int &score, vector<vector<int>> &board)
{
    if (b < 0 || b == M)
        return;

    if (k < 0 || k == N)
        return;

    if (board[b][k] != ball_number)
        return;

    score++;
    board[b][k] = 0;
    click(ball_number, b + 1, k, score, board);
    click(ball_number, b, k + 1, score, board);
    click(ball_number, b - 1, k, score, board);
    click(ball_number, b, k - 1, score, board);
}

int main(int argc, char const *argv[])
{
    cin >> M >> N;

    vector<vector<int>> board(M, vector<int>(N));
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
        {
            int ball_number = board[i][j];
            if (ball_number == 0)
                continue;

            int score = 0;
            click(ball_number, i, j, score, board);

            if (score > ans)
                ans = score;
        }

    cout << ans * (ans - 1) << endl;

    return 0;
}
