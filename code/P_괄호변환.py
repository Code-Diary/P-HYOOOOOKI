def func(s):
    if(len(s)==0):
        return ""

    # print(s)
    rst=""
    open1 =0
    close1=0
    u=""
    v=""
    for i,j in enumerate(s):
        # print(j)
        if(j == "("):
            open1+=1
        elif(j == ")"):
            close1+=1

        if(open1==close1):
            u=s[:i+1]
            v=s[i+1:]
            break

    # print(u,v)    

    open1 =0
    close1=0
    chk=False
    for i in u:
        if(i=="("):
            open1+=1
        else:
            close1+=1

        if(open1 < close1):
            chk = False
            break

    if(open1 == close1):
        chk=True    

    if(chk):
        rst+=u
        rst+=func(v)
        return rst
    else:    
        temp = func(v)
        temp = "("+temp+")"
        u=u[1:-1]
        for k in u:
            if(k =="("):
                temp+=")"
            else:
                temp+="("   
        return temp



def solution(p):
    answer = ''
    answer=func(p)


    return answer


print(solution(	"(()())()"))    