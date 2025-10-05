#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;
typedef unsigned long long ull;

const int mod = 1e9 + 7;
// const int mod = 998'244'353;

using namespace std;

/*
for all multisets to have the same elements
the AMOUNT of any specific value V must be divisible by K to form a multiset
each multiset would be of size n / k if you can form one

there are cases where l == r, r = l + 1 are valid
if we select a boundary, we have to make every other multiset first equal to multiset 1
then take and distribute the other elements that have neither been selected before nor are in the subarray
and there must be some multiple of K of them

i need a frequency array that stores the frequency of all numbers up to an index i (i'll call it f)
because then I could calculate in O(1) the frequency of each element inside of boundaries [l, r]
so, i pick some boundary [l, r], get the frequency of the elements in there, and then for each element
subtract f[n][x] - freq([l, r])
(frequency of some element x at index n (last index)) with the frequency of the element in the boundary
if said subtraction gives me a result that is divisible by K, i can form a multiset with those elements
if it works out for all elements then it is a cool subarray

idea good, too tired and occupied with school stuff to actually implement
*/

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t{};
    cin >> t;

    while (t--)
    {
        ll n{}, k{};
        cin >> n >> k;

        vector<ll> a(n), freq(n+1);
        for(auto& x : a)
        {
            cin >> x;
            freq[x]++;
        }

        ll res{}; bool flag{true};

        for(int i = 0; i <= n; i++)
        {
            if(freq[i] % k != 0)
            {
                flag = 0;
                break;
            }

            else
                freq[i] /= k;
        }

        if(flag)
        {
            vector<ll> cnt(n+1);

            for(int l = 0, r = 0; r >= l && r < n; r++)
            {
                cnt[a[r]]++;
                while(cnt[a[r]] > freq[a[r]])
                {
                    cnt[a[l]]--;
                    l++;
                }

                res += (r - l + 1);
            }
        }

        cout << res << '\n';
    }
}
