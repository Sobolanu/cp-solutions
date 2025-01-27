#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
typedef long long ll;

/*
am using namespace from now on since it's easier for me
this problem was p. simple, a test case fucked with me a lot tho

i used int for the two largest values instead of long long and that
cost me 4 wrong submissions lmao

tl:dr cyclically use the two largest elements
*/
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false); std::cin.tie(0);
    int n{}, m{}, k{};
    cin >> n >> m >> k;

    vector<int> v(n);
    for(auto& x : v) std::cin >> x;

    std::sort(all(v), std::greater<int>());
    ll ans{};

    ll val{v[0]}, val2{v[1]};

    while(m != 0)
    {
        if(k >= m)
        {
            ans += (val * m);
            break;
        }

        ans += ((val * k) + val2);
        m -= (k + 1);
    }

    std::cout << ans << '\n';
}
