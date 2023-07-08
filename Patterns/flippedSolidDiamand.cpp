// **** ****
// ***   ***
// **     **
// *       *
// *       *
// **     **
// ***   ***
// **** ****

#include<iostream>
using namespace std;
#define ll long long

int main()
{
    int n;
    cin>>n;

  //--------Upper Side-------  
    for(int i=0; i<n; i++){
      //half pyramid-decreasing
      for(int j=0; j<n-i; j++){
      	cout<<"*";
      }	
     //full pyramid with space
      for(int j=0; j<2*i + 1; j++){
        cout<<" ";
      }
     //half pyramid-decreasing
      for(int j=0; j<n-i; j++){
        cout<<"*";
      }
      cout<<endl;
    }	

  //------Lower Side-------
  
    for(int i=0; i<n; i++){
     //half pyramid-increasing
      for(int j=0; j<i+1;j++){
        cout<<"*";
      }
     
     // space inverted pyramid 
      for(int j=0; j<2*n - 2*i-1; j++){
        cout<<" ";
      }
      
     //half pyramid-increasing
      for(int j=0; j<i+1;j++){
        cout<<"*";
      }
      cout<<endl;
    }  
    return 0;
}