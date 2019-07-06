#include <bits/stdc++.h>
using namespace std;
int main(){
    int m,a,c,X,n;
    cout<<"Enter the modulus (0 < m) : ";
    cin>>m;
    cout<<"\nEnter the seed (0 <= X < m) : ";
    cin>>X;
    cout<<"\nEnter the multiplier (0 < a < m) : ";
    cin>>a;
    cout<<"\nEnter the increment (0 <= c < m) : ";
    cin>>c;
    cout<<"\nHow many numbers need to be generated? : ";
    cin>>n;
    cout<<"\n";
    for(int i=0; i<n; i++){
        X = (a * X + c) % m;
        cout << X << " ";
    }
    return 0;
}

/*
    Enter the modulus (0 < m) : 100000
    Enter the seed (0 <= X < m) : 65
    Enter the multiplier (0 < a < m) : 37
    Enter the increment (0 <= c < m) : 131
    How many numbers need to be generated? : 30
*/
