string = input()
dic = {"c=": 0, "c-": 0, "dz=": 0, "d-": 0, "lj": 0, "nj": 0, "s=": 0, "z=": 0}

count = 0

for word in dic:
    dic[word] = string.count(word)

dic["z="] -= dic["dz="]

croatian_count = 0
for word in dic:
    croatian_count += (len(word) * dic[word])
    
count += sum(dic.values())
count += (len(string) - croatian_count)

print(count)
