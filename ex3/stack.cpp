#include<iostream>
using namespace std;
class A_Stack{
private:
    int* arr;
    int capacity;
    int top;
public:
    A_Stack();
    A_Stack(int*,int,int);
    A_Stack(const A_Stack&);
    ~A_Stack();
    int Push(int);
    int isFull();
    int isEmpty();
    int displayStack();
    int Pop();
    int makeStackEmpty();
    int Peek();
};

A_Stack::A_Stack()
{
    top=-1;
    capacity=10;
    arr=new int[capacity];
    for (int i = 0 ; i<10 ; i++)
        arr[i]=-1;
}
A_Stack::A_Stack(int* a,int c,int t)
{
    top=t;
    capacity=c;
    arr=new int[capacity];
    for (int i = 0 ; i<t ; i++)
        arr[i]=a[i];
    for (int i = t ; i<c ; i++)
        arr[i]=-1;
}
A_Stack::A_Stack(const A_Stack& obj)
{
    top=obj.top;
    capacity=obj.capacity;
    arr=new int[capacity];
    for (int i = top ; i<capacity ; i++)
        arr[i]=-1;
}
A_Stack::~A_Stack()
{
    top=-1;
    capacity=0;
    delete[] arr;
    arr=NULL;
}
int A_Stack::isFull()
{
    if(top+1==capacity)
    {
        return 1;
    }
    else{
        return 0;
    }
}
int A_Stack::isEmpty()
{
    if(top==-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int A_Stack::Push(int a)
{
    if(isFull())
    return -1;
    else{
        arr[++top]=a;
        return 1;
    }
}


int A_Stack::Pop()
{
    if(isEmpty())
    {
        return -1;
    }
    else{
        arr[top--]=-1;
        return 1;
    }

}

int A_Stack::displayStack()
{
   if(isEmpty())
      return -1;
    for(int i=top;i>=0;i--)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    return 1;
}

int A_Stack::makeStackEmpty()
{
    if(isEmpty())
       return -1;
    for (int i=0;i<capacity;i++)
    {
        Pop();
    }
    return 1;
}
int A_Stack::Peek()
{
    if(isEmpty()==0)
        return arr[top];
    return -1;
}

int main()
{
    int ch,n,e;
    A_Stack obj;
    cout<<"\nStack functions\n1.Push\n2.Pop\n3.Peek\n4.IsEmpty\n5.IsFull\n";
    cout<<"6.DisplayStack\n7.MakestackEmpty\n8.Exit";

    do{
        cout<<"\nEnter your choice:";
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                cout<<"Enter the value to Push:";
                cin>>n;
                e=obj.Push(n);
                if(e==1)
                    cout<<"the element is inserted"<<endl;
                else
                    cout<<"the array is full"<<endl;
                break;
            }
            case 2:
            {
                cout<<"Pop the top element"<<endl;
                e=obj.Pop();
                if(e==1)
                    cout<<"the element is deleted"<<endl;
                else
                    cout<<"the array is empty"<<endl;
                break;
            }
            case 3:
            {
                e=obj.Peek();
                if(e==-1)
                    cout<<"The stack is empty";
                else
                    cout<<"The Peek Function to print the top value:"<<e<<endl;
                break;
            }
            case 4:
            {
                cout<<"TO check the array is empty"<<endl;
                if(obj.isEmpty())
                    cout<<"the stack is empty";
                else
                    cout<<"The stack is not empty"<<endl;
                break;
            }
            case 5:
            {
                cout<<"To check the array is full"<<endl;
                if(obj.isFull())
                    cout<<"the stack is full";
                else
                    cout<<"the stack is not full";
                    break;
            }
            case 6:
            {
                cout<<"Displaying the stack from the top"<<endl;
                e=obj.displayStack();
                if(e!=1)
                    cout<<"the array is empty";
                break;
            }
            case 7:
            {
                cout<<"Making the stack empty";
                e=obj.makeStackEmpty();
                 if(e!=1)
                    cout<<"\nthe array is already empty";
                break;
            }
            case 8:
            {
                cout<<"Exiting..."<<endl;
                break;
            }
            default:
                cout<<"Invalid choice";
            }
        }while(ch!=8);
}
