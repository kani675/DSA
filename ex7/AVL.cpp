#include<iostream>
using namespace std;
class AVL_TreeNode{
    private:
        int data;
        int height;
        AVL_TreeNode* left;
        AVL_TreeNode* right;
    public:
        AVL_TreeNode(int);
        ~AVL_TreeNode();
        friend class L_AVL;
};
class L_AVL{
    private:
        AVL_TreeNode* root;
    public:
        L_AVL();
        ~L_AVL();
        AVL_TreeNode* insert(AVL_TreeNode*,AVL_TreeNode*);
        AVL_TreeNode* insert(AVL_TreeNode*);
        //void Delete(AVL_TreeNode*);

        int Search(int);
        int FindMin();
        int FindMax();
        int isEmpty();
        void inorder(AVL_TreeNode*);//inorder
        void preorder(AVL_TreeNode*);
        void postorder(AVL_TreeNode*);
        int getHeight(AVL_TreeNode*);
        AVL_TreeNode* LLRotate(AVL_TreeNode*);
        AVL_TreeNode* RRRotate(AVL_TreeNode*);
        AVL_TreeNode* RLRotate(AVL_TreeNode*);
        AVL_TreeNode* LRRotate(AVL_TreeNode*);
        int max(int,int);
        int BF(AVL_TreeNode*);
        AVL_TreeNode* getroot();
};
//AVL_TreeNode* BALANCE(AVL_TreeNode*);

AVL_TreeNode::AVL_TreeNode(int d){
    data=d;
    left=NULL;
    right=NULL;
    height=0;
}
AVL_TreeNode::~AVL_TreeNode(){
    data=-1;
    height=-1;
    left=NULL;
    right=NULL;
}
L_AVL::L_AVL(){
    root=NULL;
}
L_AVL::~L_AVL(){
    root=NULL;
}
AVL_TreeNode* L_AVL::insert(AVL_TreeNode* currentNode, AVL_TreeNode* newNode) {
    // Base case
    if (currentNode ==NULL )
        return newNode;

    // Recursive case
    if (newNode->data < currentNode->data)
        currentNode->left = insert(currentNode->left, newNode);
    else if (newNode->data > currentNode->data)
        currentNode->right = insert(currentNode->right, newNode);
    else
        return currentNode; // Duplicate nodes are not allowed

    currentNode->height = 1 + max(getHeight(currentNode->left), getHeight(currentNode->right));

    int balanceFactor = BF(currentNode);

    if (balanceFactor > 1 && newNode->data < currentNode->left->data)
        return LLRotate(currentNode);

    if (balanceFactor < -1 && newNode->data > currentNode->right->data)
        return RRRotate(currentNode);

    if (balanceFactor > 1 && newNode->data > currentNode->left->data) {
       // currentNode->left = LLRotate(currentNode->left);
        return LRRotate(currentNode);
    }

    if (balanceFactor < -1 && newNode->data < currentNode->right->data) {
     //   currentNode->right = RRRotate(currentNode->right);
        return RLRotate(currentNode);
    }

    return currentNode;
}

AVL_TreeNode* L_AVL::insert(AVL_TreeNode* newNode) {
    root = insert(root, newNode);
    return root;
}

int L_AVL::isEmpty(){
    if(root==NULL)
        return 1;
    else{
        return 0;}
}
int L_AVL::getHeight(AVL_TreeNode* myNode)
{
            if(myNode==NULL){
                return -1;    }
            else{
                return max(getHeight(myNode->left),getHeight(myNode->right))+1;
            }
}

int L_AVL::BF(AVL_TreeNode* myNode)
{
    if(myNode==NULL){
                return 0;    }
            else{
                if(myNode->left!=NULL&&myNode->right!=NULL)
                return myNode->left->height-myNode->right->height;
                else if(myNode->left==NULL&&myNode->right!=NULL)
                return -1-myNode->right->height;
                else if(myNode->left!=NULL&&myNode->right==NULL)
                return myNode->left->height+1;
                else
                return -999;
            }
}
int L_AVL::max(int a,int b)
{
    if(a<b)
        return b;
    else
        return a;
}
AVL_TreeNode* L_AVL::LLRotate(AVL_TreeNode* K3)
{
    AVL_TreeNode* K2 = K3->left;
    AVL_TreeNode* temp = K2->right;
    K2->right = K3;
    K3 ->left = temp;
    K3->height = max(getHeight(K3->left),getHeight(K3->right))+1;
    K2->height = max(getHeight(K2->left),getHeight(K2->right))+1;
    return K2;
}
AVL_TreeNode* L_AVL::RRRotate(AVL_TreeNode* K3)
{
    AVL_TreeNode* K2 = K3->right;
    AVL_TreeNode* temp = K2->left;
    K2->left = K3;
    K3 ->right = temp;
    K3->height = max(getHeight(K3->left),getHeight(K3->right))+1;
    K2->height = max(getHeight(K2->left),getHeight(K2->right))+1;
    return K2;
}
AVL_TreeNode* L_AVL::RLRotate(AVL_TreeNode* K3)
{
    K3->right = LLRotate(K3->right);
    return RRRotate(K3);
}
AVL_TreeNode* L_AVL::LRRotate(AVL_TreeNode* K3)
{
    K3->left = RRRotate(K3->left);
    return LLRotate(K3);
}
int L_AVL::Search(int key){
    if(isEmpty()){

        return -1;
    }
    else{
        AVL_TreeNode*temp=root;
        while(temp!=NULL)
        {

            if(temp->data>key)
                temp=temp->left;
            else if(temp->data<key)
                temp=temp->right;
            else
                return 1;
        }

        return -2;

    }
}
int L_AVL::FindMin(){
    if(isEmpty()){

        return -999;
    }
    else{
        AVL_TreeNode*temp=root;
        while(temp->left!=NULL)
        {
            temp=temp->left;
        }
        return temp->data;
    }
}
int L_AVL::FindMax(){
    if(isEmpty()){

        return -999;
    }
    else{
        AVL_TreeNode*temp=root;
        while(temp->right!=NULL)
        {
            temp=temp->right;
        }
        return temp->data;
    }
}
void L_AVL::preorder(AVL_TreeNode* temp)
{
    if(isEmpty()){

        cout<<"The list is empty";
    }
    if(temp!=NULL){
        cout<<temp->data<<" ";
        preorder(temp->left);
        preorder(temp->right);
    }

}
void L_AVL::inorder(AVL_TreeNode* temp)
{
   if(isEmpty()){
      cout<<"The list is empty";
   }
   if(temp!=NULL){
      //cout<<temp->data<<" ";

      inorder(temp->left);
      cout<<temp->data<<" ";
      inorder(temp->right);
   }
}
void L_AVL::postorder(AVL_TreeNode* temp)
{
   if(isEmpty()){
      cout<<"The list is empty";
   }
   if(temp!=NULL){
    //  cout<<temp->data<<" ";
      postorder(temp->left);
      postorder(temp->right);
      cout<<temp->data<<" ";
   }
}
AVL_TreeNode* L_AVL::getroot() {
    return root;
}

int main(){
    int ch,e,d,key;
    L_AVL obj;
    AVL_TreeNode* ee;
    cout<<"\n1.Insert\n2.Find MIN\n3.Find MAX\n4.Search\n5.IsEmpty\n6.inorder\n7.preorder\n8.Postorder\n9.Exit";
    do{
        cout<<"Enter your choice:";
        cin>>ch;
        switch(ch){
            case 1:
            {
                cout<<"Enter the data:";
                cin>>d;
                AVL_TreeNode* newNode = new AVL_TreeNode(d);
                ee=obj.insert(newNode);
                if(ee==NULL)
                    cout<<"Duplicate can t be inserted"<<endl;
                else if(ee!=obj.getroot()){
                   cout<<"continue rotation";
                }
                else
                    cout<<"the node is inserted "<<endl;
                break;
                }
            case 2:
            {
                e=obj.FindMin();
                if(e==-1)
                    cout<<"Empty"<<endl;
                else
                    cout<<"The mininumum term is "<<e<<endl;
                break;
            }
            case 3:
            {
                e=obj.FindMax();
                if(e==-1)
                    cout<<"Empty"<<endl;
                else
                    cout<<"The mininumum term is "<<e<<endl;
                break;
            }
            case 4:
            {
                cout<<"Enter the search key";
                cin>>key;
                e=obj.Search(key);
                if(e==1)
                    cout<<"The Search term is found"<<endl;

                else if(e==-2)
                    cout<<"The term not found"<<endl;
                else
                    cout<<"Empty"<<endl;
                break;
            }
            case 5:
            {
                e=obj.isEmpty();
                if(e==1)
                    cout<<"Empty"<<endl;
                else
                    cout<<"Not Empty"<<endl;
                break;
            }

            case 6: {
                if (obj.isEmpty())
                    cout << "The tree is empty\n";
                else{
                    obj.inorder(obj.getroot());
                cout << endl;}
                break;
                }
            case 7: {
                if (obj.isEmpty())
                   cout << "The tree is empty\n";
                else{
                   obj.preorder(obj.getroot());
                   cout << endl;}
                break;
                    }
            case 8: {
                 if (obj.isEmpty())
                    cout << "The tree is empty\n";
                 else{
                    obj.postorder(obj.getroot());
                    cout << endl;}
                 break;
                    }
            case 9:{break;}
            default:{
                cout<<"Invaalid";
            }
           /*case 7:
           {
               cout<<"Enter the delete element";
               cin>>key;
               e=obj.Delete(key);
               cout<<"the value of e is"<<e<<endl;
           }*/
        }
    }while(ch!=9);
}
