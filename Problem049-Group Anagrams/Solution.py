"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 264ms
"""
class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        returnColumn = []
        hash = {}
        for i in range(len(strs)):
            tmp = strs[i][0:]
            tmp = sorted(tmp)
            res = "".join(tmp)
            if hash.has_key(res):
                index = hash[res]
                column = returnColumn[index]
                column.append(strs[i])
                returnColumn[index] = column
            else:
                hash[res] = len(returnColumn)
                column = [strs[i]]
                returnColumn.append(column)
        for i in range(len(returnColumn)):
            returnColumn[i] = sorted(returnColumn[i])
        return returnColumn