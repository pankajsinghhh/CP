#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, t;
    cin>>n >> t;
    vector<long long> machine(n);
    for(int i = 0; i<n; i++){
        cin>> machine[i];
    }  
    long long low = 0, high = 1LL* (*min_element(machine.begin(), machine.end()))*t;
    while(low <= high){
        long long mid = low+(high-low)/2;
        long long prod = 0;
        for(int i = 0; i <n; i++){
            prod += (mid/machine[i]);
            if(prod >= t) break;
        }
        if(prod < t) low = mid+1;
        else high = mid - 1;
    }
    cout<< low << "\n";
    return 0;
}
