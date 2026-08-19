#include<iostream>
using namespace std;
class LinearProbing{
    private:
        int Tablesize;
        int *HT;
    public:
        LinearProbing(int);
        ~LinearProbing();
        int Insert(int);
        int Delete(int);
        int Search(int);
        void Display();
        int Hashing(int,int);
        int isEmpty(int);
        int isEmpty();
};

LinearProbing::LinearProbing(int t)
{
    Tablesize = t;
    HT = new int[t];
    for(int i=0;i<t;i++){
        HT[i] = -1;
    }
}
LinearProbing::~LinearProbing()
{
    Tablesize=0;
    delete[] HT;
    HT = NULL;
}
int LinearProbing::Insert(int x)
{
    for(int i=0;i<Tablesize;i++){
        int f = Hashing(x,i);
        if(isEmpty(f)){
            HT[f] = x;
            return 1;
        }
        cout<<"Collision occured"<<endl;
    }
    return -1;
}
int LinearProbing::Delete(int x)
{
    for(int i=0;i<Tablesize;i++){
        int f = Hashing(x,i);
        if(x==HT[f]){
            HT[f] = -1;
            return 1;
        }
    }
    return -1;
}
int LinearProbing::Search(int x)
{
    for(int i=0;i<Tablesize;i++){
        int f = Hashing(x,i);
        if(x==HT[i]){
            return i;
        }
    }
    return -1;
}
void LinearProbing::Display()
{
    for(int i=0;i<Tablesize;i++){
        cout<<HT[i]<<" ";
    }
    cout<<endl;
}
int LinearProbing::Hashing(int x,int i)
{
    int h = x%Tablesize;
    int f = (h+i)%Tablesize;
    return f;
}
/*int LinearProbing::isEmpty()
{
    if(){
       return 1;
    }
    else
    {
        return 0;
    }
}*/
int LinearProbing::isEmpty(int i)
{
    return HT[i]==-1;
}
int LinearProbing::isEmpty()
{
    for(int i=0;i<Tablesize;i++){
        if(HT[i]!=-1)
            return 0;
    }
    return 1;
}



int main()
{
    int ch,V,capacity;
    cout<<"Enter the table size";
    cin>>capacity;
    LinearProbing lp(capacity);
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
                int e =lp.Insert(V);
                if( e<1){cout<<"List is full\n";}
                else{cout<<"insertion successfull"<<endl;}
                break;
            }
            case 2:
            {
                cout<<"Enter the value  to delete:";
                cin>>V;
                int e =lp.Delete(V);
                if( e<1){cout<<"Error\n";}
                break;
            }
            case 3:
            {
                cout<<"Enter the value  to search:";
                cin>>V;
                int e =lp.Search(V);
                if( e<1){cout<<"Not found"<<endl;}
                else{cout<<"The index is "<<e<<endl;}
                break;
            }
            case 4:
            {   int e = lp.isEmpty();
               if(e)
                  cout<<"Empty"<<endl;
               else
                  cout<<"Not empty"<<endl;
                break;
            }
            case 5:
            {
                lp.Display();
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
