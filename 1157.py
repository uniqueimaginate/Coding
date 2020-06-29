word = list(input().upper())

words = sorted(word)

if len(words) == 1:
    print(words[0])
    exit(0)


words_dict = {}

for c in words:
    if c in words_dict:
        words_dict[c] = words_dict[c] + 1
    else:
        words_dict[c] = 1

sorted_tuple = sorted(words_dict.items(), key= lambda x:x[1], reverse=True)

if sorted_tuple[0][1] == sorted_tuple[1][1]:
    print("?")
else:
    print(sorted_tuple[0][0])