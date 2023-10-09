#include<iostream>
#include<vector>

using namespace std;
#define ll long long


// Brute Force Approach
// By using 3-nested Loop

// Approach:
// The steps are as follows:

// 1) First, we will run a loop(say i) that will select every possible starting index of the subarray. The possible starting indices can vary from index 0 to index n-1(n = size of the array).
// 2) Inside the loop, we will run another loop(say j) that will signify the ending index of the subarray. For every subarray starting from the index i, the possible ending index can vary from index i to n-1(n = size of the array).
// 3) After that for each subarray starting from index i and ending at index j (i.e. arr[i….j]), we will run another loop to calculate the sum of all the elements(of that particular subarray).
// 4) If the sum is equal to k, we will consider its length i.e. (j-i+1). Among all such subarrays, we will consider the maximum length by comparing all the lengths.

int LongestSubArray(vector<int> &arr, ll k){
	int len = 0;
	for(int i=0; i<arr.size(); i++){
		for(int j=i; j<arr.size(); j++){
			ll sum = 0;
			for(int k=i; k<= j; k++){
				sum = sum + arr[k];
			}

			if(sum == k){
				len = max(len, j - i + 1);
			}
		}
	}

	return len;

	// T.c : O(n^3) approax
	// S.c : O(1)
}



// Optimal Solution 
// Approach - By using 2-pointer Approach

// Approach:
// The steps are as follows:

// 1) First, we will take two pointers: left and right, initially pointing to the index 0.
// 2) The sum is set to a[0] i.e. the first element initially.
// 3) Now we will run a while loop until the right pointer crosses the last index i.e. n-1.
// 4) Inside the loop, we will do the following:
// 		1) We will use another while loop and it will run until the sum is lesser or equal to k.
// 			1) Inside this second loop, from the sum, we will subtract the element that is pointed by the left pointer and increase the left pointer by 1.
//      2) After this loop gets completed, we will check if the sum is equal to k. If it is, we will compare the length of the current subarray i.e. (right-left+1) with the existing one and consider the maximum one.
// 		3) Then we will move forward the right pointer by 1. If the right pointer is pointing to a valid index(< n) after the increment, we will add the element i.e. a[right] to the sum.
// 5) Finally, we will return the maximum length.

int LongestSubArray2(vector<int> &arr, ll k){
	int l = 0;
	int r = 0;
	int n = arr.size();

	ll sum = arr[0];
	int maxLen = 0;

	while(r < n){

		 // if sum > k, reduce the subarray from left
        // until sum becomes less or equal to k:
		while(l <= r && sum > k){
			sum = sum - arr[l];
			l++;
		}
 		
 		 // if sum = k, update the maxLen i.e. answer:
		if(sum == k){
			maxLen = max(maxLen, r - l + 1);
		}

		// Move forward thw right pointer:
		r++;
		if(r < n){
			sum +=  arr[r];
		}
	}
	return maxLen;
}
int main()
{
	int n;
	cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    ll k;
    cin>>k;
    
	cout<<LongestSubArray2(arr, k);
    return 0;
}