/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 232ms
 */
public class Solution {
    public int lengthOfLastWord(String s) {
        char[] str = s.toCharArray();
        int sum=0,length=0;
        for(int i=0;i<str.length;i++){
            if(str[i]==' '){
                if(sum!=0)length=sum;
                sum=0;
            }else{
                sum++;
            }
        }
        if(sum!=0)length=sum;
        return length;
    }
}