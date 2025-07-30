#include <bits/stdc++.h>
using namespace std;

string check(int x) {
    if (x == 1)
        return "YA";
    int j, count = 0, x1 = floor(sqrt(x));
    for (j = 2; j <= x1; j++) {
        if (x % j == 0) {
            count++;
            // cout<<j<<endl;
        }
    }
    // cout<<count<<endl;
    if (count <= 1)
        return "YA";
    else
        return "BUKAN";
}
main() {
    int a, x, j;
    string ans;
    cin >> a;
    while (a--) {
        cin >> x;
        ans = check(x);
        cout << ans << endl;
    }
}
