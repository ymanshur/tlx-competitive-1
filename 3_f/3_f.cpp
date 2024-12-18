#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    int arr[N], a;
    cin >> a;
    arr[0] = a;
    for (int i = 1; i < N; i++)
    {
        cin >> a;
        arr[i] = arr[i - 1] + a;
    }

    int Q, x;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        cin >> x;
        int l = 0, h = N - 1, m, a;
        while (l <= h)
        {
            m = (h - l) / 2 + l;
            if (arr[m] == x)
            {
                a = m;
                break;
            }

            if (arr[m] > x)
            {
                h = m - 1;
                a = m;
            }
            else
            {
                l = m + 1;
                a = l;
            }
        }

        cout << a + 1 << endl;
    }

    return 0;
}
