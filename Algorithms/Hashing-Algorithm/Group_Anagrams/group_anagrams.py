from itertools import groupby
print("Please input the required data seperated with space")
test_list=input("Enter data:").split()


temp = lambda test_list: sorted(test_list) 
res = [list(val) for key, val in groupby(sorted(test_list, key = temp), temp)] 

# print result 
print("The grouped Anagrams : " + str(res)) 
