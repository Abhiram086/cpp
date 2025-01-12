#include<iostream>
using namespace std;

class Shape{
    public:
    void virtual area()=0;
    void virtual perimeter()=0;

};
class Square: public Shape{
    public:
     int a;
    square()
    {
        cout<<"Enter the length if side";
        cin>>a;

    }
    void area()
    {
        cout<<"the area of the square is "<<a*a;
    }
    void perimeter(){
        cout<<"the perimeter of square is "<<4*a;
    }

};
class Triangle:public Shape{
    public:
    int b,h,p,q,r;
    triangle(){
        
        cout<<"Enter base,height,and sides";
        cin>>b>>h>>p>>q>>r;
    }
        void area()
        {
            cout<<"area of triangle is "<<0.5*b*h;
        }
        void perimeter(){
            cout<<"perimeter of triangle is "<<q+p+r;
        }
    
};

int main(){
    Square x;
    x.square();
    x.area();
    x.perimeter();

    Triangle y;
    y.triangle();
    y.area();
    y.perimeter();
    return 0;
}

