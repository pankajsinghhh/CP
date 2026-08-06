#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; 
    cin >> n >> q;
    
    int LOG = 0;
    while((1<<LOG) <= n) LOG++;

    vector<vector<int>> up(n+1, vector<int>(LOG, 0));

    for(int i = 2; i <= n; i++){
        cin >> up[i][0];
    }

    for(int j= 1; j < LOG; j++){
        for(int i = 1; i <= n; i++){
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }

    while(q--){
        int x, k;
        cin >> x >> k;


    }
    
}



// vector<int> boss(n+1, -1);
// for(int i = 2; i <= n; i++){
//     cin >> boss[i];
// }
// vector<vector<int>> bosslvl(n+1, vector<int>(n, -1));
// for(int i = 2;i <= n; i++) bosslvl[i][1] = boss[i];

// for(int i = 2;i <= n; i++){
//     for(int j = 2; j < n; j++){
//         bosslvl[i][j] = (bosslvl[i][j-1] != -1)? boss[bosslvl[i][j-1]] : -1;
//     }
// }
// while(q--){
//     int x , k;
//     cin >> x >> k;
    
//     cout<< bosslvl[x][k] << "\n";
// }