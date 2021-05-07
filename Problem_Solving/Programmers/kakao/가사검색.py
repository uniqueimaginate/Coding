from collections import defaultdict

class TrieNode:
    def __init__(self):
        self.word = 0
        self.children = defaultdict(TrieNode)
        
class Trie:
    def __init__(self):
        self.root = TrieNode()
        
    def insert(self, word: str) -> None:
        node = self.root
        node.word += 1
        for char in word:
            node.children[char].word += 1
            node = node.children[char]

    def search(self, word: str) -> int:
        node = self.root
        for char in word:
            if char not in node.children:
                return 0
            node = node.children[char]
        return node.word


trie_dict = defaultdict(Trie)
trie_dict_reverse = defaultdict(Trie)
    
def solution(words, queries):
    answer = []

    for word in words:
        trie_dict[len(word)].insert(word)
        trie_dict_reverse[len(word)].insert(word[::-1])

        
    for query in queries:
        size = len(query)
        space = query.replace("?", "")
        if not space:
            answer.append(trie_dict[size].root.word)
            continue
        
        
        if query[-1] == "?":
            pre = query.replace("?", "")
            num = trie_dict[size].search(pre)
            answer.append(num)
            
        else:
            post = query[::-1].replace("?", "")
            num = trie_dict_reverse[size].search(post)
            answer.append(num)
        
    
    
    return answer