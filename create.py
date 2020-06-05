import sqlite3 as sql
con = sql.connect('database.db')
cur = con.cursor()
con.execute('CREATE TABLE IF NOT EXISTS secret_list(id primary key, school_name, bbs_url, user_name, password)')
cur.close()
con.close()
