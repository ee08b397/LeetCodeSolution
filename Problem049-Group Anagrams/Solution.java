/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 436ms
 */
public class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> returnColumn = new ArrayList<List<String>>();
        Map<String,Integer> hash = new HashMap<String,Integer>();
        for(int i=0;i<strs.length;i++){
            char[] tmp = strs[i].toCharArray();
            Arrays.sort(tmp);
            String res = new String(tmp);
            if(hash.containsKey(res)){
                int index = hash.get(res);
                List<String> column = returnColumn.get(index);
                column.add(strs[i]);
            }else{
                hash.put(res,returnColumn.size());
                List<String> column = new ArrayList<String>();
                column.add(strs[i]);
                returnColumn.add(column);
            }
        }
        for(int i=0;i<returnColumn.size();i++){
            Collections.sort(returnColumn.get(i));
        }
        return returnColumn;
    }
}