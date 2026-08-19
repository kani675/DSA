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
L_List::L_List()
{
    first=NULL;
}
L_List::L_List(CNode* n)
{
    first=n;
}
L_List::L_List(const L_List &n)
{
    first=n.first;
}
L_List::~L_List()
{
    first=NULL;
}
int L_List::isEmpty()
{
    if(first==NULL)
        return 1;
    else
        return 0;
}
int L_List::insertAtFirst(CNode* newNode)
{
    if(isEmpty()){
        first=newNode;
        return 1;
    }
    else
    {
        newNode->next=first;
        first=newNode;
        return 2;
    }
}
int L_List::insertAtLast(CNode* newNode)
{
    if(isEmpty()){
        first  =newNode;
        return 1;
    }
    else
    {
        CNode* temp=first;
        while(temp->next!=NULL){
            temp=temp->next;}
        temp->next=newNode;
        return 2;
    }
}
int L_List::insertByPosition(int position,CNode* newNode)
{
    if(isEmpty()){
        cout<<"empty";
        return -1;
    }
    else if(position==1)
    {
        insertAtFirst(newNode);
        return 2;
    }
    else if(position==countOfTheElement()+1)
    {
        insertAtLast(newNode);
        return 2;
    }
    else if(countOfTheElement()>=position)
    {
        int count=1;
        CNode* temp=first;
        //CNode* prev=first;
        while(count<position-1){
            count++;
            //prev=temp;
            temp=temp->next;}
        newNode->next=temp->next;
        temp->next=newNode;
        cout<<"inserted";
        return 1;
    }

    else{
        cout<<"not alloted";
        return -2;
    }
}
int L_List::deleteAtFirst()
{
    if(isEmpty()){
        return -1;
    }
    else
    {
        CNode* temp=first;
        first=first->next;
        delete temp;
        temp=NULL;
        return 1;
    }
}
int L_List::deleteAtLast()
{
    if(isEmpty()){
        return -1;
    }
    else
    {
        CNode* temp=first;
        CNode* prev=first;
        while(temp->next!=NULL){
            prev=temp;
            temp=temp->next;}
        prev->next=NULL;
        delete temp;
        temp=NULL;
        return 1;
    }
}
int L_List::deleteByPosition(int position)
{
    if(isEmpty()){
        cout<<"empty";
        return -1;
    }
    else if(position==1)
    {
        deleteAtFirst();
        return 2;
    }
    else if(position==countOfTheElement())
    {
        deleteAtLast();
        return 2;
    }
    else if(countOfTheElement()>position)
    {
        int count=1;
        CNode* temp=first;
        CNode* prev=first;
        while(count<position){
            count++;
            prev=temp;
            temp=temp->next;}
        prev->next=temp->next;
        delete temp;
        temp=NULL;
        cout<<"deleted";
        return 1;
    }

    else{
        cout<<"position not alloted";
        return -2;
    }
}
int L_List::countOfTheElement()
{
    if(isEmpty()){

        return 0;
    }
    else
    {
        int count=1;
        CNode* temp=first;
        while(temp->next!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
}
}
int L_List::retreiveData(int position)
{
    if(isEmpty()){
        cout<<"empty";
        return -1;
    }
    else if(countOfTheElement()>=position)
    {
        int count=1;
        CNode* temp=first;
        CNode* prev=first;
        while(count<position){
            count++;
            prev=temp;
            temp=temp->next;}
        return temp->data;
    }
    else{
        cout<<"position not found"<<endl;
        return -2;
    }
}
int L_List::positionOfTheElement(int ele)
{
    if(isEmpty()){
        cout<<"empty";
        return -1;
    }
    else
    {
        int l=countOfTheElement();
        for(int i=1;i<=l;i++)
        {
            if(retreiveData(i)==ele)
            {
                return i;
            }
        }
        return -2;
    }
}
int L_List::updateList(int position,int data)
{
    if(isEmpty()){
        cout<<"empty";
        return -1;
    }
    else if(countOfTheElement()>=position)
    {
        int count=1;
        CNode* temp=first;
        CNode* prev=first;
        while(count<position){
            count++;
            prev=temp;
            temp=temp->next;}
        temp->data=data;
        return 1;
    }
    else{
        cout<<"position not found"<<endl;
        return -2;
    }
}
void L_List::displayList()
{
    if(isEmpty()){
        cout<<"The list is empty"<<endl;
    }
    else
    {
        CNode* temp=first;
        while(temp!=NULL){

            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
}
}
void L_List::reverse()
{
     if (isEmpty()) {
        cout<<"The list is empty"<<endl;
    } else {
        int l = countOfTheElement();
        CNode* temp = first;
        CNode* prev = first;
        while (temp->next != NULL)
            temp = temp->next;
        while (temp != first){
            while (prev->next != temp){
                prev = prev->next;}
            cout << temp->data << " ";
            temp = prev;
            prev = first;
        }
        cout << temp->data << "\n ";
    }

}
void L_List::makeListEmpty()
{
    int l=countOfTheElement();
    for(int i=0;i<l;i++)
    {
        deleteAtFirst();
    }
}
int L_List::insertAtMiddle(CNode* newNode)
{
    int l=countOfTheElement();
    if(l>1)
    {
        insertByPosition(l/2+1,newNode);
        return 1;
    }
    return -1;
}
int L_List::deleteByValue(int val)
{
   int pos=positionOfTheElement(val);
   int e=deleteByPosition(pos);
   return e;
}
int L_List::insertAfterAnElement(int ele,CNode* newNode)
{
   int pos=positionOfTheElement(ele);
   int e=insertByPosition(pos+1,newNode);
   return e;
}
