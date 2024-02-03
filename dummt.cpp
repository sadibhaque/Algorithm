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
#define ft first
#define sd second
#define ins insert
#define sadib main

#define sortv(x) sort((x).begin(),(x).end())
#define sorta(x,n) sort((x),(x)+(n))
#define revv(x) reverse((x).begin(),(x).end())
#define reva(x,n) reverse((x),(x)+(n))
#define all(x) (x).begin(),(x).end()

void solve(){
    ll n,e;
    cin>>n>>e;

    ll dis[n][n];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) dis[i][j] = 0;
            else dis[i][j] = LLONG_MAX;
        }
    }

    while(e--){
        ll x,y,z;
        cin>>x>>y>>z;

        dis[x][y] = min(dis[x][y],z);
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(dis[i][k] < LLONG_MAX && dis[k][j] < LLONG_MAX){
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
    }

    int q;
    cin>>q;

    while(q--){
        ll d,tar;
        cin>>d>>tar;

        if(dis[d][tar] == LLONG_MAX) cout<<"-1\n";
        else cout<<dis[d][tar]<<endl;
    }
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


// 4 4
// 1 2 4
// 2 3 4
// 3 1 2
// 1 2 10
// 6
// 1 2
// 2 1
// 1 3
// 3 1
// 2 3
// 3 2


