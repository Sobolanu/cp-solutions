#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;

// literally just brute force

int upLeft(std::vector<std::vector<int>>& grid, std::pair<int, int> cellPos)
{
    int sum{};
    int i = cellPos.first, j = cellPos.second;
    while (i - 1 >= 0 && j - 1 >= 0)
    {
        i--; j--;
        sum += grid[i][j];
    }

    return sum;
}
int upRight(std::vector<std::vector<int>>& grid, std::pair<int, int> cellPos)
{
    int sum{};
    int i = cellPos.first, j = cellPos.second;
    while (i - 1 >= 0 && j + 1 < grid[i].size())
    {
        i--; j++;
        sum += grid[i][j];
    }

    return sum;
}
int downLeft(std::vector<std::vector<int>>& grid, std::pair<int, int> cellPos)
{
    int sum{};
    int i = cellPos.first, j = cellPos.second;
    while (i + 1 < grid.size() && j - 1 >= 0)
    {
        i++; j--;
        sum += grid[i][j];
    }

    return sum;
}
int downRight(std::vector<std::vector<int>>& grid, std::pair<int, int> cellPos)
{
    int sum{};
    int i = cellPos.first, j = cellPos.second;
    while (i + 1 < grid.size() && j + 1 < grid[i].size())
    {
        i++; j++;
        sum += grid[i][j];
    }

    return sum;
}

int checkAllDiagonals(std::vector<std::vector<int>>& grid, std::pair<int, int> cellPos)
{
    int sum{ grid[cellPos.first][cellPos.second] };
    sum += upLeft(grid, cellPos);
    sum += upRight(grid, cellPos);
    sum += downLeft(grid, cellPos);
    sum += downRight(grid, cellPos);

    return sum;
}

int main()
{
    std::ios_base::sync_with_stdio(false), std::cin.tie(0);

    int t{};
    std::cin >> t;

    while (t--)
    {
        int n{}, m{};
        std::cin >> n >> m;

        std::vector<std::vector<int>> v(n, std::vector<int>(m));
        for (auto& x : v)
            for (auto& y : x)
                std::cin >> y;

        int ans{};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int sum = checkAllDiagonals(v, {i, j});
                if (sum > ans)
                    ans = sum;
            }
        }

        std::cout << ans << '\n';
    }
}