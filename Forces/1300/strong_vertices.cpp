#include<bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin>> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n+1), b(n+1);
        for(int i = 1;i <= n; i++){
            cin >> a[i];
        }
        for(int i = 1;i <= n; i++){
            cin >> b[i];
        }

        int maxi = INT_MIN;
        int cnt = 0;
        for(int i = 1;i <= n; i++){
            int l = a[i] - b[i];
            if(l == maxi)cnt++;
            if(l > maxi){
                cnt = 1;
                maxi = l;
            }
        }
        cout << cnt << '\n';  

        for(int i = 1; i <= n; i++)                 
            if(a[i] - b[i] == maxi) cout << i << ' ';
        cout << '\n';
    }
}