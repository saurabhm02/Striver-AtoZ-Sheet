// Problem Statement: Given an integer array arr of size N, sorted in ascending order (may contain duplicate values) 
// and a target value k. Now the array is rotated at some pivot point unknown to you. Return True if k is present and otherwise, return False. 


#include<iostream>
#include<vector>

using namespace std;
#define ll long long

// Brute Force 
// Approach -> Linear Search

// We will traverse the array and check every element if it is equal to k. If we find any element, we will return True.
// Otherwise, we will return False.

bool SearchInRotatedArray(vector<int> &arr, int target){
	int n = arr.size();
	for(int i=0; i<n; i++){
		if(arr[i] == target){
			return true;
		}
	}
	return false;
}

// Optimal Approach 
// Approach -> Binary Search

// 1) First, we identify the sorted half of the array. 
// 2) Once found, we determine if the target is located within this sorted half. 
// 		1) If not, we eliminate that half from further consideration. 
// 		2) Conversely, if the target does exist in the sorted half, we eliminate the other half.

bool SearchInRotatedArray2(vector<int>& nums, int target) {
       int n = nums.size();
       int s = 0;
       int e = n - 1;

       while(s <= e){
           int mid = s + (e - s) / 2;
           if(nums[mid] == target){
               return true;
           }

           // Corner case if starting point is same as mid and mid is same as end
           if(nums[s] == nums[mid] && nums[mid] == nums[e]){
               s++;
               e--;
               continue;
           }

           // it will check if left part is sorted
           if(nums[s] <= nums[mid]){
               if(nums[s] <= target && target <= nums[mid]){
               	 //element exists:
                   e = mid - 1;
               }
               else{
               	   //element does not exist:
                   s = mid + 1;
               }
           }

           // it will check if right part is sorted
           else{
               if(nums[mid] <= target && target <= nums[e]){
               	//element exists:
                   s = mid + 1;
               }
               else{
               	//element does not exist:
                   e = mid -1;
               }
           }
       } 
       return false;
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
	cout<<SearchInRotatedArray2(arr, target);
    return 0;
}