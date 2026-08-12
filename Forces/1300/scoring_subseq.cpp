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
        vector<int> arr(n+1);
        for(int i = 1;i <= n; i++) cin >> arr[i];
        int ans = 1;
        cout << 1;
        for(int k = 2; k <= n; k++){
            if(arr[k-ans] >= ans+1) ans++;
            cout << ' '<< ans;
        }   
        cout << '\n';
    }
}