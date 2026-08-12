#include<iostream>
#include<vector>
using namespace std;
int cnt;
string s;

int dfs(int node, vector<vector<int>>& edges){
    int bal = (s[node-1] == 'W')? 1 : -1;
    for(int child: edges[node]){
        bal += dfs(child, edges);
    }
    if(bal == 0) cnt++;
    return bal;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    cin >>t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> edges(n+1);
        for(int i = 2; i <= n; i++){
            int a;
            cin >> a;
            edges[a].push_back(i);
        }
        cin >> s;
        cnt = 0;
        dfs(1, edges);
        cout << cnt << '\n';
    }
}