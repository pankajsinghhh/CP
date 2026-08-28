#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while(t--){
        long long n, k;
        cin >>n >> k;
        
        long long groups = k /(n-1);
        long long rem = k % (n-1);

        if(rem == 0){
            cout<< groups*n-1 << '\n';
        }
        else{
            cout<< groups*n+rem << '\n';
        }
    }
}