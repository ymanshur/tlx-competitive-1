#include <iostream>

using namespace std;

long long gcd(long long a, long long b)
{
    if (b > a)
    {
        long long temp = a;
        a = b;
        b = temp;
    }

    long long r = a % b;
    while (r > 0)
    {
        a = b;
        b = r;
        r = a % b;
    }

    return b;
}

int main(int argc, char const *argv[])
{
    long long A, B, C, D;
    cin >> A;
    cin >> B;
    cin >> C;
    cin >> D;

    long long F = B * D / gcd(B, D);
    long long E = (F / B * A) + (F / D * C);
    long long gcd_E_F = gcd(E, F);

    cout << E / gcd_E_F << " " << F / gcd_E_F << endl;

    return 0;
}
