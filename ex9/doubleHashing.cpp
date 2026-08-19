#include<iostream>
using namespace std;
class DoubleHashing{
    private:
        int Tablesize;
        int *HT;
        int r;
    public:
        DoubleHashing(int);
        ~DoubleHashing();
        int Insert(int);
        int Delete(int);
        int Search(int);
        void Display();
        int Hashing(int,int);
        int isEmpty(int);
        int isEmpty();
        int nearerSmallPrime();
};

DoubleHashing::DoubleHashing(int t)
{
    Tablesize = t;
    r=nearerSmallPrime();
    cout<<r;
    HT = new int[t];
    for(int i=0;i<t;i++){
        HT[i] = -1;
    }
}
DoubleHashing::~DoubleHashing()
{
    Tablesize=0;
    delete[] HT;
    HT = NULL;
}
int DoubleHashing::nearerSmallPrime()
{
    for(int i=Tablesize;i>1;i--){
        int flag =0;
        for(int j=2;j<i/2;j++){
            if(i%j==0){
            flag=1;
            break;}
        }
        if(flag ==0)
            return i;
    }
    return 2;
}
int DoubleHashing::Insert(int x)
{
    int flag=Hashing(x,0);
    int f = Hashing(x,0);
    if(isEmpty(f)){
       HT[f] = x;
       return 1;}
    for(int i=1;i<Tablesize;i++){
        int f = Hashing(x,i);
        if(flag==f)return -2;
        if(isEmpty(f)){
            HT[f] = x;
            return 1;
        }
        cout<<"collision occured"<<endl;
    }
    return -1;
}
int DoubleHashing::Delete(int x)
{
    int flag=Hashing(x,0);
    int f = Hashing(x,0);
    if(isEmpty(f)){
       HT[f] = x;
       return 1;}
    for(int i=1;i<Tablesize;i++){
       int f = Hashing(x,i);
       if(flag==f)return -2;
       if(x==HT[f]){
            HT[f] = -1;
            return 1;
        }
    }
    return -1;
}
int DoubleHashing::Search(int x)
{   int flag=Hashing(x,0);
    if(isEmpty(flag)){
          HT[flag]=x;
          return 1;}
    for(int i=1;i<Tablesize;i++){
        int f = Hashing(x,i);
        if(flag==f)return -2;
        if(HT[f]==x){
            return f;
        }
    }
    return -1;
}
void DoubleHashing::Display()
{
    for(int i=0;i<Tablesize;i++){
        cout<<HT[i]<<" ";
    }
    cout<<endl;
}
int DoubleHashing::Hashing(int x,int i)
{
    int h1 = x%Tablesize;
    int h2 = r - x%r;
    int f = (h1+(i*h2))%Tablesize;
    return f;
}
int DoubleHashing::isEmpty()
{
    for(int i=0;i<Tablesize;i++){
        if(HT[i]!=-1)
            return 0;
    }
    return 1;
}
int DoubleHashing::isEmpty(int i)
{
    return HT[i]==-1;
}


int main()
{
    int ch,V,capacity;
    cout<<"Enter the table size";
    cin>>capacity;
    DoubleHashing dh(capacity);
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
                int e =dh.Insert(V);
                if( e<1){cout<<"Space not found\n";}
                else{
                   cout<<"Insertion successfull"<<endl;}
                break;
            }
            case 2:
            {
                cout<<"Enter the value  to delete:";
                cin>>V;
                int e =dh.Delete(V);
                if( e<1){cout<<"Error\n";}
                break;
            }
            case 3:
            {
                cout<<"Enter the value  to search:";
                cin>>V;
                int e =dh.Search(V);
                if( e==-1)
                {cout<<"Error"<<endl;}
                else{cout<<"The index is "<<e<<endl;}
                break;
            }
            case 4:
            {
                int e = dh.isEmpty();
                if(e==1){cout<<"Empty";}
                else{cout<<"Not empty";}
                break;
            }
            case 5:
            {
                dh.Display();
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
