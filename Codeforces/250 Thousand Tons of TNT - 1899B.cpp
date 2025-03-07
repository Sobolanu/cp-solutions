#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ull unsigned long long

using namespace std;

/*
nice lil' brute force problem, oddly enough the toughest part was the
"splitting array into k sections" part, which is
if((j + 1) % divs[i] == 0)...
*/

/*
so we distribute k of the boxes we have in the array
to trucks
obviously, each "k" would be divisors of the number
of trucks
*/

vector<int> divisors(int val)
{
    vector<int> divisors{};
    for(int i = 1; i * i <= val; i++)
    {
        if(val % i == 0)
        {
            divisors.emplace_back(i);
            if(i != val / i)
                divisors.emplace_back(val / i);
        }
    }

	sort(all(divisors));
    return divisors;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int t{};
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> v(n);
        for (auto& x : v) cin >> x;

        vector<int> divs = divisors(n);

        ull ans{};
        for (int i = 0; i < divs.size(); i++)
        {
            ull val{};
            vector<ull> diffs{};

            for (int j = 0; j < n; j++)
            {
                val += v[j];

                if((j + 1) % divs[i] == 0)
                {
                    diffs.emplace_back(val);
                    val = 0;
                }
            }

            ull mx = 0, mn = ULLONG_MAX;
            for (ull d : diffs)
            {
                mx = max(mx, d);
                mn = min(mn, d);
            }

            ans = max(ans, (mx - mn));
        }

        cout << ans << '\n';
    }
}
