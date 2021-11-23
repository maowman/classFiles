article = input()
words = article.split(" ")
keyword = []
result = []
for i in range(len(words)):
    if (words[i].count("(") > 0 and words[i].count(")") > 0 and len(words[i]) > 2 and words[i].upper() == words[i]):
        # print(words[i])
        keyword.append(i)
        # () / )(

# print(keyword)

for i in range(len(keyword)):
    acronymSize = len(words[keyword[i]])-2
    meaning = []
    for k in range(acronymSize):
        if (words[keyword[i]-acronymSize+k].upper()[0] != words[keyword[i]][k+1]):
            break
        else:
            meaning.append(words[keyword[i]-acronymSize+k])
    if (len(meaning) == acronymSize):
        # print(meaning)
        result.append(meaning)

for el in result:
    for word in el:
        print(word.upper()[0], end="")
    print(": ", end="")
    print(" ".join(el))
