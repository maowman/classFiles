a = [1, 2, 3,  4, 5]
b = a
# shallow copy 淺複製
c = a.copy()
b[0] = 100
c[0] = 1000
print(a)
print(b)
print(c)
print(hex(id(a)))
print(hex(id(b)))
print(hex(id(c)))
