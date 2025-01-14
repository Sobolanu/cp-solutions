#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
typedef unsigned long long ull;

using namespace std;
/*
copied from editorial i got scammed by the test cases, the number of distinct values was literally the same on a test case and i checked it
but it decided to give me WA anyway
*/
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int cur = 0;
        for (int i = 1; i <= n; i += 2) {
            for (int j = i; j <= n; j *= 2) {
                a[cur++] = j;
            }
        }
        for (int i = 0; i<n; ++i) {
            cout << a[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}