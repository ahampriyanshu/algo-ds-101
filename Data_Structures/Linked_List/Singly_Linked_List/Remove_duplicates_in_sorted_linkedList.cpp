//Assuming the Linked List is Sorted//



 
struct ListNode {
    int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        vector<int> check;
        ListNode *temp = head;
        int count=0;
        while(temp!=NULL){
            if(check.empty()){
                check.push_back(temp->val);
            }else{
                if(check.back()!=temp->val){
                    check.push_back(temp->val);
                }
            }
            temp=temp->next;
        }
        temp=head;
        ListNode *temp2,*temp3;
        for(int i=0;i<check.size();i++){
            temp->val=check[i];
            if(i==check.size()-1){
                temp2=temp->next;
                temp->next=NULL;
                break;
            }
            temp=temp->next;
        }
        return head;
    }
};
