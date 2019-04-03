dict = {'2':['a','b','c'],
        '3':['d','e','f'],
        '4':['g','h','i'],
        '5':['j','k','l'],
        '6':['m','n','o'],
        '7':['p','q','r','s'],
        '8':['t','u','v'],
        '9':['w','x','y','z']
        }

def get_result(string,list1):
    new_list = []
    if string == "":
        return list1
    if string[0] in dict.keys():
        for i in dict[string[0]]:
            if list1 != []:
                for j in list1:
                    new_list.append(j+i)
            else:
                new_list.append(i)
        list1 = new_list
        return get_result(string[1:],list1)

class Solution:
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        list1 = []
        if digits == "":
            return list1
        else:
            return get_result(digits,list1)
        
        
