n = input()

numbers = input().split()
numbers = [int(i) for i in numbers]

print("{} {}".format(min(numbers), max(numbers)))