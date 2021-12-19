import matplotlib.pyplot as plt
plt.figure(dpi=2000)
with open("lab2Data.txt") as file:
    time = []
    voltage = []
    for line in file.readlines():
        [a, b] = map(lambda str: float(
            str.replace("\n", "")), line.split("\t"))
        time.append(a)
        voltage.append(b)
    avgrVoltage = []
    avgrNumber = 20
    for i in range(len(voltage)):
        try:
            total = voltage[i]
            for k in range(1, avgrNumber+1):
                total += (voltage[i+k] + voltage[i-k])
            avgrVoltage.append(total / (avgrNumber*2 + 1))
        except IndexError:
            avgrVoltage.append(voltage[i])
    deltaVoltage = []
    for i in range(len(voltage)):
        try:
            delta = (avgrVoltage[i+1] - avgrVoltage[i])/(time[i+1] - time[i])
            deltaVoltage.append(delta)
        except IndexError:
            deltaVoltage.append(0)

    plt.plot(time, voltage, label="raw voltage" , linewidth = 0.1)
    plt.plot(time, avgrVoltage, label="flatten voltage" , linewidth = 0.1)
    plt.plot(time, deltaVoltage, label="delta voltage" , linewidth = 0.1)
    plt.xlabel('Time(sec)')
    plt.ylabel("Voltage(mV)")
    plt.title("Lab2 data")
    plt.legend()
    plt.savefig("Lab2.png" , dpi=2000)
