#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if (b > a)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    int r = a % b;
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
    int N;
    cin >> N;

    int D[N];
    for (int i = 0; i < N; i++)
    {
        int d;
        cin >> d;
        D[i] = d;
    }

    int res = D[0];
    for (int i = 1; i < N; i++)
    {
        res = res * D[i] / gcd(res, D[i]);
    }

    cout << res << endl;

    return 0;
}
