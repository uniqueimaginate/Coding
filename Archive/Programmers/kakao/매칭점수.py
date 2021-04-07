import re
from collections import defaultdict

re_meta_tag = re.compile('<meta.+content="(.+?)"/>')
re_a_tag = re.compile('<a href="(.+?)">')
re_word = re.compile('[^a-z]+')

page_dict = defaultdict(list)
score_dict = defaultdict(list)


def solution(input_word, pages):

    word = input_word.lower()

    for i, page in enumerate(pages):
        pg = page.lower()
        url = re_meta_tag.findall(pg)[0]
        a_tag = re_a_tag.findall(pg)

        words_split = re_word.sub('.', pg).split('.')
        score = 0
        for w in words_split:
            if w == word:
                score += 1

        page_dict[url].extend(a_tag)
        score_dict[url].extend([i, score, len(a_tag), 0])

    for url in page_dict:
        for other in page_dict:
            if url != other:
                if url in page_dict[other]:
                    score_dict[url][3] += (score_dict[other]
                                           [1] / score_dict[other][2])

    score_list = score_dict.values()
    result = []
    for s in score_list:
        result.append([s[1]+s[3], s[0]])
    result.sort(key=lambda x: (-x[0], x[1]))
    return result[0][1]
