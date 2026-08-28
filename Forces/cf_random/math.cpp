#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; 
    cin>> t;
    while(t--){
        int n; 
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        unordered_map<long long, long long> freq;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            long long key = 1LL * a[i] - i;
            ans += freq[key];
            freq[key]++;
        }

        cout << ans << "\n";
    }
}