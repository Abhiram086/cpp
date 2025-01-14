#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
    ifstream fin;
    fin.open("file2.txt");
    string str;
  

   while(fin >> str)
   {
    cout<<str<<endl;
   }
    fin.close();
    return 0;

}