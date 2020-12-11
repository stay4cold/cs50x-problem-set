words = []
with open("dictionaries/large", "r") as file:
  for line in file.readlines():
    words.append(line.strip())
print("\n".join(words))