a = list(input())

total = 0

for i in a:
    if(i == chr(65) or i == chr(66) or i==chr(67)):
        total+=3
    elif(i == chr(68) or i == chr(69) or i==chr(70)):
        total+=4
    elif(i == chr(71) or i == chr(72) or i==chr(73)):
        total+=5
    elif(i == chr(74) or i == chr(75) or i==chr(76)):
        total+=6
    elif(i == chr(77) or i == chr(78) or i==chr(79)):
        total+=7
    elif(i == chr(80) or i == chr(81) or i==chr(82) or i==chr(83)):
        total+=8
    elif(i == chr(84) or i == chr(85) or i==chr(86)):
        total+=9
    elif(i == chr(90) or i == chr(87) or i==chr(89) or i == chr(88)):
        total+=10

print(total)
