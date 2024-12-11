#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    int N, X;
    cin >> N >> X;

    int a, d, ans;
    cin >> a;
    d = abs(a - X);
    ans = a;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> a;
        if (abs(a - X) > d)
            continue;

        if (abs(a - X) < d)
        {
            d = abs(a - X);
            ans = a;
            continue;
        }

        if (a < ans)
            ans = a;
    }

    cout << ans << endl;

    return 0;
}
