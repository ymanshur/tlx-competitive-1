#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int N, K;
    cin >> N >> K;

    int arr[N], a;
    cin >> a;
    arr[0] = a;
    for (int i = 1; i < N; i++)
    {
        cin >> a;
        arr[i] = arr[i - 1] + a;
    }

    int arr2[K];
    for (int i = 0; i < K; i++)
        cin >> arr2[i];

    for (int i = 0; i < K; i++)
    {
        int l = 0, h = N - 1, m, a;
        while (l <= h)
        {
            m = (h - l) / 2 + l;
            if (arr[m] == arr2[i])
            {
                a = m;
                break;
            }

            if (arr[m] > arr2[i])
            {
                h = m - 1;
                a = h;
            }
            else
            {
                l = m + 1;
                a = m;
            }
        }

        cout << a + 1 << endl;
    }

    return 0;
}
