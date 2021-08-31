from typing import Counter
import requests
counter = 0
while (True):
    counter +=1
    r =  requests.get("http://apc.aca.ntu.edu.tw/fcc/ShowContent.aspx?pid=90")
    print(counter)