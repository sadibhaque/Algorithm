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
vpi graph[N];
int dis[N];

void dijakstra(int src){
	queue <pi> q;
	q.push({src,0});
	dis[src] = 0;
	
	while(!q.empty()){
		pi tmp = q.front();
		int ver = tmp.f;
		int cost = tmp.s;
		q.pop();
		
		
		for(auto it : graph[ver]){
			int chVer = it.f;
			int chCost = it.s;
			
			if(cost + chCost < dis[chVer]){
				dis[chVer] = cost + chCost;
				q.push({chVer,cost + chCost});
			}
		}
	}
}

void solve(){
	int v,e;
	cin>>v>>e;
	
	for(int i = 0; i < e; i++){
		int x,y,z;
		cin>>x>>y>>z;
		
		graph[x].pb({y,z});
		graph[y].pb({x,z});
	}
	
	for(int i = 0; i < v; i++) dis[i] = INT_MAX;
	
	dijakstra(0);
	
	for(int i = 0; i < v; i++){
		cout<<i<<" : "<<dis[i]<<endl;
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
