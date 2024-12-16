# def recursion_fib(n, dp):
#   if n == 1:
#     return 0
#   if n == 2:
#     return 1
#   if(dp[n] != -1): return dp[n]

#   dp[n] = recursion_fib(n - 1, dp) + recursion_fib(n - 2, dp)
#   return dp[n]


# def printFibonnaciSeq(n):
#   dp = [-1] * (n+1)
#   for i in range(1, n+1):
#     print(recursion_fib(i, dp))



# def tabulation_fib(n):
#   if(n==1): return 0
#   if(n==2): return 1
#   dp = [-1] * (n+1)
#   dp[1] = 0
#   if n>1:
#     dp[2] = 1
#   for i in range(3, n + 1):
#     dp[i] = dp[i - 1] + dp[i - 2]
#   return dp[n]  



def tabulation_fib2(n):
  if(n==1): return 0
  if(n==2): return 1

  prev2 = 0
  prev = 1
  for i in range(3, n + 1):
    curr = prev + prev2
    prev2 = prev
    prev = curr
  return prev  

def printFibonnaciSeq2(n):
  for i in range(1, n + 1):
    print(tabulation_fib2(i), end=" ")

printFibonnaciSeq2(5)

