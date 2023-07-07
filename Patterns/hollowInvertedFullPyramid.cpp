#include<iostream>
using namespace std;

int main()
{
    int size;
    cin >> size;

    for(int i = 0; i < size; i++) {
        // for spaces
        for(int j = 0; j < i; j++) {
            cout <<"  ";
        }

        // for asterisks and spaces
        for(int j=0; j<((2*size)-(2*i-1)); j=j+1){
            if(j == 0 || j== 2*size-2*i-2) {
                cout << "* ";
            }
            else {
                cout <<"  ";
            }
        }

        cout << endl;
    }
    return 0;
}
