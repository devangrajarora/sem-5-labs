n = int(input())
odd_len_strs = []
cnt = 0

for i in range(n):
	my_str = input()
	length = len(my_str)
	if length >= 2 and my_str[0] == my_str[length - 1]:
		cnt += 1
	if length % 2 == 1:
		odd_len_strs.append(my_str)

print("\nNumber of strings with first and last letter same and having length >= 2: ", cnt)
print("Strings with odd length: ", odd_len_strs)
