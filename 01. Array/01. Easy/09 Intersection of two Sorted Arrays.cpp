#include<iostream>
#include<vector>
#include<set>

using namespace std;
#define ll long long

// - Brute Force Approach
vector<int> IntersectionArr(vector<int> &arr1, vector<int> &arr2, int size1, int size2){
    vector<int> intersectionArr;
    int vis[size2] = {0};
    for(int i=0; i< size1; i++){
        for(int j=0; j< size2; j++){
            if(arr1[i] == arr2[j] && vis[j] == 0){
                intersectionArr.push_back(arr1[i]);
                vis[j] = 1;
                break;
            }

            if(arr2[j] > arr1[i]){
                break;
            }
        }
    }
    return intersectionArr;
}


// 2 - Optimmal Approach
//  2-Pointers Approach


vector<int> IntersectionArr2(vector<int> arr1, vector<int> arr2, int size1, int size2){
    int i = 0;
    int j = 0;
    vector<int> intersectionArr;
    while(i < size1 && j < size2){
        if(arr1[i] < arr2[j]){
            i++;
        }
        else if(arr1[i] > arr2[j]){
            j++;
        }
        else{
            intersectionArr.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    return intersectionArr; 
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

    vector<int> intersection = IntersectionArr2(arr1, arr2, n, m);
    for (auto & val: intersection){
        cout << val << " ";
    }
    return 0;
}
