def make_url(text):
    result = ''
    for char in text:
        if char == " ":
            result += '%20'
        else:
            result += char
    return result

def make_url_pythonic(text):
    return text.replace(' ', '%20')
