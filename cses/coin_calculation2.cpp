#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n>> x;
    vector<int> coins(n);

    for(int i = 0; i < n; i++){
        cin >> coins[i];
    } 

    const int MOD = 1e9 + 7;

    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    for (int j = 0; j < n; j++) {
        for (int i = coins[j]; i <= x; i++) {
            dp[i] += dp[i - coins[j]];
            if (dp[i] >= MOD) dp[i] -= MOD;
        }
    }
    cout<< dp[x] << "\n";
    return 0;
}