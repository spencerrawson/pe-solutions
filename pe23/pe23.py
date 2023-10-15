abundant = []
import math
import time
sum = 0
sTime = time.time()
def canBeSum (n):
    for row in range(0,len(abundant)-1):
        for col in range(row,len(abundant)-1):
            if(n == abundant[row] + abundant[col]):
                return 0
    return n
def isAbundant (x):
    divSum = 0
    for j in range(1, x):
        if(x%j == 0):
            divSum += j
    return (divSum > x) #28123
for i in range(1, 28123):
    print(i)
    if(isAbundant(i)):
        abundant.append(i)
    sum += canBeSum(i)
fTime = time.time()
print(sum)
print(fTime - sTime)
