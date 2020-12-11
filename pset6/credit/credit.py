from cs50 import get_string

number = get_string("Number: ")
if len(number) not in range(13, 17):
  print("INVALID")
else:
  intlist = list(map(int, reversed(number)))
  total = 0
  even = intlist[1::2]
  odd = intlist[::2]
  for i in even:
    if 2*i > 9:
      total += ((2*i // 10) + (2*i % 10))
    else:
      total += 2*i
  total += sum(odd)
  if total % 10 == 0:
    if len(number) == 16:
      if number.startswith("4"):
        print("VISA")
      elif int(number[:2]) in range(51, 56):
        print("MASTERCARD")
      else:
        print("INVALID")
    elif len(number) == 15:
      if number.startswith("34") or number.startswith("37"):
        print("AMEX")
      elif number.startswith("4"):
        print("VISA")
      else:
        print("INVALID")
    elif len(number) in range(13, 15) and number.startswith("4"):
      print("VISA")
    else:
      print("INVALID")
  else:
    print("INVALID")