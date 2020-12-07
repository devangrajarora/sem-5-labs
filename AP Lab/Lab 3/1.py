def multiply(li):
	#check for empty list
	if not li:
		return "List is empty"
	ans = 1
	for num in li:
		ans = ans * num
	return ans

li = list(map(int, input().split()))
print(multiply(li))