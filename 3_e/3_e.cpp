#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;

    int arr[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int x, y;
        cin >> x >> y;

        // search approximate right-most y index
        int y1_index = -1;
        int l = 0;
        int h = N - 1;
        int m;
        while (h >= l)
        {
            m = (h - l) / 2 + l;
            if (y >= arr[m])
            {
                y1_index = m;
                l = m + 1;
            }
            else
            {
                y1_index = m - 1;
                h = m - 1;
            }
        }

        // search approximate left-most x index
        int x1_index = -1;
        l = 0;
        h = y1_index;
        while (h >= l)
        {
            m = (h - l) / 2 + l;
            if (x >= arr[m])
            {
                x1_index = m + 1;
                l = m + 1;
            }
            else
            {
                x1_index = m;
                h = m - 1;
            }
        }

        if (y1_index - x1_index < 0 || x1_index < 0 || y1_index < 0)
        {
            cout << 0 << endl;
            continue;
        }

        int ans = y1_index - x1_index + 1;

        cout << y1_index - x1_index + 1 << endl;
    }
    return 0;
}
