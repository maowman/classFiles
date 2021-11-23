width = int(input())
dataType = input().split(",")
delayPrint = []

while (True):
    raw = input()
    if (raw == "RECORD_END"):
        break
    else:
        data = raw.split(",")
        output = []
        for i in range(len(data)):
            final = ""
            if (dataType[i] == "f"):
                data[i] = float(data[i])
                strNumber = "{:.2f}".format(round(data[i], 2))
                realWidth = len(strNumber)
                if (realWidth <= width):
                    final = strNumber
                else:
                    final = strNumber[0:width-1] + "~"
            elif (dataType[i] == "s"):
                realWidth = len(data[i])
                if (realWidth <= width):
                    final = data[i]
                else:
                    final = data[i][0:width-1] + "~"
            output.append("{0:>{width}}".format(final, width=width))
        delayPrint.append(" ".join(output))

for el in delayPrint:
    print(el)
