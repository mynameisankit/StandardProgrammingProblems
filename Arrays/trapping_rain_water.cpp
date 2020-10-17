//Link - https://www.geeksforgeeks.org/trapping-rain-water/

#include<bits/stdc++.h>
#include<climits>

using namespace std;

int main() {
    
    int *arr, n;
    
    cout << "\nEnter the size of the elevation map : ";
    cin >> n;

    arr = new int[n];

    cout << "\nEnter the elements of the elevation map : ";

    for(int i = 0; i < n ; i++) {
        cin >> arr[i];
    }

    int rainwater = 0;

    int start = 0, end, max;

    while(start < n - 1) {
        max = INT_MIN;
        
        for(int i = start + 1; i < n; i++) {
            //For subsets like 1, 0, 0, 2
            if(arr[i] >= arr[start]) {
                end = i;
                break;
            }
            //For subsets like 3, 0, 0, 0, 1
            else if(max < arr[i]) {
                max = arr[i];
                end = i;
            }
        }

        if(arr[end] >= arr[start]) {
            for(int i = start + 1; i < end; i++) {
                rainwater += (arr[start] - arr[i]);
            }
        }
        else {
            for(int i = end - 1; i > start; i--) {
                rainwater += (arr[end] - arr[i]);
            }
        }

        start = end;
        //cout << "\nHELLO, New Start = " << start << "\n";
    }    

    cout << "\nThe amount of rainwater that can be collected is : " << rainwater << "\n\n";

    delete arr;

    return 0;
}
