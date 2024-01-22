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
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<ps> vps;

#define py cout<<"YES\n"
#define pn cout<<"NO\n"
#define pend cout<<"\n"
#define pctr cout<<ctr<<endl;
#define psum cout<<sum<<endl;
#define pans cout<<ans<<endl;
#define ptmp cout<<tmp<<endl;

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

const ll G_MAX = 1005;
vi graph[G_MAX];
vi level(G_MAX, -1);
vb visited(G_MAX,false);

void bfs(int v){
	queue <int> q;
	q.push(v);
	visited[v] = true;
	level[v] = 0;

	while(!q.empty()){
		int par = q.front();
		q.pop();
		
		for(auto child : graph[par]){
			if(!visited[child]){
				q.push(child);
				visited[child] = true;
				level[child] = level[par] + 1;
			}
		}
	}
}

void solve(){
	int n,e;
	cin>>n>>e;
	
	for(auto it : graph) it.clear();
	
	for(int i = 0; i < e; i++){
		int x,y;
		cin>>x>>y;
		
		graph[x].pb(y);
		graph[y].pb(x);
	}
	
	visited.assign(n, false);	
	level.assign(n, 0);	
	
	int l;
	cin>>l;
	
	bfs(0);
	
	vi ans;
	
	for(int i = 0; i < n; i++){
		if(level[i] == l) ans.pb(i);
	}
	
	sortv(ans);
	revv(ans);
	
	for(auto it : ans) cout<<it<<" ";
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
