def solution(msg):
    answer = []
    m=list(msg)
    s=[]

    rst=[]
    temp2=""
    chk=False
    cnt=0

    temp = ""
    temp=m[0]

    if(len(m)==1):
        rst.append(m[0])

    for i in range(1,len(m)):
        temp2 = temp + m[i]

        if(temp2 not in s):
            s.append(temp2)
            rst.append(temp)
            temp = m[i]
            if(i==len(m)-1):
                rst.append(m[i])
        else:
            temp=temp2        
            if(i==len(m)-1):
                rst.append(temp2)

    for i in rst:
        if(1<len(i)) :
            answer.append(s.index(i)+27)
        else:
            answer.append(ord(i)-64)               

    return answer