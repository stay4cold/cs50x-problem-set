from cs50 import SQL
from sys import argv
from csv import reader, DictReader

if len(argv) != 2:
    print(f"Usage: python {argv[0]} data.csv")
    exit()
students = []
with open(argv[1], "r") as file:
    data = DictReader(file)
    for d in data:
        names = d["name"].split()
        if len(names) == 2:
            d["first"] = names[0]
            d["middle"] = None
            d["last"] = names[1]
        elif len(names) == 3:
            d["first"] = names[0]
            d["middle"] = names[1]
            d["last"] = names[2]
        students.append(d)
db = SQL("sqlite:///students.db")
for s in students:
    first = s["first"]
    middle = s["middle"]
    last = s["last"]
    house = s["house"]
    birth = int(s["birth"])
    db.execute(
        "insert into students(first, middle, last, house, birth) values(?, ?, ?, ?, ?)", s["first"], s["middle"], s["last"], s["house"], int(s["birth"]))
