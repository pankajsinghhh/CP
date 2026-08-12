#include<iostream>
#include<vector>

typedef long long ll;
using namespace std;

ll solve(ll m, ll k){
    if(m < k) return m * (m+1)/2;
    ll extra = m - k;
    return (k*(k+1)/2) + extra*k - extra*(extra+1)/2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    cin >>t;

    while(t--){
        ll k , x;
        cin >> k >> x;
        if(k*k < x){
            cout << 2*k - 1<< '\n';
            continue;
        }
        ll low = 1, high = 2*k-1, ans = 2*k-1;
        while(low <= high){
            ll mid = (low + high)/2;

            if(solve(mid, k) >= x){
                ans = mid;
                high = mid - 1;
            }
            else low = mid+1;
        }
        cout << ans << '\n';
    }
}