#include <iostream>
#include <vector>

using namespace std;

int ans = 0;

void click(int ball_number, int b, int k, vector<vector<int>> &board)
{
    if (b < 0 || b == board.size())
        return;

    if (board[b][k] != ball_number)
        return;

    ans++;
    board[b][k] = 0;
    click(ball_number, b + 1, k, board);
    click(ball_number, b, k + 1, board);
    click(ball_number, b - 1, k, board);
    click(ball_number, b, k - 1, board);
}

int main(int argc, char const *argv[])
{
    int M, N;
    cin >> M >> N;

    vector<vector<int>> board(M, vector<int>(N));
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    int B, K;
    cin >> B >> K;

    int ball_number = board[B][K];
    click(ball_number, B, K, board);

    cout << ans * (ans - 1) << endl;

    return 0;
}
