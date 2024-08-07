#include<iostream>
using namespace std;

int main(){
    int n =3;
    int arr[n] = {1,2,0};
    int start = 0, mid;
    int end = n;

    while(start<end){
        mid = (start+end)/2;
        if(arr[mid]<arr[mid+1]){
            start = mid+1;
        }
        else end = mid;
    }

    cout<<arr[start];

    return 0;
}