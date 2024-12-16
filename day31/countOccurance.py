def countOccurance(sentence, tar):
  if(not isinstance(tar, str)):
    print("Invalid target value")
    return 
  
  # ans = []
  # for i in range(0, len(sentence)):
  #   if sentence[i] == tar:
  #     ans.append(i)

  # alternative of above code and checks condition more efficiently
  ans = [i for i in range(len(sentence)) if(sentence[i:i+len(tar)] == tar)]

  if(len(ans) == 0):
    print("Target doesn't exists there!")
    return
  
  for i in ans:
    print (i,end=" ")



# test
countOccurance("hello world", "o")
print("\n")
countOccurance("hello world", "p")
