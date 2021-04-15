import sys
input = sys.stdin.readline

N = int(input())
nums = list(map(int, input().split()))
op = list(map(int, input().split()))

op_permutation = []

result_max = -sys.maxsize
result_min = sys.maxsize

def dfs(element):
    if len(element) == N-1:
        op_permutation.append(element[:])
    for i in range(4):
        if op[i] > 0:
            op[i] -= 1
            element.append(i)
            dfs(element)
            op[i] += 1
            element.pop()
        
def calculate(op, num1, num2):
    if op == 0:
        return num1 + num2
    elif op == 1:
        return num1 - num2
    elif op == 2:
        return num1 * num2
    else:
        if num1 < 0:
            return -((-num1)//num2)
        else:
            return num1 // num2

dfs([])

# + - * //

for ops in op_permutation:
    num1 = nums[0]
    for i in range(len(ops)):
        num1 = calculate(ops[i], num1, nums[i+1])
    result_max = max(result_max, num1)
    result_min = min(result_min, num1)
    
print(result_max)
print(result_min)