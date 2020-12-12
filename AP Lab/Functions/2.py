def unique(li):
	return list(set(li))

li = list(map(int, input("Enter input list: ").split()))
print("Unique List: ", unique(li))