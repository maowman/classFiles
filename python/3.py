n=int(input())
ans = 0
num1 = 0
 
line_one=input().split(',')
for i in range(n):
  line_one[i]=int(line_one[i])
 
line_two=input().split(',')
for i in range(n):
  line_two[i]=int(line_two[i])
 
for i in range(n):
  ans += line_one[i]*line_two[i]
#print(ans)
if ans//1000 == 1:
  num1 += 1
else:
  num1 += 0
if (ans%1000)//100 == 1:
  num1 += 1
else:
  num1 += 0
if ((ans%1000)%100)//10 == 1:
  num1 += 1
else:
  num1 += 0
if ((ans%1000)%100)%10 == 1:
  num1 += 1
else:
  num1 += 0
 
print(ans,num1,sep=',')