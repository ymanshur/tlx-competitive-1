#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    string S;
    cin >> S;

    int S_size = S.size();
    int N = ceil(sqrt(S_size));

    int i = 0;
    while (i < N * N)
    {
        if (((i / N) % 2 == 1))
        {
            int k = i + N - 1;
            for (int j = 0; j < N; j++)
            {
                if (k > S_size - 1)
                {
                    cout << '.';
                    i++;
                    k--;
                    continue;
                }

                cout << S[k];
                i++;
                k--;
            }
            cout << endl;
            continue;
        }

        for (int j = 0; j < N; j++)
        {
            if (i > S_size - 1)
            {
                cout << '.';
                i++;
                continue;
            }

            cout << S[i];
            i++;
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
