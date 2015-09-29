#include <cstdio>
#include <vector>
#include <iostream>
#define FOR(i,a,b)  for(int i=a;i<b;i++)
// #define MOD     (int)(1e9+7)
#include <algorithm>


int calccc(int n){
    int dp[n][3];
    dp[0][0] = dp[0][2] = 1; dp[0][1] = 0;  

    //0 means noting
    // 1 means left 
    // 2means right
    int x, y, z;
    for(int i = 1; i < n ; i++){
        dp[i][1] = dp[i- 1][1] + dp[i-1][0];
        dp[i][0] = dp[i][1];
        dp[i][2]= dp[i-1][2];
    }
    // dp[n-1][0] = 
    return  dp[n - 1][0] + dp[n - 1][1];
    // return 0;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    std:: ios::sync_with_stdio(false);
    int MOD = 1000000007;
    int t, n; std :: cin >> t;
    std :: vector<int> v;
    while(t--){
        std :: cin>> n;
        v.push_back(n);
        // calc(n);
    }
    long long int tr = 0;
    FOR(i, 0 ,v.size()) {
        if(v[i] == 1) tr = 1; else if(v[i] == 2) tr = 6; else {tr = 6;for(int j = 3; j < (v[i] + 1); j++) {tr = tr*3 + 1; tr %= MOD;} } 
        // std :: cout << v[i] <<tr << calccc(v[i]) << std ::endl;
        printf("%lld\n", (tr  - calccc(v[i])) %MOD); }
    return 0;
}
