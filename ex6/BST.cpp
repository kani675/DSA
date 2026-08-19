//Non recursive
#include<iostream>
using namespace std;
class TreeNode{
    private:
        int data;
        TreeNode* left;
        TreeNode* right;
    public:
        TreeNode(int);
        ~TreeNode();
        friend class L_BST;
};
class L_BST{
    private:
        TreeNode* root;
    public:
        L_BST();
        ~L_BST();
        int insert(TreeNode*);
        int Delete(int);
        int Search(int);
        int FindMin();
        int FindMax();
        int isEmpty();
        void preOrder(TreeNode*);
        void postOrder(TreeNode*);
        void inOrder(TreeNode*);
        TreeNode* getroot();
};


TreeNode::TreeNode(int d){
    data=d;
    left=NULL;
    right=NULL;
}
TreeNode::~TreeNode(){
    data=-1;
    left=NULL;
    right=NULL;
}
L_BST::L_BST(){
    root=NULL;
}
L_BST::~L_BST(){
    root=NULL;
}
int L_BST::insert(TreeNode* newNode){
    if(isEmpty()){
        root=newNode;
        return 1;
    }
    else{
        TreeNode*temp=root;
        TreeNode* parent=NULL;
        while(temp!=NULL)
        {
            parent=temp;
            if(temp->data>newNode->data)
                temp=temp->left;
            else if(temp->data<newNode->data)
                temp=temp->right;
            else
                return -1;//duplicate

        }
        if(parent->data>newNode->data)
            parent->left=newNode;
        else
            parent->right=newNode;
        return 2;

    }
}
int L_BST::isEmpty(){
    if(root==NULL)
        return 1;
    else
        return 0;
}
int L_BST::Search(int key){
    if(isEmpty()){

        return -1;
    }
    else{
        TreeNode*temp=root;
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
int L_BST::FindMin(){
    if(isEmpty()){

        return -999;
    }
    else{
        TreeNode*temp=root;
        while(temp->left!=NULL)
        {
            temp=temp->left;
        }
        return temp->data;
    }
}
int L_BST::FindMax(){
    if(isEmpty()){

        return -999;
    }
    else{
        TreeNode*temp=root;
        while(temp->right!=NULL)
        {
            temp=temp->right;
        }
        return temp->data;
    }
}
void L_BST::inOrder(TreeNode* temp)
{
       if(isEmpty()){
          cout<<"The list is empty";
       }
       if(temp!=NULL){
          inOrder(temp->left);
          cout<<temp->data<<" ";
          inOrder(temp->right);
       }
}
void L_BST::preOrder(TreeNode* temp)
{
       if(isEmpty()){
          cout<<"The list is empty";
       }
       if(temp!=NULL){
          cout<<temp->data<<" ";
          preOrder(temp->left);
          preOrder(temp->right);
       }
}
void L_BST::postOrder(TreeNode* temp)
{
    if(isEmpty()){

        cout<<"The list is empty";
    }
    if(temp!=NULL){

        postOrder(temp->left);
        postOrder(temp->right);
        cout<<temp->data<<" ";
    }

}
TreeNode* L_BST::getroot() {
    return root;
}
int L_BST::Delete(int ele) {
    TreeNode* temp = root;
    TreeNode* parent = NULL;

    while (temp != NULL) {
        if (temp->data == ele) {
             if (temp->left == NULL && temp->right == NULL) {
                if (temp == root) {
                    root = NULL;  // Root node is a leaf node
                } else {  // Normal leaf node
                    if (parent->left == temp) {
                        parent->left = NULL;
                    } else {
                        parent->right = NULL;
                    }
                }
                delete temp;
                return 1;  // Element deleted successfully
            }

            // Case 2: Single child
            else if (temp->left != NULL && temp->right == NULL) {
                if (temp == root) {
                    root = temp->left;  // Root with only left child
                } else {
                    if (parent->left == temp) {
                        parent->left = temp->left;
                    } else {
                        parent->right = temp->left;
                    }
                }
                delete temp;
                return 1;
            } else if (temp->left == NULL && temp->right != NULL) {
                if (temp == root) {
                    root = temp->right;  // Root with only right child
                } else {
                    if (parent->left == temp) {
                        parent->left = temp->right;
                    } else {
                        parent->right = temp->right;
                    }
                }
                delete temp;
                return 1;
            }

            // Case 3: Two children
            else if (temp->left != NULL && temp->right != NULL) {
                TreeNode* successorParent = temp;
                TreeNode* successor = temp->right;

                // Find the minimum value in the right subtree (inorder successor)
                while (successor->left != NULL) {
                    successorParent = successor;
                    successor = successor->left;
                }

                // Replace temp's data with successor's data
                temp->data = successor->data;

                // Delete the successor node
                if (successorParent->left == successor) {
                    successorParent->left = successor->right;
                } else {
                    successorParent->right = successor->right;
                }

                delete successor;
                return 1;
            }
        }

        // Update parent and traverse the tree
        parent = temp;
        if (temp->data < ele) {
            temp = temp->right;
        } else {
            temp = temp->left;
        }
    }

    return 0;  // Element not found
}


int main(){
    int ch,e,d,key;
    L_BST obj;
    cout<<"\n1.Insert\n2.Find MIN\n3.Find MAX\n4.Search\n5.IsEmpty\n6.Delete\n7.Inorder\n8.Preorder\n9.PostOrder\n10.Exit";
    do{
        cout<<"Enter your choice:";
        cin>>ch;
        switch(ch){
            case 1:
            {
                cout<<"Enter the data:";
                cin>>d;
                TreeNode* newNode = new TreeNode(d);
                e=obj.insert(newNode);
                if(e==-1)
                    cout<<"Duplicate can t be inserted"<<endl;
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

            case 7:
            {
               cout << "The tree in InOrder Format\n";
               obj.inOrder(obj.getroot());
               cout << endl;
               break;
            }
            case 8:
            {
               cout << "Displaying the Tree in Preorder \n";
               obj.preOrder(obj.getroot());
               cout << endl;
               break;
            }
            case 9:
            {
               cout << "The tree is empty\n";
               obj.postOrder(obj.getroot());
               cout << endl;
               break;
            }

           case 6:
           {
               cout<<"Enter the delete element";
               cin>>key;
               e=obj.Delete(key);
               if(e==1)
                  cout<<"Deletion is successfull\n";
               else if(e==-1)
                  cout<<"The tree is empty"<<endl;
               else
                  cout<<"the element not found"<<endl;
               break;
           }
           case 10:
                break;
          default:
           {
              cout<<"Invalid Choice";
              break;
           }
        }
    }while(ch!=10);
}
