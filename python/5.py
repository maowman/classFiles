def multiple(data, k):
    result = []
    ptr = 0  
    #現在程式看到哪個元素
    count = 1
    #目前持續遞增的個數
    #data[ len(data) ] -> index out of range
    while (ptr < len(data)-1):
        if (data[ptr+1] > data[ptr]):
            count += 1
        else:
            if (count >= k):
                result.append([ptr-count+1, ptr])
            count = 1
        ptr += 1
    if (count >=k):
        result.append([ptr-count+1, ptr])
    return result


data = list(map(int, input().split(",")))
k = int(input())

print(multiple(data, k))
