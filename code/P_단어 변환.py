min_v = 100000

def dfs(s_words,s_begin,s_target,cnt1):
    global min_v 
    count = cnt1
    if(s_target == s_begin):
        min_v = min(min_v,count)
        return min_v

    if(len(s_words) < count):
        return min_v
    
    for i,v in enumerate(s_words):
        cnt=0
        for j in range(len(v)):
            if(s_begin[j] == v[j]):
                cnt+=1

            if(cnt == len(v)-1 and j == len(v)-1):
                temp_arr=s_words[:]
                del temp_arr[i]
                dfs(temp_arr,v,s_target,count+1)
            
            elif(j == len(v)-1 and cnt == len(v) and  v== s_target):
                min_v=min(min_v,count)
                return 

    return
    

def solution(begin, target, words):
    answer = 0
    global min_v
    min_v=100000

    if target not in words:
        return 0

    for i,v in enumerate(words):
        cnt=0
        for j in range(len(v)):
            if(begin[j] == v[j]):
                cnt+=1

            if(cnt == len(v)-1 and j == len(v)-1):
                temp_arr=words[:]
                del temp_arr[i]
                dfs(temp_arr,v,target,1)
            elif(j == len(v)-1 and cnt == len(v)and v == target):
                return 1
            

    answer=min_v


    return answer

