#include<bits/stdc++.h>
using namespace std;
#define int long long
 
signed main(){
    int n; cin>>n;
    const int modulo = 1e9 + 7;
    int dp[n+1];
    for(int i = 1; i <= n; i++) dp[i] = 0;
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 6; j++){
            if(j > i) break;
            dp[i] += dp[i - j];
            dp[i] %= modulo;
        }
    }
    
    cout<<dp[n] % modulo<<endl;
}
