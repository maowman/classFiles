

def lineParser(raw):
    # raw = one line of data
    data = raw.split(",")
    result = []
    cache = []
    flag = False
    for i in range(len(data)):
        if (len(data[i]) > 0 and data[i][0] == '"' and data[i][-1] == '"'):
            #print("whole element")
            result.append(data[i])
        elif (len(data[i]) > 0 and data[i][-1] == '"'):
            # print("breaking")
            cache.append(data[i])
            result.append(",".join(cache))
            cache = ""
            flag = False
        elif (flag == True or (len(data[i]) > 0 and data[i][0] == '"')):
            # print("concating")
            cache.append(data[i])
            flag = True
        else:
            #print("whole element")
            result.append(data[i])
    if (len(cache)>0):
        result.append(",".join(cache))
    print(len(result))
    return result


#print(lineParser('"彰化縣員林市新生里莒光路３８４,３８６號一樓",14851353,,"佳順免洗餐具商行",550000,0910719,獨資,Y,472999,未分類其他食品、飲料及菸草製品零售,474911,免洗餐具零售,474917,清潔用品零售,485299,未分類其他全新商品零售'))

filename = "data.csv"

file = open(filename , "r")

rawData = file.readlines()
n = 5
data = lineParser(rawData[n])
print(data)
