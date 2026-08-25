#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;   
    cin >>t;

    while(t--){
        int n, W;
        cin >> n >> W;
        vector<int> cnt(21, 0);
        for(int i = 0; i < n; i++){
            int x; 
            cin >> x;

            cnt[log2(x)]++;
        }

        int boxes = 0;
        while(n > 0){
            int space = W;
            for(int i = 20; i >= 0; i--){
                int width = (1 << i);
                if(width <= space && cnt[i] > 0){
                    int take = min(cnt[i], space/width);
                    cnt[i] -= take;
                    n -= take;
                    space = space - (take * width);
                }
            }
            boxes++;
        }
        cout<< boxes << '\n';
    }
}