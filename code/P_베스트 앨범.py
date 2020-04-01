a=["classic", "pop", "classic", "classic", "pop"]
b=[500, 600, 500, 800, 2500]

test ={}
test_i = {}


for i in range(len(a)):
    if a[i] in test:
        test[a[i]] = test.get(a[i])+b[i]
        test_i[a[i]] = test_i.get(a[i]) + [(b[i],i)]
    else:
        test[a[i]]=b[i]
        test_i[a[i]] = [(b[i],i)]

test = sorted(test.items(), key=lambda t : t[1], reverse = True)

rst=[]

for i in test:
    test_i.get(i[0]).sort(reverse=True,  key=lambda t : t[0])
    print(test_i.get(i[0]))
    cnt = 0
    for j in test_i.get(i[0]):
        rst.append(j[1])
        cnt +=1
        if cnt == 2:
            break

print(rst)
