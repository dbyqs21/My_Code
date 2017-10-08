import MySQLdb
#cxn=MySQLdb.connect(host="localhost",user="root",passwd="<Andy>",db="<Andy>",charset="utf-8")
cxn=MySQLdb.connect(passwd="<Andy>")
cur=cxn.cursor()
cur.execute('select * from andy')