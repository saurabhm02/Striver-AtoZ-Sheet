// * * * * *
// * * * * *      
// * * * * *
// * * * * *

#include<iostream>
using namespace std;
#define ll long long
int main()
{
	int rowColumn;
	cin>>rowColumn;
	for(int i=0 ;i<rowColumn; i++){
		for(int j=0; j<rowColumn;j++){
			cout<<"* ";
		}
		cout<<endl;
	}
  return 0;
}