// * * * * *
// *       *
// *       *
// * * * * *

#include<iostream>
using namespace std;
#define ll long long
int main()
{
  int rows, columns;
  cin>>rows>>columns;

  for(int i=0; i<rows; i++){
  	if(i==0 || i==rows-1){
  		for(int j=0; j<columns; j++){
        cout<<"* ";
      }
  	}
  	else{
  		cout<<"* ";
  		for(int j=0; j<columns-2; j++){
  			cout<<"  ";
  		}
  		cout<<"* ";
  	} 
    cout<< endl;
  }  
  return 0;
}

//------------Alternate Code-------------------- 

// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define Int unsigned int

// int main()
// {
//   Int rows, columns;
//     cin >> rows >> columns;

//     for (int i = 0; i < rows; i++) {
//         for (int j = 0; j < columns; j++) {
//             if (i == 0 || i == rows - 1 || j == 0 || j == columns - 1) {
//                 cout << "* ";
//             } else {
//                 cout << "  ";
//             }
//         }
//         cout << endl;
//     } 
//   return 0;
// }