from cs50 import get_string
import re

text = input("Text: ")
sentences = list(filter(None, re.split(r'[!\.\?]', text)))
s_count = len(sentences)
words = [w for s in sentences for w in s.split()]
# for s in sentences:
#   words.extend(s.split())
w_count = len(words)
letters = [l for w in words for l in w if l.isalpha()]
l_count = len(letters)
# for w in words:
#   for l in w:
#     if l.isalpha():
#       l_count += 1
L = l_count * 100 / w_count
S = s_count * 100 / w_count
grade = round(0.0588 * L - 0.296 * S - 15.8)
if grade >= 16:
  print("Grade 16+")
elif grade < 1:
  print("Before Grade 1")
else:
  print("Grade", grade)
