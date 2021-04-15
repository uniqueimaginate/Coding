import re
import collections

def solution(str1, str2):
    str1, str2 = str1.lower(), str2.lower()
    str1_dict = collections.defaultdict(int)
    str2_dict = collections.defaultdict(int)
    for i in range(len(str1)-1):
        str1_2 = str1[i:i+2]
        str1_2 = re.sub('[^a-z]', '', str1_2)
        if len(str1_2) == 2:
            str1_dict[str1_2] += 1
    
    for i in range(len(str2) - 1):
        str2_2 = str2[i:i+2]
        str2_2 = re.sub('[^a-z]', '', str2_2)
        if len(str2_2) == 2:
            str2_dict[str2_2] += 1
        
    union = {}
    for key in str1_dict:
        union[key] = str1_dict[key]
    
    for key in str2_dict:
        if key not in union:
            union[key] = str2_dict[key]
        else:
            if union[key] < str2_dict[key]:
                union[key] = str2_dict[key]
    
    union_length = 0
    for _, value in union.items():
        union_length += value
                
    intersection = {}
    for key in str1_dict:
        if key in str2_dict:
            if str2_dict[key] < str1_dict[key]:
                intersection[key] = str2_dict[key]
            else:
                intersection[key] = str1_dict[key]
    
    intersection_length = 0
    for _, value in intersection.items():
        intersection_length += value
    
    answer = 0
    if union_length == 0:
        answer = 65536
    else:
        answer = int((intersection_length / union_length) * 65536)
    return answer