// * 
// * * 
// * * * 
// * * * * 
// * * * 
// * * 
// *

#include<iostream>
using namespace std;
#define ll long long

int main()
{
	int n;
	cin>>n;

	for(int i=1; i<=2*n - 1; i++){
		int stars = i;
		if(i>n) stars = 2*n - i;
		for(int j=0; j<stars; j++){
			cout<<"* ";
		}
		cout<<endl;
	}
    return 0;
}