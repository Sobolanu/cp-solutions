#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;
typedef unsigned long long ull;

const int mod = 1e9 + 7;
// const int mod = 998'244'353;

using namespace std;

/*
count arrays of size N such that:
- all numbers are between 0 and 2^k-1 (inclusive)
- bitwise AND of all elements is 0
- sum is maximized

print ans mod 1e9 + 7

bitwise and: returns 1 if two bits are ones, else it's 0
for a bitwise AND of 0, no two bits should match

2^k-1 for k = 4 is

one col is one array

for n = 4 and k = 4, max sum is 30
maximizing sum leads to an alternating pattern?

idea for brute force:
first number in array should have the most significant bit set and none else
then the second number should have every other bit set except for that first one
(if number is x, then ~x would be this other number, therefore x & ~x = 0)
and then keep alternating between those two for one array

move the bit for the first number to the right and keep doing this
once you've moved the bit fully to the right, we add a 2nd bit and move that 2nd bit to the right, then the 1st, then
the 2nd, then the 1st etc.

but given N numbers and K bits, n^k?
*/

ull binpow(ull a, ull b) {
    a %= mod;
    ull res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        ull n, k;
        cin >> n >> k;

        cout << binpow(n, k) << '\n';
    }
}

