from sys import argv
from csv import reader, DictReader

def dnaCount(source, sub):
  max = 0
  c = 0
  l = len(sub)
  q = 0
  while q < len(source):
    if source[q:q+l] == sub:
      c += 1
      if c > max:
        max = c
      q += l
    else:
      c = 0
      q += 1
  return max

if len(argv) != 3:
  print(f"Usage: python {argv[0]} data.csv sequence.txt")
  exit()
with open(argv[2], "r") as file:
  dna = file.read()
people = []
with open(argv[1], "r") as file:
  reader = DictReader(file)
  for p in reader:
    people.append(p)

all = False
for p in people:
  all = True
  for k, v in p.items():
    if k == "name":
      continue
    if dnaCount(dna, k) != int(v):
      all = False
      break
  if all:
    print(p["name"])
    break
if not all:
  print("No match")
