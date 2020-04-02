def solution(m, musicinfos):
    answer = ''
    
    rst = []
    n1=len(m)
    
    song = []
    for i in m:
        if(i=="#"):
            song[-1]=song[-1]+"#"
        else:
            song.append(i)

    print(song)        

    for i in range(len(musicinfos)):
        melody=[]
        melody2=[]
        info = musicinfos[i].split(",")
        hour = int(info[1][:2]) - int(info[0][:2])
        minu = int(info[1][3:]) - int(info[0][3:])
        m_t = hour*60 + minu

        for j in info[3]:
            if(j=="#"):
                melody[-1]=melody[-1]+"#"
            else:
                melody.append(j)

        mel=len(melody)

        melody2.extend(melody*(m_t//mel))
        melody2.extend(melody[:m_t%mel])
        print(melody2)

        for j in range(len(melody2)):
            for k in range(len(song)):
                try:
                    # print(j,k)
                    if(len(melody2) < j+k):
                        break
                    if(melody2[j+k]==song[k]):
                        if(k==len(song)-1):
                            rst.append((m_t,i,info[2]))
                            break
                    else:
                        break    
                except:
                    pass    


    rst.sort(key=lambda t : (-t[0],t[1]))
    
    if(len(rst)==0):
        return "(None)"
    else:
        return rst[0][2]
    return answer