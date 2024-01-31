/* " Each conquered bug is a step towards mastery. " */

#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
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
#define sorta(x,n) sort((x),(x) + (n))
#define revv(x) reverse((x).begin(),(x).end())
#define reva(x,n) reverse((x),(x)+(n))
#define all(x) (x).begin(),(x).end()

class Edge{
public:
    int u,v,c;
    Edge(int uu, int vv, int cc){
        u = uu;
        v = vv;
        c = cc;
    }
};

const int N = 1000;
int dis[N];

void solve(){
    int n,e;
    cin>>n>>e;

    vector <Edge> edgeList;
    
    for(int i = 0; i < e; i++){
        int u,v,c;
        cin>>u>>v>>c;

        edgeList.pb(Edge(u,v,c));
    }

    for(int i = 0; i < n; i++) dis[i] = INT_MAX;

    dis[0] = 0; //src = 0;
    
    for(int i = 0; i < n - 1; i++){
        for(auto it : edgeList){
            int u,v,c;
            u = it.u;
            v = it.v;
            c = it.c;

            if(dis[u] < INT_MAX && dis[u] + c < dis[v]){
                dis[v] = dis[u] + c;
            }
        }
    }

    for(int i = 0; i < n; i++) cout<<dis[i]<<" ";
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
