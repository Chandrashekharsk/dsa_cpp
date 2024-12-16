def filterOdds( nums ):
  for i in nums:
    if i%2 != 0:
      print(i, end=" ")

# test:
nums = [1,2,3,4,5,6,7,8,9,10,11,12,13]
filterOdds(nums)
