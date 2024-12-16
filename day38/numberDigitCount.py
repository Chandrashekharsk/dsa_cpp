
def countDigits(num):
  count = 0
  sum = 0

  while(num != 0):
    lastDigit = num%10
    count +=1
    sum+=lastDigit
    num //= 10
  
  return {"Count": count, "Sum":sum}

res = countDigits(54321)
print(res)

