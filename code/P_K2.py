


def solution(s):
    answer = []
    
    temp=[]
    temp2=[]
    chk=False
    ts=""

    t=list(s.split("}"))
    # print(t)

    for i in t:
        temp=[]
        for j in i:
            if(chr(48)<=j <=chr(57)):
                if(chk == True):
                    ts=ts+j
                else:
                    ts=j
                chk = True
            else:
                chk=False
                if(len(ts)!=0):
                    temp.append(ts)
        if(len(ts)!=0):
            temp.append(ts)
        ts=""    
        if(len(temp)!=0):        
            temp2.append(temp)


    temp2.sort(key=len)
    # print(temp2)


    answer = []

    for i in temp2:
        for j in i:
            if int(j) not in answer:
                answer.append(int(j))

    # print(answer)    

    return answer