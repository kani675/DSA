#include<iostream>
using namespace std;
class CNode
{
    public:
        CNode();
        CNode(int,CNode*);
        CNode(const CNode&);
        ~CNode();
        void get();
        void display();
    private:
        int data;
        CNode* next;
        friend class L_Queue;
};
class L_Queue
{
    public:
        L_Queue();
        L_Queue(CNode*,CNode*);
        L_Queue(const L_Queue&);
        ~L_Queue();
        int EnQueue(CNode*);
        int isEmpty();
        void displayQueue();
        int DeQueue();
        int size();
        void makeQueueEmpty();
        int displayRear();
        int displayFront();
    private:
        CNode* front;
        CNode* rear;
};
CNode::CNode()
{
    data=-1;
    next=NULL;
}
CNode::CNode(int d,CNode* n)
{
    data=d;
    next=n;
}
CNode::CNode(const CNode& n)
{
    data=n.data;
    next=n.next;
}
CNode::~CNode()
{
    data=-1;
    next=NULL;
}
void CNode::get()
{
    int d;
    cout<<"Enter the data value:";
    cin>>d;
    data=d;
}
void CNode::display()
{
    cout<<"The value of data is "<<data<<endl;
}
L_Queue::L_Queue()
{
    front=NULL;
    rear=NULL;
}
L_Queue::L_Queue(CNode* n,CNode* n2)
{
    front=n;
    rear=n2;
}
L_Queue::L_Queue(const L_Queue &n)
{
    front=n.front;
    rear=n.rear;
}
L_Queue::~L_Queue()
{
    front=NULL;
    rear=NULL;
}
int L_Queue::isEmpty()
{
    if(front==NULL)
        return 1;
    else
        return 0;
}

int L_Queue::EnQueue(CNode* newNode)
{
    if(isEmpty()){
        front  =newNode;
        rear=newNode;
        return 1;
    }
    else
    {
        rear->next=newNode;
        rear=newNode;
        return 2;
    }
}

int L_Queue::DeQueue()
{
    if(isEmpty()){
        return -1;
    }
    else if(rear==front)
    {
        CNode* temp=front;
        delete temp;
        temp=NULL;
        front=NULL;
        rear=NULL;
        return 1;
    }
    else
    {
        CNode* temp=front;
        front=front->next;
        delete temp;
        temp=NULL;
        return 1;
    }
}


int L_Queue::size()
{
    if(isEmpty()){

        return 0;
    }
    else
    {
        int count=1;
        CNode* temp=front;
        while(temp!=rear){
            count++;
            temp=temp->next;
        }
        return count++;
    }
}

void L_Queue::displayQueue()
{
    if(isEmpty()){
        cout<<"The Queue is empty"<<endl;
    }
    else
    {
        CNode* temp=front;
        while(temp!=rear->next){

            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
}
}

void L_Queue::makeQueueEmpty()
{

    while(!isEmpty())
    {
        DeQueue();
    }
}
int L_Queue::displayRear(){
   return rear->data;}
int L_Queue::displayFront(){
   return front->data;}
[23bcs010@mepcolinux ex5b]$cat imp.cpp
#include "header.h"
CNode::CNode()
{
    data=-1;
    next=NULL;
}
CNode::CNode(int d,CNode* n)
{
    data=d;
    next=n;
}
CNode::CNode(const CNode& n)
{
    data=n.data;
    next=n.next;
}
CNode::~CNode()
{
    data=-1;
    next=NULL;
}
void CNode::get()
{
    int d;
    cout<<"Enter the data value:";
    cin>>d;
    data=d;
}
void CNode::display()
{
    cout<<"The value of data is "<<data<<endl;
}
L_Queue::L_Queue()
{
    front=NULL;
    rear=NULL;
}
L_Queue::L_Queue(CNode* n,CNode* n2)
{
    front=n;
    rear=n2;
}
L_Queue::L_Queue(const L_Queue &n)
{
    front=n.front;
    rear=n.rear;
}
L_Queue::~L_Queue()
{
    front=NULL;
    rear=NULL;
}
int L_Queue::isEmpty()
{
    if(front==NULL)
        return 1;
    else
        return 0;
}

int L_Queue::EnQueue(CNode* newNode)
{
    if(isEmpty()){
        front  =newNode;
        rear=newNode;
        return 1;
    }
    else
    {
        rear->next=newNode;
        rear=newNode;
        return 2;
    }
}

int L_Queue::DeQueue()
{
    if(isEmpty()){
        return -1;
    }
    else if(rear==front)
    {
        CNode* temp=front;
        delete temp;
        temp=NULL;
        front=NULL;
        rear=NULL;
        return 1;
    }
    else
    {
        CNode* temp=front;
        front=front->next;
        delete temp;
        temp=NULL;
        return 1;
    }
}


int L_Queue::size()
{
    if(isEmpty()){

        return 0;
    }
    else
    {
        int count=1;
        CNode* temp=front;
        while(temp!=rear){
            count++;
            temp=temp->next;
        }
        return count++;
    }
}

void L_Queue::displayQueue()
{
    if(isEmpty()){
        cout<<"The Queue is empty"<<endl;
    }
    else
    {
        CNode* temp=front;
        while(temp!=rear->next){

            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
}
}

void L_Queue::makeQueueEmpty()
{

    while(!isEmpty())
    {
        DeQueue();
    }
}
int L_Queue::displayRear(){
   return rear->data;}
int L_Queue::displayFront(){
   return front->data;
}


int main(){

       int choice,d,n,e;
       L_Queue obj;
       cout<<"Functions of the Queue"<<endl;
       cout<<"\n1.Enqueue\n2.Dequeue\n3.IsEmpty\n4.DisplayFront\n5.DisplayRear\n6.DisplayQueue";
       cout<<"\n7.Size\n8.MakeQueueEmpty\n9.Exit\n"<<endl;
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
                CNode* newNode = new CNode(n,NULL);
                e=obj.EnQueue(newNode);
                cout<<"the element is inserted"<<endl;
                break;
             }
             case 2:
             {
                cout<<"Dequeue the element"<<endl;
                e=obj.DeQueue();
                if(e<1)
                   cout<<"the Queue is empty"<<endl;
                else
                   cout<<"The element is deleted"<<endl;
                break;
             }
             case 3:
             {
                cout<<"Check whether the Queue is Empty"<<endl;
                if(obj.isEmpty())
                   cout<<"the Queue is Empty";
                else
                   cout<<"The Queue is not empty";
                break;
             }
             case 4:
             {
                cout<<"the front index is "<<obj.displayFront()<<endl;
                break;
             }
             case 5:
             {
                cout<<"the rear index is "<<obj.displayRear()<<endl;
                break;
             }
             case 6:
             {
                cout<<"Displaying the Queue"<<endl;
                obj.displayQueue();
                break;
             }
             case 7:
             {
                cout<<"the number of the elements in the Queue is"<<obj.size()<<endl;
                break;
             }
             case 8:
             {
                cout<<"Making the Queue empty"<<endl;
                obj.makeQueueEmpty();
                break;
             }
             case 9:
             {
                cout<<"Exiting ..."<<endl;
                break;
             }
             default:
             cout<<"Invalid choice"<<endl;
          }
       }while(choice!=9);
}
