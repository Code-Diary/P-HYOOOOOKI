import queue
import collections
import sys
input = sys.stdin.readline

cnt=0
zero_idx = list()
virus_idx = list()
arr=list()
dr=[0,-1,0,1]
dc=[-1,0,1,0]
wr=[-1,1,1,-1]
wc=[1,1,-1,-1]
q = collections.deque()

nm = list(map(int,input().split(" ")))
n=int(nm[0])
m=int(nm[1])

for i in range(n):
    temp = list(map(int,input().split(' ')))
    arr.append(temp)

    for j in temp:
        if j==0:
            zero_idx.append(cnt)
        elif j ==2:    
            virus_idx.append(cnt)
        cnt+=1
        
zl=len(zero_idx)

visited=[]
rst=0
for f1 in range(zl):
    for f2 in range(f1+1,zl):
        for f3 in range(f2+1,zl):
            i=[zero_idx[f1],zero_idx[f2],zero_idx[f3]]
            for j in i:
                nx=j//m
                ny=j%m
                arr[nx][ny] = 1
            
            for j in virus_idx:
                t_n = int(j)//m
                t_m = int(j)%m
                if(t_n,t_m) not in visited:
                    q.append((t_n,t_m))
                    while(len(q)!=0):
                        t_val = q.popleft()
                        if(t_val[0],t_val[1]) in visited:
                            continue
                        visited.append((t_val[0],t_val[1]))
                        for k in range(4):
                            nx = t_val[0]+dr[k]
                            ny = t_val[1]+dc[k]
                            if(nx < n and 0<= nx  and 0 <= ny and ny < m):
                                # print((t_val[0]+dr[k]),(t_val[1]+dc[k]))
                                if(arr[nx][ny] == 1):
                                    pass
                                else:    
                                    if((nx,ny) not in visited):
                                        q.append((nx,ny))
                    
            t_rst=0
            for arr_idx, arr_val in enumerate(arr):
                for t_idx,tt_val in enumerate(arr_val):
                    if ((arr_idx,t_idx) not in visited) and tt_val == 0:
                        t_rst+=1  

            rst=max(rst,t_rst)    

            visited.clear()
            for z in i:
                nx=z//m 
                ny=z%m
                if(nx < n and 0 <= nx  and 0 <= ny and ny < m):
                    arr[nx][ny] = 0

print(rst)