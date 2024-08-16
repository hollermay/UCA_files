// 14.08.2024 Ritesh sir's question

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[10] = {0,0,1,1,1,1,2,2,0,3};
    int n = 10;
    // map approach
    // map<int,int> mpp;

    // for(int i:arr){
    //     mpp[i]++;
    // }

    // for(auto &it: mpp){
    //     if(it.second%2 != 0){
    //         cout<<it.first<<endl;
    //     }

    // }
    
    //bit manipulation approach

    for (int i : arr) {
        int index = abs(i);
        if (index < n) { 
            arr[index] *= -1; 
        }
    }

    for (int i : arr) {
        int index = abs(i);
        if (index < n && arr[index] < 0) { 
            cout << index << endl;
            arr[index] = abs(arr[index]);
        }
    }
    return 0;
}