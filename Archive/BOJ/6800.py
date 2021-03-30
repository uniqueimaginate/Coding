import collections

class TrieNode:
    def __init__(self):
        self.alpha = ''
        self.children = collections.defaultdict(TrieNode)
        
class Trie:
    def __init__(self):
        self.root = TrieNode()
        
        
    def insert(self, word, alpha):
        node = self.root
        for char in word:
            node = node.children[char]
        node.alpha = alpha
        
    def search(self, word):
        node = self.root
        for char in word:
            if char not in node.children:
                return ''
            node = node.children[char]
        return node.alpha
    
T = int(input())
trie = Trie()
for _ in range(T):
    alpha, num = list(input().rstrip().split())
    trie.insert(num, alpha)
    
binary_sequence = input().rstrip()

i = 0
result = ''
while binary_sequence:
    temp = trie.search(binary_sequence[:i])
    if not temp:
        i += 1
    else:
        result += temp
        binary_sequence = binary_sequence[i:]
        i = 0
print(result)