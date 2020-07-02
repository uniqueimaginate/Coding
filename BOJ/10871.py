x = int(input().split()[1])

numbers = input().split()
numbers =[int(i) for i in numbers]
result = [i for i in numbers if x > i]

for i in result:
    print(i, end = " ")