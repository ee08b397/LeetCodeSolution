/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 397ms
 */
public class Solution {
    public int romanToInt(String s) {
        int index=0,num=0,temp=0;
        char[] chs=s.toCharArray();
        while(index<s.length()){
            char c=chs[index++];
            switch(c){
                case 'I':num+=1;temp=1;break;
                case 'V':num+=temp==1?3:5;break;
                case 'X':num+=temp==1?8:10;temp=10;break;
                case 'L':num+=temp==10?30:50;break;
                case 'C':num+=temp==10?80:100;temp=100;break;
                case 'D':num+=temp==100?300:500;break;
                case 'M':num+=temp==100?800:1000;break;
            }
        }
        return num;
    }
}