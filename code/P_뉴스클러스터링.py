def solution(str1, str2):
    answer = 0
    
    s1=str1
    s2=str2

    s1=s1.lower()
    s2=s2.lower()

    t1=[]
    t2=[]

    for i in s1:
        if(97<=ord(i)<=122):
            t1.append(i)
        else:
            t1.append("/")

    for i in s2:        
        if(97<=ord(i)<=122):
            t2.append(i)    
        else:
            t2.append("/")

    print(t1,t2)

    tt1=[]
    tt2=[]
    ttt1=[]
    ttt2=[]

    for i in range(len(t1)-1):
        if(t1[i] != "/" and t1[i+1] != "/"):
            ttt1.append(t1[i]+t1[i+1])
            tt1.append(t1[i]+t1[i+1]+str(ttt1.count(t1[i]+t1[i+1])))


    for i in range(len(t2)-1):
        if(t2[i] != "/" and t2[i+1] != "/"):
            ttt2.append(t2[i]+t2[i+1])
            tt2.append(t2[i]+t2[i+1]+str(ttt2.count(t2[i]+t2[i+1])))

    print(tt1,tt2)

    if(len(tt1) ==0 and len(tt2)==0):
        return 65536

    mix=[]
    plus=[]

    for i in tt1:
        for j in tt2:
            if(i==j):
                if i not in mix:
                    mix.append(i)
                    break

    rst1 = len(mix)
    rst2 = len(tt1)+len(tt2)-rst1

    answer=int((rst1/rst2)*65536)            

    return answer


# solution("aa1+aa2","AAAA12")    