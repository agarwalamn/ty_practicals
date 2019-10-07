def longSub(arr,n):
    maxArr=[]

    s=set()
    ans=0
    for e in arr:
        s.add(e)
    for i in range(n):
        curArr=[]
        if(arr[i]-1) not in s:
            j=arr[i]
            while(j in s):
                curArr.append(j)
                j+=1
            # ans=max(ans,j-arr[i)
            if(ans<j-arr[i]):
                maxArr=curArr.copy()
                ans=j-arr[i]
    return maxArr
n=int(input())
arr=list(map(int,input().split()))
print(longSub(arr,n))