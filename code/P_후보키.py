from itertools import combinations

def solution(relation):
    answer=0
    row = len(relation)
    col = len(relation[0])

    t_list = [i for i in range(col)]
    c_list=[]
    
    for i in range(col):
        c_list.extend(list(combinations(t_list,i+1)))

    temp=[]
    cnt = 0
    chk=[]
    b_c=False

    for comb in c_list:
        valid = []
        b_c=False
        for r in relation:
            ta=""
            for co in comb:
                ta+=r[co]+","
            valid.append(ta)

        if(b_c == False and len(set(valid))==row):
            chk.append(comb)                 
                
    for i in chk[:]:
        for j in chk[:]:
            if set(i)!=set(j) and set(i) == set(i).intersection(set(j)):
                chk.remove(j)

    answer=len(chk)
                
    return answer