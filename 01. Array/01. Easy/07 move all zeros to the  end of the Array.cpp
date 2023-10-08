#include<iostream>
#include<vector>

using namespace std;
#define ll long long

// Brute Force
// Approach: 
// The extremely naive solution, we can think of, involves the use of an extra array. The algorithm is as follows.

// Algorithm:
// Suppose, there are N-X zeros and X non-zero elements in the array. We will first copy those X non-zero elements from the original array to a temporary array. 
// Then, we will copy the elements from the temporary array one by one and fill the first X places of the original array. 
// The last N-X places of the original array will be then filled with zero. Now, our task is completed.

vector<int> moveZeros(vector<int> a, int n) {
    //temporary array:
    vector<int> temp;
    //copy non-zero elements
    //from original -> temp array:
    for (int i = 0; i < n; i++) {
        if (a[i] != 0)
            temp.push_back(a[i]);
    }

    // number of non-zero elements.

    //copy elements from temp
    //fill first nz fields of
    //original array:
    for (int i = 0; i < temp.size(); i++) {
        a[i] = temp[i];
    }

    //fill rest of the cells with 0:
    for (int i = temp.size(); i < n; i++) {
        a[i] = 0;
    }
    return a;

    // T.c : O(2n) = O(n)
		//      O(N) + O(X) + O(N-X) ~ O(2*N), where N = total no. of elements,
		// X = no. of non-zero elements, and N-X = total no. of zeros.
		// Reason: O(N) for copying non-zero elements from the original to the temporary array. O(X) for again copying it back from the temporary to the original array. O(N-X) for filling zeros in the original array. So, the total time complexity will be O(2*N).


    // S.c : O(n)
		//     as we are using a temporary array to solve this problem and the maximum size of the array can be N in the worst case.
		// Reason: The temporary array stores the non-zero elements. In the worst case, all the given array elements will be non-zero.
}


// Optimal Approach(Using 2 pointers): 
// We can optimize the approach using 2 pointers i.e. i and j. The pointer j will point to the first 0 in the array and i will point to the next index.

// Assume, the given array is {1, 0, 2, 3, 2, 0, 0, 4, 5, 1}. Now, initially, we will place the 2-pointers like the following:

// The algorithm will be the following.

// Algorithm:
// First, using a loop, we will place the pointer j. If we don’t find any 0, we will not perform the following steps.
// After that, we will point i to index j+1 and start moving the pointer using a loop.
// While moving the pointer i, we will do the following:
// If a[i] != 0 i.e. a[i] is a non-zero element: We will swap a[i] and a[j]. Now, the current j is pointing to the non-zero element a[i]. So, we will shift the pointer j by 1 so that it can again point to the first zero.
// Finally, our array will be set in the right manner.

vector<int> moveZeros2(vector<int> a, int n) {
    int j = -1;
    //place the pointer j:
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            j = i;
            break;
        }
    }

    //no non-zero elements:
    if (j == -1) return a;

    //Move the pointers i and j
    //and swap accordingly:
    for (int i = j + 1; i < n; i++) {
        if (a[i] != 0) {
            swap(a[i], a[j]);
            j++;
        }
    }
    return a;

    // T.c : O(n)
    	// Reason: We have used 2 loops and using those loops, we are basically traversing the array once.

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
    vector<int> ans = moveZeros(arr, n);
    for (auto &it : ans) {
        cout << it << " ";
    }


    return 0;
}