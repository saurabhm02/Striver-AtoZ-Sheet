#include<iostream>
#include<vector>

using namespace std;
#define ll long long

// Brute force Approach
// Approach -> Linear Search

// 1) As the array is already sorted, start traversing the array from the start using a for loop and check whether the element is present or not.
// 2) If the target element is present, break out of the loop and print the resulting index.
// 3) If the target element is not present inside the array, then print -1

int firstOccurence(vector<int> &arr, int n, int target){
	for(int i=0; i< n; i++){
		if(arr[i] == target){
			return i;
			break;
		}
	}
	return -1;
	// T.c : O(n)
	// S.c : O(1)
}

// Optimal Approach 
// Approach -> Binary Search

// If the mid element is equal to the key value, store the mid-value in the result and move the end pointer to mid - 1(move rightward)
// Else if the key value is less than the mid element then end= mid-1(move leftward)
// Else do start = mid+1 (move rightwards)

int firstOccurence2(vector<int> &arr, int n, int target){
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
	cout<<firstOccurence2(arr, n, target);
    return 0;
}