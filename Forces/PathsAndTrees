#include<bits/stdc++.h>
using namespace std;

const long long INF = (1LL << 60);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >>n >> m;

    vector<vector<pair<int,long long>>> adj(n+1);
    vector<tuple<int, int, long long>> edges(m);
    for(int i = 0;i < m; i++){
        int p ,v;
        long long w;
        cin >> p >> v >> w;
        adj[p].push_back({v, w});
        adj[v].push_back({p, w});
        edges[i] = {p,v,w};
    }
    int u;
    cin >> u;

    vector<long long> dist(n+1, INF);
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    dist[u] = 0;
    pq.push({0,u});
    while(!pq.empty()){
        long long wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if(wt > dist[node]) continue;

        for(const auto &it: adj[node]){
            int v = it.first;
            long long adjwt = it.second;
            if(adjwt + wt < dist[v]){
                dist[v] = adjwt + wt;
                pq.push({dist[v], v});
            }
        }
    }
    vector<int> parentEdge(n+1, -1);
    vector<long long> bestW(n+1, INF);

    for(int i = 0; i< m; i++){
        auto[a, b, w]= edges[i];

        if(dist[a] != INF && dist[a] + w == dist[b]){
            if(w < bestW[b]){
                bestW[b] = w;
                parentEdge[b] = i;
            }
        }

        if(dist[b] != INF && dist[b] + w == dist[a]){
            if(w < bestW[a]){
                bestW[a] = w;
                parentEdge[a] = i;
            }
        }
    }
    long long totalweight = 0;
    for(int i = 1; i <= n; i++){
        if(i == u) continue;
        totalweight += bestW[i];
    }
    cout<< totalweight<< '\n';
    
    for(int j = 1; j <= n; j++){
        if(j == u) continue;
        cout<< parentEdge[j] + 1 << (j == n? '\n':' ');
    }
}