#include<iostream>
#include<vector>

using namespace std;
#define ll long long

// Brute force Approach
// by Using XOR 

// ) We will declare an ‘ans’ variable initialized with 0.
// 2) We will traverse the array and XOR each element with the variable ‘ans’.
// 3) After complete traversal, the ‘ans’ variable will store the single element and we will return it.

int singleNonDuplicate(vector<int> &arr){
	int n = arr.size();
	int ans = 0;

	for(int i=0; i<n; i++){
		ans = ans ^ arr[i];
	}
	return ans;
	// T.c : O(n)
	// S.c : O(1)
}


// Optimal Solution
// Using Binary Search

// 1) If n == 1: This means the array size is 1. If the array contains only one element, we will return that element only.
// 2) If arr[0] != arr[1]: This means the very first element of the array is the single element. So, we will return arr[0].
// 3) If arr[n-1] != arr[n-2]: This means the last element of the array is the single element. So, we will return arr[n-1].
// 4) Place the 2 pointers i.e. low and high: Initially, we will place the pointers excluding index 0 and n-1 like this: low will point to index 1, and high will point to index n-2 i.e. the second last index.
// 5) Calculate the ‘mid’: Now, inside a loop, we will calculate the value of ‘mid’ using the following formula:
// 	    mid = (low+high) // 2 ( ‘//’ refers to integer division)
// 6) Check if arr[mid] is the single element:
// 		If arr[mid] != arr[mid-1] and arr[mid] != arr[mid+1]: If this condition is true for arr[mid], we can conclude arr[mid] is the single element. We will return arr[mid].
// 7) If (mid % 2 == 0 and arr[mid] == arr[mid+1])
// 		or (mid%2 == 1 and arr[mid] == arr[mid-1]): This means we are in the left half and we should eliminate it as our single element appears on the right. So, we will do this:
// 		low = mid+1.
// 8) Otherwise, we are in the right half and we should eliminate it as our single element appears on the left. So, we will do this: high = mid-1.

int singleNonDuplicate2(vector<int> &arr){
	int n = arr.size();

	if(n == 1){
		return arr[0];
	}
	if(arr[0] != arr[1]){
		return arr[0];
	}
	if(arr[n - 1] != arr[n - 2]){
		return arr[n - 1];
	}

	int s = 1;
	int e = n - 2;
	while(s <= e){
		int mid  = s + (e - s) / 2;

		if(arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]){
			return arr[mid];
		}

		if((mid % 2 == 0 && arr[mid] == arr[mid + 1]) || mid % 2 == 1 && arr[mid] == arr[mid - 1]){
			s = mid + 1;
		}
		else{
			e = mid - 1;
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
	cout<<singleNonDuplicate2(arr);
    return 0;
}