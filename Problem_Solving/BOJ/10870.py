N = int(input())
def recursion(num):
    if num == 0:
        return 0
    elif num == 1:
        return 1
    return recursion(num - 1) + recursion(num - 2)
print(recursion(N))