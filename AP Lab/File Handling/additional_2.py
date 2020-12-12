a = ['a.c', 'b.py', 'c.php', 'd.cpp', 'e.js']
a.sort(key = lambda item: item.split('.')[1])
print(a)
