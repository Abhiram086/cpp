#include<iostream>
using namespace std;

template <typename T>
class Stack{
    public:
T* arr;
int max;
int top;

Stack(int size){
    max=size;
    top=-1;
    arr=new T[size];

}

void push(T d){
    if(!isfull()){
        top++;
        arr[top]=d;
    }
    else cout<<"Stack is full";
}
 T pop() {
        if (!isempty()) {
            T temp = arr[top];
            top--;
            return temp;
        } else {
            cout << "Stack is empty";
            return T(); // Return default value of T
        }
    }
T peek(){
    if(!isempty()){
        cout<<"Peeked element is "<<arr[top];
        return arr[top];
    }
        else
        return T();
    

}
bool isfull(){
    return top==max-1;
}
bool isempty(){
    return top==-1;
}};

int main(){
   
int size;
    cout<<"Enter the size of the stack";
    cin>>size;
     Stack <int> s(size);

    int ch=0;
    while(ch!=4){
        cout<<"1.Push\n2.Pop\n3.Peek\n4.Exit\n";
        cin>>ch;
        switch(ch){
            case 1:
            int d;
            cout<<"Enter the element to be pushed";
            cin>>d;
            s.push(d);
            break;

            case 2:
            s.pop();
            break;

            case 3:
            s.peek();
            break;

            case 4:
            break;

            default:
            cout<<"Invalid choice";
        }   
    }
    return 0;
}