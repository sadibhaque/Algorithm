#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll dpCoinMin(ll coin[], ll n, ll amount){
    ll dp[n+1][amount+1];

    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= amount; j++){
            if(i == 0) dp[i][j] = j;
            else if(j < coin[i-1]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = min(dp[i-1][j], (1+ dp[i][j-coin[i-1]]));
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n][amount];
}


int main()
{
    ll coin[] = {9, 6, 5, 1};
    ll n = sizeof(coin) / sizeof(coin[0]);
    ll amount = 11;
    cout << dpCoinMin(coin, n, amount);
    return 0;
}
