// * * * * 
// * * * * 
// * * * *

#include<iostream>
using namespace std;
#define ll long long

int main()
{
  int rows, columns;
  cin>>rows>>columns;

  for(int i=0; i<rows; i++){
  	for(int j=0; j<columns; j++){
  		cout<<"* ";
  	}
  	cout<<endl;
  }
   
  return 0;
}