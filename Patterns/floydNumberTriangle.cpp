// 1
// 23
// 456
// 78910
// 1112131415

#include<iostream>
using namespace std;
#define ll long long

int main()
{
    int n;
    cin>>n;
    int num = 1;
    for(int i=1; i<=n; i++){
    	for(int j=1; j<=i; j++){
    		cout<<num;
    		num = num + 1;
    	}
    	cout<<endl;
    }	
    return 0;
}