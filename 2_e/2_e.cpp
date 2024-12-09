#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int N, A, B;
    cin >> N;
    cin >> A;
    cin >> B;

    const unsigned int M = 1000000007;

    int C[B + 1];
    for (int i = 0; i <= B; i++)
        C[i] = 0;

    C[0] = 1;
    for (int i = 1; i <= N; i++)
        for (int j = min(B, i); j > 0; j--)
            C[j] = (C[j - 1] + C[j]) % M;

    int res = 0;
    for (int i = A; i <= B; i++)
        res = (res + C[i]) % M;

    cout << res << endl;

    return 0;
}
