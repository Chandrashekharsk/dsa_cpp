def sumOfDigitInStr(sentence):
  sum = 0
  for i in sentence:
    if i.isdigit():
      sum += int(i)

  print("Sum: ", sum)
sumOfDigitInStr("a1b2c3")
