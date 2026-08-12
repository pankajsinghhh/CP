#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; 
    cin >>t;
    while(t--){
        int n; 
        cin >> n;
        vector<int> glass(n+1);
        for(int i = 1; i<=n; i++){
            cin >> glass[i];
        }
        vector<long long> prefixeven(n+1), prefixodd(n+1);
        prefixeven[1] = 0;
        prefixodd[1] = glass[1];
        for(int i = 2; i <= n; i++){
            if(i % 2 == 0) {
                prefixeven[i] = prefixeven[i-1] + glass[i];
                prefixodd[i] = prefixodd[i-1];
            }else{
                prefixodd[i]  = prefixodd[i-1] + glass[i]; 
                prefixeven[i] = prefixeven[i-1];
            }
        }

        bool found = false;
        map<long long int, int> mpp;
        mpp[0] = 1;
        for(int i = 1;i <= n; i++){
            long long a = prefixeven[i] - prefixodd[i];
            mpp[a]++;
            if(mpp[a] >= 2) { cout << "yes\n"; found = true; break; }
        }
        if(!found) cout << "no\n";
    }
    return 0;
}