#include <iostream>
using namespace std;

struct node
{
    int data;
    int khang=0;
    node* right;
    node* left;
};

node* creatNode(int value){
    node* nodeNew=new node;
    nodeNew->data=value;
    nodeNew->left=nullptr;
    nodeNew->right=nullptr;
    return nodeNew;
}
void LNR(node * pNode){
    if(pNode==nullptr){
        return;
    }
    LNR(pNode->left);
    cout<<pNode->data<<" ";
    LNR(pNode->right);
}
void insertNode(node*& root,node * pNode){
    if(root==nullptr){
        root=pNode;
        return;
    }
    if(pNode->data < root->data){
        insertNode(root->left,pNode);
    }
    else{
        insertNode(root->right,pNode);
    }
}

node* SearchNode(node* root,int value){
    if(root==nullptr){
        return nullptr;
    }
    if(root->data==value){
        return root;
    }
    if(root->data<value){
        return SearchNode(root->right,value);
    }
    else{
        return SearchNode(root->left,value);
    }
}

void updateNode(node *root,int value,int valueNew){
    if(root==nullptr){
        cout<<"khong tim thay";
        return;
    }
    if(root->data==value){
        root->khang=valueNew;
        return;
    }
    if(root->data>value){
        updateNode(root->left,value,valueNew);
    }
    else{
        updateNode(root->right,value,valueNew);
    }
    
}
node*& minNode(node*& root){
    if(root->left==nullptr){
        return root;
    }
    return minNode(root->left);
}

void deleteNode(node*& root,int value){
    if(root==nullptr){
        return;
    }

    if(root->data<value){
        deleteNode(root->right,value);
    }
    else if(root->data>value){
        deleteNode(root->left,value);
    }
    else{
        node* temp=root;
        if(root->left==nullptr&& root->right==nullptr){
            root=nullptr;
            delete temp;
        }
        else if(root->left==nullptr){
            root=root->right;
            delete temp;
        }
        else if(root->right==nullptr){
            root=root->left;
            delete temp;
        }
        else{
            node*& minN=minNode(root->right);
            root->data=minN->data;

            node* tempMin=minN;
            minN=minN->right;
            delete tempMin;
        }
    }
}
int main(){
    node * root=creatNode(10);
    root->left=creatNode(9);
    root->right=creatNode(15);
    LNR(root);
    cout<<endl;
    node *khang=creatNode(20);
    node *khang1=creatNode(5);
    node *khang2=creatNode(11);
    insertNode(root,khang);
    insertNode(root,khang1);
    insertNode(root,khang2);
    LNR(root);

    // cout<<endl;
    // deleteNode(root,20);
    // LNR(root);

    
    cout<<endl;
    deleteNode(root,10);
    LNR(root);



    updateNode(root,20,10);
    cout<<endl<<root->right->right->khang;
    return 0;
}