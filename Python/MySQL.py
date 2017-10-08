import MySQLdb
cxn=MySQLdb.connect(db='school')
cur=cxn.cursor()
cur.execute('select * from student')
