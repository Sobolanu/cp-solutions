#include <bits/stdc++.h>
using namespace std;


/*
not my code, this is editorial

i did a sol with binary search but it didn't wanna work for whatever reason
and i am NOT debugging the 1162nd number of the test case that fails.
I got the idea though - prefix sums and whatnot.
*/

#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;

void setIO() {
    ios_base::sync_with_stdio(0); cin.tie(0);
}

int main(){
    setIO();
    int T;
    cin >> T;
    for(int tt = 1; tt <= T; tt++){
        int n;
        cin >> n;
        pii arr[n + 1];
        for(int i = 1; i <= n; i++) cin >> arr[i].ff, arr[i].ss = i;
        sort(arr + 1, arr + n + 1);
        int nxt[n + 1];
        ll sum[n + 1];
        int ans[n + 1];
        nxt[0] = sum[0] = 0;
        for(int i = 1; i <= n; i++){
            if(nxt[i - 1] >= i){
                nxt[i] = nxt[i - 1];
                sum[i] = sum[i - 1];
            } else {
                sum[i] = sum[i - 1] + arr[i].ff;
                nxt[i] = i;
                while(nxt[i] + 1 <= n && sum[i] >= arr[nxt[i] + 1].ff){
                    nxt[i]++;
                    sum[i] += arr[nxt[i]].ff;
                }
            }
            ans[arr[i].ss] = nxt[i];
        }
        for(int i = 1; i <= n; i++) cout << ans[i] - 1 << " ";
        cout << endl;
    }
}
