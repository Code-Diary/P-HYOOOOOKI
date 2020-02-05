from collections import deque

if __name__ == "__main__":
    T=int(input())
    for i in range(T):
        result = 0
        cycle=[]
        check=[]
        a=[]

        K=int(input())
        
        a.append(deque(map(int,input().split(" "))))
        a.append(deque(map(int,input().split(" "))))
        a.append(deque(map(int,input().split(" "))))
        a.append(deque(map(int,input().split(" "))))
        
        for j in range(K):
            check.clear()
            cycle=list(map(int,input().split(" ")))
            for k in range(3):
                if (a[k][2] != a[k+1][6]):
                    check.extend([1])
                else:
                    check.extend([0])
            circle = cycle[0]-1
            rot = cycle[1]
            a[circle].rotate(rot)  
            while 0 <= circle:
                if(0 <= circle-1 and check[circle-1] == 1):
                    circle -= 1
                    rot = -rot
                    a[circle].rotate(rot)  
                else:
                    break
                
            circle = cycle[0]-1
            rot = cycle[1]
            while circle <= 3:
                if(circle+1 <=3 and check[circle] == 1):
                    circle += 1
                    rot = -rot
                    a[circle].rotate(rot) 
                else:
                    break
   

        for o in range(4):
            if(a[o][0] == 1):
                result = result + (2**o)

        print("#"+str(i+1),result)       
        a.clear()
        check.clear()
        cycle.clear()
                
