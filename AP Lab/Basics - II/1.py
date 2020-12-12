dic = {}
sentence = input()
ans = 0

# calculate frquency of each word
for word in sentence.split():
	if word not in dic:
		dic[word] = 1
	else:
		dic[word] += 1

# add frequencies
for cnt in dic.values():
	ans += cnt

print(ans)