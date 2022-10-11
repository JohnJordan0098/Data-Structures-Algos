# https://www.codechef.com/submit/TWOTRAINS?tab=statement

# the lateness is bottlenecked by the longest time between two stations. Thus, we use max(time).
t = int(input())
while(t):
    n = int(input())
    time = [int(x) for x in input().split()]
    ans = 0
    for i in range(0,n-1):
        ans = ans + time[i]
    print(max(time) + ans)
    t = t-1