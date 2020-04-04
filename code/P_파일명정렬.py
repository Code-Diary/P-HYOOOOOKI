def solution(files):
    answer = []
    

    s_file=[]

    chk_n=0
    chk=False

    print(files)
    for i in files:
        temp=[]
        chk=False
        for j in range(len(i)):
            if(chk == False and 48 <= ord(i[j])<= 57):
                chk = True
                chk_n=j
                temp.append(i[:j])

            if(chk==True):
                if(j == len(i)-1):
                    temp.append(i[chk_n:])
                if(57 < ord(i[j]) or ord(i[j]) < 48):
                    temp.append(i[chk_n:j])
                    temp.append(i[j:])
                    break
                

        s_file.append(tuple(temp))
    print(s_file)    

    f_files=sorted(s_file,key=lambda t:(t[0].lower(),int(t[1])))

    for i in f_files:
        temp=""
        for j in i:
            if(j is not None):
                temp += str(j)
        answer.append(temp)    

    print(answer)
    
    return answer

solution(["F-15"])    