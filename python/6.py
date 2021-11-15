def my_hhi(ylist,htype):
  buttom = 0
  HHI = 0
  HH2 = 0
  for i in range(len(ylist)):
    buttom += abs(ylist[i])
    #print('deno:',deno)
  for i in range(len(ylist)):
    HHI += (ylist[i]/buttom)*(ylist[i]/buttom)
    #print('HHI:',HHI)
  if htype == "Original" : 
    return HHI
  else:
    HH2 += (HHI-(1/len(ylist)))/(1-1/len(ylist))
    #print('分子:',HHI-(1/len(ylist)))
    #print('分母:',1-1/len(ylist))
    #print('HH2:',HH2)
    return HH2
      
ylist = input().split(',')
for i in range(len(ylist)):
  ylist[i] = float(ylist[i])
htype = input() #string?
 
ans =  my_hhi(ylist,htype)
print(f"{ans:.4f}")