
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}  ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0,sum=1,temp;
        ListNode *root= NULL , *node=NULL;
        
        while(l1 && l2){
            temp= l1->val + l2->val + carry;
            
            sum= temp % 10;
            carry=temp/10;            
                        
            if(!root){
                root = new ListNode(sum , NULL);
                node =root;
            }
            else{
                node->next = new ListNode(sum , NULL);
                node= node->next;
            }
            
            l1= l1->next;
            l2= l2->next;
        }
        
        while(l1){
            temp= l1->val + carry;
            
            sum= temp % 10;
            carry=temp/10;    
                        
            node->next = new ListNode(sum , NULL);;
            node= node->next;
            
            l1= l1->next;

        }
        while(l2){
            temp= l2->val + carry;
            
            sum= temp % 10;
            carry=temp/10;    
                        
            node->next = new ListNode(sum , NULL);;
            node= node->next;
            
            l2= l2->next;
        }
        
        if(carry){
            node->next= new ListNode(carry , NULL);;
        }
        return root;
    }
};