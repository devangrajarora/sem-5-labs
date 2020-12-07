import random

sum_numbers, count_numbers = 0,0
concatenated_string = ''
dic = {}

print("Enter values for dictionary. Enter -1 to quit: ")
while True:
	elem = input()

	if elem == '-1':
		break;

	if elem.isnumeric():
		elem = int(elem)
		sum_numbers += elem
		count_numbers += 1
	else:
		concatenated_string += elem

	random_no = random.randrange(0,100)
	# avoid using same random no as key for differnt values
	while random_no in dic.keys():
		random_no = random.randrange(0,100)
	dic[random_no] = elem

if count_numbers == 0:
	avg = 0
else:
	avg = sum_numbers / count_numbers

print("\nAverage: ", avg)
print("Concatenated String: ", concatenated_string)

search_str = input("\nEnter string to search: ");
if search_str in dic.values():
	print(search_str + " is present")
else:
	print(search_str + " is not present") 


print("\nStrings with special charcter: ")
for elem in dic.values():
	# if string 
	if type(elem) is str:
		valid = 1
		for char in elem:
			if char.isalpha() or char.isnumeric():
				valid = 0
				break
		# this string is only printed if all characters in string are special charcters
		if valid == 1:
			print(elem)