num = str(input())
change = num
count = 0

while True:
    if int(change) < 10:
        change = str(int(change + change))
    else:
        new = str(int(change[0]) + int(change[1]))
        change = str(int(change[1] + new[-1]))
    
    count += 1

    if str(num) == str(change):
        break

print(count)