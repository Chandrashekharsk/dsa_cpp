
def reverseArr(nums):
  st,end = 0, len(nums)-1
  while(st<end):
    nums[st], nums[end] = nums[end], nums[st]
    st+=1
    end-=1


nums = [1,2,34,3,5,5,6,3]
reverseArr(nums)
for i in nums:
  print(i, end=" ")
