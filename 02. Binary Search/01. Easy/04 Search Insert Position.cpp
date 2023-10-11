#include<iostream>
#include<vector>

using namespace std;
#define ll long long


// We will solve this problem using the lower-bound algorithm which is basically a modified version of the classic Binary Search algorithm. 
int searchInsert(vector<int> & arr, int n, int x){
	int s = 0;
	int e = n - 1;
	int ans = n;
	while(s <= e){
		int mid = s + (e - s) / 2;
		if(arr[mid] >= x){
			ans = mid;
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
	cout<<searchInsert(arr, n, target);
    return 0;
}