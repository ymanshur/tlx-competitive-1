#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    long long B, C, D;
    cin >> B;
    cin >> C;
    cin >> D;

    if (C - D == 0)
    {
        if (B <= C)
        {
            cout << 0 << endl;
            return 0;
        }

        cout << B - C << endl;
        return 0;
    }

    long long ans = 0;
    for (long long i = D + 1; i <= C - D && i <= B; i++)
        if (C % i == D)
            ans++;

    cout << ans << endl;

    return 0;
}
