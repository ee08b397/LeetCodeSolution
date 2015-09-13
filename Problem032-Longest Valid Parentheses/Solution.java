/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 350ms
 */
public class Solution {
    public int longestValidParentheses(String s) {
        int len=s.length(),max=0;
        Stack<Character> str_stack = new Stack<Character>();
        Stack<Integer> pos_stack = new Stack<Integer>();
        char[] str=s.toCharArray();
        for(int i=0;i<len;i++){
            if(str[i]=='('){
                str_stack.push('(');
                pos_stack.push(i);
            }else{
                if(str_stack.size()>0 && str_stack.peek().equals('(')){
                    str_stack.pop();
                    pos_stack.pop();
                    int tmp=pos_stack.size()==0?i+1:i-pos_stack.peek();
                    max=Math.max(max,tmp);
                }else{
                    str_stack.push(')');
                    pos_stack.push(i);
                }
            }
        }
        return max;
    }
}