import math
def isPerfect(num):
  if num <= 1:
    return False
  totSum = 1
  for i in range(2, int(math.sqrt(num)+1)):
    if num % i == 0:
      totSum += i
      if num != num//i:
        totSum += num//i

  return totSum == num

print(isPerfect(28))
print(isPerfect(29))


