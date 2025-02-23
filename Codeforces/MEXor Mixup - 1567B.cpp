#include <bits/stdc++.h>
#define ull unsigned long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;

/*
MEX of the array is a, and XOR is b, ans always exists.
what's the minimum length of the array?

the array must contain elements at least from [0, b) to meet the MEX condition

if our XOR value at a current position is greater than B, then we want to reduce it
by modifying values

if our XOR value is smaller than B, then we add more elements, preferably ones that increase
our XOR
*/

/*
took from editorial given that i haven't really done xor problems before
i was right in assuming the "base size" of the array would be from [0, b)
but i didn't observe the 3 cases for this
*/

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int t{};
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;

        int pXor;
        if(a % 4 == 1)
            pXor = a - 1;
        else if(a % 4 == 2)
            pXor = 1;
        else if(a % 4 == 3)
            pXor = a;
        else
            pXor = 0;

        if(pXor == b)
            cout << a << '\n';
        else if((pXor ^ b) != a)
            cout << a + 1 << '\n';
        else
            cout << a + 2 << '\n';
    }
}

