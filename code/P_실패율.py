def solution(N, stages):
    answer = []
    rst = [0 for _ in range(N+1)]
    rst2=[]

    for i in stages:
        rst[i-1]+=1

    for i in range(N):
        if(sum(rst[i:]) == 0):
            rst2.append((0,i))
        else:    
            rst2.append((rst[i]/sum(rst[i:]),i))
 
    rst2.sort(key=lambda t:(-t[0],t[1]))

    for i in rst2:
        answer.append(i[1]+1)
    return answer