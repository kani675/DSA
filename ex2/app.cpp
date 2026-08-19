#include "header.h"

int main()
{
    L_List obj;
    int choice,d,e,pos;
    cout<<"\n\nFunctions of array"<<endl;
    cout<<"1.InsertAtFirst\t2.InsertAtLast\t3.insertByPosition\n4.insertAtMiddle\t5.IsEmpty\t6.displayList\n7.deleteAtFirst\t8.deleteAtLast\t9.deleteByPosition\n10.InsertAfteran Element\t11.Delete by anElement\n12.retreiveData\t13.countOfTheElement\t14.updateList\n15.position Of The Element\t16.make List Empty\n17.reverse\t18.Exit\nEnter your choice:";
    cin>>choice;
    do{
    switch(choice)
    {
        case 1:
        {
            cout<<"Enter the data value:";
            cin>>d;
            CNode *newNode = new CNode(d,NULL);
            obj.insertAtFirst(newNode);
            break;
        }
        case 2:
        {
            cout<<"Enter the data value:";
            cin>>d;
            CNode* newNode = new CNode(d,NULL);
            obj.insertAtLast(newNode);
            break;
        }
        case 3:
        {
            cout<<"Enter the data value:";
            cin>>d;
            CNode* newNode = new CNode(d,NULL);
            cout<<"Enter the position value:";
            cin>>pos;
            e=obj.insertByPosition(pos,newNode);
            if (e<1)
                cout<<"position out of range"<<endl;
            break;
        }
        case 4:
        {
            cout<<"Enter the data value:";
            cin>>d;
            CNode* newNode = new CNode(d,NULL);
            e=obj.insertAtMiddle(newNode);
            break;

        }
        case 5:
        {
            e=obj.isEmpty();
            if (e==1)
                cout<<"list is empty"<<endl;
            else
                cout<<"the list is not empty"<<endl;
            break;
        }
        case 6:
        {
            cout<<"displaying the list"<<endl;
            obj.displayList();
            break;
        }
        case 7:
        {
            e=obj.deleteAtFirst();
            if (e<1)
                cout<<"The list is empty"<<endl;
            break;
        }
        case 8:
        {
            e=obj.deleteAtLast();
            if (e<1)
                cout<<"the list is empty"<<endl;
            break;
        }
        case 9:
        {
            cout<<"enter the position:";
            cin>>pos;
            e=obj.deleteByPosition(pos);
            if (e<1)
                cout<<"the list is empty/the position out of range"<<endl;
            break;
        }
        case 10:
        {
           cout<<"Enter the data value to be inserted:";
           cin>>d;
           CNode* newNode = new CNode(d,NULL);
           cout<<"Enter the data value after which the insersion takes palce:";
           cin>>d;
           e=obj.insertAfterAnElement(d,newNode);

           if (e<1)
               cout<<"element not found"<<endl;
           break;
        }
        case 11:
        {
           cout<<"Enter the data value:";
           cin>>d;
           e=obj.deleteByValue(d);
           if (e<1)
               cout<<"Element not found"<<endl;
           break;
        }
        case 12:
        {
            cout<<"Enter the position value:";
            cin>>pos;
            e=obj.retreiveData(pos);
            cout<<"The data in the position is"<<e<<endl;
            if (e<1)
                cout<<"Element not found"<<endl;
            break;
        }
        case 13:
        {
            cout<<"displaying the count:"<<obj.countOfTheElement()<<endl;
            break;
        }
        case 14:
        {
            cout<<"Enter the new data value:";
            cin>>d;
            cout<<"Enter the position value to which it is inserted:";
            cin>>pos;
            e=obj.updateList(pos,d);
            if (e<1)
                cout<<"Element not found"<<endl;
            break;
        }
        case 15:
        {
            cout<<"Enter the data value:";
            cin>>d;
            e=obj.positionOfTheElement(d);
            cout<<"the position of the data is"<<e<<endl;
            if (e<1)
                cout<<"Element not found"<<endl;
            break;
        }
        case 16:
        {
            obj.makeListEmpty();
            break;
        }
        case 17:
        {
            cout<<"reverse\n";
            obj.reverse();
            break;
        }
        case 18:
        {
            cout<<"Exiting the loop";
            break;
        }
        default:
        {
            cout<<"invalid choice"<<endl;
        }
    }
    cout<<"\nEnter the choice:";
    cin>>choice;
    }while(choice!=18);
}

