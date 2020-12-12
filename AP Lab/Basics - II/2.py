m, n = map(int,input("Enter order: ").split())
dic1 = {}

print("Enter matrix 1:\n")
for i in range(m):
	# read ith row 
	row = list(map(int, input().split())) 
	for j in range(len(row)):
		dic1[(i,j)] = row[j] 

dic2 = {}
print("\nEnter matrix 2:\n")
for i in range(m):
	# read ith row 
	row = list(map(int, input().split())) 
	for j in range(len(row)):
		dic2[(i,j)] = row[j] 

final_matrix = []

# add two matrices and store in final_matrix
for i in range(m):
	row = []
	for j in range(n):
		num = dic1[(i,j)] + dic2[(i,j)]
		row.append(num)

	final_matrix.append(row)

print("\nFinal matrix:\n")
# display as 2D matrix
for row in final_matrix:
	for elem in row:
		print(elem, end = " ")
	print()