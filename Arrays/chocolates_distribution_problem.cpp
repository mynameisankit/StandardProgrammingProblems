#include<bits/stdc++.h>
#include<climits>

using namespace std;

int solution(void);

int main() {
    int t;
    cin >> t;

    while(t--) {
        cout << solution() << "\n";
    }

    return 0;
}

int solution(void) {
    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int m;
    cin >> m;

    sort(a, a + n);
    int min = INT_MAX;

    for(int start = 0; (start + m - 1) < n; start++) {
        if(min > a[start + m - 1] - a[start]) {
            min = a[start + m - 1] - a[start];
        }
    }

    return min;
}