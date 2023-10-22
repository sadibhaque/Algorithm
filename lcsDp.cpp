#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define llf double

int dplcs(string str1, string str2,int a, int b){
    ll dp[a+1][b+1];

    for (int i = 0; i <= a; i++){
        for (int j = 0; j <= b; j++){
            if(i == 0 || j == 0) dp[i][j] = 0;
            else if(str1[i-1] == str2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
        }
    }
    return dp[a][b];
}

void solve() {

    string str1,str2;
    cin>>str1>>str2;

    ll a = str1.length();
    ll b = str2.length();

    cout<<dplcs(str1,str2,a,b);
}

int main() {

    ll t;
    t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
