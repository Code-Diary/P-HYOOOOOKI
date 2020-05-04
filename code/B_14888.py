from itertools import permutations

N=int(input())

num = list(map(int,input().split(" ")))
oper=list(map(int,input().split(" ")))

oper_model=[]
for idx,val in enumerate(oper):
    for j in range(val):
        if(idx==0):
            oper_model.append("+")
        elif(idx==1):
            oper_model.append("-")
        elif(idx==2):
            oper_model.append("*")
        elif(idx==3):   
            oper_model.append("/")

oper_p = list(permutations(oper_model,N-1))            


max_v=-1000000000
min_v=1000000000

for val1 in oper_p:
    t1=num[0]
    for idx,val in enumerate(val1):
        t2=num[idx+1]
        if(val == '+'):
            t1 = t1+t2
        elif(val=='-'):
            t1 = t1 - t2
        elif(val == '/'):
            if(t1<0):
                t1 = -(abs(t1)//t2)
            else:
                t1 = t1//t2    
        elif(val =='*'):
            t1 = t1*t2

    max_v = max(max_v,t1)
    min_v = min(min_v,t1)

print(max_v)
print(min_v)    