from cs50 import get_float

cash = -1
while cash < 0:
    cash = get_float("Change owed:")
cash *= 100
count = cash // 25
cash = cash % 25
count += cash // 10
cash = cash % 10
count += cash // 5
cash = cash % 5
count += cash // 1
print(int(count))
    