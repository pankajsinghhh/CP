#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;   
    cin >>t;

    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> k(n+1), c(m+1);

        for(int i = 0;i < n; i++){
            cin >> k[i];
        }
        for(int j = 1;j <= m; j++){
            cin >> c[j];
        }
        int cnt = 1;
        long long cost = 0;
        sort(k.begin(), k.end(), greater<int>());
        for(int i = 0; i < n; i++){
            if(cnt > k[i]) cost += c[k[i]];
            else{
                cost += c[cnt]; 
                cnt++;
            }
        }
        cout << cost <<'\n';
    }
}