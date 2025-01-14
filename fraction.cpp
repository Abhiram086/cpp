#include<iostream>
using namespace std;

class fraction{
    public:
    int numerator;
    int denominator;
    public:

    fraction(int num=0,int den=1)
    {
        if(den==0){
            cout<<"den cant be zero";
            den=1;
        }
        numerator=num;
        denominator=den;

    }
    friend fraction operator +(fraction f1,fraction f2);
    friend fraction operator -(fraction f1,fraction f2);

    void display(){
        cout<<numerator<<"/"<<denominator;
    }
};

fraction operator +(fraction f1,fraction f2){
    fraction temp;
    temp.numerator=f1.numerator*f2.denominator+f1.denominator*f2.numerator;
    temp.denominator=f1.denominator*f2.denominator;
    return temp;
}
fraction operator -(fraction f1,fraction f2){
    fraction temp;
     temp.numerator=f1.numerator*f2.denominator-f1.denominator*f2.numerator;
    temp.denominator=f1.denominator*f2.denominator;
    return temp;
}
int main()
{
    int num1,den1,num2,den2;
    cout<<"Enter fraction 1: "<<endl;
    cin>>num1>>den1;

    fraction f1(num1,den1);
    cout<<"Enter fraction 2: "<<endl;
    cin>>num2>>den2;

    fraction f2(num2,den2);

    fraction f3=f1+f2;
    cout<<"Addition";
    f3.display();
    cout<<endl;

    fraction f4=f1-f2;
    cout<<"subtraction";
    f4.display();
    cout<<endl;
    return 0;
    

}