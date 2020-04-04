class Trie():
    def __init__(self):
        self.next = dict()
        self.value = 0
    

def solution(words):
    answer = 0

    tree= Trie()

    for word in words:
        subtree = tree
        for idx,val in enumerate(word):
            subtree.value+=1
            if(val not in subtree.next):
                subtree.next[val] = Trie()
            subtree=subtree.next[val]
            if(idx == len(word)-1):
                subtree.value+=1

    for word in words:
        subtree=tree
        cnt=0
        for idx, val in enumerate(word):
            cnt+=1
            subtree = subtree.next[val]
            if(subtree.value == 1 ):
                answer+=cnt
                break
            elif(idx == len(word)-1):
                answer+=cnt
                break
            else:
                continue
            
    return answer