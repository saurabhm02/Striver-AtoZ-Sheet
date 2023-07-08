// 1
// 2*2
// 3*3*3
// 4*4*4*4
// 4*4*4*4
// 3*3*3
// 2*2
// 1

#include<iostream>
using namespace std;
#define ll long long

int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
    	for(int j=0; j<i+1; j++){
    		cout<<i+1;
    		if(j!=i){
    			cout<<"*";
    		}

    	}
    	cout<<endl;
    }

    for(int i=0; i<n; i++){
    	for(int j=0; j<n-i; j++){
    		cout<<n-i;
    		if(j!=n-i-1){
    			cout<<"*";
    		}

    	}
    	cout<<endl;
    }	
    return 0;
}