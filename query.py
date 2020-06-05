"""
table name == secret_list

id primary key: 记录id
school_name: 学校名字
bbs_url: bbs链接
user_name: 用户名
password: 密码
"""
import sqlite3 as sql
con = sql.connect('database.db')
cur = con.cursor()
# cur.execute('insert into secret_list values(?, ?, ?, ?, ?)',
#             (1, '兰州大学', 'http://lzu.myubbs.com/', 'cxbz_1998', 'suanfabbw'))
cur.execute("insert into secret_list values(3, '厦门大学', 'http://xmu.23du.com/', 'LeetCodeKing', 'suanfa!1234')")
con.commit()
print(cur.execute('select * from secret_list').fetchall())
cur.close()
con.close()
