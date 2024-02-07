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

const int N = 1000;
int par[N];
int sz[N];

void init(int n){
    for(int i = 0; i < n; i++){
        par[i] = i;
        sz[i] = 1;
    }
}

int find(int n){
    if(par[n] == n){
        return n;
    }

    return par[n] = find(par[n]);
}

void makeUnion(int x, int y){
    int a = find(x);
    int b = find(y);

    if(sz[a] > sz[b]){
        par[b] = a;
        sz[a] += sz[b];
    }
    else{
        par[a] = b;
        sz[b] += sz[a];
    }
}

class Edge{
public:
    int u,v,c;

    Edge(int u, int v, int c){
        this -> u = u;
        this -> v = v;
        this -> c = c;
    }
};

bool cmp(Edge a, Edge b){
    return a.c < b.c;
}

void solve(){
    int v,e;
    cin>>v>>e;

    init(v);

    vector <Edge> list;
    while(e--){
        int u,v,c;
        cin>>u>>v>>c;

        list.pb(Edge(u,v,c));
    }

    sort(all(list),cmp);

    int ans = 0;

    for(auto it : list){
        int x = find(it.u);
        int y = find(it.v);

        if(x == y) continue;
        else{
            makeUnion(it.u,it.v);
            ans += it.c;
        }
    }

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
