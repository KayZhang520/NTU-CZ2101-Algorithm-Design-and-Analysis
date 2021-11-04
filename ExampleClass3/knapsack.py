

def unboundedKnapsack(W, n, val, wt):
    prev = [None]*(n-1)

    dp = [0 for i in range(W + 1)]

    for i in range(W + 1):
        for j in range(n):
            if (wt[j] <= i):
                if(dp[i - wt[j]] + val[j] > dp[i]):
                    prev[i] = j #set last item placed in bag at current capacity to be that item, j
                    dp[i] = dp[i - wt[j]] + val[j]
    return prev
W = 14
val = [7,6,9]
wt = [5,6,8]
n = len(val)

arr=unboundedKnapsack(W, n, val, wt)
i=14
while(i>=min()) 