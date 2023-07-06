// * * * * 
// * * * 
// * * 
// *

#include<iostream>
using namespace std;
#define ll long long

int main()
{	
	int size;
	cin>>size;
	for(int i=0; i<size; i++){
		for(int j=0; j<size-i; j++){
			cout<<"* ";
		}
		cout<<endl;
	}
    return 0;
}