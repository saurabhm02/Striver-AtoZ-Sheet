
//       *       
//     *   *     
//   *       *   
// * * * * * * *

#include<iostream>
using namespace std;
#define ll long long

int main()
{
	int size;
	cin>>size;

	for(int i=0; i<size; i++){
		int k=0;
		for(int j=0; j<((2*size)-1); j++){
			if(j < size - i - 1){
				cout<<"  ";
			}
			else if(k < 2 * i + 1){
				if(k==0 || k==2*i || i==size-1){
					cout<<"* ";
				}
				else{
					cout<<"  ";
				}
				k++;
			}
			else{
				cout<<"  ";
				
			}
		}
		cout<<endl;
	}
    return 0;
}