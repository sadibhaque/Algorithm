#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll dpCoinWays(ll coin[], ll n, ll amount){
    ll dp[n+1][amount+1];

    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= amount; j++){
            if(j == 0 && i == 0) dp[i][j] = 1;
            else if(i == 0) dp[i][j] = 0;
            else if(j<coin[i-1]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = dp[i-1][j] + (dp[i][j-coin[i-1]]);
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n][amount];
}


int main()
{
    ll coin[] = { 1, 3, 5 };
    ll n = sizeof(coin) / sizeof(coin[0]);
    ll amount = 8;
    cout << dpCoinWays(coin, n, amount);
    return 0;
}
