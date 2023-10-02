#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define llf double

int main(){
	ll cap = 10;
	ll w[] = {2, 5, 7, 3, 1};
	ll p[] = {10, 20, 30, 5, 2};
    ll x = sizeof(w)/sizeof(w[0]);

    llf ratio[x];
    for (int i = 0; i < x; i++){
        ratio[i] = (llf)p[i] / w[i];
    }

	for (int i = 0; i < x-1; i++){
		if(ratio[i+1] > ratio[i]){
            swap(w[i],w[i+1]);
            swap(p[i],p[i+1]);
        }
	}

    int temp = 0;
    llf total_profit = 0;
    for (int i = 0; i < x; i++){
        if(temp + w[i] <= cap){
            total_profit += p[i];
            temp += w[i];
        }
        else total_profit += (ratio[i]*(cap-temp));
    }

    printf("%.3lf",total_profit);
}