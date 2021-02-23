numbers = input().split()

if sorted(numbers, reverse=True) == numbers:
    print("descending")
elif sorted(numbers) == numbers:
    print("ascending")
else:
    print("mixed")

