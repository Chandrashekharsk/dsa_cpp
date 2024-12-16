def countVowels(sentence):
  count = 0
  for i in sentence:
    if i in "aeiou":
      count += 1
  
  print(count)

# test 
countVowels("hello world")


