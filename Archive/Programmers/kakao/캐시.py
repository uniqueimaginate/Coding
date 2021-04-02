def solution(cacheSize, cities):
    cache = []
    cached_time = []
    
    if cacheSize == 0:
        return 5 * len(cities)
    
    pos = 0
    result = 0
    
    for i, city in enumerate(cities):
        if city.lower() not in cache:
            if len(cache) < cacheSize:
                cache.append(city.lower())
                cached_time.append(i)
                result += 5
            else:
                min_time = min(cached_time)
                idx = cached_time.index(min_time)
                cache[idx] = city.lower()
                cached_time[idx] = i
                result += 5
                
        else:
            idx = cache.index(city.lower())
            cached_time[idx] = i
            result += 1
    

    return result