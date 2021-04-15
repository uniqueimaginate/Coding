def solution(records):
    user = {}
    ele = []
    for record in records:
        commands = record.split()
        uid = commands[1]
        if commands[0] == "Enter":
            name = commands[2]
            user[uid] = name
            ele.append((uid, 1))
            
        elif commands[0] == "Leave":
            ele.append((uid, 0))
            
        elif commands[0] == "Change":
            name = commands[2]
            user[uid] = name
            
    
    answer = []
    for uid, status in ele:
        if status == 0:
            answer.append(user[uid] + "님이 나갔습니다.")
        else:
            answer.append(user[uid] + "님이 들어왔습니다.")
        
        
    return answer