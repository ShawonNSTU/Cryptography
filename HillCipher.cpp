#include <bits/stdc++.h>
using namespace std;
int n;
float encrypt[5][1], decrypt[5][1], a[5][5], b[5][5], mes[5][1], c[5][5];
void getKeyMessage(){
    cout<<"Enter n : ";
    cin>>n;
	int i, j;
	char msg[n];
	cout<<"Enter "<<n<<"x"<<n<<" matrix for key : \n";
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			cin>>a[i][j];
			c[i][j] = a[i][j];
		}
	}
	cout<<"\nEnter a "<<n<<" letter string : ";
	cin>>msg;
	for(i = 0; i < n; i++){
		mes[i][0] = msg[i] - 97;
	}
}
void encryption(){
	int i, j, k;
	for(i = 0; i < n; i++){
		for(j = 0; j < 1; j++){
			for(k = 0; k < n; k++){
				encrypt[i][j] = encrypt[i][j] + a[i][k] * mes[k][j];
			}
		}
	}
	cout<<"\nEncrypted string is: ";
	for(i = 0; i < n; i++){
		cout<<(char)(fmod(encrypt[i][0], 26) + 97);
	}
}
void inverse(){
	int i, j, k;
	float p, q;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(i == j)
				b[i][j] = 1;
			else
				b[i][j] = 0;
		}
	}
	for(k = 0; k < n; k++){
		for(i = 0; i < n; i++){
			p = c[i][k];
			q = c[k][k];
			for(j = 0; j < n; j++){
				if(i != k) {
					c[i][j] = c[i][j]*q - p*c[k][j];
					b[i][j] = b[i][j]*q - p*b[k][j];
				}
			}
		}
	}
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			b[i][j] = b[i][j] / c[i][i];
		}
	}
	cout<<"\n\nInverse Matrix is:\n";
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			cout<<b[i][j]<<" ";
		}
		cout<<"\n";
	}
}
void decryption(){
	int i, j, k;
	inverse();
	for(i = 0; i < n; i++){
		for(j = 0; j < 1; j++){
			for(k = 0; k < n; k++){
				decrypt[i][j] = decrypt[i][j] + b[i][k] * encrypt[k][j];
			}
		}
	}
	cout<<"\nDecrypted string is: ";
	for(i = 0; i < n; i++){
		cout<<(char)(round(fmod(decrypt[i][0], 26) + 97));
	}
	cout<<"\n";
}
int main(){
	getKeyMessage();
	encryption();
	decryption();
}
/* Enter n : 3
Enter 3x3 matrix for key :
6 24 1
13 16 10
20 17 15
Enter a 3 letter string: act */

/* Enter n : 2
Enter 2x2 matrix for key :
3 3
2 5
Enter a 2 letter string: he */
