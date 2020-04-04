def solution(record):
    answer = []
    user=dict()
    result=[]

    for i in record:
        info = i.split(" ")
        if(i[0] == "E"):
            user[info[1]] = info[2]
            result.append(("E",info[1]))
        elif(i[0] == "C"):
            user[info[1]] = info[2]
        elif(i[0] == "L"):
            result.append(("L",info[1]))


    for i in result:
        if(i[0] =="E"):
            answer.append(str(user.get(i[1]))+"님이 들어왔습니다.")
        elif(i[0] == "L"):
            answer.append(str(user.get(i[1]))+"님이 나갔습니다.")
    
    return answer