array =  [[1, 2, 7] , [1 , 2 , 4] , [2 , 5 , 5]]

sortedArray = sorted( array ,key = lambda x:x[0]*100+x[1]*10+x[0] ,reverse=True)

print(sortedArray)