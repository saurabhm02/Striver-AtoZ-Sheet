#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define Int unsigned int

int main()
{
  Int rows, columns;
  cin>>rows>>columns;

  for(int i=0; i<rows; i++){
  	for(int j=0; j<columns; j++){
  		cout<<"* ";
  	}
  	cout<<endl;
  }
   
  return 0;
}