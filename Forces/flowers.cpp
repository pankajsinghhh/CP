#include<bits/stdc++.h>
using namespace std;

int solve(int n){
    if(n == 0) return 1;
    int sum = 0;
    if(n >= k) sum += solve(n-k);
    sum += solve(n-1);
    return sum;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, k;
    cin >> t >> k;
    while(t--){
        int a, b;
        cin >> a >> b;
        int ways = 0;
        for(int i = a; i < b; i++){
            ways += solve(i);
        }
        cout<< ways<< nline;
    }
}