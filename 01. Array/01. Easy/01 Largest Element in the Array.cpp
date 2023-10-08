#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define ll long long

// 01 - Brute-Force
int LargestElement(vector<int> &Arr, int size){
	sort(Arr.begin(), Arr.end());
	return Arr[size-1];

	// T.c : O(nLogn)
	// S.c : O(1)
}

// 02 - Better 
int LargestElement2(vector<int> &Arr, int size){
	int largest = Arr[0];
	for(int i=1; i<size; i++){ // we start from 1 instead of 0 bcoz we store the 0 index in for largest element
		if(Arr[i] > largest){
			largest = Arr[i];
		}
	}
	return largest;
}
int main() {
    int size;
    cin >> size;
    vector<int> Arr;

    for (int i = 0; i < size; i++) {
        int element;
        cin >> element;
        Arr.push_back(element);
    }

    cout << LargestElement2(Arr, size);
    return 0;
}