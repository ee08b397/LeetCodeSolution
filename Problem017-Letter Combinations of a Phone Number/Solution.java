/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 253ms
 */
public class Solution {
    char[][] map={" ".toCharArray(), "".toCharArray(), 
    "abc".toCharArray(), "def".toCharArray(), "ghi".toCharArray(), 
    "jkl".toCharArray(), "mno".toCharArray(), "pqrs".toCharArray(), 
    "tuv".toCharArray(), "wxyz".toCharArray()};
    int length=0;
    public List<String> letterCombinations(String digits) {
        List<String> res = new ArrayList<String>();
        length=digits.length();
        if(length==0)return res;
        char[] tmp = new char[length];
        char[] newdigits = digits.toCharArray();
        getLetterCom(res,0,newdigits,tmp);
        return res;
    }
    private void getLetterCom(List<String> res,int index,char[] digits,char[] tmp){
        if(index>=length){
            String letters = new String(tmp);
            res.add(letters);
            return;
        }
        int digit=digits[index]-'0';
        for(int i=0;i<map[digit].length;i++){
            tmp[index]=map[digit][i];
            getLetterCom(res,index+1,digits,tmp);
        }
    }
}