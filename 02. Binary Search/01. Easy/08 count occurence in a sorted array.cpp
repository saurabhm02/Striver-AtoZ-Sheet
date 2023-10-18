#include<iostream>
#include<vector>

using namespace std;
#define ll long long


// Brute force
// Approach -> linearlyy Search

// The approach is simple. We will linearly search the entire array, and try to increase the counter
 // whenever we get the target value in the array. Using a for loop that runs from 0 to n – 1, containing 
 // an if the condition that checks whether the value at that index equals target. If true then increase the 
 // counter, at last return the counter.

int totalOccurrence(vector<int> &arr, int n, int target){
	int count = 0;
	for(int i=0; i<n; i++){
		if(arr[i] == target){
			count++;
		}
	}
	return count;
}

// OPtimal SOlution
// Approach -> Binary Search

// 1) We will get the first and the last occurrences of the number using the function firstAndLastPosition(). For the implementation details of the function, please refer to the previous article.
// 2) After getting the indices, we will check the following cases:
// 		1) If the first index == -1: This means that the target value is not present in the array. So, we will return 0 as the answer.
// 		2) Otherwise: We will find the total number of occurrences like this:
// 			The total number of occurrences  = (last index – first index + 1) and return this length as the answer.


int firstOccurence(vector<int> &arr, int n, int target){
	int s = 0;
	int e = arr.size() - 1;
	int ans = -1;

	while(s <= e){
		int mid = s + (e - s) / 2;
		if(arr[mid] == target){
			ans = mid;
			e = mid - 1;
		}
		else if(arr[mid] < target){
			s = mid + 1;
		}
		else{
			e = mid - 1;
		}
	}
	return ans;
	// T.c : O(logn)
	// S.c : O(1)
}


int lasttOccurence(vector<int> &arr, int n, int target){
	int s = 0;
	int e = arr.size() - 1;
	int ans = -1;

	while(s <= e){
		int mid = s + (e - s) / 2;
		if(arr[mid] == target){
			ans = mid;
			s = mid + 1;
		}
		else if(arr[mid] < target){
			s = mid + 1;
		}
		else{
			e = mid - 1;
		}
	}
	return ans;

	// T.c : O(logn)
	// S.c : O(1)
}

int totalOccurrence2(vector<int> &arr, int n, int target){
	int firOcc = firstOccurence(arr, n, target);
	int lastOcc = lasttOccurence(arr, n, target);

	if(firOcc != -1 && lastOcc != -1){
		int totalOcc = lastOcc - firOcc + 1;
		return totalOcc;
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
	cout<<totalOccurrence2(arr, n, target);
    return 0;
}