class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        if not s:
            return ''
        if s == '':
            return ''
        temp_string = []
        split_string = s.split(' ')
        for ele in split_string:
            if not ele:
                continue
            else:
                temp_string.append(ele)
        temp_string.reverse()
        ret = " ".join(temp_string)
        return ret
