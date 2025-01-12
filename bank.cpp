#include<iostream>
using namespace std;
class bank{
    
    int accnum;
    string name;
    float balance;
    float depamount;
    float withamount;
    public:
    void readdata()
    {
        cout<<"Enter your bank details:\n Enter account number:\nEnter name:\nEnter account balance:";
        cin>>accnum>>name>>balance;
    }
    void display(){
        cout<<accnum<<name<<balance;

    }
    void deposit(){
        cout<<"Enter amount to be deposited";
        cin>>depamount;
        balance+= depamount;
        cout<<"New balance is: "<<balance;
    }
    void withdraw()
    {
        cout<<"Enter amount to be withdrawn";
        cin>>withamount;
        balance-=withamount;
        cout<<"new balance "<<balance;
    }};
    int main()
    {
        bank x;
        x.readdata();
        int ch=0;
        while(ch!=4)
        {

        
        cout<<"choose an option \n 1.deposit \n 2.withdraw \n 3.details \n 4.exit";
        cin>>ch;
        switch(ch)
        {
            case 1: x.deposit(); break;
            case 2: x.withdraw(); break;
            case 3: x.display(); break;
            default: cout<<"Exit"; ch=4; break;
        }
        }
        return 0;
    }

