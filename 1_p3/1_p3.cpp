#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;

    map<char, char> map_s1;
    map<char, char> map_encoded_s1; // decoder

    string s1, encoded_s1, encoded_s2;
    cin >> s1;
    cin >> encoded_s1;
    cin >> encoded_s2;

    for (int i = 0; i < N; i++)
    {
        if (map_s1.count(s1[i]) > 0 && map_s1[s1[i]] != encoded_s1[i])
        {
            cout << "Pak Dengklek bingung" << endl;

            return 0;
        }

        if (map_encoded_s1.count(encoded_s1[i]) > 0 && map_encoded_s1[encoded_s1[i]] != s1[i])
        {
            cout << "Pak Dengklek bingung" << endl;

            return 0;
        }

        map_s1[s1[i]] = encoded_s1[i];
        map_encoded_s1[encoded_s1[i]] = s1[i];
    }

    // for (auto &&i : map_s1)
    // {
    //     cout << i.first << "->" << i.second << endl;
    // }

    for (int i = 0; i < N; i++)
    {
        char c = '?';
        if (map_encoded_s1.count(encoded_s2[i]) > 0)
        {
            c = map_encoded_s1[encoded_s2[i]];
        }

        cout << c;
    }
    cout << endl;

    return 0;
}
