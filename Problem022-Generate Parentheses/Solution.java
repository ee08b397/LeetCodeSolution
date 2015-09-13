/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 252ms
 */
public class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<String>();
        char[] tmp=new char[n+n];
        generate(res,n,n,tmp,0);
        return res;
    }
    private void generate(List<String> res,int l,int r,char[] tmp,int index){
        if(l==0 && r==0){
            res.add(new String(tmp));
            return;
        }
        if(l>0){
            tmp[index]='(';
            generate(res,l-1,r,tmp,index+1);
        }
        if(r>0 && r>l){
            tmp[index]=')';
            generate(res,l,r-1,tmp,index+1);
        }
    }
}