#not working:(

#function to efficiently hash a substring
def hash(Txt, m, d, q):
    q = 7
    h = ord(Txt[0])%q
    for x in range(1,m):
        h = (h*d+ord(Txt[x]))%q
    return h

#function to rehash after shifting text window right by 1
def rehash(T, i, m, ht, q, d):
    #ht is the hash value for the substring that start at index i, we want to find value for index i+1
    dM=1
    for x in range(0,m-1):
        dM*d
    oldestHash = (ord(T[i])*dM)%q
    newHash = ((ht-oldestHash)*d + ord(T[i+m]))%q
    return newHash

def RKscan(P,T):
    q = int(input('Enter a suitable prime number:'))
    m = len(P)
    n = len(T)
    dM = 1
    d=127
    for x in range(0,m-1):
        dM = (dM*d)%q
    hp = hash(P,m,d,q) 
    ht = hash(T,m,d,q) #starting substring hash value whr i = 0
    for j in range(0,n-m):
        if(hp==ht and P==T[j:j+m]):
            return j
        ht = rehash(T,j,m,ht,q,d)
    return -1

i = RKscan('chao', 'zhang chaofan kay')
print(i)



