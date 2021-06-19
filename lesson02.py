def isLeap (year):
    if (year%4==0 and year%100 !=0) or (year%400 == 0):
        return True
    else:
        return False

[yr , daystart] = map( int , input().split(" "));
n = int(input())

months = [31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31]
if isLeap(n):
    months = [31 , 29 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31]

results = []

for i in range(n):
    [month , day] = map(int , input().split(" "))
    if month > 12 or month <1 :
        results.append(-1)
    elif day> months[month -1] or day < 1:
        results.append(-2)
    else :
        daycount = -1
        for k in range(month-1):
            daycount += months[k];
        daycount += daystart
        daycount += day
        result = daycount %7 ;
        results.append(result)

print((" ").join(map(str , results)))

