import sqlite3
conn = sqlite3.connect('test.db')
print('Opened DB succesfully')

def printDB():
	a = conn.execute("SELECT * FROM Employee");
	for row in a:
		print(row)

conn.execute("DROP TABLE IF EXISTS Employee;")
conn.execute(''' 
	CREATE TABLE IF NOT EXISTS Employee(
	id INTEGER PRIMARY KEY AUTOINCREMENT,
	name TEXT NOT NULL); ''')

print('Table created succesfully')

conn.execute("INSERT INTO Employee(name) VALUES('Devang')");
conn.execute("INSERT INTO Employee(name) VALUES('Nimesh')");

printDB()

id, name = input().split()
id = int(id)
conn.execute(f"UPDATE Employee SET name = \'{name}\' WHERE id = {id}")

printDB()
# conn.commit()