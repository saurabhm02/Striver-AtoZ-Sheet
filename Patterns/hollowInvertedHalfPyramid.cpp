// * * * * * 
// *     *   
// *   *     
// * *       
// *

#include<iostream>
using namespace std;
#define ll long long

int main()
{
    int size;
    cin>>size;
    for(int i=0; i<size; i++){
    	for(int j=0; j<size; j++){
    		if(i==0 || j==0 || j==size-i-1){
    			cout<<"* ";
    		}
    		else{
    			cout<<"  ";
    		}
    	}
    	cout<<endl;
    }	
    return 0;
}