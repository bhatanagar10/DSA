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
    template <typename T>struct tree *insert_in_binary_tree(T data){
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

      display_binary_tree(Node->left);
      cout<<Node->data<<" ";
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

    bool isIdentical(struct tree *root1 , struct tree *root2){

        if(root1== NULL && root2 == NULL ){
            return true;
        }

        if((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL)){
            return false;
        }

        bool left = isIdentical(root1->left , root2->left);
        bool right = isIdentical(root1->left , root2->right);

        bool equal = root1->data == root2->data;

        if(left && right &&  equal){
            return true;
        }
        else{
            return false;
        }

    }

    pair<bool,int> isSumTree(struct tree *root){

        pair<int,int>p;
        if(root== NULL){
            p= make_pair(true, 0);
            return p;
        }

        if(root->left == NULL && root->right== NULL){
            p= make_pair(true , root->data);
        }

        pair<bool,int>left= isSumTree(root->left);
        pair<bool,int>right= isSumTree(root->right);
        p.second =2 * root->data;

        if(left.first && right.first && root->data == left.second + right.second){
            p.first = true;

        }
        else{
            p.first= false;
        }

        return p;
    }

    void preOrdertraversal(struct tree *root){
        if(root==NULL){
            return;
        }

        cout<<root->data<<" ";
        preOrdertraversal(root->left);
        preOrdertraversal(root->right);
    }

    void inOrdertraversal(struct tree *root){
        if(root==NULL){
            return;
        }

        inOrdertraversal(root->left);
        cout<<root->data<<" ";
        inOrdertraversal(root->right);
    }

    void postOrdertraversal(struct tree *root){
        if(root==NULL){
            return;
        }

        postOrdertraversal(root->left);

        postOrdertraversal(root->right);
        cout<<root->data<<" ";
    }

    void level_order_traversal(struct tree *root){

        queue<struct tree *>q;
        vector<char>answer;
        q.push(root);

        while(!q.empty()){

            if(q.front()->left!=NULL){
                q.push(q.front()->left);
            }
            if(q.front()->right!=NULL){
                q.push(q.front()->right);
            }

            answer.push_back(q.front()->data);
            q.pop();
        }

        for(auto i:answer){
            cout<<i<<" ";
        }

    }

    void zigZagtraversal(struct tree *root){

        queue<struct tree*>q;
        q.push(root);
        bool lefttoRight=true;
        vector<char>result;
        while(!q.empty()){
            int size = q.size();
            vector<char>temp(size);
            for(int i=0; i <size ; i++){
                int index = lefttoRight ? i : size - i -1;

                temp[index] = q.front()->data;

                if(q.front()->left)
                    q.push(q.front()->left);
                if(q.front()->right)
                    q.push(q.front()->right);
                q.pop();
            }

            lefttoRight = !lefttoRight;
            for(auto i: temp){
                result.push_back(i);
            }
        }
        for(auto i :result){
            cout<<i<<" ";
        }
    }

    void print_left(struct tree *node){

        if( ( !node->left && !node->right ) || !node){
            return;
        }

        cout<<node->data<<" ";
        if(node->left)
            print_left(node->left);
        else    
            print_left(node->right);
    }

    void print_right(struct tree *node){

        if( ( !node->left && !node->right ) || !node){
            return;
        }

        if(node->right)
            print_right(node->right);
        else    
            print_right(node->left);
        cout<<node->data<<" ";
    }

    void print_leaf(struct tree * node){
        if( !node->left && !node->right){
            cout<<node->data<<" ";
            return;
        }

        print_leaf(node->left);
        print_leaf(node->right);
    }
    
    void boundary_nodes(struct tree *root){

        print_left(root);
        print_leaf(root);
        print_right(root->right); 
    }

    void vertTrav(struct tree *node , int distance , map<int,map<int,vector<int>>>&m , int level){

        if(!node){
            return;
        }

        m[distance][level].push_back(node->data);
        vertTrav(node->left , distance-1 , m, level+1);
        vertTrav(node->right , distance+1 , m, level+1);
    }

    void vertical_traversal(struct tree *node){

        map<int,map<int,vector<int>>>m;
        vertTrav(node , 0 , m , 0);

        vector<vector<int>>vec;
        for(auto i:m){
            vector<int>v;
            for(auto j: i.second){
                vector<int>temp;
                for(auto k:j.second){
                    temp.push_back(k);
                }
                sort(temp.begin() , temp.end());
                for(auto x:temp)
                    v.push_back(x);
            }
            vec.push_back(v);
        }
        for(auto i :vec){
            for(auto j:i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }

    void topFunc(struct tree *node , int distance , map<int,pair<int,int>>&m , int level){
        if(!node){
            return;
        }

        if(m.find(distance) == m.end()){
            m[distance].first= node->data;
            m[distance].second = level;
        }
        else if(m[distance].second > level){
            m[distance].first= node->data;
            m[distance].second = level;
        }
        topFunc(node->left , distance-1 , m , level+1);
        topFunc(node->right , distance+1 , m , level+1);
    }

    void top_view(struct tree *node){

        int distance=0;
        map<int,pair<int,int>>m;
        topFunc(node , distance , m , 0);
        for(auto i:m){
            cout<<i.first<<" "<<i.second.first<<endl;
        }
    }

    void bottomFunc(struct tree *node , int distance , map<int,pair<int,int>>&m, int level){
        if(!node){
            return;
        }
       
        if(m.find(distance) == m.end()){
             m[distance].first= node->data;
             m[distance].second = level;
        }

        else if(m[distance].second <= level){            
             m[distance].first= node->data;
             m[distance].second = level;
        }

        bottomFunc(node->left , distance-1 , m , level+1);
        bottomFunc(node->right , distance+1 , m, level+1);
    }

    void bottom_view(struct tree *node){

        int distance=0;
        map<int,pair<int,int>>m;
        bottomFunc(node , distance , m ,0);
        for(auto i:m){
            cout<<i.first<<" "<<i.second.first<<endl;
        }
    }
    /* left view with queue */
    /* void leftViewFunc(vector<tree*>&vec, queue<tree*>&q){

        if(q.empty()){
            return;
        }
        int size = q.size();
        
        vec.push_back(q.front());

        while(size>0){
            if(q.front()->left)
                q.push(q.front()->left);
            if(q.front()->right)    
                q.push(q.front()->right);

            q.pop();
            size--;
        }

        leftViewFunc(vec,q);
    }

    void leftView(struct tree *node){

        queue<tree*>q;
        q.push(node);
        vector<tree*>vec;
        leftViewFunc(vec,q);

        for(auto i: vec){
            cout<<i->data<<" ";
        }

    } */

/* left view without queue */
    void leftViewFunc(tree *node , vector<int>&vec, int level){

        if(!node){
            return;
        }

        if(level == vec.size())
            vec.push_back(node->data);

        leftViewFunc(node->left , vec , level+1);
        leftViewFunc(node->right , vec , level+1);
    }

    void leftView(struct tree *node){

        vector<int>vec;
        leftViewFunc(node, vec,0);

        for(auto i: vec){
            cout<<i<<" ";
        }

    }
    void rightViewFunc(vector<tree*>&vec, queue<tree*>&q){

        if(q.empty()){
            return;
        }
        int size = q.size();
        tree *temp=NULL;

        while(size>0){
            if(q.front()->left)
                q.push(q.front()->left);
            if(q.front()->right)    
                q.push(q.front()->right);

            temp=q.front();
            q.pop();
            size--;
        }

        vec.push_back(temp);
        rightViewFunc(vec,q);
    }

    void rightView(struct tree *node){

        queue<tree*>q;
        q.push(node);
        vector<tree*>vec;
        rightViewFunc(vec,q);

        for(auto i: vec){
            cout<<i->data<<" ";
        }

    }

    void diagonalTraverseFunc(tree *node , int d , map<int,vector<int>>&m){

        if(!node){
            return;
        }

        m[d].push_back(node->data);

        diagonalTraverseFunc(node->left , d-1 , m);
        diagonalTraverseFunc(node->right , d , m);
    }

    void digonalTraverse(tree *node , int d ){
        map<int , vector<int>>m;
        diagonalTraverseFunc(node , 0 , m);

      
        vector<int>vec;
        int k=0;
        while(1){
            if(m.find(k)== m.end())
                break;

            for(auto i:m[k]){
                vec.push_back(i);
            }
            k--;
            
        }

        for(auto i:vec){
            cout<<i<<" ";
        }
    }

    // sum of nodes on the longest path from root to leaf
    pair<int,int> sumOfnodesoflongestpath(struct tree *node){
        pair<int,int>p;

        if(node == NULL){
            p=make_pair(0,0);
            return p;
        }

        pair<int,int>left = sumOfnodesoflongestpath(node->left);
        pair<int,int>right = sumOfnodesoflongestpath(node->right);

        if(left.first == right.second){
            p.first= right.first+1;
            p.second = node->data + max(right.second,left.second);
        } 
        else if(left.first > right.second){
            p.first= left.first+1;
            p.second = node->data + left.second;
        }
        else{
            p.first= right.first+1;
            p.second = node->data + right.second;
        }
        cout<<p.first<<" "<<p.second<<endl;
        return  p ;
    }

    tree *leastCommonancestor(struct tree *node , int m ,int n){
        if(!node)
            return NULL;

        if(node->data == m || node->data == n)
            return node;

        struct tree *left =leastCommonancestor(node->left , m , n);  
        struct tree *right =leastCommonancestor(node->right , m , n);

        if(left && right){
            return node;
        }
        else if(left == NULL && right== NULL){
            return NULL;
        }
        else if(left != NULL){
            return left; 
        }
        else{
            return right;
        }
    }

    pair<bool,tree *> kthAncestor(struct tree *node , int m ,int n , int &count){
        
        pair<bool,tree *>p;
        if(!node){
            p=make_pair(false, nullptr);
            return p;
        }            

        if(node->data == m || node->data == n){
            p=make_pair(false,node);
            return p;
        }    

        pair<bool,tree *>left =kthAncestor(node->left , m , n,count);  
        pair<bool,tree *>right =kthAncestor(node->right , m , n,count);

        if((left.first || right.first) && count>0){
            p=make_pair(true , node);
            count--;
            return p;
        }


        if(left.second && right.second){
            count--;
            p=make_pair(true,node);
            return p;
        }
        else if(left.second == NULL && right.second == NULL){
            p=make_pair(false,nullptr);
            return p;
        }
        else if(left.second != nullptr){
            p=make_pair(false,left.second);
            return p; 
        }
        else{
            p=make_pair(false,right.second);
            return p;
        }
    }

    // find maximum sum of the adjacent nodes
    void maxSumofAdjacentNodesFunc(tree *node , pair<int,int>&sum , bool check){
        if(!node){
            return;
        }

        if(check){
            sum.first+=node->data;
        }
        else{
            sum.second+=node->data;
        }

        maxSumofAdjacentNodesFunc(node->left, sum , !check);
        maxSumofAdjacentNodesFunc(node->right, sum , !check);


    }

    void maxSumofAdjacentNodes(struct tree *node ){  
        pair<int,int>sum=make_pair(0,0);      
        maxSumofAdjacentNodesFunc(node , sum ,true);
        cout<<sum.first<<" "<<sum.second; 

    }

};

int code(){
    //code here
    binary_tree obj;
    struct tree *root= obj.insert_in_binary_tree(1);
    root->left= obj.insert_in_binary_tree(2);
    root->left->left= obj.insert_in_binary_tree(4);
    root->left->right= obj.insert_in_binary_tree(5);

    root->right=obj.insert_in_binary_tree(3);
    root->right->left=obj.insert_in_binary_tree(6);
    root->right->left->right=obj.insert_in_binary_tree(8);
    root->right->left->left=obj.insert_in_binary_tree(10);
    root->right->right= obj.insert_in_binary_tree(7);
    root->right->right->right= obj.insert_in_binary_tree(9);

    /* struct tree *root= obj.insert_in_binary_tree('A');
    root->left= obj.insert_in_binary_tree('B');
    root->right=obj.insert_in_binary_tree('C');
    root->left->left=obj.insert_in_binary_tree('D');
    root->left->right=obj.insert_in_binary_tree('E');
    root->right->left= obj.insert_in_binary_tree('F');
    root->right->right= obj.insert_in_binary_tree('G'); 
    root->left->right->left=obj.insert_in_binary_tree('H');
    root->left->right->right=obj.insert_in_binary_tree('I');

    root->right->right->left= obj.insert_in_binary_tree('J');
    root->right->right->right= obj.insert_in_binary_tree('K');*/

    /* obj.display_binary_tree(root);
    cout<<endl<<"Height:-"<<obj.get_height_binary_tree(root)<<endl;
    pair<int,int>p=obj.get_diameter_binary_tree(root);
    cout<<"Diameter:-"<<p.first<<endl;

    if(obj.isBalanced(root).first)
        cout<<"Balanced"<<endl;

    else
        cout<<"Unbalanced"<<endl;

    if(obj.isSumTree(root).first)
        cout<<"SumTree"<<endl;

    else
        cout<<"Not SumTree"<<endl;
 

    cout<<"Pre order:- "; obj.preOrdertraversal(root); cout<<endl;
    cout<<"Inorder:- "; obj.inOrdertraversal(root); cout<<endl;
    cout<<"Post order:- "; obj.postOrdertraversal(root); cout<<endl;
    cout<<"Level order traversal:-"; obj.level_order_traversal(root);cout<<endl;
    obj.zigZagtraversal(root);
 */
    
    // obj.display_binary_tree(root);
    // obj.boundary_nodes(root);
    // obj.vertical_traversal(root);
    // obj.top_view(root);
    // obj.bottom_view(root);
    // obj.leftView(root);
    // obj.rightView(root);
    // obj.digonalTraverse(root,0);
    // cout<<obj.sumOfnodesoflongestpath(root).second;
    // cout<<obj.leastCommonancestor(root, 8 ,9 )->data;
    int count=2;
    // cout<<obj.kthAncestor(root, 8 ,10 , count).second->data;
    obj.maxSumofAdjacentNodes(root);


    return 0;
}

int main(){
    code();
    return 0;
}
