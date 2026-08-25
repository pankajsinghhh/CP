#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int best = 1;
        if(k >= n) cout << 1 << '\n';
        else{
            for (int i = 1; i * i <= n; i++) {
                if (n % i == 0) {
                    if (i <= k) best = max(best, i);
                    if (n / i <= k) best = max(best, n / i);
                }
           }
           cout << n / best << '\n';
        }
        
    }
    return 0;
}