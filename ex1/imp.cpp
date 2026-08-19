#include "header.h"
A_List::A_List()
{
    size=0;
    capacity=10;
    arr=new int[capacity];
    for (int i = 0 ; i<10 ; i++)
        arr[i]=-1;
}
A_List::A_List(int* a,int c,int s)
{
    size=s;
    capacity=c;
    arr=new int[capacity];
    for (int i = 0 ; i<s ; i++)
        arr[i]=a[i];
    for (int i = s ; i<c ; i++)
        arr[i]=-1;
}
A_List::A_List(const A_List& obj)
{
    size=obj.size;
    capacity=obj.capacity;
    arr=new int[capacity];
    for (int i = 0 ; i<size ; i++)
        arr[i]=obj.arr[i];
    for (int i = size ; i<capacity ; i++)
        arr[i]=-1;
}
A_List::~A_List()
{
    size=0;
    capacity=0;
    delete[] arr;
    arr=NULL;
}
int A_List::isFull()
{
    if(size==capacity)
    {
        return 1;
    }
    else{
        return 0;
    }
}
int A_List::isEmpty()
{
    if(size==0)
    {
        return 1;
    }
    else{
        return 0;
    }
}
int A_List::insertAtFirst(int a)
{
    if(isFull())
    return -1;
    else if(isEmpty())
    {
        arr[size++]=a;
        return 1;
    }
    else{
        for(int i=size;i>0;i--)
        {
            arr[i]=arr[i-1];
        }
        arr[0]=a;
        size++;
        return 1;
    }

}
int A_List::insertAtLast(int a)
{
    if(isFull())
    return -1;
    else{
        arr[size++]=a;
        return 1;
    }
}
int A_List::insertByPosition(int a,int pos)
{
    if(isFull())
    return -1;
    else if(isEmpty()&&(pos==1))
    {
        arr[size++]=a;
        return 1;
    }
    else if(isEmpty()&&(pos!=1))
    {
        return -2;
    }

    else{
        for(int i=size;i>pos-1;i--)
        {
            arr[i]=arr[i-1];
        }
        arr[pos-1]=a;
        size++;
        return 1;
    }
}
int A_List::insertAtMiddle(int a)
{
   insertByPosition(a,(size/2+1));
}
 /*   if(isFull())
    return -1;
    else if(isEmpty())
    {
        arr[size++]=a;
        return 1;
    }
    else{
        for(int i=size;i>size/2;i--)
        {
            arr[i]=arr[i-1];
        }
        arr[size/2]=a;
        size++;
        return 1;
    }
}*/
int A_List::deleteAtFirst()
{
    if(isEmpty())
    {
        return -1;
    }
    else{
        for(int i=0;i<size-1;i++)
        {
            arr[i]=arr[i+1];
        }
        arr[size-1]=-1;
        size--;
        return 1;
    }

}
int A_List::deleteAtLast()
{
    if(isEmpty())
    {
        return -1;
    }
    else{
        arr[size-1]=-1;
        size--;
        return 1;
    }

}
int A_List::deleteByPosition(int pos)
{
   if(isEmpty())
    {
        return -1;
    }
    else{
        for(int i=pos-1;i<size;i++)
        {
            arr[i]=arr[i+1];
        }
        size--;
        return 1;
    }
}
int A_List::deleteByIndex(int index)
{
   if(isEmpty())
    {
        return -1;
    }
    else{
        for(int i=index;i<size;i++)
        {
            arr[i]=arr[i+1];
        }
        size--;
        return 1;
    }
}
int A_List::retreiveData(int a)
{
    if(isEmpty()||(a>=size))
        return -1;
    else
    {
        cout<<"The element in the given index "<<a<<" is "<<arr[a]<<endl;
        return 1;
    }
}
int A_List::indexOfTheElement(int a)
{
    if(isEmpty())
    {
        return -1;
    }
    else
    {
        for(int i=0;i<size;i++)
        {
            if(arr[i]==a)
            {
               return i;
            }
        }
        return -2;
    }
}
int A_List::updateList(int old,int n)
{
   if(isEmpty())
    {
        return -1;
    }
    else
    {
        for(int i=0;i<size;i++)
        {
            if(arr[i]==old)
            {
                arr[i]=n;
                return 1;
            }
        }
        return -2;
    }
}
int A_List::displayList()
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 1;
}
int A_List::lengthOfList()
{
    return size;
}
int A_List::makeListEmpty()
{
    for (int i=0;i<capacity;i++)

    {
        deleteByIndex(i);
    }
    return 1;
}
int A_List::insertAfterElement(int a,int b)
{
   if(isEmpty()||isFull())
   {
      return -1;

   }
   else if(indexOfTheElement(a)==1)
   {
      int i;
      for(i=0;i<size;i++)
      {
         if(arr[i]==a)
         {break;
         }
      }
      insertByPosition(b,i+2);
      return 1;
   }
   else
      return -2;
}
int A_List::deleteBeforeElement(int a)
{
   if(isEmpty())
      return -1;
   else if(indexOfTheElement(a)==1)
   {
      int i;
      for(i=0;i<size;i++)
      {
         if(arr[i]==a)
            break;
      }
      if(i>0)
      {
      deleteByPosition(i);
      return 1;
      }
      else
      {
         return -2;
      }
   }
   else
      return -2;
}
int A_List::reverseList()
{
   for(int i=size-1;i>=0;i--)
      cout<<arr[i]<<" ";
}
