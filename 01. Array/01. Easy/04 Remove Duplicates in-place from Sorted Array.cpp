#include<iostream>
#include<vector>
#include <set>

using namespace std;
#define ll long long

// Brute Force
// Intuition: We have to think of a data structure that does not store duplicate elements. So can we use a Hash set? Yes! We can. As we know HashSet only stores unique elements.

// Approach: 

// Declare a HashSet.
// Run a for loop from starting to the end.
// Put every element of the array in the set.
// Store size of the set in a variable K.
// Now put all elements of the set in the array from the starting of the array.
// Return K.

int removeDuplicate(vector<int> &arr, int size){
	set<int> set;
	for(int i=0; i< size; i++){
		set.insert(arr[i]);
	}
	int index = 0;
	for(auto it : set){
		arr[index] = it;
		index++;
	}
	return set.size();

	// T.c : O(nlogn) - bcoz of set STL
	// S.c : O(n) - if all elements are unique then set will have to store n elements andit tkes n space
	
}


// Optimal Solution

// Two pointers - Approach
// Intuition: We can think of using two pointers ‘i’ and ‘j’, we move ‘j’ till we don’t get 
// a number arr[j] which is different from arr[i]. As we got a unique number we will increase
//  the i pointer and update its value by arr[j]. 

// Approach:
// Take a variable i as 0;
// Use a for loop by using a variable ‘j’ from 1 to length of the array.
// If arr[j] != arr[i], increase ‘i’ and update arr[i] == arr[j].
// After completion of the loop return i+1, i.e size of the array of unique elements.


int removeDuplicate2(vector<int> &arr, int size){
	int i=0;
	for(int j=1; j< size; j++){
		if(arr[i] != arr[j]){
			i++;
			arr[i] = arr[j];
		}
	}
	return i + 1;

	// T.c : O(n)
	// S.c : O(1)
}



int main()
{
	int size;
    cin >> size;
    vector<int> Arr;

    for (int i = 0; i < size; i++) {
        int element;
        cin >> element;
        Arr.push_back(element);
    }
    int result = removeDuplicate2(Arr, size);
    cout <<"size of unique arr element is "<< removeDuplicate2(Arr, size)<<endl;

     for (int i = 0; i < result; i++) {
    cout << Arr[i] << " ";
  }
    return 0;
}