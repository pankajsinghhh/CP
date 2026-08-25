#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;   
    cin >>n;
    int k = n/2;
    if(n % 2 == 0){
        cout << (k+1)*(k+1) << '\n';

    }
    else{
        cout << (k+1)*2*(k+2) << '\n';
    }
    return 0;
}