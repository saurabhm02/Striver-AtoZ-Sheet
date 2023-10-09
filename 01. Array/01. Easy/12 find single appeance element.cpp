#include<iostream>
#include<vector>

using namespace std;
#define ll long long


// Brute-force approach
// Intuition:
// For every element present in the array, we will do a linear search and count the occurrence. If for any element, the occurrence is 1, we will return it.

// Approach:
// The steps are as follows:

// First, we will run a loop(say i) to select the elements of the array one by one.
// For every element arr[i], we will perform a linear search using another loop and count its occurrence.
// If for any element the occurrence is 1, we will return it.

int getSingleElement(vector<int> &arr) {
    // Size of the array:
    int n = arr.size();

    //Run a loop for selecting elements:
    for (int i = 0; i < n; i++) {
        int num = arr[i]; // selected element
        int cnt = 0;

        //find the occurrence using linear search:
        for (int j = 0; j < n; j++) {
            if (arr[j] == num)
                cnt++;
        }

        // if the occurrence is 1 return ans:
        if (cnt == 1) return num;
    }

    //This line will never execute
    //if the array contains a single element.
    return -1;

    // T.c : O(n2)
    // S.c : O(1)
}



// Optimal Approach(Using XOR): 
// Intuition:
// Two important properties of XOR are the following:

// XOR of two same numbers is always 0 i.e. a ^ a = 0. ←Property 1.
// XOR of a number with 0 will result in the number itself i.e. 0 ^ a = a.  ←Property 2

// Approach:
// We will just perform the XOR of all elements of the array using a loop and the final XOR will be the answer.
int getSingleElement2(vector<int> &arr) {
    //size of the array:
    int n = arr.size();

    // XOR all the elements:
    int xorr = 0;
    for (int i = 0; i < n; i++) {
        xorr = xorr ^ arr[i];
    }
    return xorr;

    // t.c : O(n)
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
    
	cout<<getSingleElement(arr);
    return 0;
}