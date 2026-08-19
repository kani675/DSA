#include<iostream>
using namespace std;
class A_List{
private:
    int* arr;
    int capacity;
    int size;
public:
    A_List();
    A_List(int*,int,int);
    A_List(const A_List&);
    ~A_List();
    int insertAtFirst(int);
    int insertAtLast(int);
    int insertByPosition(int,int);
    int isFull();
    int isEmpty();
    int displayList();
    int deleteAtFirst();
    int deleteAtLast();
    int deleteByPosition(int);
    int deleteByIndex(int);
    int insertAtMiddle(int);
    int retreiveData(int);
    int indexOfTheElement(int);
    int updateList(int,int);
    int lengthOfList();
    int makeListEmpty();
    int deleteBeforeElement(int);
    int insertAfterElement(int,int);
    int reverseList();
};
