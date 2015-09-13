/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 522ms
 */
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    private int[] tree;
    public ListNode mergeKLists(ListNode[] lists) {
        int len=lists.length;
        if(len==0)return null;
        else if(len==1)return lists[0];
        tree=new int[len];
        initTree(lists,len);
        if(lists[tree[1]]==null)return null;
        ListNode p,head;
        p=lists[tree[1]];
        lists[tree[1]]=lists[tree[1]].next;
        head=p;
        adjustToRoot(lists,(tree[1]+len)/2,len);
        while(lists[tree[1]]!=null){
            p.next=lists[tree[1]];
            lists[tree[1]]=lists[tree[1]].next;
            p=p.next;
            adjustToRoot(lists,(tree[1]+len)/2,len);
        }
        return head;
    }
    private void adjustToRoot(ListNode[] lists,int tar,int len){
        while(tar>0){
            adjustTree(lists,tar,len);
            tar=tar/2;
        }
    }
    private void initTree(ListNode[] lists,int len){
        for(int i=len-1;i>=1;i--){
            adjustTree(lists,i,len);
        }
    }
    private void adjustTree(ListNode[] lists,int i,int len){
        int l,r;
        if(i+i < len){
            l=tree[i+i];
        }else{
            l=i+i-len;
        }
        if(i+i+1 < len){
            r=tree[i+i+1];
        }else{
            r=i+i+1-len;
        }
        if(lists[l]==null)tree[i]=r;
        else if(lists[r]==null)tree[i]=l;
        else tree[i]= lists[l].val > lists[r].val ? r:l;
    }
}