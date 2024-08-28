#include <iostream>
#include <vector>
using namespace std;


vector<int> fibonacci(int n){
    vector<int> arr(n,0);
    if (n >= 1) arr[0] = 0;
    if (n >= 2) arr[1] = 1;

    for(int i =2;i<n;i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
    


    return arr;
}

int even_sum(vector<int> arr){
    int ans =0;
    for(int i=2;i< arr.size();i++){
        if (arr[i]%2 == 0) ans+=arr[i];
    }

    return ans;
}

int main(){
    int n; cin>>n;
    vector<int> ans = fibonacci(n);

    int a = even_sum(ans);

    cout<<a;



    return 0;
}


