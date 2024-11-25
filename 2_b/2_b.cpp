#include <iostream>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

bool is_prime(int x)
{
    for (int i = 2; i <= floor(sqrt(x)); i++)
    {
        if (x % i == 0)
            return false;
    }

    return true;
}

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;

    vector<int> prime_numbers;
    for (int i = 2; i <= N; i++)
    {
        if (i == 2)
        {
            prime_numbers.push_back(i);
            continue;
        }

        if (is_prime(i))
        {
            prime_numbers.push_back(i);
        }
    }

    map<int, int> N_prime_factors;
    int i = N;
    int j = 0;
    while (i > 1)
    {
        int prime_number = prime_numbers[j];
        if (i % prime_number == 0)
        {
            if (N_prime_factors.count(prime_number) > 0)
                N_prime_factors[prime_number]++;
            else
                N_prime_factors[prime_number] = 1;

            i /= prime_number;
            continue;
        }

        j++;
    }

    int counter = 0;
    for (auto &&i : N_prime_factors)
    {
        if (counter > 0)
            cout << " x ";

        cout << i.first;

        if (i.second > 1)
            cout << '^' << i.second;

        counter++;
    }
    cout << endl;

    return 0;
}
