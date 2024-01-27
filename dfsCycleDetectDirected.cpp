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

const int N = 1000; 
vi graph[N];
bool vis[N];

bool path[N];
bool ans = false;

void dfs(int par){
	vis[par] = true;
	path[par] = true;
	
	for(auto it : graph[par]){
		if(path[it]){
			ans = true;
		}
		if(!vis[it]){
			dfs(it);
		}
	}
	
	path[par] = false;
}

void solve(){
	int v,e;
	cin>>v>>e;
	
	for(int i = 0; i < e; i++){
		int x,y;
		cin>>x>>y;
		
		graph[x].pb(y);
	}
	
	memset(vis,false,sizeof(vis));
	memset(path,false,sizeof(path));
	ans = false;
	for(int i = 0; i < v; i++){
		if(!vis[i]) dfs(i);
	}
	
	if(ans) py;
	else pn;
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
