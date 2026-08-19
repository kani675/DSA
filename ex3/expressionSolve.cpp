#include<iostream>
#include <cctype>
using namespace std;
class A_Stack{
private:
    int* arr;
    int capacity;
    int top;
public:
    A_Stack();
    A_Stack(int);
    A_Stack(const A_Stack&);
    ~A_Stack();
    int Push(int);
    int isFull();
    int isEmpty();
    int displayStack();
    int Pop();

};
int ExpressionApplication();

A_Stack::A_Stack()
{
    top=-1;
    capacity=10;
    arr=new int[capacity];
    for (int i = 0 ; i<10 ; i++)
        arr[i]=-1;
}
A_Stack::A_Stack(int c)
{
    top=-1;
    capacity=c;
    arr=new int[c];
    for (int i = 0 ; i<c ; i++)
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
        int c=arr[top];
        arr[top--]=-1;
        return c;
    }

}

int A_Stack::displayStack()
{
    for(int i=top;i>=0;i--)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    return 1;
}

int ExpressionApplication()
{
   int count,capacity;
   char* array = new char[count];
   cout<<"Enter the capacity:";
   cin>>capacity;
   // A_Stack obj(capacity);
   cout << "Enter number of elements (max): ";
   cin >> count;
   cout << "Enter the elements (digits and operators only): ";
   for (int j = 0; j < count; j++)
      cin >> array[j];
   cout<<"***"<<endl;
   A_Stack s(capacity);
   int obj1,obj2,res;
   for (int i = 0; i < count; i++)
   {
        char C=array[i];
        if (isdigit(C))
        {
            s.Push(C-'0');
            cout<<"the element in the stack(at last):"<<C<<endl;
        }
        else
        {
            obj2=s.Pop();
            obj1=s.Pop();

            switch (C)
            {
                case '+':
                    res = obj1 + obj2;
                    break;
                case '-':
                    res = obj1 - obj2;
                    break;
                case '*':
                    res = obj1 * obj2;
                    break;
                case '/':
                    res = obj1 / obj2;
                    break;
                default:
                    return -1;
            }
            cout<<"the operation is "<<obj1<<" "<<C<<" "<<obj2<<" = "<<res<<endl;
            s.Push(res);
        }
   }
   cout<<"***"<<endl;
   return res;
}

int main()
{
   int count,n,e,capacity;
   //A_Stack obj;
   //char* array = new char[count];
   //cout<<"Enter the capacity:";
   //cin>>capacity;
   // A_Stack obj(capacity);
   // cout << "Enter number of elements (max): ";
   // cin >> count;
   // cout << "Enter the elements (digits and operators only): ";
   // for (int j = 0; j < count; j++)
   //     cin >> array[j];
    e = ExpressionApplication();
    if (e == -1)
        cout << "Error in calculation" << endl;
    else
        cout << "The result of the expression is: " << e << endl;
    return 0;
}
