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

char grid[100][100];
bool visited[100][100];
int n,m;
vpi d = {{0,1},{1,0},{0,-1},{-1,0}};

bool valid(int x, int y){
	return x >= 0 && x < n && y < m && y >= 0;
}

void dfs(int x, int y){
	cout<<x<<" "<<y<<endl;
	visited[x][y] = true;
	
	for(int i = 0; i < 4; i++){
		int a = x + d[i].first;
		int b = y + d[i].second;
		
		if(valid(a,b) && !visited[a][b]){
			dfs(a,b);
		}
	}
}


void solve()
{
    cin>>n>>m;
    
    for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin>>grid[i][j];
		}
	}
	
	int x,y;
	cin>>x>>y;
	
	memset(visited,false,sizeof(visited));
	
	dfs(x,y);
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
