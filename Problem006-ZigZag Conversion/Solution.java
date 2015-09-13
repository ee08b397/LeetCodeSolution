/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 409ms
 */
public class Solution {
    public String convert(String s, int numRows) {
        if(numRows==1)return s;
        char[] chs=s.toCharArray();
        if(numRows==2){
            int index=0;
            for(int i=0;i<s.length();i=i+2)chs[index++]=s.charAt(i);
            for(int i=1;i<s.length();i=i+2)chs[index++]=s.charAt(i);
            return new String(chs);
        }
        char[][] map = new char[numRows][s.length()];
        int index=0,col=0;
        while(index<s.length()){
            if(col%2==1){
                int i=numRows-2;
                while(i>=1 && index<s.length())map[i--][col]=s.charAt(index++);
            }else{
                int i=0;
                while(i<numRows && index<s.length())map[i++][col]=s.charAt(index++);
            }
            col++;
        }
        index=0;
        for(int i=0;i<numRows;i++){
            for(int j=0;j<col;j++){
                if(map[i][j]!=0)chs[index++]=map[i][j];
            }
        }
        return new String(chs);
    }
}