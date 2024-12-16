def isArmstrong(num):
  nums = list(map(int, str(num)))
  totSum = sum(i**len(nums) for i in nums)
  return totSum == num


print(isArmstrong(153))
