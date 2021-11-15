class Town:
    def __init__(self, value, seq, toOtherTown):
        self.value = value
        self.seq = seq
        self.toOtherTown = toOtherTown
        self.toNearstOffice = 10000

    def __str__(self):
        return "Town seq: {seq} , value: {value} , toOtherTown: {toOtherTown} , toNearstOffice : {toNearstOffice}" .format(seq=self.seq, value=self.value, toOtherTown=self.toOtherTown , toNearstOffice = self.toNearstOffice)

    def __eq__(self, other):
        return (self.value == other.value and self.seq == other.seq)

    def __lt__(self, other):
        if (self.toNearstOffice == other.toNearstOffice):
            return self.seq > other.seq
        else:
            return self.toNearstOffice < other.toNearstOffice


[numberOfTown, numberOfOffice] = list(map(int,  input().split(',')))
firerates = list(map(int, input().split(",")))
towns = []
for i in range(numberOfTown):
    distance = list(map(int, input().split(",")))
    value = 0
    for k in range(len(distance)):
        value += firerates[k]*distance[k]

    town = Town(value, i, distance)
    towns.append(town)

for town in towns:
    print(town)


currentPtr = 0
for k in range(len(towns)):
    if (towns[k].value < towns[currentPtr].value):
        currentPtr = k

for i in range(numberOfOffice):
    print("Number {} office is located at {}".format(i+1, towns[currentPtr].seq+1))
    for k in range(len(towns)):
        towns[k].toNearstOffice = min( towns[k].toNearstOffice , towns[currentPtr].toOtherTown[towns[k].seq] )
    towns.sort()
    currentPtr = len(towns)-1
    for town in towns:
        print(town)

totalDistace = 0
for i in range(len(towns)):
    totalDistace +=  towns[i].toNearstOffice*firerates[towns[i].seq]
print("Total distance = {}".format(totalDistace))    


