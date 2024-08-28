#include <iostream>
#include <stack>
using namespace std;
void towerOfHanoi(int n, stack<int>& source, stack<int>& auxiliary, stack<int>& destination) {
    if (n > 0) {
        // Move n-1 disks from source to auxiliary peg
        towerOfHanoi(n - 1, source, destination, auxiliary);

        // Move the nth disk from source to destination peg
        int disk = source.top();
        source.pop();
        destination.push(disk);
        cout << "Move disk " << disk << " from source to destination" << endl;

        // Move the n-1 disks from auxiliary peg to destination peg
        towerOfHanoi(n - 1, auxiliary, source, destination);
    }
}

int main() {
    int n = 3; // Number of disks

    stack<int> source, auxiliary, destination;

    // Push disks onto the source peg
    for (int i = n; i >= 1; --i) {
        source.push(i);
    }

    towerOfHanoi(n, source, auxiliary, destination);

    return 0;
}