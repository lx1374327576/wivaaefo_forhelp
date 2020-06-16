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
cur.execute('insert into work_list values(?, ?, ?, ?, ?,?,?)',
            (2,2,'哈工大', 'http://www.myhit.cn', 'LeetCodeKing', 'suanfa!1234',546))
# cur.execute('update secret_list set bbs_url="http://bbs.csu.edu.cn/bbs/" where id=6')
con.commit()
print(cur.execute('select * from work_list').fetchall())
cur.close()
con.close()
