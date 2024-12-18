#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    string A, B;
    cin >> A >> B;

    if (A.size() <= B.size())
    {
        cout << "Wah, tidak bisa :(" << endl;
        return 0;
    }

    int j = 0, n_remove = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (n_remove > 1)
            break;

        if (j == B.size())
        {
            n_remove += A.size() - B.size();
            break;
        }

        if (A[i] != B[j])
            n_remove++;
        else
            j++;
    }

    if (n_remove == 1)
        cout << "Tentu saja bisa!" << endl;
    else
        cout << "Wah, tidak bisa :(" << endl;

    return 0;
}
