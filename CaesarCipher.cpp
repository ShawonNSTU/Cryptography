#include <bits/stdc++.h>
using namespace std;
string Encrypt(string text, int shift){
    string result = "";
    for(int i=0; i<text.length(); i++){
        if(text[i] == ' '){
            result += ' ';
            continue;
        }
        if(isupper(text[i])){
            result += char(int(text[i]+shift-65)%26 + 65);
        }
        else{
            result += char(int(text[i]+shift-97)%26 +97);
        }
    }
    return result;
}
string Decrypt(string text, int shift){
    string result = "";
    for(int i=0; i<text.length(); i++){
        if(text[i] == ' '){
            result += ' ';
            continue;
        }
        else if(isupper(text[i])){
            if(int(text[i]-shift-65) < 0){
                result += char(int(text[i]-shift-65)%26 + 26 + 65);
            }
            else{
                result += char(int(text[i]-shift-65)%26 + 65);
            }
        }
        else{
            if(int(text[i]-shift-97) < 0){
                result += char(int(text[i]-shift-97)%26 + 26 + 97);
            }
            else{
                result += char(int(text[i]-shift-97)%26 + 97);
            }
        }
    }
    return result;
}
int main(){
    cout<<"Enter the text : ";
    string text; getline(cin,text);
    int shift;
    cout<<"Enter the shift value : ";
    cin>>shift;
    string CipherText = Encrypt(text,shift);
    string PlainText = Decrypt(CipherText,shift);
    cout << "\nCipherText : " << CipherText << endl;
    cout << "\nPlainText : " << PlainText << endl;
    return 0;
}
/*
    Enter the text : ICE Programming Club
    Enter the shift value : 2
*/
