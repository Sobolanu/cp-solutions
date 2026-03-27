#include <bits/stdc++.h>
using namespace std;

const int max_n = 1e3 + 1;
/*
to calculate value at i, j:
    down -> i+1, so big before small
    dright -> i+1 and j+1
*/

/* int solve(vector<vector<int>>& a, int i, int j) {
    if(a[i][j] == -1) {
        return 0;
    }
    
    if(i == a.size() - 1) {
        return a[i][j];
    }
    
    int down = solve(a, i+1, j) + a[i][j];
    int dright = solve(a, i+1, j+1) + a[i][j];
    
    return max(down, dright);
} */

vector<int> dp_i1(max_n, 0);

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> a(n, vector<int>(n, -1));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cin >> a[i][j];
            if(i == a.size() - 1) dp_i1[j] = a[i][j];
        }
    }
    
    for(int i = n - 1; i >= 0; i--) {
        vector<int> dp_i = dp_i1;
        
        for(int j = i; j >= 0; j--) {
            if(a[i][j] == -1 || i == a.size() - 1) continue;
            
            dp_i[j] = max(dp_i1[j], dp_i1[j+1]) + a[i][j];
        }
        
        dp_i1 = dp_i;
    }
    
    cout << dp_i1[0];
}

