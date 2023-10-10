#include<iostream>
#include<vector>

using namespace std;
#define ll long long

// Brute Force Approach
// Approach -> By using Linear Search

// Let’s understand how we can find the answer using 
// the linear search algorithm. With the knowledge that
// the array is sorted, our approach involves traversing the array
// starting from the beginning. During this traversal, each element will be 
// compared with the target value, x. The index, i, where the condition arr[i] > x is first satisfied, will be the answer.
 
int upperBound(vector<int> &arr, int n, int x){
	for(int i=0; i<n; i++){
		if(arr[i] > x){
			return i;
		}
	}
	return n;
	// T.c : O(n)
	// S.c : O(1)
}


// Optimal Solution
// Approach -> By using Binary Search

// As the array is sorted, we will apply the Binary Search algorithm to find the index. The steps are as follows:

// We will declare the 2 pointers and an ‘ans’ variable initialized to n i.e. the size of the array(as If we don’t find any index, we will return n).

// 1) Place the 2 pointers i.e. 's' and 'e': Initially, we will place the pointers like this: 's' will point to the first index and 'e' will point to the last index.
// 2) Calculate the ‘mid’: Now, we will calculate the value of mid using the following formula:
// 	   mid = ('s'+'e') // 2 ( ‘//’ refers to integer division)
// 3) Compare arr[mid] with x: With comparing arr[mid] to x, we can observe 2 different cases:
// 		1) Case 1 – If arr[mid] > x: This condition means that the index mid may be an answer. So, we will update the ‘ans’ variable with mid and search in the 's' half if there is any smaller index that satisfies the same condition. Here, we are eliminating the right half.
// 		2) Case 2 – If arr[mid] <= x: In this case, mid cannot be our answer and we need to find some bigger element. So, we will eliminate the left half and search in the right half for the answer.
// The above process will continue until the pointer 's' crosses 'e'.


int upperBound2(vector<int> &arr, int n, int x){
	int s = 0;
	int e = n - 1;
	int ans = n;

	while(s <= e){
		int mid = s + (e - s) / 2;

		if(arr[mid] > x){
			ans = mid;
			e = mid - 1;
		}
		else{
			s = mid + 1;
		}
	}
	return ans;
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
	cout<<upperBound2(arr, n, target);
    return 0;
}