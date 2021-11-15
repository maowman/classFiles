data = []

while True:
    string = input()
    if (string == "RECORDSTOP"):
        break
    else:
        [a, b, c] = string.split("_")
        # ["芒果蘇" , "1.00" , "30.00" , "29.7"]
        data.append([a, float(b), float(c)])

totalDiscount = 0
totalPrice = 0
for el in data:
    if (el[2] > 0):
        totalPrice += el[2]
    elif (el[2] < 0):
        totalDiscount -= el[2]

for el in data:
    if (el[2] > 0):
        el.append(el[2] - totalDiscount * (el[2]) / totalPrice)
    elif (el[2] < 0):
        el.append(el[2])

for el in data:
    if (el[2] > 0):
        if (el[3] < 1e-3):
            el[3] = 0
        print("_".join([el[0], str(el[1]), f"{el[3]:.2f}"]))
print("---Original---")
for el in data:
    print("_".join([el[0], str(el[1]), f"{el[2]:.2f}"]))
