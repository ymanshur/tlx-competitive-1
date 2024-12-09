#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x;
        cin >> y;
    }

    int C[4];
    for (int i = 0; i <= 3; i++)
        C[i] = 0;

    const unsigned int M = 1000000007;

    C[0] = 1;
    for (int i = 1; i <= N; i++)
        for (int j = min(3, i); j > 0; j--)
            C[j] = (C[j - 1] + C[j]) % M;

    cout << C[3] << endl;

    return 0;
}
