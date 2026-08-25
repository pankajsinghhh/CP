#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >>t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int>> caves;
        for(int i = 1; i <= n; i++){
           vector<int> v;
           int m ; cin >> m;
           for(int j = 0; j < m; j++){
            int x ; cin >> x;
            v.push_back(x-j+1);
           }
           sort(v.begin(), v.end());
           caves.push_back({v[m-1], m});
        }
        sort(caves.begin(), caves.end());
        int ans = caves[0].first;
        int increase = caves[0].second;
        for(int i = 1; i < n; i++){
            ans = max(ans , caves[i].first - increase);
            increase += caves[i].second;
        }
        cout<< ans<< '\n';
    }
}