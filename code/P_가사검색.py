class Node:
	def __init__(self, val, leaf=False):
		self.val = val
		self.leaf = leaf
		self.cnt = 0
		self.child = {}

class Trie:
	def __init__(self):
		self.head = Node(None)

	def insert(self, string):
		cur = self.head

		for c in string:
			if c not in cur.child: cur.child[c] = Node(c)
			cur.cnt+=1
			cur = cur.child[c]

		cur.cnt+=1
		cur.leaf = True

	def search(self, prefix):
		
		ret = 0
		cur = self.head

		for c in prefix:
			if c in cur.child: cur = cur.child[c]
			else: return 0

		node_list = []
		for c in cur.child:
			node_list.append(cur.child[c])

		for i in node_list:
			ret+=i.cnt

		return ret


def solution(words, queries):
	answer = []

	trie = [ Trie() for i in range(10000)] 
	reverse = [ Trie() for i in range(10000)]

	for w in words:
		trie[len(w)-1].insert(w)
		reverse[len(w)-1].insert(w[::-1])

	for query in queries:
		flag = False
		if query[0]=='?' and query[-1]!='?': 
			flag = True
			query = query[::-1]

		pre=0
		for idx,c in enumerate(query):
			if c == '?': 
				pre = idx
				break

		if flag:
			answer.append(reverse[len(query)-1].search(query[:pre]))
		else:
			answer.append(trie[len(query)-1].search(query[:pre]))

	return answer