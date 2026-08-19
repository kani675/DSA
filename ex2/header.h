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
        friend class L_List;
    private:
        int data;
        CNode* next;
};
class L_List
{
    public:
        L_List();
        L_List(CNode*);
        L_List(const L_List&);
        ~L_List();
        int insertAtFirst(CNode*);
        int insertAtLast(CNode*);
        int insertByPosition(int,CNode*);
        int isEmpty();
        void displayList();
        int deleteAtFirst();
        int deleteAtLast();
        int deleteByPosition(int);
        int insertAtMiddle(CNode*);
        int retreiveData(int);
        void reverse();
        int countOfTheElement();
        int updateList(int,int);
        void makeListEmpty();
        int positionOfTheElement(int);
        int deleteByValue(int);
        int insertAfterAnElement(int,CNode*);
    private:
        CNode* first;
};
