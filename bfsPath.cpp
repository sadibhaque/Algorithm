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
vb visited(G_MAX,false);
vi parent(G_MAX);

void bfs(int src){
	queue <int> q;
	q.push(src);
	visited[src] = true;
	parent[src] = -1;
	
	while(!q.empty()){
		int par = q.front();
		q.pop();
		
		cout<<par<<" ";
		
		for(auto child : graph[par]){
			if(!visited[child]){
				q.push(child);
				visited[child] = true;
				parent[child] = par;
			}
		}
	}
}

void pathPrint(int x){
	if(x == -1){
		return;
	}
	cout<<x<<" ";
	pathPrint(parent[x]);
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
	parent.assign(n, -1);	
	
	bfs(0);
	
	pend;
	
	pathPrint(5);
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

//input 
//6 7
//0 1
//1 2
//1 3
//2 4
//2 5
//4 5
//4 3
