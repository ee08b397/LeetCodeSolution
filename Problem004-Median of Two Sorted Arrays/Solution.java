/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 509ms
 */

public class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        if((nums1.length+nums2.length)%2==1){
            return findKth(nums1,nums2,(nums1.length+nums2.length+1)/2);
        }else{
            return (1.0*findKth(nums1,nums2,(nums1.length+nums2.length+1)/2)+findKth(nums1,nums2,(nums1.length+nums2.length+1)/2+1))/2;
        }
    }
    public int findKth(int[] a,int[] b,int k){
        int len1=a.length,len2=b.length;
        if(len1==0)return b[k-1];
        if(len2==0)return a[k-1];
        if(k==1)return min(a[0],b[0]);
        int mid1=min(k/2,len1),mid2=min(k/2,len2);
        if(a[mid1-1] < b[mid2-1]){
            int[] c = new int[len1-mid1];
            for(int i=0;i<c.length;i++)c[i]=a[i+mid1];
            return findKth(c,b,k-mid1);
        }else{
            int[] c = new int[len2-mid2];
            for(int i=0;i<c.length;i++)c[i]=b[i+mid2];
            return findKth(a,c,k-mid2);
        }
    }
    public int min(int a,int b){
        return a>b?b:a;
    }
}