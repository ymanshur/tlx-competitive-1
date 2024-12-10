#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    long long B, K;
    cin >> B;
    cin >> K;

    long long i = K - B;
    int k = log2(i);
    while (i > 0)
    {
        long long K = pow(2, k);
        if (i - K < 0)
        {
            k--;
            continue;
        }

        i -= K;
        cout << K << endl;
    }

    return 0;
}
