#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
#define ll long long

// 1- Brute - Force Approach

int SecontLargestElement(vector<int> &Arr, int size){
	sort(Arr.begin(), Arr.end());
	int largest = Arr[size-1];
	int SecondLargest = -1;
	for(int i=size-1; i>=0; i--){
		if(Arr[i] != largest){
			SecondLargest = Arr[i];
			break;
		}
	}
	return SecondLargest;
	// T.c : O(nLogn) + O(n) = O(nlogn)
	// S.c : O(1)
}

// 2 - Better Approach
int SecondLargestElement2(vector<int> &Arr, int size){
	int largest = Arr[0];
	for(int i=1; i<size; i++){ // we start from 1 instead of 0 bcoz we store the 0 index in for largest element
		if(Arr[i] > largest){
			largest = Arr[i];
		}
	}

	int SecondLargest = -1;
	for(int i=0; i<size; i++){
		if(Arr[i] > SecondLargest && Arr[i] != largest){
			SecondLargest = Arr[i];
		}
	}
	return SecondLargest;
	// T.c : O(n) + O(n) = O(2n)
	// S.c : O(1)
}


// 3- Optimal Approach

int SecondLargestElement3(vector<int> &Arr, int size){
	int largest = Arr[0];
	int SecondLargest = -1;
	for(int i=1; i<size; i++){
		if(Arr[i] > largest){
			SecondLargest = largest;
			largest = Arr[i];
		}
		else if(Arr[i] < largest && Arr[i] > SecondLargest){
				SecondLargest = Arr[i];
		}
	}
	return SecondLargest;
    // constraints are
	// 2 ≤ 'n' ≤ 10^5
    // 0 ≤ 'a'[i] ≤ 10^9


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

    cout << SecondLargestElement3(Arr, size);
    return 0;
}