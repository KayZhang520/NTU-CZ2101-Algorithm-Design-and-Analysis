def rabinKarpSimple(P, T, m):
    p = ord(P[0]) #code for pattern P
    t = ord(T[0])
    d =127  #number of characters possible 
    dM = 1  #weight of msb of each pattern-size
    i = 0 #current assumed starting matched index
    for x in range(1,m):
        p = p*d + ord(P[x])
        t = t*d + ord(T[x])
        dM = dM*d
    while(i<len(T)-m):
        if(p!=t):
            t = (t - ord(T[i])*dM)*d + ord(T[i+m]) #shift working range right by 1 and update t
            i+=1
        else: return i
    return -1

x = rabinKarp('dog','snoopdogg',3)
print(x)