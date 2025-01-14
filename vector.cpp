#include<iostream>
using namespace std;

template <typename T>
class vector{
    public:

    T* arr;
    int max;
    int top;

    vector(int size){
        max=size;
        top=-1;
        arr =new T[size];
    }
    void push(T obj) {
        if (!isFull()) {
            arr[++top] = obj;
            cout << "Pushed element is " << obj << endl;
        } else {
            resize();
        }
    }

    void pop() {
        if (!isEmpty()) {
            T temp = arr[top--];
            cout << "Popped element " << temp << endl;
        } else {
            cout << "Vector is empty" << endl;
        }
    }

    T peek() {
        if (!isEmpty()) {
            cout << "Peeked element is " << arr[top] << endl;
            return arr[top];
        } else {
            cout << "Vector is empty" << endl;
            return T();
        }
    }
        bool isFull() {
        return top == max - 1;
    }

    bool isEmpty() {
        return top == -1;
    }
    void resize(){
        int newMax=max*2;
        T* newarr;
        newarr=new T[newMax];

        for(int i=0;i<max;i++){
            newarr[i]=arr[i];
        }
        delete[] arr;
        cout<<"vectore resized";
    }
};

int main()
{

    int size;
    cout<<"Enterq size of vector";
    cin>>size;
    vector<int> v(size);
    int choice=0;
    while(choice!=6){
        cout<<"1.Push\n2.Pop\n3.Peek\n4.isFull\n5.isEmpty\n6.Exit\n";
        cin>>choice;
        switch(choice){
            case 1:
            int ele;
            cout<<"Enter element to push";
            cin>>ele;
            v.push(ele);
            break;

            case 2:
            v.pop();
            break;

            case 3:
            v.peek();
            break;

            case 4:
            cout<<v.isFull();
            break;

            case 5:
            cout<<v.isEmpty();
            break;

        

            default:
            int ch=6;
            cout<<"Invalid choice";
            break;
        }
    }
}

