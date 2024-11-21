#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    int R, C;
    cin >> R;
    cin >> C;

    int board[R][C];
    for (int i = 0; i < R; i++)
    {
        string c;
        cin >> c;
        for (int j = 0; j < c.size(); j++)
        {
            board[i][j] = c[j] - '0';
        }
    }

    while (true)
    {
        int r_fall_index = -1;

        for (int i = 0; i < R; i++)
        {
            bool r_full = true;
            for (int j = 0; j < C; j++)
            {
                if (board[i][j] == 0)
                {
                    r_full = false;
                    break;
                }
            }

            if (!r_full)
            {
                continue;
            }

            r_fall_index = i;
            for (int j = 0; j < C; j++)
            {
                board[i][j] = 0;
            }
        }

        if (R == 1 || r_fall_index <= 0)
        {
            break;
        }

        for (int i = r_fall_index; i > 0; i--)
        {
            for (int j = 0; j < C; j++)
            {
                if (board[i - 1][j] == 0)
                {
                    continue;
                }

                // board[i][j] = board[i - 1][j];
                // board[i - 1][j] = 0;

                for (int k = i; k < R; k++)
                {
                    if (board[k][j] != 0)
                    {
                        break;
                    }

                    board[k][j] = board[k - 1][j];
                    board[k - 1][j] = 0;
                }
            }
        }
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }

    return 0;
}
