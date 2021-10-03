#To write a python program find the square root of a number(Newton's method)

def newton_method(number, number_iters = 100):

    a = float(number)

    for i in range(number_iters):

        number = 0.5 * (number + a / number)

    return number

a=int(input("Enter 1st number:"))

b=int(input("Enter 2nd number:"))

print("Square root of 1st number:",newton_method(a))

print("Square root of 2nd number:",newton_method(b))
