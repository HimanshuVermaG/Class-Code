#gcd of two numbers

import math

print("The gcd of 95 and 150 is :", end="")

print(math.gcd(95,150))

#gcd of two numbers
a=75
b=300
def hcf(a,b):
    if(b==0):
        return a
    else:
        return hcf(b,a%b)

print("The gcd of 8 and 100 is :", end="")
print(hcf(8,100))
