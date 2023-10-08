#include<iostream>
#include<vector>

using namespace std;
#define ll long long

int check(vector<int> &arr, int size){
	for(int i=1; i<size; i++){
		if(arr[i] >= arr[i-1]){

		}
		else{
			return false;
		}
	}
	return true;
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

    cout << check(Arr, size);
    return 0;
}
