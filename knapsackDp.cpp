#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int knapsack(ll x, ll n, ll w[], ll p[]){
    ll mat[n+1][x+1];

    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= x; j++){
            if(i == 0 || j == 0) mat[i][j] = 0;
            else if(j < w[i-1]) mat[i][j] = mat[i-1][j];
            else mat[i][j] = max(mat[i-1][j] ,  p[i-1]+ mat[i-1][j-w[i-1]]);
        }
    }
    return mat[n][x];
}

int main() {
    ll w[] = {20,10,30},p[] = {32,9,93};
    ll n = sizeof(w)/sizeof(w[0]);
    ll cap = 25;

    cout<<knapsack(cap,n,w,p)<<endl;

    return 0;
}