#include <bits/stdc++.h>
#include<climits>

using namespace std;

int main() {
	
	int t;
	cin >> t;
	
    int n;
	int *arr;
	
	while((t--) > 0) {
	    cin >> n;
	    
	    arr = new int[n];
	    
	    for(int i = 0; i < n; i++) {
	        cin >> arr[i];
	    }

        int steps = 0, curr_pos = 0;

        while(curr_pos < n - 1) {
            
            if(curr_pos + arr[curr_pos] >= n - 1) {
                curr_pos = n - 1;
                steps++;
                break;
            }
            else if(arr[curr_pos] == 0) {
                steps = -1;
                break;
            }
            else {
                int temp, max_index;
                temp = max_index = curr_pos;

                while(temp <= curr_pos + arr[curr_pos]) {
                    if(temp + arr[temp] > max_index + arr[max_index]) {
                        max_index = temp;
                    }
                    temp++;
                }

                if(curr_pos == max_index) {
                    curr_pos += arr[curr_pos];
                    steps++;
                }
                else {
                    steps += 2;
                    curr_pos = max_index + arr[max_index];
                }
            }
        }
	    
	    cout << steps << "\n";
	    
	    delete arr;
	}
	
	return 0;
}