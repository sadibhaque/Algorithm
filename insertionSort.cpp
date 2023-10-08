#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define llf double

void selectionSort(ll arr[], ll n){
	for (int i = 0; i < n-1; i++){
		ll temp = i;
		for (int j = i+1; j < n; j++){
			if(arr[temp]>arr[j]){
			}
		}
		
	}
}

int main()
{
	ll arr[] = { 64, 25, 12, 22, 11 };
	ll n=5;
	
	selectionSort(arr,n);
	
	for (int i = 0; i < n; i++){
		cout<<arr[i]<<" ";
	}
    return 0;
}
