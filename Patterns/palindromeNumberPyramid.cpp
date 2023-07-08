// 1
// 121
// 12321
// 1234321

#include<iostream>
using namespace std;
#define ll long long

int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
    	int j;
    	for(j=0; j<i+1;j++){
    		cout<<j+1;
    	}
    	j = j-1;

      //print reverse counting	
    	for(;j>=1;j--){
    		cout<<j;
    	}
    	cout<<endl;
    }	
    return 0;
}