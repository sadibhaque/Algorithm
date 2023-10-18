#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll dpKnapsack(ll w[], ll p[], ll c, ll n){
    ll dp[n+1][c+1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= c; j++)
        {
            if (i == 0 || j == 0) dp[i][j] = 0;
            else if (j < w[i - 1]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], p[i - 1] + dp[i - 1][j - w[i - 1]]);
        }
    }
    return dp[n][c];
}


int main()
{

    ll w[] = {3, 3, 2, 5, 1};
    ll p[] = {10, 15, 10, 12, 8};
    ll c = 10;
    ll n = sizeof(p) / sizeof(p[0]);

    cout << dpKnapsack(w, p, c, n) << endl;

    return 0;
}
