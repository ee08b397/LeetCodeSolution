/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 1ms
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *p=head,*s;
    if(p!=NULL && p->next!=NULL){
        s=p->next;
        p->next=s->next;
        s->next=p;
        head=s;
        while(p->next!=NULL && p->next->next!=NULL){
            s=p->next->next;
            p->next->next=s->next;
            s->next=p->next;
            p->next=s;
            p=s->next;
        }
    }
    return head;
}
