# Check whether the string is palindrome or not considering
# only Alpha-Numeric Characters ignoring cases


s = input();

t = ''.join([i.lower() if i.isalnum() else '' for i in s])

if t==''.join(reversed(t)): print("It is a Palindrome String")
else: print("It is not a Palindrome String")

