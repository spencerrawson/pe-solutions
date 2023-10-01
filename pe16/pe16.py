#turns the value into a string and iterates through to find the total
num = str(2**1000)
total = int(0)
for i in num:
    print(i)
    total += int(i)
print(total)
