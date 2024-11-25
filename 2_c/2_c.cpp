#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> prime_numbers;
    prime_numbers.push_back(2);

    int x = 3;
    while (prime_numbers.size() < 77777)
    {
        bool is_prime = true;
        for (int i = 0; prime_numbers[i] <= floor(sqrt(x)); i++)
        {
            if (x % prime_numbers[i] == 0)
            {
                is_prime = false;
                break;
            }
        }

        if (is_prime)
            prime_numbers.push_back(x);

        x += 2;
    }

    int T;
    cin >> T;
    while (T--)
    {
        int K;
        cin >> K;
        cout << prime_numbers[K - 1] << endl;
    }

    return 0;
}
