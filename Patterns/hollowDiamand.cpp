//    *
//   * *
//  *   *
// *     *
// *     *  
//  *   *  
//   * *  
//    *

#include<iostream>
using namespace std;
#define ll long long

int main()
{   int size;
	cin>>size;

	for(int i=0; i<size; i++){
     // Spaces		
		for(int j=0; j<size-i-1; j++){
			cout<<" ";
		}
     // Stars

		for(int j=0; j<2*i+1; j++){
			if(j==0 || j==2*i){
				cout<<"*";
			}
			else{
				cout<<" ";
			}
		}
		cout<<endl;
	}

 // inverted------
	for(int i = 0; i < size; i++) {
        // for spaces
        for(int j = 0; j < i; j++) {
            cout <<" ";
        }

        // for asterisks and spaces
        for(int j=0; j<((2*size)-(2*i-1)); j=j+1){
            if(j == 0 || j== 2*size-2*i-2) {
                cout <<"*";
            }
            else {
                cout <<" ";
            }
        }

        cout << endl;
    }
	
    return 0;
}


//------------------2nd Way--------------------


// #include<iostream>
// using namespace std;
// #define ll long long

// int main()
// {
// 	int size;
// 	cin>>size;

// 	for(int i=0; i<size; i++){
// 		int k=0;
// 		for(int j=0; j<((2*size)-1); j++){
// 			if(j < size - i - 1){
// 				cout<<"  ";
// 			}
// 			else if(k < 2 * i + 1){
// 				if(k==0 || k==2*i){
// 					cout<<"* ";
// 				}
// 				else{
// 					cout<<"  ";
// 				}
// 				k++;
// 			}
// 			else{
// 				cout<<"  ";
// 			}
// 		}
// 		cout<<endl;
// 	}
//     return 0;
// }