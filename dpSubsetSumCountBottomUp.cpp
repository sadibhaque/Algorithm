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

// int generate(vi arr, int n, int target){
//     if(n == 0){
//         if(target == 0){
//             return 1;
//         }
//         else return 0;
//     }

//     if(arr[n-1] <= target){
//         return generate(arr,n-1,target - arr[n-1]) + generate(arr,n-1,target);
//     }
//     else return generate(arr,n-1,target);
// }

int generate(vi arr, int n, int target){
    int dp[n+1][target+1];

    for(int i = 0; i <=n; i++){
        for(int j = 0; j <=target; j++){
            dp[i][j] = 0;
        }
    }

    for(int i = 1; i <=n; i++){
        dp[0][i] = 0;
    }

    dp[0][0] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= target; j++){
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j] + dp[i-1][j - arr[i-1]];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    for(int i = 0; i <=n; i++){
        for(int j = 0; j <=target; j++){
            cout<<dp[i][j]<<" ";
        }
        pend;
    }

    return dp[n][target];
}

void solve(){
    int n;
    cin>>n;

    vi arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    int target;
    cin>>target;

    int ans = generate(arr,n,target);

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
