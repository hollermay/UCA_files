#include <iostream>
using namespace std;

void reachEnd(int i, int j, int m, int n){
    if(i == m-1 && j == n-1){
        cout << i <<" " << j << endl;
        return;
    }
    cout<< i << " " << j << "->";
    if(i >= m || j >= n){
        return;
    }
    reachEnd(i+1, j, m, n);
    reachEnd(i, j+1, m, n);

}

int main(){
    int m = 3, n = 3;
    reachEnd(0, 0, m, n);
    return 0;
}

