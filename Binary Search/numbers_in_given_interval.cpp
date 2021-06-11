#include<bits/stdc++.h>

using namespace std;

int findLowerNum(vector<int> &arr, int l, int r, int start, int end) {
    int min_num = INT_MAX, min_idx = -1;
    int start_idx = start;
    int end_idx = end;

    int mid;
    while(start_idx < end_idx) {
        mid = start_idx + (end_idx - start_idx)/2;

        if(arr[mid] >= l && arr[mid] <= r) {
            if(min_num >= arr[mid]) {
                min_num = arr[mid];
                min_idx = mid;
            }

            end_idx = mid - 1;
        }
        else if(arr[mid] < l) {
            start_idx = mid + 1;
        }
        else if(arr[mid] > r) {
            end_idx = mid - 1;
        }
    }

    if(start_idx == end_idx && arr[start_idx] >= l && arr[start_idx] <= r) {
        if(min_num >= arr[start_idx]) {
            min_num = arr[start_idx];
            min_idx = start_idx;
        }
    }

    return min_idx;
}

int findUpperNum(vector<int> &arr, int l, int r, int start, int end) {
    int max_num = INT_MIN, max_idx = -1;
    int start_idx = start;
    int end_idx = end;

    int mid;
    while(start_idx < end_idx) {
        mid = start_idx + (end_idx - start_idx)/2;

        if(arr[mid] >= l && arr[mid] <= r) {
            if(max_num <= arr[mid]) {
                max_num = arr[mid];
                max_idx = mid;
            }

            start_idx = mid + 1;
        }
        else if(arr[mid] < l) {
            start_idx = mid + 1;
        }
        else if(arr[mid] > r) {
            end_idx = mid - 1;
        }
    }

    if(start_idx == end_idx && arr[start_idx] >= l && arr[start_idx] <= r) {
        if(max_num <= arr[start_idx]) {
            max_num = arr[start_idx];
            max_idx = start_idx;
        }
    }

    return max_idx;
}

int main() {
    vector<int> array{1, 2, 3, 4, 5, 6, 7, 8};

    int min_idx, min_num;
    min_idx = findLowerNum(array, 9, 10, 0, array.size() - 1);
    min_num = array[min_idx];

    int max_idx, max_num;
    max_idx = findUpperNum(array, 9, 10, 0, array.size() - 1);
    max_num = array[max_idx];

    if(min_idx != -1) {
        cout << "array[" << min_idx << "] : " << min_num << "\n";
    }
    if(max_idx != -1) {
        cout << "array[" << max_idx << "] : " << max_num << "\n";
    }

    return 0;
}