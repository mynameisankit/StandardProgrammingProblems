#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long int UINT;
typedef long long int INT;

//This is a small improvement over brute force solution
//Time Complexity -> O(n^(1/2)) ??

void sieve_of_erastothenes(UINT n, set<UINT, less<UINT>> &primes);
UINT number_of_divisors(UINT n);

int main() {
    UINT n;
    cout << "Enter the number : ";
    cin >> n;

    cout << "\nThe number of divisors are " << number_of_divisors(n) << "\n";

    return 0;
}

UINT number_of_divisors(UINT n) {
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

        set<UINT, less<UINT>> primes;
        //log(n) time
        sieve_of_erastothenes(n, primes);

        //log(n) access time due to map being ordered
        //Pair -> Prime, Power
        map<UINT, UINT> divisors;

        UINT num = n;
        auto d = primes.begin(); 

        //TC -> ??
        while(d != primes.end() && primes.find(num) == primes.end()) {
            if(num % *d == 0) {
                if(divisors.find(*d) == divisors.end()) {
                    divisors.insert(pair<UINT, UINT>(*d, 1));
                }
                else {
                    divisors.find(*d)->second += 1;
                }
                num = num / *d;
            }
            else {
                d++;
            }
        }

        if(divisors.find(num) == divisors.end()) {
            divisors.insert(pair<UINT, UINT>(num, 1));
        }
        else {
            divisors.find(num)->second += 1;
        }

       //TC -> O(Number of Divisors)
       //Calculate Divisors
       count = 1;
       for(auto it = divisors.begin(); it != divisors.end(); it++) {
           count *= (it->second + 1);
       }
    }

    return count;
}

void sieve_of_erastothenes(UINT n, set<UINT, less<UINT>> &primes) {
    vector<bool> num(n + 1, true);

    for(UINT i = 2; i < n + 1; i++) {
        if(num[i] == true) {
            primes.insert(i);
            for(UINT j = 2*i; j < n + 1; j += i) {
                num[j] = false;
            }
        }
    }

    return;
}


/*
To print in prime factor form

string str = "";
for(auto it = divisors.begin(); it != divisors.end(); it++) {
    str += to_string(it->first) + "^" + to_string(it->second) + " ";
}
    str += "\n";
cout << str;
*/
