#include<iostream>
#include<vector>

using namespace std;
#define ll long long

// Find FLOOR
// The floor of x is the largest element in the array which is smaller than or equal to x( i.e. largest element in the array <= x).

// We will declare the 2 pointers and an ‘ans’ variable initialized to -1 (If we don’t find any index, we will return -1).

// 1) Place the 2 pointers i.e. 's' and 'e': Initially, 's' = 0 & 'e' = size - 1
// 2) Calculate the ‘mid’:  mid = ('s'+'e') // 2
// 3) Compare arr[mid] with x: With comparing arr[mid] to x, we can observe 2 different cases:
// 		1) Case 1 – If arr[mid] <= x: The index arr[mid] is a possible answer. So, we will store it and will try to find a larger number that satisfies the same condition. That is why we will remove the left half and try to find the number in the right half.
// 		2) Case 2 – If arr[mid] > x: arr[mid] is definitely not the answer and we need a smaller number. So, we will reduce the search space to the left half by removing the right half.
// The above process will continue until the pointer 's' crosses 'e'.

int findFloor(vector<int> &arr, int n, int x){
	int s = 0;
	int e = n - 1;
	int ans = -1;
	while(s <= e){
		int mid = s + (e - s) / 2;
		if(arr[mid] <= x){
			ans = arr[mid];

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


// Find Ceil of Number
// The ceiling of x is the smallest element in the array greater than or equal to x( i.e. smallest element in the array >= x).

// 1) Place the 2 pointers i.e. 's' and 'e': Initially, s = 0 & e = size - 1;
// 2) Calculate the ‘mid’: mid = ('s'+'e') / 2 

// 3) Compare arr[mid] with x: With comparing arr[mid] to x, we can observe 2 different cases:
// 		1) Case 1 – If arr[mid] >= x: This condition means that the index arr[mid] may be an answer. So, we will update the ‘ans’ variable with arr[mid] and search in the left half if there is any smaller number that satisfies the same condition. Here, we are eliminating the right half.
// 		2) Case 2 – If arr[mid] < x: In this case, arr[mid] cannot be our answer and we need to find some bigger element. So, we will eliminate the left half and search in the right half for the answer.
// The above process will continue until the pointer 's' crosses 'e'.
// int main()
int findCeil(vector<int> &arr, int n, int x){
	int s = 0;
	int e = n - 1;
	int ans = -1;

	while(s <= e){
		int mid = s + (e - s) / 2;
		if(arr[mid] >= x){
			ans = arr[mid];

			e = mid - 1;
		}
		else{
			s = mid + 1;
		}
	}
	return ans;
	// T.c : O(logn)
	// S.c : O(1)
}


int main(){

	int n;
	cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int target;
    cin>>target;
	cout<<findFloor(arr, n, target);
    return 0;
}