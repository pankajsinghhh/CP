#include<bits/stdc++.h>
using namespace std;

vector<int> find_distance(int node, vector<vector<int>> &edges, int n){
    vector<int> dist(n+1, -1);
    dist[node] = 0;
    queue<int> q;
    q.push(node);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v: edges[u]){
            if(dist[v] == -1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}

int main(){
    int n; 
    cin>> n;

    vector<vector<int>> edges(n+1);
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin>> a>> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    vector<int> dist1 = find_distance(1, edges, n);
    int A = max_element(dist1.begin()+1, dist1.end()) - dist1.begin();
    vector<int> dist2 = find_distance(A, edges, n);
    int diameter = *max_element(dist2.begin(), dist2.end());
    
    cout<< diameter<< "\n";

    return 0;
}