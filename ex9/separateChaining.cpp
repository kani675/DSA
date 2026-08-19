#include<iostream>
using namespace std;
class TNode{
    private:
        int data;
        TNode* next;
    public:
        TNode(int);
        ~TNode();
        friend class hashTable;
        friend class S_List;
};
class S_List{
    private:
        TNode* first;
    public:
        S_List();
        ~S_List();
        int isEmpty();
        int insertNode(TNode*);
        int deleteNode(int);
        void displayNodes();
        int searchNode(int);
        friend class hashTable;

};
class hashTable{
    private:
        int Tablesize;
        S_List* HT;
    public:
        hashTable(int);
        ~hashTable();
        int Insert(int);
        int Delete(int);
        int Search(int);
        void display();
        int isEmpty();
};

TNode::TNode(int d){
    data= d;
    next=NULL;
}
TNode::~TNode(){
    data= -1;
    next=NULL;
}
S_List::S_List(){
    first = NULL;
}
S_List::~S_List(){
    first = NULL;
}
int S_List::isEmpty()
{
    if(first==NULL)
        return 1;
    else
        return 0;
}
int S_List::insertNode(TNode* newNode)
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
int S_List::deleteNode(int val) {
    if (isEmpty()) {
        cout << "List is empty" << endl;
        return -1;
    } else {
        TNode* temp = first;
        TNode* prev = NULL;
        while (temp != NULL) {
            if (temp->data == val) {
                if (temp == first) {
                    first = temp->next;
                } else {
                    prev->next = temp->next;
                }
                delete temp;
                cout << "Deleted node with value " << val << endl;
                return 1;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << "Value not found" << endl;
        return -2;
    }
}
int S_List::searchNode(int val) {
    if (isEmpty()) {
        return -1;
    } else {

        TNode* temp = first;
        while (temp != NULL) {
            if (temp->data == val) {
                return 1;
            }
            temp = temp->next;

        }
        return -2;  // Value not found
    }
}
void S_List::displayNodes()
{
    if(isEmpty()){
        cout<<"The list is empty"<<endl;
    }
    else
    {
        TNode* temp=first;
        while(temp!=NULL){

            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
}
}
hashTable::hashTable(int s){
    Tablesize = s;
    HT = new S_List[Tablesize];
}
hashTable::~hashTable()
{
    Tablesize=-1;
    delete[] HT;
}
int hashTable::Insert(int value) {
    int index = value % Tablesize;

    TNode* newNode = new TNode(value);
    int e =HT[index].insertNode(newNode);
    return e;
}

int hashTable::Delete(int value) {
    int index = value % Tablesize;
    int e =HT[index].deleteNode(value);
    return e;
}
int hashTable::Search(int key)
{
    int index = key % Tablesize;
    int e =HT[index].searchNode(key);
    if(e==1)
    {
       return index;
    }
    else
    {return e;}
}
void hashTable::display() {
    for (int i = 0; i < Tablesize; i++) {
        cout << "Index " << i << ": ";
        HT[i].displayNodes();
    }
}
int hashTable::isEmpty()
{
    int e =0;
    for(int i=0;i<Tablesize;i++)
    {
        e+=HT[i].isEmpty();
    }
    if(e==Tablesize)
        return 1;
    else
        return 0;
}


int main()
{
    int ch,V,capacity;
    cout<<"Enter the table size";
    cin>>capacity;
    hashTable hp(capacity);
    cout<<"\n1.Insert\n2.Delete\n3.Search\n4.isEmpty \n5.Display\n6.Exit"<<endl;

    do{
        cout<<"Enter your choice:";
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                cout<<"Enter the value  to insert:";
                cin>>V;
                int e =hp.Insert(V);
                if( e<1){cout<<"Error\n";}
                break;
            }
            case 2:
            {
                cout<<"Enter the value  to delete:";
                cin>>V;
                int e =hp.Delete(V);
                if( e<1){cout<<"Error\n";}
                break;
            }
            case 3:
            {
                cout<<"Enter the value  to search:";
                cin>>V;
                int e =hp.Search(V);
                if( e<0){cout<<"Not Found"<<endl;}
                else{cout<<"The index is "<<e<<endl;}
                break;
            }
            case 4:
            {
                int e =hp.isEmpty();
                if(e==1){cout<<"Empty";}
                else{cout<<"Not empty";}
                break;
            }
            case 5:
            {
                hp.display();
                break;
            }
            case 6:{
                break;
            }
            default:
            {
                cout<<"invalid choice";
                break;
            }
        }
    }while (ch!=6);
}
