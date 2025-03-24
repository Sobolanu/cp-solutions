#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ll long long

using namespace std;

/*
simple brute-force, had to swap from vector to deque
for faster performance.
*/
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);

    // int t;
    // cin >> t;

    // while (t--)
    // {
    int n, q;
    cin >> n >> q;

    deque<int> a(n);
    for (auto& x : a) cin >> x;

    while (q--)
    {
        int val{};
        cin >> val;

        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == val)
            {
                cout << i + 1 << " ";
                a.push_front(a[i]);
                a.erase(a.begin() + i + 1);
                break;
            }
        }
    }
    // }
}
