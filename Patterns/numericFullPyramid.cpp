//    1
//   232
//  34543
// 4567654

#include<iostream>
using namespace std;
#define ll long long

int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
      // spaces
        for(int j=0; j<n-i-1; j++){
            cout<<" ";
        }
      //numers
        for(int j=0; j<i+1; j++){
            cout<<i+j+1;
        }
      //reverse counting
        int start = 2*i;
        for(int j=0; j<i; j++){
        	cout<<start;
        	start = start - 1;
        }  
        cout<<endl;
    }
    return 0;
}