#include<bits/stdc++.h>

using namespace std;

string solution(void);

int main() {
    int t;
    cin >> t;

    while(t--) {
        cout << solution() << "\n";
    }

    return 0;
}

string solution(void) {
    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int sum = 0;

    for(int i = 0; i < n; i++) {
        sum = 0;
        
        for(int j = i; j < n; j++) {
            sum += a[j];

            if(sum == 0) {
                return "Yes";
            }
        }
    }

    return "No";
}