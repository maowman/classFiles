# 輸入要檢查的文章
article = input().split(" ")
 
# 將英文常見的標點符號去掉
forbid = '。，、；：「」『』（）─？！─…﹏《》〈〉．～　,.; !"'\
     + "#$%&'*+,-./:;<=>?@[]^_`{¦}~"
 
# 因為article_revise後續裝的為字串，故先給一初始值方便後續的添加
article_revise = [""]
 
# 將每一格填入被標點符號分隔後的字串
for i in range(len(article)):
    for j in range(len(article[i])):
        if forbid.count(article[i][j]) == 0:
            article_revise[i] += article[i][j]  # 若該字元不為標點符號，利用字串的串接加入同一格
    if i != len(article) - 1:
        article_revise.append("")
 
# 檢查文章是否有acronym並執行所求
for i in range(len(article_revise)):
    acronym = ""  # 給定acronym的預設值方便後續添加
    # 題目中有提及acronym會被()刮住
    if article_revise[i].count("(") != 0 and article_revise[i].count(")") != 0:
        if article_revise[i].isupper() is True:  # 確認是否為acronym
            # 將article_revise的文字加入到acronym裡面
            for k in range(len(article_revise[i])):
                if article_revise[i][k].isalpha() is True:
                    acronym += article_revise[i][k]
            meaning = []
            for j in range(len(acronym), 0, -1):  # 檢查acronym前面幾個字是否為其說明
                if article_revise[i - j][0].isupper() is True\
                 and article_revise[i - j][0] == acronym[len(acronym) - j]:
                    meaning.append(article_revise[i - j])  # 將符合說明的單字加入到meaning
                elif article_revise[i - j][0].islower() is True:
                    # 檢查開頭為小寫的單字必須先將單字開頭轉為大寫
                    number = ord(article_revise[i - j][0]) - ord("a")
                    capital = chr(number + 65)
                    if capital == acronym[len(acronym) - j]:
                        meaning.append(article_revise[i - j])
            if meaning != []:  # 為了不讓有些前面明明沒有說明的acronym印出
                print(acronym + ":", end="")
                for word in meaning:
                    print(" " + word, end="")
                print()  # 為了換行
 