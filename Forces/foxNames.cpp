#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include <tuple>
#include <climits>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> adj(26);
    vector<int> indegree(26, 0);
    vector<string> str(n);
    vector<vector<bool>> edge(26, vector<bool>(26, false));

    for(int i = 0; i < n; i++){
        cin>> str[i];
    }

    bool impossible = false;

    for(int i = 0; i < n-1 && !impossible; i++){
        string s1 = str[i];
        string s2 = str[i+1];
        int minlength = min(s1.size(), s2.size());
        bool founddiff = false;
        for(int j = 0; j < minlength ; j++){
            if(s1[j] != s2[j]){
                if(!edge[s1[j]-'a'][s2[j]-'a']){
                    edge[s1[j]-'a'][s2[j]-'a'] = true;
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    indegree[s2[j]-'a']++;
                }
                founddiff = true;
                break;
            }
            
        }
        if(!founddiff && s1.size()> s2.size()){
                impossible = true;
        }
    }

    if(impossible){
        cout<< "Impossible"<<"\n";
        return 0;
    }

    queue<int> q;

    for(int c = 0; c < 26; c++){
       if(indegree[c] == 0) q.push(c);
    }
    vector<char> result;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        result.push_back('a' + node);

        for(int adjnode: adj[node]){
            indegree[adjnode]--;
            if(indegree[adjnode] == 0) q.push(adjnode);
        }
    }

    if(result.size() < 26){
        cout<< "Impossible"<<'\n';
        return 0;
    }

    for(char c: result){
        cout<<c;
    }
    cout<<'\n';

    return 0;
}