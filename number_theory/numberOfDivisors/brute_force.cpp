#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long int UINT;
typedef long long int INT;

//This is a brute force solution
//Time Complexity -> O(n)

int main() {
    UINT n;
    cout << "\nEnter the number : ";
    cin >> n;

    UINT count;

    if(n == 0) {
        count = 0;
    }
    else if(n == 1) {
        count = 1;
    }
    else if(n == 2) {
        count = 2;
    }
    else {
        count = 2;

        for(UINT i = 2; i < n; i++) {
            if(n % i == 0) {
                count++;
            }
        }
    }

    cout << "\nThe number of divisors are " << count << "\n\n";

    return 0;
}