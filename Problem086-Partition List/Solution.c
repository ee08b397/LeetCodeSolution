/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 0ms
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *l,*r,*tmp;
    node->next = head;
    l=node;
    while(l->next!=NULL && l->next->val < x)l=l->next;
    r = l;
    while(r->next!=NULL){
        if(r->next->val < x){
            tmp = r->next;
            r->next = tmp->next;
            tmp->next = l->next;
            l->next = tmp;
            l=l->next;
        }else r=r->next;
    }
    return node->next;
}
