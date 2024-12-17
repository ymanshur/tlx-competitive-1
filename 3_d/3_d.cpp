#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int N;
    cin >> N;

    int arr[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int ans = 0;
    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j < N - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                ans++;
            }

    cout << ans << endl;

    return 0;
}
