def isPalindrome(sentence):
  st, end = 0, len(sentence)-1

  while(st <= end):
    if(sentence[st] != sentence[end]):
      print("not a palindrome")
      return
    st+=1
    end-=1 
    

  print("palindrome")

# test 
isPalindrome("hello")
isPalindrome("nitin")
isPalindrome("car")