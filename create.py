import sqlite3 as sql
con = sql.connect('database.db')
cur = con.cursor()
con.execute('''CREATE TABLE IF NOT EXISTS work_list
(id INTEGER primary key,
name_id REFERENCES person_list(id) ,
company_name,station,choice,program,price)''')
cur.close()
con.close()
