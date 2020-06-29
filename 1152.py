stringinput = input("")

stringinput = stringinput.lstrip()
stringinput = stringinput.rstrip()
if len(stringinput) == 0:
    print("0")

else:
    arr = stringinput.split(' ')
    print(len(arr))