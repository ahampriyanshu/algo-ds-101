"""
author- Ose Oaiya (esoiya)
problem :- The edit distance between two strings is the minimum number of operations (insertions, deletions, and
substitutions of symbols) to transform one string into another. It is a measure of similarity of two strings.
Edit distance has applications, for example, in computational biology, natural language processing, and spell
checking. Your goal in this problem is to compute the edit distance between two strings

Overall time complexity:- O(m*n)
"""

def edit_distance(string1, string2):
    
    # for all i and j, d[i,j] will hold the Levenshtein distance between
    # the first i characters of string1 and the first j characters of string2
    # note that d has (m+1)*(n+1) values
    m = len(string1) + 1
    n = len(string2) + 1

    d = [0] * (m * n)

    # source prefixes can be transformed into empty string by
    # dropping all characters
    for i in range(m):
        d[i] = i

    # target prefixes can be reached from empty source prefix
    # by inserting every character

    for j in range(n):
        d[j * m] = j

    for j in range(1, n):
        for i in range(1, m):
            if string1[i-1] == string2[j-1]:
                d[i + j * m] = d[i-1 + (j-1) * m]
            else:
                d[i + j * m] = min(
                    d[i - 1 + j * m] + 1,  # deletion
                    d[i + (j - 1) * m] + 1, # insertion
                    d[i - 1 + (j - 1) * m] + 1 # subsitution
                )

    return d[-1]
