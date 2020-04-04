def solution(lines):
    answer = 0
    
    if(len(lines)==1):
        return 1

    s=[]
    f=[]

    for i in lines:
        info = i.split(" ")
        time_v = info[1].split(":")
        f_time = int( (float(time_v[2])*1000)) + int(time_v[1])*60000 + int(time_v[0])*3600000
        a=int((float(info[2][:-1]) * 1000))
        s_time = f_time-a+1            
        # s.append(s_time)
        s.append(f_time)

    rst=0
    chkt=False
    for sv in s:
        cnt=0
        fv=sv+999
        for i in lines:
            t = i.split(" ")
            t1=t[1].split(":")
            ft = int( (float(t1[2])*1000) ) + int(t1[1])*60000+ int(t1[0])*3600000
            b=int((float(t[2][:-1])*1000))
            st = ft-b+1
            if (sv <= st <=fv or sv<= ft <= fv or (st <= sv and fv<=ft) ):
            # print(sv,fv,st,ft)
                cnt+=1
        
        rst = max(cnt,rst)
        if(rst == len(lines)):
            break
    
    answer=rst
            
    return answer