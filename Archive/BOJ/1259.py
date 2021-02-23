while True:
    word = input()
    if word == "0":
        break
    
    word = list(word)
    sortedstr = word[::-1]
    if word == sortedstr:
        print("yes")
    else:
        print("no")
