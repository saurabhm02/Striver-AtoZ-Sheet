// 1
// 12
// 123
// 1234

#include<iostream>
using namespace std;
#define ll long long

int main()
{
    int size;
    cin>>size;
    for(int i=0; i<size; i++){
    	for(int j=0; j<i+1; j++){
    		cout<<j+1;
    	}
    	cout<<endl;
    }
    return 0;
}

//----------------2nd Way-------------------

// for(int i=1; i<=size; i++){
//     	for(int j=1; j<i; j++){
//     		cout<<j;
//     	}
//     	cout<<endl;
//     }