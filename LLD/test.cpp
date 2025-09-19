#include<bits/stdc++.h>
using namespace std;

void increment(int &a) {
    a = a + 1; // HERE
    cout << "a in increment " << a << endl;
}

int* myFunc() {
    int* phantom = new int(4);
    return phantom;
}

int main() {
    cout<<myFunc();
} 