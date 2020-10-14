# Link to Problem: https://leetcode.com/problems/simplify-path/
# Input : String of Absolute Path
# Output : Return Canonical Path

def simplifyPath(path):
        paths = path.split("/")
        stack=[]
        for p in paths:
            if p in ("","."):
                pass
            elif p == "..":
                if stack:
                    stack.pop()
            else:
                stack.append(p)
        return '/'+'/'.join(stack)

Absolute_Path = input("Input the absolute Path: ")
print("Canonical Path: ",simplifyPath(Absolute_Path))