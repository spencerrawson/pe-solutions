#solution uses factorial base numbers, an awesome thing for counting permutations that i found while researching
factoradic = [1,2,3,4,5,6,7,8,9,10]
digits     = [0,1,2,3,4,5,6,7,8,9]
def convertToFactoradic(n):
    #factoradic starts at 0 (for fun) so subtract 1 from n
    n -= 1
    converted = []
    #find the factoradical equivalent using the bases on n
    for base in factoradic:
        converted.append(n%base)
        n = (int)(n/base)
    #reverse it as factoradic is read backwards from conversion
    converted.reverse()
    #save each digit to the ans str and then print ans
    ans = ""
    print(converted)
    for num in converted:
        ans += (str)(digits[num])
        digits.remove(digits[num])
    print(ans)
#call function
convertToFactoradic(1000000)
