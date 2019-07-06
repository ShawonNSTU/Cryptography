#include <bits/stdc++.h>
using namespace std;
char matrix[5][5];
pair<int,int>arr[100];
int visited[100];
string characters = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
char validChar(){
    for(int i=0; i<characters.size(); i++){
        int a = characters[i];
        if(!visited[a]){
            visited[a] = 1;
            return characters[i];
        }
    }
}
void buildMatrix(string keyword){
    string newKey;
    for(int i=0; i<keyword.size(); i++){
        int a = keyword[i];
        if(!visited[a]){
            newKey.push_back(keyword[i]);
            visited[a] = 1;
        }
    }
    int Size = newKey.size();
    int k = 0;
    int i,j;
    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            if(k == newKey.size()) break;
            matrix[i][j] = newKey[k];
            int a = newKey[k];
            arr[a] = make_pair(i,j);
            ++k;
        }
        if(k == newKey.size()) break;
    }
    for(k=j; k<5; k++){
        matrix[i][k] = validChar();
        int start = matrix[i][k];
        arr[start] = make_pair(i,k);
    }
    ++i;
    for(; i<5; i++){
        for(j=0; j<5; j++){
            matrix[i][j] = validChar();
            int start = matrix[i][j];
            arr[start] = make_pair(i,j);
        }
    }
    cout<<"\nMatrix\n\n";
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
string Decipher(char ch1, char ch2){
    string s;
    int ascii1 = ch1;
    int ascii2 = ch2;
    int col1 = arr[ascii1].second;
    int row1 = arr[ascii1].first;
    int col2 = arr[ascii2].second;
    int row2 = arr[ascii2].first;
    if(col1 == col2){
        if(!row1) row1 = 5;
        if(!row2) row2 = 5;
        s += matrix[row1-1][col1];
        s += matrix[row2-1][col2];
    }
    else if(row1 == row2){
        if(!col1) col1 = 5;
        if(!col2) col2 = 5;
        s += matrix[row1][col1-1];
        s += matrix[row2][col2-1];
    }
    else{
        s += matrix[row1][col2];
        s += matrix[row2][col1];
    }
    return s;
}
string Encipher(char ch1, char ch2){
    string s;
    int ascii1 = ch1;
    int ascii2 = ch2;
    int col1 = arr[ascii1].second;
    int row1 = arr[ascii1].first;
    int col2 = arr[ascii2].second;
    int row2 = arr[ascii2].first;
    if(col1 == col2){
        if(row1 == 4) row1 = -1;
        if(row2 == 4) row2 = -1;
        s += matrix[row1+1][col1];
        s += matrix[row2+1][col2];
    }
    else if(row1 == row2){
        if(col1 == 4) col1 = -1;
        if(col2 == 4) col2 = -1;
        s += matrix[row1][col1+1];
        s += matrix[row2][col2+1];
    }
    else{
        s += matrix[row1][col2];
        s += matrix[row2][col1];
    }
    return s;
}
int main(){
    string text, keyword;
    cout<<"Enter the message : ";
    getline(cin, text);
    cout<<"Enter the keyword : ";
    cin>>keyword;
    buildMatrix(keyword);
    string cipherText, decipherText;
    for(int i=0; i<text.size(); i+=2){
        char ch1, ch2;
        ch1 = text[i];
        if(ch1 == ' '){
            --i; continue;
        }
        if(i+1 == text.size()) ch2 = 'X';
        else{
            if(ch1 != ' ' && text[i+1] == ' ') i++;
            ch2 = text[i+1];
        }
        cipherText += Encipher(ch1,ch2);
    }
    cout<<"Cipher Text : "<<cipherText<<endl;
    for(int i=0; i<cipherText.size(); i+=2){
        char ch1, ch2;
        ch1 = cipherText[i];
        ch2 = cipherText[i+1];
        decipherText += Decipher(ch1,ch2);
    }
    cout<<"Plain Text : "<<decipherText<<endl;
    return 0;
}
/*
    Enter the message : ICE PROGRAMMING CLUB
    Enter the keyword : MONARCHY
*/
