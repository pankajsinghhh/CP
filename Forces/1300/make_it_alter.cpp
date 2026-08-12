#include<bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int maxn = 200005;
    vector<long long> fact(maxn);
    fact[0] = 1;
    for(int i = 1;i < maxn; i++) fact[i] = fact[i-1] * i % MOD;

    int t; 
    cin >>t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        int len = 1;
        long long ans = 0, ways = 1;

        for(int i = 0;i < n-1; i++){
            if(s[i] == s[i+1]) len++;
            else{
                ans = ans + (len-1);
                ways = (ways * len)% MOD;
                len = 1;
            }
        }
        ans = ans + (len-1);
        ways = (ways * len) % MOD;

        ways = ways * fact[ans] % MOD;
        cout << ans << ' ' << ways << '\n';
    }
}