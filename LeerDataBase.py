import mysql.connector

cnx = mysql.connector.connect(user='admin',password='iot',host='127.0.0.1',database='InfoElectrica')

print("1")

cursor = cnx.cursor()

sql = "SELECT * FROM datos"

cursor.execute(sql)

tables = cursor.fetchall()

for table in tables:
	print(table)


cursor.close()
cnx.close() 
