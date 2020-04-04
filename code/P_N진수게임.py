def solution(n, t, m, p):
    answer = ''

    if(t==0):
        return ""

    num=[]
    i=0
    cnt=0
    while(1):
        temp=""
        if(i==0):
            temp="0"
        else:
            while(0<i):
                na=i%n
                if(10<=na): 
                    temp+=chr(na+55)
                else:    
                    temp+=str(na)
                i=i//n
        temp=temp[::-1]
        num.extend(list(temp))
        cnt+=1
        i=cnt
        if(t*m < len(num)):
            break
        

    for i in range(t):
        answer+=str(num[i*m+(p-1)])           

    return answer