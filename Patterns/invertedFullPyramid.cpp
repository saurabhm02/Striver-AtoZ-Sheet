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


//--------------------2nd Way-------------

// for(int i=0; i<size; i++){
//         for(int j=0; j<i; j++){
//             cout<<" ";
//         }
//         for(int j=0; j<size-i;j++){
//             cout<<"* ";
//         }
//         cout<<endl;
// }