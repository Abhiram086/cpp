#include<iostream>
using namespace std;

class sum{
    public:
    void sum2(int first,int last)
    {
        int f=first;
        int l=last;
    int sum=0;
        for(int i=f;i<=l;i++)
        {
             sum=sum+i;
        }
        cout<<"\n\nsum is: "<<sum;
    }
};
int main()
{
    int first,last;
    sum x;
    cout<<"Enter first";
    cin>>first;
    cout<<"enter last";
    cin>>last;
    x.sum2(first,last);
    return 0;
}