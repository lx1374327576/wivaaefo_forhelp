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
#             (5, '深圳大学', 'http://www.myszu.cn', 'LeetCodeKing', 'suanfa!1234'))
con.commit()
print(cur.execute('select * from secret_list').fetchall())
cur.close()
con.close()
