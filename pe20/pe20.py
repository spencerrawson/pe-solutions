#num of digits = n*sum(n-1)+1
n=100
fact = 1
while n > 0:
    fact *= n
    n -= 1
sum = 0
#for each digit add to sum
for c in str(fact):
    sum += (int)(c)
print(sum)