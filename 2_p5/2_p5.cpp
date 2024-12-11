#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    long long B, C, D;
    cin >> B >> C >> D;

    if (C == D)
    {
        cout << max(0LL, B - C) << endl;
        return 0;
    }

    long long ans = 0;
    long long e = C - D;
    for (long long i = 1; i * i <= e && i <= B; i++)
    {
        if (e % i != 0)
            continue;

        if (i > D)
            ans++;

        long long f = e / i;
        if (f != i && f > D && f <= B)
            ans++;
    }

    cout << ans << endl;

    return 0;
}
