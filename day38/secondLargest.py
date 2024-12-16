import sys

def findSecondLargest(list):
  i=0
  maxi= -sys.maxsize-1
  secondMaxi = maxi

  while(i!= len(list)):
    if(list[i]>maxi):
      secondMaxi = maxi
      maxi = list[i]
    elif (list[i]>secondMaxi and list[i] != maxi):
      secondMaxi = list[i]
    i = i+1
  return secondMaxi


list = [9,7,3,2]
print(findSecondLargest(list))
