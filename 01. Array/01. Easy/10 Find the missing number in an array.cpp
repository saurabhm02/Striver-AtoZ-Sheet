// 268. Missing Number
// https://leetcode.com/problems/missing-number/description/

#include<iostream>
#include<vector>

using namespace std;
#define ll long long
// Brute-force approach:
// Intuition: For each number between 1 to N, we will try to find it in the given array using linear search. And if we don’t find any of them, we will return the number.

// Approach: 

// The algorithm steps are as follows:

// We will run a loop(say i) from 1 to N.
// For each integer, i, we will try to find it in the given array using linear search.
// For that, we will run another loop to iterate over the array and consider a flag variable to indicate if the element exists in the array. Flag = 1 means the element is present and flag = 0 means the element is missing.
// Initially, the flag value will be set to 0. While iterating the array, if we find the element, we will set the flag to 1 and break out from the loop.
// Now, for any number i, if we cannot find it, the flag will remain 0 even after iterating the whole array and we will return the number.

int missingNumber(vector<int>&a, int N) {

    // Outer loop that runs from 1 to N:
    for (int i = 1; i <= N; i++) {

        // flag variable to check
        //if an element exists
        int flag = 0;

        //Search the element using linear search:
        for (int j = 0; j < N - 1; j++) {
            if (a[j] == i) {

                // i is present in the array:
                flag = 1;
                break;
            }
        }

        // check if the element is missing
        //i.e flag == 0:

        if (flag == 0) return i;
    }

    // The following line will never execute.
    // It is just to avoid warnings.
    return -1;
}


// Better Approach (using Hashing):
// Intuition:
// Using the hashing technique, we will store the frequency of each element of the given array. Now, the number( i.e. between 1 to N) for which the frequency will be 0, will be returned. Refer to the article link to know more about hashing.

// Approach:
// The algorithm steps are as follows:

// The range of the number is 1 to N. So, we need a hash array of size N+1 (as we want to store the frequency of N as well).
// Now, for each element in the given array, we will store the frequency in the hash array.
// After that, for each number between 1 to N, we will check the frequencies. And for any number, if the frequency is 0, we will return it.


int missingNumber2(vector<int>&a, int N) {

    int hash[N + 1] = {0}; //hash array

    // storing the frequencies:
    for (int i = 0; i < N - 1; i++)
        hash[a[i]]++;

    //checking the freqencies for numbers 1 to N:
    for (int i = 1; i <= N; i++) {
        if (hash[i] == 0) {
            return i;
        }
    }

    // The following line will never execute.
    // It is just to avoid warnings.
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
    
	cout<<missingNumber2(arr, n);
    return 0;
}