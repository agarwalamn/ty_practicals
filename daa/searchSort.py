def linearSearch(arr,item):
	for i in arr:
		if i==item:
			print("Found at",arr.index(i)+1)
			return
	print("given element not present")


#============================================================


def binarySearch(arr,item,start,end):
	if start>end:
		print("Not found")
		return
	mid = (start+end)//2
	if arr[mid]==item:
		print("Found at ",mid+1)
		return
	elif(arr[mid]>item):
		binarySearch(arr,item,start,mid-1)
	else:
		binarySearch(arr,item,mid+1,end)


#============================================================


def inserstionSort(arr):
	for i in range(len(arr)):
		key=arr[i]
		j=i-1
		while(j>=0 and key<arr[j]):
			arr[j],arr[j+1]=arr[j+1],arr[j]
			j=j-1
		arr[j+1]=key
	for i in arr:
		print(i,)


#============================================================


def mergeSort(arr):
	if len(arr)>1:
		mid = len(arr)//2
		l = arr[:mid]
		r = arr[mid:]
		#dividing step
		mergeSort(l)
		mergeSort(r)
		#meriging step
		i=j=k=0

		while(i<len(l) and j<len(r)):
			if(l[i]>r[j]):
				arr[k]=r[j]
				j+=1
			else:
				arr[k]=l[i]
				i+=1
			k+=1

		while(i<len(l)):
			arr[k]=l[i]
			i+=1
			k+=1

		while(j<len(r)):
			arr[k]=r[j]
			j+=1
			k+=1


#============================================================


def hepify(arr,n,i):
	largest=i
	l = 2*i+1
	r=2*i+2

	if l<n and arr[largest]<arr[l]:
		largest=l
	if r<n and arr[largest]<arr[r]:
		largest=r
	if largest!=i:
		arr[largest],arr[i]=arr[i],arr[largest]

		hepify(arr,n,largest)
def heapSort(arr):
	n=len(arr)
	for i in range(n,-1,-1):
		hepify(arr,n,i)
	for i in range(n-1,0,-1):
		arr[i],arr[0]=arr[0],arr[i]

		hepify(arr,i,0)

#============================================================



def partition(arr,start,end):
	i=start-1
	pivot = arr[end]
	for j in range(start,end):

		if arr[j]<=pivot:
			i+=1
			arr[i],arr[j]=arr[j],arr[i]
	arr[i+1],arr[end]=arr[end],arr[i+1]
	return (i+1)

def quickSort(arr,start,end):
	if start<end:

		p = partition(arr,start,end)

		quickSort(arr,start,p-1)
		quickSort(arr,p+1,end)


#============================================================



arr=[]
item=0
print("Enter array:")
arr=list(map(int,input().split()))

print("What operation would you like to perform")
print("Enter 1 for searching")
print("Enter 2 for Sorting")
n = int(input())
if n==1:
	print("Enter element to find:",)
	item=int(input())
	print("By which method:")
	print("Press 1 for linear search")
	print("Press 2 for binary search")
	k = int(input())
	if k==1: linearSearch(arr,item)
	else : 
		mergeSort(arr)
		binarySearch(arr,item,0,len(arr))
else:
	print("By which method:")
	print("Press 1 for insertion sort")
	print("Press 2 for merge sort")
	print("Press 3 for quick sort")
	print("Press 4 for heap sort")
	k=int(input())
	if k==1: inserstionSort(arr)
	elif k==2: 
		mergeSort(arr)
		print(arr)
	elif k==3:
		quickSort(arr,0,len(arr)-1)
		print(arr)
	else:
		heapSort(arr)
		print(arr)