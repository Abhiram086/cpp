#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
    ofstream fout;

    fout.open("file2.txt");

    string str;
    cin>>str;

    fout<<str;
    fout.close();
}