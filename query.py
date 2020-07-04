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
# cur.execute('insert into person_list values(?, ?, ?, ?, ?)',
#             (1,'cd0iqh9unclw21','广东垃圾一本', '研究生', '研二'))
cur.execute('insert into work_list values(?, ?, ?, ?, ?,?,?)',
            (1,1,'shopee','海外开发', 25, 1,130))
# cur.execute('delete from person_list where id=1')
# cur.execute('update secret_list set bbs_url="http://bbs.csu.edu.cn/bbs/" where id=6')
con.commit()
print(cur.execute('select * from work_list').fetchall())
cur.close()
con.close()
