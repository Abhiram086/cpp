#include<iostream>
using namespace std;

class studies{
    public:
    string name;
    int marks[10],id;
int n;
    void details()
    {
        cout<<"enter your name";
        cin>>name;
        cout<<"enter number of subjects";
        
        cin>>n;
        cout<<"enter marks";
        for(int i=0;i<n;i++)
        {
            cin>>marks[i];
        }
        
    }
};
class sports{
    public:
    int smark;
    void sportmark()
    {
        cout<<"enter your sports grade";
        
        cin>>smark;

    }
};

class total:public studies,public sports{
    public:
    int tmark=0;
    void totalmark()
    {
        for(int i=0;i<n;i++)
        {
            tmark=tmark+marks[i];
        }
        int total=tmark+smark;
        cout<<"total is: "<<total;
    }
};

int main()
{
    total x;
    x.details();
    x.sportmark();
    x.totalmark();
    return 0;
}