#include "header.h"
int main()
{
    A_List obj;
    int choice,n1,n2,e,pos;

        cout<<"\n\nFunctions of array"<<endl;
    cout<<"1.InsertAtFirst\t2.InsertAtLast\t3.insertByPosition\n4.IsFull\t5.IsEmpty\t6.displayList\n7.deleteAtFirst\t8.deleteAtLast\t9.deleteByPosition\n10.deleteByIndex\t11.insertAtMiddle\n12.retreiveData\t13.indexOfTheElement\t14.updateList\n15.lengthOfList\t16.makeListEmpty\t17.reverseList\n18.DeleteBeforeElement\t19.InsertAfterElement\n20.Exit\nEnter your choice:";
    cin>>choice;
    do{
    switch(choice)
    {
        case 1:
        {
            cout<<"Enter the value to insert at first:";
            cin>>n1;
            e=obj.insertAtFirst(n1);

            if (e!=1)
                cout<<"the list is full"<<endl;
            break;
        }
        case 2:
        {
            cout<<"Enter the value to insert at last:";
            cin>>n1;
            e=obj.insertAtLast(n1);
            if (e!=1)
                cout<<"the list is full"<<endl;
            break;
        }
        case 3:
        {
            cout<<"Enter the value to insert:";
            cin>>n1;
            cout<<"enter the position:";
            cin>>pos;
            e=obj.insertByPosition(n1,pos);
            if (e!=1)
                cout<<"position not found/list is full"<<endl;
            break;
        }
        case 4:
        {
            e=obj.isFull();
            if (e==1)
                cout<<"File is full"<<endl;
            else
                cout<<"the file is not full"<<endl;
            break;
        }
        case 5:
        {
            e=obj.isEmpty();
            if (e==1)
                cout<<"File is empty"<<endl;
            else
                cout<<"the file is not empty"<<endl;
            break;
        }
        case 6:
        {
            obj.displayList();
            break;
        }
        case 7:
        {
            e=obj.deleteAtFirst();
            if (e!=1)
                cout<<"list is empty"<<endl;
            break;
        }
        case 8:
        {
            e=obj.deleteAtLast();
            if (e!=1)
                cout<<"list is empty"<<endl;
            break;
        }
        case 9:
        {
            cout<<"enter the position:";
            cin>>pos;
            e=obj.deleteByPosition(pos);
            if (e!=1)
                cout<<"position out of bound"<<endl;
            break;
        }
        case 10:
        {
            cout<<"enter the index:";
            cin>>pos;
            e=obj.deleteByIndex(pos);
            if (e!=1)
                cout<<"index outof bound"<<endl;
            break;
        }
        case 11:
        {
            cout<<"Enter the value to insert at middle:";
            cin>>n1;
            obj.insertAtMiddle(n1);
            break;
        }
        case 12:
        {
            cout<<"enter the index:";
            cin>>pos;
            e=obj.retreiveData(pos);
            cout<<"The element in the position is "<<e<<endl;
            if (e<1)
                cout<<"Element not found"<<endl;
            break;
        }
        case 13:
        {
            cout<<"enter the element:";
            cin>>n1;
            e=obj.indexOfTheElement(n1);
            if (e<1)
                cout<<"Element not found"<<endl;
            break;
        }
        case 14:
        {
            cout<<"enter old value:";
            cin>>n1;
            cout<<"enter new value:";
            cin>>n2;
            e=obj.updateList(n1,n2);
            if (e<1)
                cout<<"Element not found"<<endl;
            break;
        }
        case 15:
        {
            e=obj.lengthOfList();
            cout<<"The length of the list is "<<e<<endl;
            break;
        }
        case 16:
        {
            obj.makeListEmpty();
            break;
        }
        case 17:
        {
           obj.reverseList();
           break;
        }
        case 18:
        {
           cout<<"Enter the elment to delete the element before it:";
           cin>>n1;
           e=obj.deleteBeforeElement(n1);
           if (e!=1)
              cout<<"Element not found"<<endl;
           break;
        }
        case 19:
        {
           cout<<"Enter the element to which the next element inserted:";
           cin>>n1;
           cout<<"Enter the element to be inserted:";
           cin>>n2;
           e=obj.insertAfterElement(n1,n2);
           if (e!=1)
              cout<<"Element not found"<<endl;
           break;
        }
        case 20:
        {
            cout<<"Exiting the loop";
            break;
        }
        default:
        {
            cout<<"invalid choice"<<endl;
        }
    }
    cout<<"\nEnter your choice:";
    cin>>choice;
    }while(choice!=20);
}
