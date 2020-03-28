from itertools import combinations
from itertools import product
import itertools

def solution(user_id, banned_id):
    answer = 0
    
    chk = False
    temp=[]
    temp2=[]
    c_list=[]
    b = len(banned_id)
    u = len(user_id)

    for i in banned_id:
        for j in user_id:
            if(len(i) == len(j)):
                # print(i,j)
                chk=True
                for k in range(len(i)):
                    if(i[k] == j[k] or i[k] == '*'):
                        # print(i[k],j[k])
                        chk = True
                        continue
                    else:
                        chk = False
                        break

                if(chk == True):
                    temp2.append(j)
                    # print(temp2)

        temp.append(temp2)
        c_list.append(temp2)
        temp2=[]

    # print(temp)

    for i in range(len(c_list)):
        for j in range(len(c_list[i])):
            c_list[i][j]=0


    tv=1
    for i in c_list:
        tv = tv*(len(i))

    answer = tv


            
    
    return answer