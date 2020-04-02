

def solution(cacheSize, cities):
    answer = 0

    cache=[]
    time=0

    if(len(cities) ==0):
        return 0

    if(cacheSize == 0):
        return len(cities)*5

    for i in cities:
        if i.lower() not in cache:
            cache.append(i.lower())
            time+=5

            if cacheSize+1 == len(cache):
                del cache[0]
        else:
            t = cache.index(i.lower())
            del cache[t]
            cache.append(i.lower())
            time+=1

    return time