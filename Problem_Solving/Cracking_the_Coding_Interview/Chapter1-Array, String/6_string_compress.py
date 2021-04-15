def string_zip(string):
    latest_char = string[0]
    count = 0
    result = ''
    for char in string:
        if latest_char != char:
            result += (latest_char + str(count))
            count = 1
            latest_char = char
        else:
            count += 1
    result += (latest_char + str(count))
    return string if len(string) < len(result) else result
