height_command = input().rstrip().split()
height = 0
command = ''
if len(height_command) == 1:
    height = int(height_command[0])
else:
    height = int(height_command[0])
    command = height_command[1]


end = 2 ** (height+1)
start = 1
for char in command:
    if char == 'L':
        start *= 2
    else:
        start = 2 * start + 1
        
print(end - start)

