#include<iostream>
#include<vector>
using namespace std;

const int M = 1e9+7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, k; 
    cin >> t >> k;

    vector<pair<int,int>> queries(t);
    int maxB = 0;
    for(int i = 0;i < t; i++){
        cin >> queries[i].first >> queries[i].second;
        maxB = max(maxB, queries[i].second);
    }
    vector<long long> dp(maxB+1);
    dp[0] = 1;
    for(int i = 1;i <= maxB; i++){
        long long red = dp[i-1];
        long long white = (k <= i? dp[i-k] : 0);
        dp[i] = (red + white) % M;
    }

    vector<long long> prefix(maxB+1);
    for(int i = 1; i <= maxB; i++){
        prefix[i] = (prefix[i-1] + dp[i]) % M;
    }
    for(auto [a,b]:queries){
        cout<< (prefix[b] - prefix[a-1] + M) % M << '\n';
    }
}