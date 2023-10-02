#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main() 
{
    int arr[] = { 1, 9, 5, 4, 3, 2, 1, 0, 8, 9, 10, 10};
    int n = 12;
    int lis[n];

    for (int i = 0; i < n; i++){
        lis[i] = 1;
        for (int j = 0; j < i; j++){
            if(arr[j] < arr[i]){
                lis[i] = max(lis[j]+1,lis[i]); 
            }
        }
    }
    cout<<"Sequence : ";
    for (int i = 0; i < n; i++) cout<<lis[i]<<" ";

    cout<<endl<<"LIS : ";
    sort(lis, lis+n);
    cout<<lis[n-1]<<endl;
}