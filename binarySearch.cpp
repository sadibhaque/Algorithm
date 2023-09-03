#include <bits/stdc++.h>

using namespace std;


int binarySearch(int arr[],int key,int n,int low,int high){
    int mid = (high+low)/2;
    if(arr[mid] == key){
        return mid;
    }
    else if(key > arr[mid]){
        low = mid+1;
        return binarySearch(arr,key,low,mid,high);
    }
    else{
        high = mid-1;
        return binarySearch(arr,key,low,mid,high);
    }

}

int main() {

    int key= 444;

    int arr[] = {1,22,330,444,550,634,799};

    int n =sizeof(arr)/sizeof(arr[0]);

    int low = 0, high = n-1;

    int ans = binarySearch(arr,key,n,low,high);

    cout<<"Key at index : "<<ans<<endl;

    return 0;
}