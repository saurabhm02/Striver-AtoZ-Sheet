#include<iostream>
#include<vector>
#include<set>

using namespace std;
#define ll long long


// 1 - Brute Force Approach
// Suppose we consider arr1 and arr2 as a single array say arr, 
// then the union of arr1 and arr2 is the distinct elements in arr.

vector<int> UnionArr(vector<int> arr1, vector<int> arr2, int size1, int size2){
    set<int> st;
    vector<int> unionArr;

    for(int i=0; i<size1; i++){
        st.insert(arr1[i]);
    }
    for(int i=0; i<size2; i++){
        st.insert(arr2[i]);
    }

    for(auto it : st){
        unionArr.push_back(it);
    }

    return unionArr; 
}


// 2 - Optimmal Approach
//  2-Pointers Approach

// Approach:
//  * Take two pointers let’s say i,j pointing to the 0th index of arr1 and arr2.
//  * Create an empty vector for storing the union of arr1 and arr2.
//  *  From solution 2 we know that the union is nothing but the distinct elements in arr1 + arr2 
//  *  Let’s traverse the arr1 and arr2 using pointers i and j and insert the distinct elements found into the union vector.


vector<int> UnionArr2(vector<int> arr1, vector<int> arr2, int size1, int size2){
    int i = 0;
    int j = 0;
    vector<int> unionArr;

    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            if (unionArr.empty() || unionArr.back() != arr1[i]) {
                unionArr.push_back(arr1[i]);
            }
            i++; 
        } 
        else{
            if (unionArr.empty() || unionArr.back() != arr2[j]) {
                unionArr.push_back(arr2[j]);
            }
            j++;
        }
    }

    while (i < size1) {
        if (unionArr.empty() || unionArr.back() != arr1[i]) {
            unionArr.push_back(arr1[i]);
        }
        i++; 
    }

    while (j < size2) {
        if (unionArr.empty() || unionArr.back() != arr2[j]) {
            unionArr.push_back(arr2[j]);
        }
        j++; 
    }

    return unionArr;
}
int main()
{
    int n, m;
    cin >> n >> m; 

    vector<int> arr1(n);
    vector<int> arr2(m);
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    vector<int> Union = UnionArr2(arr1, arr2, n, m);
    for (auto & val: Union){
        cout << val << " ";
    }
    return 0;
}
