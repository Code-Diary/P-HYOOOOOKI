from itertools import combinations
from queue import Queue

dx = [-1,0,1,0]
dy = [0,1,0,-1]

n=0

def chk(x,y):
    global n
    if(n<=x or n<=y or x<0 or y<0):
       return False

    return True    

def bfs(i,j,land,h,c_num,color):
    q1 = Queue()
    q1.put((i,j))
    while(not q1.empty()):
        top = q1.get()
        x= top[0]
        y=top[1]
        color[x][y]=c_num

        for d in range(4):
            nx = x+dx[d]
            ny = y+dy[d]
            if (chk(nx,ny) and abs(land[nx][ny]-land[x][y])<=h and color[nx][ny]==0):
                q1.put((nx,ny))
                color[nx][ny] = c_num   


def solution(land, height):
    answer = 0
    min_v=10000
    global n
    n = len(land)
    v_land=[]
    
    color=[]
    group=1
    
    for i in range(n):
        temp = []
        for j in range(n):
            temp.append(0)
        color.append(temp)   

    for i in range(n):
        for j in range(n):
            if(color[i][j] == 0):
                bfs(i,j,land,height,group,color)
                group+=1

    t = [i for i in range(1,group)]
    color_list = list(combinations(t,2))
    rst = dict()
  

    for i in range(n):
        for j in range(n):
            nx=i+1
            ny=j+1
            if(chk(nx,j) and color[i][j] != color[nx][j]):
                a,b = min(color[i][j],color[nx][j]),max(color[i][j],color[nx][j])
                if((a,b) not in rst):
                    rst[(a,b)] = abs(land[i][j]-land[nx][j])
                else:    
                    rst[(a,b)] = min(rst[(a,b)],abs(land[i][j]-land[nx][j]))
            if(chk(i,ny) and color[i][j] != color[i][ny]):
                a,b = min(color[i][j],color[i][ny]),max(color[i][j],color[i][ny])
                if((a,b) not in rst):
                    rst[(a,b)] = abs(land[i][j]-land[i][ny])
                else:    
                    rst[(a,b)] = min(rst[(a,b)],abs(land[i][j]-land[i][ny]))
  
    temp=sorted(rst.items(),key=lambda t:t[1])
    t1=[]

    for i in range(1,group):
        t1.append(0)

    for i in temp:
        print(i)
        if(t1[i[0][0]-1] == 0 and t1[i[0][1]-1] ==0):
            answer+=rst[i[0]]
            t1[i[0][0]-1] = 1
            t1[i[0][1]-1] = 1
        elif(t1[i[0][0]-1]==0):
            answer+=rst[i[0]]
            t1[i[0][0]-1] = 1
        elif(t1[i[0][1]-1]==0):
            answer+=rst[i[0]]
            t1[i[0][1]-1] = 1
        if(0 not in t1):
            break

    return answer