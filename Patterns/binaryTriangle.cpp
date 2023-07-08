// 1
// 01
// 101
// 0101

#include<iostream>
using namespace std;
#define ll long long

int main()
{
	int n;
	cin>>n;
	int num=1;
	for(int i=0; i<n; i++){
		if(i % 2 == 0) num = 1;
		else num = 0;
		for(int j=0;j<=i;j++){
			cout<<num;
			num = 1 - num;
		}
		cout<<endl;
	}
    return 0;
}