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

const int N = 1e5+5;
int par[N];
int sz[N];
int level[N];

void init(int n){
    for(int i = 0; i < n; i++){
        par[i] = -1;
        sz[i] = 1;
        level[i] = 0;
    }
}

int find(int node){
    if(par[node] == -1){
        return node;
    }

    int leader =  find(par[node]);
    par[node] = leader;

    return leader;
}

void make_union(int x, int y){
    int l1 = find(x);
    int l2 = find(y);

    par[l2] = l1; 
}

void make_union_by_size(int x, int y){
    int l1 = find(x);
    int l2 = find(y);

    if(sz[l1] > sz[l2]){
        par[l2] = l1;
        sz[l1] += sz[l2];
    }
    else{
        par[l1] = l2;
        sz[l2] += sz[l1];
    }
}

void make_union_by_rank(int x, int y){
    int l1 = find(x);
    int l2 = find(y);

    if(level[l1] > level[l2]){
        par[l2] = l1;
    }
    else if(level[l2] > level[l1]){
        par[l1] = l2;
    }
    else{
        par[l1] = l2;
        level[l2]++;
    }
}

void solve(){
    init(7);

    make_union_by_size(1,2);
    make_union_by_size(2,3);

    make_union_by_size(4,5);
    make_union_by_size(5,6);

    make_union_by_size(1,4);

    for(int i = 1; i <=6; i++){
        cout<<"Parent of "<<i<<"= "<<find(i)<<endl;
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
