#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int N, M, X;
    cin >> N;
    cin >> M;
    cin >> X;

    vector<vector<int>> matrix(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int x;
            cin >> x;
            matrix[i][j] = x;
        }
    }

    for (int i = 0; i < X; i++)
    {
        string op;
        cin >> op;

        if (op == "90")
        {
            vector<vector<int>> matrix2(M, vector<int>(N, 0));
            for (int i = 0; i < matrix.size(); i++)
            {
                for (int j = 0; j < matrix[i].size(); j++)
                {
                    matrix2[j][N - i - 1] = matrix[i][j];
                }
            }

            matrix = matrix2;
            int temp = N;
            N = M;
            M = temp;
            continue;
        }

        if (op == "180")
        {
            vector<vector<int>> matrix2(N, vector<int>(M, 0));
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    matrix2[N - i - 1][M - j - 1] = matrix[i][j];
                }
            }

            matrix = matrix2;
            continue;
        }

        if (op == "270")
        {
            vector<vector<int>> matrix2(M, vector<int>(N, 0));
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    matrix2[M - j - 1][i] = matrix[i][j];
                }
            }

            matrix = matrix2;
            int temp = N;
            N = M;
            M = temp;
            continue;
        }

        if (op == "_")
        {
            vector<vector<int>> matrix2(N, vector<int>(M, 0));
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    matrix2[N - i - 1][j] = matrix[i][j];
                }
            }

            matrix = matrix2;
            continue;
        }

        if (op == "|")
        {
            vector<vector<int>> matrix2(N, vector<int>(M, 0));

            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    matrix2[i][M - j - 1] = matrix[i][j];
                }
            }

            matrix = matrix2;
            continue;
        }
    }

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
