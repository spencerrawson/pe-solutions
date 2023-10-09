weekday = 4
sum = 0
#n will be the number of new days to add to the weekday counter
def day(n):
    global weekday
    #weekday adds the right number of days and loops over if > 7
    weekday += n%7
    if(weekday > 7):
        weekday -= 7

for i in range(1,101):
    #start each leap year as false, and update if year%4 is 0
    leap = False
    if(i%4==0):
        leap=True
    #array of differences in days for each month depending on leap year
    leapDays = [31,31,29,31,30,31,30,31,31,30,31,30]
    days     = [31,31,28,31,30,31,30,31,31,30,31,30]
    for month in range(0,12):
        #update the weekday correctly depending on if leap year, then add to sum if first day is a sunday
        if(leap):
            day(leapDays[month])
            if(weekday == 7):
                sum += 1
        else:
            day(days[month])
            if(weekday == 7):
                sum += 1
print("sum is: ",sum)



