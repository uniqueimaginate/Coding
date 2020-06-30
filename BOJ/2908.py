numbers = input().split()

num1 = int(numbers[0][::-1])
num2 = int(numbers[1][::-1])

if num1 > num2:
    print(num1)
else:
    print(num2)