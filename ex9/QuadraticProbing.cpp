#include<iostream>
using namespace std;
class QuadraticProbing{
    private:
        int Tablesize;
        int *HT;
    public:
        QuadraticProbing(int);
        ~QuadraticProbing();
        int Insert(int);
        int Delete(int);
        int Search(int);
        void Display();
        int Hashing(int,int);
        int isEmpty(int);
        int isEmpty();
};


QuadraticProbing::QuadraticProbing(int t)
{
    Tablesize = t;
    HT = new int[t];
    for(int i=0;i<t;i++){
        HT[i] = -1;
    }
}
QuadraticProbing::~QuadraticProbing()
{
    Tablesize=0;
    delete[] HT;
    HT = NULL;
}
int QuadraticProbing::Insert(int x)
{
    for(int i=0;i<Tablesize;i++){
        int f = Hashing(x,i);
        if(isEmpty(f)){
            HT[f] = x;
            return 1;
        }
        cout<<"Collission occured"<<endl;
    }
    return -1;
}
int QuadraticProbing::Delete(int x)
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
int QuadraticProbing::Search(int x)
{
    for(int i=0;i<Tablesize;i++){
        int f = Hashing(x,i);
        if(x==HT[i]){
            return i;
        }
    }
    return -1;
}
void QuadraticProbing::Display()
{
    for(int i=0;i<Tablesize;i++){
        cout<<HT[i]<<" ";
    }
    cout<<endl;
}
int QuadraticProbing::Hashing(int x,int i)
{
    int h = x%Tablesize;
    int f = (h+i*i)%Tablesize;
    return f;
}
/*int QuadraticProbing::isEmpty()
{
    if(){
       return 1;
    }
    else
    {
        return 0;
    }
}*/
int QuadraticProbing::isEmpty(int i)
{
    return HT[i]==-1;
}
int QuadraticProbing::isEmpty()
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
    QuadraticProbing qp(capacity);
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
                int e =qp.Insert(V);
                if( e<1){cout<<"List is full\n";}

                break;
            }
            case 2:
            {
                cout<<"Enter the value  to delete:";
                cin>>V;
                int e =qp.Delete(V);
                if( e<1){cout<<"Error\n";}
                break;
            }
            case 3:
            {
                cout<<"Enter the value  to search:";
                cin>>V;
                int e =qp.Search(V);
                if( e<1){cout<<"Error"<<endl;}
                else{cout<<"The index is "<<e<<endl;}
                break;
            }
            case 4:
            {   int e =qp.isEmpty();
               if(e)
                  cout<<"Empty"<<endl;
               else
                  cout<<"Not Empty"<<endl;

                break;
            }
            case 5:
            {
                qp.Display();
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
