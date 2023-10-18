#include<iostream>
#include<vector>
#include <limits.h>
#include <cmath>

using namespace std;
#define ll long long

// brute force
// Approach -> Linear Search

//	1) First, we will declare a ‘mini’ variable initialized with a large number.
// 	2) After that, we will traverse the array and compare each element with the ‘mini’ variable. Each time the ‘mini’ variable will be updated with the minimum value i.e. min(mini, arr[i]).
// 	3) Finally, we will return ‘mini’ as our answer.

int  findMin(vector<int> &arr){
	int n = arr.size();
	int mini = INT_MAX;
	for(int i=0; i<n; i++){
		mini = min(mini, arr[i]);
	}
	return mini;

	// T.c : O(N)
	// S.c : O(1)
}

// Optimal Approach
//Approach -> Binary Search

// 1) First, we identify the sorted half of the array. 
// 2) Once found, we determine if the target is located within this sorted half. 
// 		1) If not, we eliminate that half from further consideration. 
// 		2) Conversely, if the target does exist in the sorted half, we eliminate the other half.


// Let’s observe how we identify the sorted half:

// We basically compare arr[mid] with arr[low] and arr[high] in the following way:

// If arr[low] <= arr[mid]: In this case, we identified that the left half is sorted.
// If arr[mid] <= arr[high]: In this case, we identified that the right half is sorted.
int findMin2(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        int e = n - 1;
        int ans = INT_MAX;
        while(s <= e){
            int mid = s + (e - s) / 2;

            // What is Search space iis already  sorted
            // then always nums[s]  be smaller
            // in that search space

            if(nums[s] <= nums[e]){
                ans = min(ans, nums[s]);
                break;
            }
            if(nums[s] <= nums[mid]){
                ans = min(ans, nums[s]);
                s = mid + 1;
            }
            else{
                e = mid - 1;
                ans = min(ans, nums[mid]);
            }
        }
        return ans;

        // T.c : O(logn)
    }


int main()
{
	int n;
	cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
	cout<<findMin2(arr);
    return 0;
}