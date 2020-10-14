
test_list = ['lump', 'eat', 'me', 'tea', 'em', 'plum'] 
temp = lambda test_list: sorted(test_list) 
res = [list(val) for key, val in groupby(sorted(test_list, key = temp), temp)] 

# print result 
print("The grouped Anagrams : " + str(res)) 
