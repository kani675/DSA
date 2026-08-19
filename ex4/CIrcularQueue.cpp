 #include<iostream>
using namespace std;
class A_CircularQueue{
private:
    int* arr;
    int capacity;
    int rear;
    int front;
public:
    A_CircularQueue();
    A_CircularQueue(int);
    A_CircularQueue(int,int,int*,int);
    A_CircularQueue(const A_CircularQueue&);
    ~A_CircularQueue();
    int Enqueue(int);
    int Dequeue();
    int Peek();
    int isFull();
    int isEmpty();
    int displayQueue();
    int countOfTheElement();
    int makeQueueEmpty();
    int FrontIndex();
    int RearIndex();
};

A_CircularQueue::A_CircularQueue()
{
    front=-1;
    rear=-1;
    capacity=5;
    arr=new int[capacity];
    for (int i = 0 ; i<5 ; i++)
        arr[i]=-1;
}
A_CircularQueue::A_CircularQueue(int a)
{
    front=-1;
    rear=-1;
    capacity=a;
    arr=new int[capacity];
    for (int i = 0 ; i<a ; i++)
        arr[i]=-1;
}
A_CircularQueue::A_CircularQueue(int f,int r,int* a,int c)
{
    front=f;
    rear=r;
    capacity=c;
    arr=new int[capacity];
    for (int i = 0 ; i<c ; i++)
        arr[i]=a[i];
}
A_CircularQueue::A_CircularQueue(const A_CircularQueue& obj)
{
    front=obj.front;
    rear=obj.rear;
    capacity=obj.capacity;
    arr=new int[capacity];
    for (int i = 0 ; i<capacity ; i++)
        arr[i]=obj.arr[i];
}
A_CircularQueue::~A_CircularQueue()
{
    front=-1;
    rear=-1;
    capacity=0;
    delete[] arr;
    arr=NULL;
}
int A_CircularQueue::isFull()
{
    if((rear+1)%capacity==front)
    {
        return 1;
    }
    else{
        return 0;
    }
}
int A_CircularQueue::isEmpty()
{
    if(rear==-1&&front==-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int A_CircularQueue::Enqueue(int a)
{
    if(isFull())
    return -1;
    else if(isEmpty())
    {
        front=0;
        rear=0;
        arr[rear]=a;
        return 1;
    }
    else{

        rear=(rear+1)%capacity;
        arr[rear]=a;
        return 2;
    }
}

int A_CircularQueue::Dequeue()
{
    if(isEmpty())
    {
        return -1;
    }
    else if(front==rear)
    {
        arr[rear]=-1;
        front=-1;
        rear=-1;
        return 2;
    }
    else{
        arr[front]=-1;
        front=(front+1)%capacity;
        return 1;
    }

}

int A_CircularQueue::displayQueue()
{
    if(isEmpty())
        return -1;
    int i;
    for(i=front;i!=rear;i=(i+1)%capacity)
    {
        cout<<arr[i]<<" ";
    }
    cout<<arr[i]<<endl;
    return 1;
}
int A_CircularQueue::countOfTheElement()
{
    if(isEmpty())
        return 0;
    else{
        int count=0;
        for(int i=front;i!=rear;i=(i+1)%capacity)
            count++;
        return count+1;
}
}
int A_CircularQueue::makeQueueEmpty()
{
    if(isEmpty())
        return -1;
    for(int i=front;i!=rear;i=(i+1)%capacity){
        Dequeue();
    }
    Dequeue();
    return 1;
}
int A_CircularQueue::Peek()
{
    if(isEmpty())
        return -1;
    else
        return arr[front];
}
int A_CircularQueue::FrontIndex()
{
   return front;
}
int A_CircularQueue::RearIndex()
{
   return rear;
}

int main()
{
    int choice,n,e,cap;
    cout<<"Enter the capacity of the circular queue:";
    cin>>cap;
    A_CircularQueue obj(cap);
    cout<<"Functions of the Circular Queue"<<endl;
    cout<<"\n1.Enqueue\n2.Dequeue\n3.IsFull\n4.IsEmpty\n5.Peek\n6.DisplayQueue";
    cout<<"\n7.Count of the element\n8.MakeQueueEmpty\n9.DisplayFrontIndex\n10.DisplayRearIndex\n11.Exit\n"<<endl;
    do{
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                cout<<"Enqueue the element"<<endl;
                cout<<"Enter the element:";
                cin>>n;
                e=obj.Enqueue(n);
                if(e<1)
                    cout<<"the Queue is full"<<endl;
                else
                   cout<<"the element is inserted"<<endl;
                break;
            }
            case 2:
            {
                cout<<"Dequeue the element"<<endl;
                e=obj.Dequeue();
                if(e<1)
                    cout<<"the Queue is empty"<<endl;
                else
                   cout<<"The element is deleted"<<endl;
                break;
            }
            case 3:
            {
                cout<<"Check whether the Queue is full"<<endl;
                if(obj.isFull())
                    cout<<"the Queue is Full";
                else
                    cout<<"The Queue is not full";
                break;
            }
            case 4:
            {
                cout<<"Check whether the Queue is Empty"<<endl;
                if(obj.isEmpty())
                    cout<<"the Queue is Empty";
                else
                    cout<<"The Queue is not empty";
                break;
            }
            case 5:
            {
                cout<<"Peek element\n"<<endl;
                e=obj.Peek();
                if(e>1)
                    cout<<"the peek value is "<<e<<endl;
                else
                    cout<<"the Queue is empty"<<endl;
                break;
            }
            case 6:
            {
                cout<<"Displaying the list"<<endl;
                e=obj.displayQueue();
                if(e<1)
                    cout<<"the Queue is empty"<<endl;
                break;
            }
            case 7:
            {
                cout<<"the number of the elements in the Queue is"<<obj.countOfTheElement()<<endl;
                break;
            }
            case 8:
            {
                cout<<"Making the Queue empty"<<endl;
                e=obj.makeQueueEmpty();
                if(e<1)
                    cout<<"the Queue is already empty"<<endl;
                break;
            }
            case 9:
                {
                   cout<<"the index of the front is "<<obj.FrontIndex()<<endl;
                   break;
                }
           case 10:
                {
                   cout<<"the index of the rear is "<<obj.RearIndex()<<endl;
                   break;
                }
            case 11:
            {
                cout<<"Exiting ..."<<endl;
                break;
            }
            default:
                cout<<"Invalid choice"<<endl;
        }
    }while(choice!=11);
}
