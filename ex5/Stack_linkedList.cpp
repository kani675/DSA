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
        friend class L_Stack;
};
class L_Stack
{
    public:
        L_Stack();
        L_Stack(CNode*);
        L_Stack(const L_Stack&);
        ~L_Stack();
        int Push(CNode*);
        int isEmpty();
        void displayStack();
        int Pop();
        int size();
        void makeStackEmpty();
        int Peek();
    private:
        CNode* top;

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
L_Stack::L_Stack()
{
    top=NULL;

}
L_Stack::L_Stack(CNode* n)
{
    top=n;
}
L_Stack::L_Stack(const L_Stack &n)
{
    top=n.top;
}
L_Stack::~L_Stack()
{
    top=NULL;

}
int L_Stack::isEmpty()
{
    if(top==NULL)
        return 1;
    else
        return 0;
}
int L_Stack::Push(CNode* newNode)
{
    if(isEmpty()){
        top=newNode;
        return 1;
    }
    else
    {
        newNode->next=top;
        top=newNode;

        return 2;
    }
}

int L_Stack::Pop()
{
    if(isEmpty()){
        return -1;
    }
    else
    {
        CNode* temp=top;
        top=top->next;
        delete temp;
        temp=NULL;
        return 1;
    }
}


int L_Stack::size()
{
    if(isEmpty()){

        return 0;
    }
    else
    {
        int count=1;
        CNode* temp=top;
        while(temp->next!=NULL){
            count++;
            temp=temp->next;
        }
        return count++;
}
}
int L_Stack::Peek()
{
    return top->data;}
void L_Stack::displayStack()
{
    if(isEmpty()){
        cout<<"The Stack is empty"<<endl;
    }
    else
    {
        CNode* temp = top;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
}
}

void L_Stack::makeStackEmpty()
{
    int l=size();
    for(int i=0;i<l;i++)
    {
        Pop();
    }
}

int main()
{
    int n,ch,e,d;
    L_Stack obj;
    cout<<"\nStack functions\n1.Push\n2.Pop\n3.Peek\n4.IsEmpty\n5.size\n";
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
             CNode* newNode=new CNode(n,NULL);
             e=obj.Push(newNode);
             if(e>=1)
                cout<<"the element is inserted"<<endl;
             else
                cout<<"the stack is full"<<endl;
             break;
          }
          case 2:
          {
             cout<<"Pop the top element"<<endl;
             e=obj.Pop();
             if(e>=1)
                cout<<"the element is deleted"<<endl;
             else
                cout<<"the stack is empty"<<endl;
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
             cout<<"TO check the stack is empty"<<endl;
             if(obj.isEmpty())
                cout<<"the stack is empty";
             else
                cout<<"The stack is not empty"<<endl;

             break;
          }
          case 5:
          {

             if(obj.isEmpty())
                cout<<"the stack is Empty";
             else
                cout<<"The size of the Stack is "<<obj.size();
             break;
          }
          case 6:
          {
             cout<<"Displaying the stack from the top"<<endl;
             obj.displayStack();
             if(e<1)
                cout<<"the stack is empty";
             break;
          }
             case 7:
             {
                cout<<"Making the stack empty";
                obj.makeStackEmpty();
                break;
             }
             case 8:
             {
                cout<<"Exiting..."<<endl;
                break;
             }
             default:{
             cout<<"Invalid choice";}
       }
       }while(ch!=8);
}
