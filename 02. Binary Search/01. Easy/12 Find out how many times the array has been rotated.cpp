#include<iostream>
#include<vector>
#include <limits.h>

using namespace std;
#define ll long long

// Brute Force Approach
// Using Linear Search

//	1) First, we will declare an ‘ans’ and an ‘index’ variable initialized with a large number and -1 respectively.
// 	2) Next, we will iterate through the array and compare each element with the variable called ‘ans’. Whenever we encounter an element ‘arr[i]’ that is smaller than ‘ans’, we will update ‘ans’ with the value of ‘arr[i]’ and also update the ‘index’ variable with the corresponding index value, ‘i’.
// 	3) Finally, we will return ‘index’ as our answer.

int findRotate(vector<int> &arr){
	int n = arr.size();
	int ans = INT_MAX;
	int index = -1;

	for(int i=0; i<n; i++){
		if(arr[i] < ans){
			ans = arr[i];
			index = i;
		}
	}
	return index;
	// T.c : O(n)
	// S.c : O(1)
}

// Optimal Solution

// To begin, we will declare the variable ‘ans’ and initialize it with the largest possible value. Additionally, we will have two pointers, ‘low’ and ‘high’, as usual. In this case, we will also introduce an ‘index’ variable and initialize it with -1.

// 1) Place the 2 pointers i.e. low and high: Initially, we will place the pointers like this: low will point to the first index and high will point to the last index.
// 2) Calculate the ‘mid’: Now, inside a loop, we will calculate the value of ‘mid’ using the following formula:
// 		mid = (low+high) // 2 ( ‘//’ refers to integer division)
// 3) If arr[low] <= arr[high]: In this case, the array from index low to high is completely sorted. Therefore, we can select the minimum element, arr[low].
// 		Now, if arr[low] < ans, we will update ‘ans’ with the value arr[low] and ‘index’ with the corresponding index low.
// 		Once this is done, there is no need to continue with the binary search algorithm. So, we will break from this step.
// 4) Identify the sorted half, and after picking the leftmost element, eliminate that half.
// 			1) If arr[low] <= arr[mid]:
// 				This condition ensures that the left part is sorted. So, we will pick the leftmost element i.e. arr[low].
// 				Now, if arr[low] < ans, we will update ‘ans’ with the value arr[low] and ‘index’ with the corresponding index low.
// 				After that, we will eliminate this left half(i.e. low = mid+1).
// 			2) Otherwise, if the right half is sorted:  This condition ensures that the right half is sorted. So, we will pick the leftmost element i.e. arr[mid].
// 				Now, if arr[mid] < ans, we will update ‘ans’ with the value arr[mid] and ‘index’ with the corresponding index mid.
// 50 After that, we will eliminate this right half(i.e. high = mid-1).
// This process will be inside a loop and the loop will continue until low crosses high. Finally, we will return the ‘index’ variable that stores the index of the minimum element.

int findRotate2(vector<int> &arr){
	int n = arr.size();
	int s = 0;
	int e = n - 1;
	int ans = INT_MAX;
	int index = -1;

	while(s <= e){
		int mid = s + (e - s) / 2;

		if(arr[s] <= arr[e]){
			if(arr[s] < ans){
				index = s;
				ans = arr[s];
			}
			break;
		}

		if(arr[s] <= arr[mid]){
			if(arr[s] < ans){
				index = s;
				ans = arr[s];
			}

			s = mid + 1;
		}
		else{
			if(arr[mid] < ans){
				index = mid;
				ans = arr[mid];
			}
			e = mid - 1;
		}
	}
	return index;
}
int main()
{
	int n;
	cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
	cout<<findRotate2(arr);
    return 0;
}