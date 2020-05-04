import itertools

n = int(input())
rst=1000000

arr=[]
for i in range(n):
    arr.append(list(map(int,input().split(" "))))

person = [i+1 for i in range(n)]

every = list(itertools.combinations(person,n//2))

for start in every:
    link = list(set(person)-set(start))
    
    start_p = list(itertools.permutations(start,2))
    link_p = list(itertools.permutations(link,2))

    start_sum=0
    link_sum=0

    for k in range(len(start_p)):
        start_sum += arr[start_p[k][0]-1][start_p[k][1]-1]
        link_sum += arr[link_p[k][0]-1][link_p[k][1]-1]

    rst=min(rst,abs(start_sum-link_sum))
    if rst == 0:
        break

print(rst)    