//There is an integer array arr sorted in ascending order (with distinct values).

#include<iostream>
#include<vector>

using namespace std;
#define ll long long

// Brute Force Approach
// Approach -> Linear Search

// We will traverse the array and check every element if it is equal to k. If we find any element, we will return its index.
// Otherwise, we will return -1.

int SearchInRotatedArray(vector<int> &arr, int n, int target){
	for(int i=0; i<n; i++){
		if(arr[i] == target){
			return i;
		}
	}
	return -1;
	// T.c : O(n)
	// S.c : O(1)
}

// Optimal Solution
// Approach ->Binary Search

// 1) First, we identify the sorted half of the array. 
// 2) Once found, we determine if the target is located within this sorted half. 
// 		1) If not, we eliminate that half from further consideration. 
// 		2) Conversely, if the target does exist in the sorted half, we eliminate the other half.

int SearchInRotatedArray2(vector<int>& nums,int n, int target) {
        int s = 0;
        int e = n - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target) {
                return mid;
            }

            // Handle duplicates at the beginning and end
            while (s < mid && nums[s] == nums[mid]) {
                s++;
            }

            while (mid < e && nums[mid] == nums[e]) {
                e--;
            }

            // Check if left part is sorted
            if (nums[s] <= nums[mid]) {
                if (nums[s] <= target && target < nums[mid]) {
                    e = mid - 1;
                } 
                else {
                    s = mid + 1;
                }
            } 
            
            else { // Right part is sorted
                if (nums[mid] < target && target <= nums[e]) {
                    s = mid + 1;
                }
                 else {
                    e = mid - 1;
                }
            }
        }
        return -1;
    }

int main()
{
	int n;
	cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int target;
    cin>>target;
	cout<<SearchInRotatedArray2(arr, n, target);
    return 0;
}