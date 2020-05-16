def solution(s):
    answer = 0
    
    s_len = len(s)
    rst =[s_len]
        
    ts=s
    
    for i in range(1,s_len//2 + 1):
        ts=s
        temp = ts[0:i]
        result=0
        ts=ts[i:]
        cnt=1
        while(len(ts)):
            # print(ts,result)
            if(len(ts)<i):
                result+=len(ts)
                break
            if temp == ts[0:i]:
                # print(temp,result)
                cnt+=1
                ts=ts[i:]
                if(len(ts)<i):
                    result+=(i+len(str(cnt)))    
            else:
                if(1<cnt ):
                    result += (i+len(str(cnt)))
                else:
                    result+=i    
                temp = ts[0:i]
                cnt=1
                ts=ts[i:]
                if(len(ts)<i):
                    result+=(i)    

        # print(i,result)              
        rst.append(result)  
            
    answer = min(rst)


    return answer


# print(solution(""))