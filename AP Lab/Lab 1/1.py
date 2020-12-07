# input 2 lists
li1 = list(map(int,input().split()))
li2 = list(map(int,input().split()))

res = []

for num in li1:
	if num % 2 == 1:
		res.append(num)

for num in li2:
	if num % 2 == 0:
		res.append(num)

print(res)