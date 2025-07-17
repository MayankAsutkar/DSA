"""
    greedy algorithms : 
        A greedy algorithm is a problem-solving approach that makes the locally optimal choice at each stage with the hope of finding a global optimum. It focuses on making the best immediate decision without considering the consequences of that choice for future steps, aiming for the best overall solution. 
"""
def findContentChildren(g, s):
    g.sort()
    s.sort()
    m = len(g)
    n = len(s)
    j = 0
    i = 0
    while j < n and i < m:
        if g[i] <= s[j]:
            i += 1
        j+=1
    return i
g = [1,2,3]
s = [1,1]
print(findContentChildren(g,s))