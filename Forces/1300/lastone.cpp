#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int smallest_divisor(int n){
    int d = 1;
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0){
            d = i;
            break;
        }
    }
    return d;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n; 
        cin >> n;
        int sd = smallest_divisor(n);
        if(sd == 1){
            cout << 1 << ' ' << n-1 << '\n';
        }
        else{
            int a = n / sd;
            int b = n - a;
            cout << a <<' '<< b <<'\n';
        }
    }
}