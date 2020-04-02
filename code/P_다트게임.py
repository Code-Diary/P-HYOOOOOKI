def solution(dartResult):
    answer = 0
    chk=False
    temp = 0
    num=[]
    test = dartResult

    for i in test:
        if(chk == True and 48<=ord(i)<=57):
            num[-1] = 10
            continue

        if( 48<=ord(i)<=57):
            chk=True
            num.append(int(i))
            continue

        if(i == 'S'):
            pass
        elif(i=='D'):
            num[-1] = num[-1]**2
        elif(i=='T'):
            num[-1] = num[-1]**3
        elif(i=='*'):
            if(len(num)==1):
                num[0]*=2
            else:
                num[-1]*=2
                num[-2]*=2 
        elif(i=="#"):
            num[-1] = -num[-1]   

        chk=False         


    rst=0
    for i in num:
        rst +=i

    answer = rst
    return answer