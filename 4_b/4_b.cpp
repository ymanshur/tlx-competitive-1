#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> resC;

void printC(int k)
{
    if (k > K)
    {
        for (int i = 1; i < K; i++)
            cout << resC[i] << " ";
        cout << resC[K] << endl;
        return;
    }

    for (int i = resC[k - 1] + 1; i <= N; i++)
    {
        resC[k] = i;
        printC(k + 1);
    }
}

int main(int argc, char const *argv[])
{
    cin >> N >> K;

    for (int i = 0; i <= K; i++)
        resC.push_back(0);
    printC(1);
    return 0;
}
