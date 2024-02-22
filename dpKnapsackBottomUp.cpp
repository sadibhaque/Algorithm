/* Each conquered bug is a step towards mastery. */

#include "bits/stdc++.h"
using namespace std;

typedef long long int ll;
typedef long double ld;

typedef pair<int,int> pi;
typedef pair<string,int> ps;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<ps> vps;

#define py cout<<"YES\n"
#define pn cout<<"NO\n"
#define pend cout<<"\n"
#define pctr cout<<ctr<<"\n";
#define psum cout<<sum<<"\n";
#define pans cout<<ans<<"\n";
#define ptmp cout<<tmp<<"\n";

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define ins insert
#define sadib main

#define sortv(x) sort((x).begin(),(x).end())
#define sorta(x,n) sort((x),(x)+(n))
#define revv(x) reverse((x).begin(),(x).end())
#define reva(x,n) reverse((x),(x)+(n))
#define all(x) (x).begin(),(x).end()

int knapsack(int* w, int* v, int t, int n){
    int dp[n+1][t+1];

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= t; j++){
            if(i == 0 || j == 0) dp[i][j] = 0;
            else if(w[i-1] <= j) dp[i][j] = max(dp[i-1][j] , v[i-1] + dp[i-1][j - w[i-1]]);
            else dp[i][j] = dp[i-1][j];
        }
    }

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= t; j++){
            cout<<dp[i][j]<<" ";
        }
        pend;
    }

    return dp[n][t];
}

void solve(){
    int n,t;
    cin>>n>>t;

    int w[n],v[n];
    for(int i = 0; i < n; i++){
        cin>>w[i];
    }
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }

    int ans = knapsack(w,v,t,n);

    pans;

}

int sadib(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
