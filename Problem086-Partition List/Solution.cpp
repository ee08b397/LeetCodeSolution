/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 8ms
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *node = new ListNode(0);
        node->next = head;
        ListNode *l,*r,*tmp;
        l=node;
        while(l->next!=NULL && l->next->val < x)l=l->next;
        r=l;
        while(r->next!=NULL){
            if(r->next->val < x){
                tmp = r->next;
                r->next = tmp->next;
                tmp->next = l->next;
                l->next = tmp;
                l=l->next;
            }else r = r->next;
        }
        return node->next;
    }
};
