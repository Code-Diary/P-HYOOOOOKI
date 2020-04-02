def solution(n, t, m, timetable):
    answer = ''

    bus_t = []

    for i in range(n):
        hour = 9 + (t*i)//60
        minu = 0 + (t*i)%60
        if(hour < 10):
            sh = "0"+str(hour)
        else:
            sh = str(hour)

        if(minu < 10):
            bus_t.append(sh+":0"+str(minu))
        else:
            bus_t.append(sh+":"+str(minu))


    goal = "00:00"

    temp = timetable[:]
    temp.sort()

    cnt=0

    loop_c = len(temp)

    for i in range(loop_c):
        if(len(bus_t) == 1):
            if(len(temp)<=m-1):
                goal = bus_t[0]
                return goal
            else:
                del temp[:m-1]
                if(temp[0] == "00:01"):
                    return "00:00"
                if(temp[0][3:] == "00"):
                    if(int(temp[0][:2])<=10):
                        goal = "0"+str(int(temp[0][:2])-1)+":59"  
                        if(goal > bus_t[0]):
                            goal = bus_t[0]   
                        return goal
                    else:
                        goal = str(int(temp[0][:2])-1)+":59"        
                        if(goal > bus_t[0]):
                            goal = bus_t[0]   
                        return goal
                else:
                    if(int(temp[0][3:]) <= 10):
                        goal = temp[0][:2]+":0"+str(int(temp[0][3:])-1) 
                        if(goal > bus_t[0]):
                            goal = bus_t[0]   
                        return goal
                    else:
                        goal = temp[0][:2]+":"+str(int(temp[0][3:])-1) 
                        if(goal > bus_t[0]):
                            goal = bus_t[0]   
                        return goal
        else:
            if int(temp[0][:2]) < int(bus_t[0][:2]):
                cnt+=1
                del temp[0]
            elif int(temp[0][:2]) == int(bus_t[0][:2]):
                if int(temp[0][3:]) <= int(bus_t[0][3:]):
                    cnt+=1
                    del temp[0]
                else:
                    del bus_t[0]   
            elif int(temp[0][:2]) > int(bus_t[0][:2]):
                del bus_t[0]

            if(cnt == m):
                cnt=0
                del bus_t[0]           

    goal = bus_t[-1]             

    answer = goal
    return answer   