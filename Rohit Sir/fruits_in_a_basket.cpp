#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main(){
    vector<int> arr = {1,2,1};

    unordered_map<int,int> mpp;

        int bucket1 = 0;
        int bucket2 = 0;
        int max_fruits =0;
    
        for(int i=0;i<arr.size();i++){
            if(mpp.find(arr[i])==mpp.end()){
                mpp[arr[i]] = 1;
                bucket1 = arr[i];
            }else{
                mpp[arr[i]]++;
                bucket2 = arr[i];
            }
            max_fruits = max(max_fruits,mpp[bucket1]+mpp[bucket2]);
        }
        cout<<max_fruits;

}