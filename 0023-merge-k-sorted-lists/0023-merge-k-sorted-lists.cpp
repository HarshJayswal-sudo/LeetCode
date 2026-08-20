/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* merge(ListNode* left,ListNode* right){
    ListNode* bummy = new ListNode(-1);
    ListNode* temp = bummy;
    while(left && right){
        if(left->val <= right->val){
            temp->next = left;
            left=left->next;
        }else{
            temp->next = right;
            right=right->next;
        }
        temp  = temp->next;
    }
    if(left){
        temp->next = left;
    }else{
        temp->next = right;
    }
    return bummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        int interval = 1;
        while(interval<lists.size()){
            for(int i=0;i+interval<lists.size();i+=interval*2){
                lists[i] = merge(lists[i],lists[i+interval]);
            }
            interval *=2;
        } 
        return lists[0];
    }
};