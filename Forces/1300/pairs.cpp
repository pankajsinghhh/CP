#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; 
    cin >>t;
    while(t--){
        int n; 
        cin >> n;
        vector<long long> arr(n+1);
        for(int i = 1; i <= n; i++){
            cin >> arr[i];
        }
        vector<long long> v;
        long long ans = 0; 
        for(int i = 1; i <= n; i++){
            if(i <= arr[i]) continue;
            ans += (long long)(lower_bound(v.begin(), v.end(), arr[i]) - v.begin());
            v.push_back(i);
        }
        cout << ans <<'\n';
    }
}
