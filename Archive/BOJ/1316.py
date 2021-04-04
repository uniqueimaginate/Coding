N = int(input())

result = 0
for _ in range(N):
    string = input()
    prev = string[0]
    count = 0
    for char in string[1:]:
        if char != prev:
            count += 1
            prev = char
    
    if len(set(string)) - 1 == count:
        result += 1
        
print(result)