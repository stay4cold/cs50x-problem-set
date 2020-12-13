from cs50 import SQL
from sys import argv

if len(argv) != 2:
    print(f"Usage: python {argv[0]} name of a house")
    exit()
house = argv[1]
db = SQL("sqlite:///students.db")
rows = db.execute("select * from students where house=? order by last, first", house)
for row in rows:
  if row["middle"]:
    print(f"{row['first']} {row['middle']} {row['last']}, born {row['birth']}")
  else:
    print(f"{row['first']} {row['last']}, born {row['birth']}")