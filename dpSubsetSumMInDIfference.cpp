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

vector <vector <bool>> dp; 
void generate(vector<int> arr, int n, int sum){
    for(int i = 0; i <=sum; i++){
        dp[0][i] = false;
    }
    dp[0][0] = true;

    for(int i = 1; i <=n; i++){
        for(int j = 0; j <=sum; j++){
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
}

void solve(){
    int n;
    cin>>n;

    vi arr(n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        sum += arr[i];
    }

    dp.resize(n + 1, vector<bool>(sum + 1));

    generate(arr,n,sum);


    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= sum; j++){
            cout<<dp[i][j]<<" ";
        }
        pend;
    }

    pend;

    vi setSums;
    int ans = INT_MAX;

    for(int i = 0; i <= sum; i++){
        if(dp[n][i] == 1){
            cout<<i<<" ";
            setSums.pb(i);
        }
    }


    for(auto it : setSums){
        int s1 = it;
        int s2 = sum - s1;
        ans = min(ans,abs(s2-s1));
    }
    pend;

    cout<<"Ans : "<<ans<<endl;
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
