import math

def findGCD(a, b):
  maxi = 1
  for i in range(1, min(a,b)):
    if a%i == 0 and b%i == 0:
      maxi = max(maxi, i)
  return maxi

print(findGCD(15, 20))


# Using euclides algorithm
def findGCD2(a,b):
  while(b != 0):
    a,b = b, a%b
  return a

print(findGCD2(15,20))