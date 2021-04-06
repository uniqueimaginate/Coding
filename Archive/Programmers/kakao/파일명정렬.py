from functools import cmp_to_key
import re

order = dict()


def sort_key(str1, str2):
    global order
    str_num1 = re.findall("^[a-zA-Z\- ]+\d{0,5}", str1)
    str_num2 = re.findall("^[a-zA-Z\- ]+\d{0,5}", str2)

    string1 = re.findall('[a-zA-Z\- ]+', str_num1[0])
    num1 = re.findall('[\d]+', str_num1[0])
    string2 = re.findall('[a-zA-Z\- ]+', str_num2[0])
    num2 = re.findall('[\d]+', str_num2[0])

    string1 = string1[0].lower()
    num1 = int(num1[0])
    string2 = string2[0].lower()
    num2 = int(num2[0])

    if string1 > string2:
        return 1
    elif string1 == string2:
        if num1 > num2:
            return 1
        elif num1 == num2:
            if order[str1] > order[str2]:
                return 1
            else:
                return -1
        else:
            return -1
    else:
        return -1


def solution(files):
    global order
    for i, f in enumerate(files):
        order[f] = i

    co = sorted(files, key = cmp_to_key(sort_key))
    answer = co
    return answer