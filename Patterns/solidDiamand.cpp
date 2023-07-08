//       *       
//     * * *     
//   * * * * *   
// * * * * * * * 
// * * * * * * * 
//   * * * * *   
//     * * *     
//       *

#include<iostream>
using namespace std;
#define ll long long

int main()
{
	int size;
	cin>>size;

// Upper Pyramid	
    for(int i=0; i<size; i++){
  // Space
		for(int j=0; j<size-i-1; j++){
			cout<<"  ";
	 	}
  // Star
		for(int j=0; j<2*i+1; j++){
			cout<<"* ";
		}
  // Space
		for(int j=0; j<size-i-1; j++){
			cout<<"  ";
	 	}
		cout<<endl;
	}

// Lower Pyramid
	for(int i=0; i<size; i++){
      //space  
        for(int j=0; j<i; j++){
            cout<<"  ";
        }

      //Stars  
        for(int j=0; j<2*size - (2*i + 1);j++){
            cout<<"* ";
        }

      //Space
        for(int j=0; j<i;j++){
            cout<<"  ";
        } 
        cout<<endl;
    }


  
    return 0;
}


// ---------------2nd Way------------------

// // Full Pyramid
// 	for(int i=0; i<size; i++){
// 		for(int j=0; j<size-i-1; j++){
// 			cout<<" ";
// 		}

// 		for(int j=0; j<i+1; j++){
// 			cout<<"* ";
// 		}
// 		cout<<endl;
// 	}
//   // inverted Pyramid
// 	for(int i=0; i<size; i++){
//     	for(int j=0; j<i; j++){
//     		cout<<" ";
//     	}
//     	for(int j=0; j<size-i;j++){
//     		cout<<"* ";
//     	}
//     	cout<<endl;
//     }