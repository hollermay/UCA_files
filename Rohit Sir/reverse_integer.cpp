#include <iostream>
using namespace std;

int main(){
    int a = 123;
    int ans=0;
    while(a!=0){
        int d = a%10;
        
        a = a/10;
        if(ans*10+d>INT_MAX || ans*10+d<INT_MIN){
            cout<<0;
            return 0;
        }
        ans = ans*10+d;

        
    }
    cout<< ans;

    return 0;
}