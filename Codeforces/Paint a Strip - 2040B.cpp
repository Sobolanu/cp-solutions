#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define int long long

using namespace std;

/*
my initial solution was log2(n), messing around with some rounding
found this sol in a comment
overall, way easier than brute forcing it.
*/
main()
{
    std::ios::sync_with_stdio(false); std::cin.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        cout << ceil(log2(ceil(n + 2) / 3.0)) + 1 << '\n';
    }
}

