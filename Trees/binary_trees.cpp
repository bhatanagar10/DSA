#include<typeinfo>
#include<bits/stdc++.h>

using namespace std;

struct tree{
    int data;
    struct tree* left= NULL;
    struct tree* right= NULL;
};

class binary_tree{

    public:
    struct tree *insert_in_binary_tree(int data){
        struct tree *newNode= new tree();
        newNode->data= data;
        newNode->left= NULL;
        newNode->right= NULL;
        return newNode;
    }

    void display_binary_tree(struct tree *Node){

      if(Node == NULL){
        return;
      }

      cout<<Node->data<<" ";
      display_binary_tree(Node->left);
      display_binary_tree(Node->right);
    }

    int get_height_binary_tree(struct tree *node){

      if(node == NULL){
        return 0;
      }

      int left = get_height_binary_tree(node->left);
      int right = get_height_binary_tree(node->right);

      return  max(left+1,right+1) ;
    }
    
    pair<int,int> get_diameter_binary_tree(struct tree *root){

        pair<int,int>p;
        if(root == NULL){

          p= make_pair(0,0);
          return p;
        }

        pair<int,int>leftD= get_diameter_binary_tree(root->left);
        pair<int,int>rightD= get_diameter_binary_tree(root->right);

        p.second= max(leftD.second +1 , rightD.second +1);
        p.first = max( max(leftD.first ,rightD.first) , (leftD.second + rightD.second +1) );

        return p;

    }

    pair<bool,int> isBalanced(struct tree *node){

        pair<bool,int>p;
        if(node == NULL){
            p= make_pair(true,0);
            return p;
        }
        
        pair<bool,int>left= isBalanced(node->left);
        pair<bool,int>right= isBalanced(node->right);

        p.second = max(left.second , right.second)+1;
    
        if(left.first && right.first && abs(left.second-right.second)<=1 ){

            p.first= true;
        }	                      
        else{
            p.first = false;
        }
    
        return p;
    }


};

int code(){
    //code here 
    binary_tree obj;
    struct tree *root= obj.insert_in_binary_tree(10);
    root->left= obj.insert_in_binary_tree(5);
    root->right=obj.insert_in_binary_tree(20);
    root->left->left=obj.insert_in_binary_tree(1);
    root->right->right= obj.insert_in_binary_tree(30);
    root->right->right->right= obj.insert_in_binary_tree(40);

    obj.display_binary_tree(root);
    cout<<endl<<"Height:-"<<obj.get_height_binary_tree(root)<<endl;
    pair<int,int>p=obj.get_diameter_binary_tree(root);
    cout<<"Diameter:-"<<p.first<<endl;
    
    if(obj.isBalanced(root).first)
        cout<<"Balanced"<<endl;

    else    
        cout<<"Unbalanced"<<endl;

    return 0;
}

int main(){
    code();
    return 0;
}