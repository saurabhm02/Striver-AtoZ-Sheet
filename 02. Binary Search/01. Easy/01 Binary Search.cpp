#include<iostream>
#include<vector>

using namespace std;
#define ll long long


int search(vector<int>& nums, int target) {
    int start = 0;
    int end = nums.size() -1;
    while(start<=end){
        int mid = start + (end - start) / 2;
        if(nums[mid] == target){
            return mid;
        }
        else if(nums[mid] < target ){
            start = mid + 1;
        }
        else{
            end = mid - 1;
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
    int target;
    cin>>target;
	cout<<search(arr, target);
    return 0;
}