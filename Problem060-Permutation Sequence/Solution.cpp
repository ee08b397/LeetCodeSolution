/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 0ms
 */
class Solution {
public:
    string getPermutation(int n, int k) {
        int per[10],i,j;
        char tmp;
        per[0]=1;
        for(i=1;i<10;i++){
            per[i] = per[i-1]*i;
        }
        char* str = (char*)malloc(sizeof(char)*10);
        for(i=0;i<n;i++){
            str[i] = i+1+'0';
        }
        str[i]=0;
        i=0;
        while(i<n){
            j=i;
            while(k>per[n-i-1]){
                k-=per[n-i-1];
                j++;
            }
            tmp = str[j];
            while(j>i){
                str[j] = str[j-1];
                j--;
            }
            str[j] = tmp;
            i++;
        }
        return string(str);
    }
};
