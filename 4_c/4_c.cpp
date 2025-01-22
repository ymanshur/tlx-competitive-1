#include <iostream>
#include <string>
#include <vector>

using namespace std;

string s;
vector<string> ans;

void permute(int index)
{
    if (index == s.size())
    {
        if (s.size() > 2)
            for (int i = 1; i < s.size() - 1; i++)
            {
                if (s[i - 1] < s[i] && s[i] < s[i + 1])
                    return;
                if (s[i - 1] > s[i] && s[i] > s[i + 1])
                    return;
            }

        ans.push_back(s);
        return;
    }

    for (int i = index; i < s.size(); i++)
    {
        swap(s[index], s[i]);
        permute(index + 1);
        swap(s[index], s[i]);
    }
}

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
        s += ('0' + i);

    permute(0);

    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++)
        cout
            << ans[i] << endl;

    return 0;
}
