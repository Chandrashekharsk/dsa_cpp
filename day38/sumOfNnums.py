
def sumOfSquares(n):
  sum = 0
  for i in range(1, n+1):
    sum += (i**2)
  return sum

print(sumOfSquares(5))