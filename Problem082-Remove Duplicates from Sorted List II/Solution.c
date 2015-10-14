/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 4ms
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *l,*r=head,*pre=NULL;
    if(head==NULL)return head;
    while(r!=NULL &&( (pre!=NULL && pre->val==r->val)||(r->next!=NULL && r->next->val==r->val) )){
        pre=r;
        r=r->next;
    }
    head=r;
    l=r;
    pre=r;
    if(r!=NULL)r=r->next;
    while(r!=NULL){
        if(!((pre!=NULL && pre->val==r->val)||(r->next!=NULL && r->next->val==r->val))){
            l->next=r;
            l=l->next;
        }
        pre=r;
        r=r->next;
        l->next=NULL;
    }
    return head;
}
