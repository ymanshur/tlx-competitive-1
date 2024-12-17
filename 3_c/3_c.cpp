#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;

    string arr[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
        {
            if (arr[j].length() < arr[i].length())
                swap(arr[j], arr[i]);

            if (arr[j].length() == arr[i].length() && arr[j] < arr[i])
                swap(arr[j], arr[i]);
        }

    for (int i = 0; i < N; i++)
        cout << arr[i] << endl;

    return 0;
}
