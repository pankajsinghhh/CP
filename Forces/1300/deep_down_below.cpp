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
    }
}