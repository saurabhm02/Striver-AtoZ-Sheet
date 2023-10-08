#include<iostream>
#include<vector>

using namespace std;
#define ll long long

// -Brute Force
// Approach - using a temp Array

//  Rotating the Elements to left
// Step 1: Copy the first k elements into the temp array.

// Step 2: Shift n-k elements from last by k position to the left

// Step 3: Copy the elements into the main array from the temp array.

void RotateLeft(int arr[], int size, int k){
	if(size == 0){
		return;
	}
	k = k % size; // boz if the k will be 9 and size is 6 so we can get proper k size
	int temp[size];

	// Step 1
	for(int i=0; i< k; i++){
		temp[i] = arr[i];
	}
    
    // step 2
	for(int i=0; i< size-k; i++){
		arr[i] = arr[i + k];
	}

    // step 3
	for(int i=size - k; i<size; i++){
		arr[i] = temp[i - (size - k)];
	}
}



// Optimal Solution
// Approach  ” Reversal Algorithm “

// Rotating Elements to left
// Step 1: Reverse the first k elements of the array

// Step 2: Reverse the last n-k elements of the array.

// Step 3: Reverse the whole array.

void Reverse(int arr[], int start, int end)
{
  while (start <= end)
  {
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
  }
}

// Function to Rotate k elements to left
void RotateeEletoleft(int arr[], int n, int k)
{
  // Reverse first k elements
  Reverse(arr, 0, k-1);
  // Reverse last n-k elements
  Reverse(arr, k, n - 1);
  // Reverse whole array
  Reverse(arr, 0, n - 1);
}
int main()
{
	int n;
	cin >> n;

    int arr[100];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int k;
    cin>>k;
    RotateeEletoleft(arr, n, k);
    
    for(int i=0; i< n; i++){
    	cout<<arr[i]<<" ";
    }
    return 0;
}