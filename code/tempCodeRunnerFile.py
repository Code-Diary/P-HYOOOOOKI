dx = [-1,0,1,0]
dy = [0,1,0,-1]

n=0

def chk(x,y):
    global n
    if(n<=x or n<=y or x<0 or y<0):
       return False

    return True    


def solution(land, height):
    answer = 0
    min_v=10000
    global n
    n = len(land)
    c_land=[]
    v_land=[]

    for i in range(n):
        temp=[]
        for j in range(n):
            temp.append(0)
        c_land.append(temp)
        v_land.append(temp)

    print(v_land)

    for i in range(n):
        for j in range(n):
            t_val = land[i][j]
            c_land[i][j]=1
            for d in range(4):
                if(chk(i+dx[d],j+dy[d])):
                    if(abs(t_val-land[i+dx[d]][j+dy[d]]) <= height):
                        if(c_land[i+dx[d]][j+dy[d]] == 0):
                            c_land[i+dx[d]][j+dy[d]] = 1
                            v_land[i+dx[d]][j+dy[d]] = v_land[i][j]
                        else:
                            if(v_land[i+dx[d]][j+dy[d]]<v_land[i][j]):
                                v_land[i][j]=[i+dx[d]][j+dy[d]]
                            else:    
                                v_land[i+dx[d]][j+dy[d]] = v_land[i][j]
                    else:
                        if(t_val < land[i+dx[d]][j+dy[d]]):
                            if(c_land[i+dx[d]][j+dy[d]] == 0):
                                c_land[i+dx[d]][j+dy[d]] = 1
                                v_land[i+dx[d]][j+dy[d]] = abs(t_val-land[i+dx[d]][j+dy[d]])
                            else:
                                v_land[i+dx[d]][j+dy[d]] = min(v_land[i+dx[d]][j+dy[d]],abs(t_val-land[i+dx[d]][j+dy[d]]))
                        else:         
                            v_land[i][j] = min(v_land[i][j],abs(t_val-land[i+dx[d]][j+dy[d]]))
                print(v_land)
    
    answer=max(max(v_land))

    return answer