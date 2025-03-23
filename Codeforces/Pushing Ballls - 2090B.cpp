#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ll long long

using namespace std;

/*
once we place a ball at a cell, it can be pushed to either the right or bottom
because we insert balls from either the left or from the top
*/

bool chk(vector<vector<char>>& g, int row, int col)
{
    bool flag1{ true }, flag2{ true };

    for (int i = row; i >= 0; i--)
    {
        if (g[i][col] == '0')
        {
            flag1 = false;
            break;
        }

    }

    for (int i = col; i >= 0; i--)
    {
        if (g[row][i] == '0')
        {
            flag2 = false;
            break;
        }
    }

    return (flag1 || flag2);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<char>> g(n, vector<char>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> g[i][j];

        if (n == 1 || m == 1)
        {
            cout << "YES\n";
            continue;
        }

        bool flag{ true };

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (g[i][j] == '1')
                {
                    bool val = chk(g, i, j);

                    if (!val)
                    {
                        flag = false;
                        goto end;
                    }
                }
            }
        }

    end:
        (flag) ? cout << "YES\n" : cout << "NO\n";
    }
}
