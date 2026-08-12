#include<iostream>
#include<vector>

using namespace std;

int main(){
int t; 
cin >>t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n+1);
        for(int i = 1; i <= n; i++){
            cin >> arr[i];
        }
        vector<int> different_element(n+1,0);
        for(int i = 1; i < n; i++){
            int prev = 0;
            if(arr[i] != arr[i+1]) different_element[i+1] = i;
            else different_element[i+1] = different_element[i];
        }

        int q; 
        cin >> q;
        for(int i = 1; i <= q; i++){
            int l , r; 
            cin >> l >> r;
            int f = different_element[r];
            if(f < l) cout<< -1 << ' ' << -1 <<'\n';
            else cout << f << ' ' << f+1 << '\n';
        }
    }
    return 0;
}