result = 0
a=0
b=0
for i in range(1 , 15):
    for k in range(1, 15):
        cache = 0.5*(i/(i+k) + (15-i)/(30-i-k) )
        if (cache>result):
            a = i
            k = b

print (a , b)