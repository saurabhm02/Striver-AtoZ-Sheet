//    1
//   1 2
//  1   3
// 1 2 3 4

#include<iostream>
using namespace std;
#define ll long long

int main()
{   int n;
	cin>>n;
	for(int i=0; i<n; i++){
	  // spaces
        for(int j=0; j<n-i-1; j++){
            cout<<" ";
        }
      // numbers with space in between
        int start =1;
        for(int j=0; j<2*i +1; j++){
         //first row or last row
           if(i==0 || i==n-1){
	           	if(j%2 ==0){
	           	  //even	
	           		cout<<start;
	           		start = start+1;
	           	}
	           	else{
	           	  //odd
	           		cout<<" ";
	           	}
            }
            else{
              //first or last
              if(j==0){
                cout<<1;
              }
              else if(j== 2*i+1-1){
                cout<<i+1;
              }
              else{
                cout<<" ";
              }
            }

        }
        cout<<endl;
	}
    return 0;
}