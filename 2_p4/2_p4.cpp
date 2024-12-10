#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int B1, X;
    cin >> B1;
    cin >> X;

    vector<int> B2;
    while (B1 > 0)
    {
        int r = B1 % X;
        B2.push_back(r);
        B1 /= X;
    }

    for (int i = B2.size() - 1; i >= 0; i--)
        cout << B2[i];
    cout << endl;

    return 0;
}
