#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define int long long

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false); std::cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
		cin >> n;

		vector<int> v(n);
		for(auto& x : v) cin >> x;

		for(int i = 0; i < n - 1; i++)
		{
			int mn = min(v[i], v[i+1]);
			v[i] -= mn;
			v[i+1] -= mn;

			if(v[i] < 0 || v[i+1] < 0)
				break;
		}

		if(is_sorted(all(v)))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
