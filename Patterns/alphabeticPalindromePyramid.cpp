// A
// ABA
// ABCBA
// ABCDCBA

#include<iostream>
using namespace std;
#define ll long long

int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
    	int j;
    	for(j=0; j<i+1;j++){
    		int ans = j+1;
    		char ch = ans + 'A' -1;
    		cout<<ch;
    	}

      //print reverse counting	
    	for(int j=i;j>=1;j--){
    		int ans = j;
    		char ch = ans + 'A' - 1;
    		cout<<ch;
    	}
    	cout<<endl;
    }	
    return 0;
}