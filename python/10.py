paper = input().split(' ')
#print(paper)
 
check_list = []
for el in paper:
    if el[0] == '(':
        check_list.append(el)
#print(check_list):['(GPR)', '(SVR)']   
 
check_list2 = []
for c in check_list:
    c = c.replace('(','')
    c = c.replace(')','')
    check_list2.append(c)
#print(check_list2):['GPR', 'SVR']
 
#不是大寫就不行
for h in check_list2:
    for i in range(len(h)):
        if ord(h[i])<65 or ord(h[i])>90:
            check_list2.pop(h)

print(check_list)

no = '。，、；：「」『』（）─？！─…﹏《》〈〉．～　,.; !"#$%&()*+,-./:;<=>?@[\]^_`{¦}~'
paper2 = []
for el in paper:
    for o in no:
        el = el.replace(o,'')
        el = el.replace("'",'')
    paper2.append(el)
print(paper2)
 
index = []
for k in range(len(check_list2)):
    index.append(paper2.index(check_list2[k]))

print(index)
#print(index):[26,32]
 
#要轉成大寫
acronym = []
for j in range(len(check_list2)): #2
    for q in range(len(check_list2[j])): #3
        if paper2[index[j]-len(check_list2[j])+q][0].upper() == check_list2[j][q]:
            acronym.append(paper2[index[j]-len(check_list2[j])+q])
    if len(acronym) == 0 or len(acronym) != len(check_list2[j]):
        continue
    print(check_list2[j]+':',*acronym)
    acronym = []