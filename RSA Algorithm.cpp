#include <bits/stdc++.h>
using namespace std;
int main() {
   // 2 random prime numbers
   double p,q;
   cout<<"Enter two prime numbers : ";
   cin>>p>>q;
   double n = p*q;  //calculate n
   double track;
   double phi = (p-1) * (q-1);    //calculate phi
   // e stands for encryption key (public)
   double e = 7;
   //for checking that 1 < e < phi(n) and GCD(e, phi(n)) = 1; i.e., e and phi(n) are co-prime.
   while(e < phi){
      track = __gcd((int)e,(int)phi);
      if(track == 1) break;
      else e++;
   }
   //d stands for decryption key (private)
   //choosing d such that it satisfies d*e = 1 mod phi
   double d1 = 1 / e;
   double d = fmod(d1,phi);
   cout<<"Enter the message (number) : ";
   int message; cin>>message;
   double c = pow(message,e);   //encrypt the message
   double m = pow(c,d);     // decrypt the message
   c = fmod(c,n);
   m = fmod(m,n);
   cout<<"\nOriginal Message = "<<message;
   cout<<"\n"<<"p = "<<p;
   cout<<"\n"<<"q = "<<q;
   cout<<"\n"<<"n = p*q = "<<n;
   cout<<"\n"<<"phi = (p-1) * (q-1) = "<<phi;
   cout<<"\n"<<"e = "<<e;
   cout<<"\n"<<"d = "<<d;
   cout<<"\n"<<"Encrypted message = "<<c;
   cout<<"\n"<<"Decrypted message = "<<m;
   return 0;
}

/*
  Enter two prime numbers : 11 13
  Enter the message (number) : 9
*/

/*
    Enter two prime numbers : 3 11
    Enter the message (number) : 2
*/
