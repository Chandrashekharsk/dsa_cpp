import math

def isPrime(num):
  for i in range(2, int(math.sqrt(num))+1):
    if num % i == 0:
      return False
  return True

def primeNumbers():
  primeNumbers = []

  for i in range(2, 100):
    if isPrime(i):
      primeNumbers.append(i)
  return primeNumbers

ans = primeNumbers()
print (ans)
