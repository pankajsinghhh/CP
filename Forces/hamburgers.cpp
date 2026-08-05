#include<bits/stdc++.h>
using namespace std;

long long cntb = 0, cnts = 0, cntc = 0;
long long nb, ns, nc;
long long pb, ps, pc;

long long cost(long long x){
    long long needb = max(0LL, x*cntb - nb);
    long long needs = max(0LL, x*cnts - ns);
    long long needc = max(0LL, x*cntc - nc);
    return (needb*pb + needs*ps + needc*pc);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;

    cin>> nb>> ns>> nc;

    cin>> pb>> ps>> pc;

    long long r; 
    cin >> r;

    for(long long i = 0; i < s.size(); i++){
        if(s[i] == 'B') cntb++;
        else if(s[i] == 'C') cntc++;
        else cnts++;
    }
    long long ans = 0;
    long long lo = 0, high = 2e9;
    while(lo <= high){
        long long mid = lo + (high - lo)/2;
        if(cost(mid) <= r){
            ans = mid;
            lo = mid+1;
        }
        else high = mid-1;
    }
    cout<< ans<< "\n";
    return 0;
}