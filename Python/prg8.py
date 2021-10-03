def search(list,n):

    for i in range(len(list)):

        if list[i] == n:

            return True

    return False

list = [1, 2, 'himanshu',  4,56,'tii','python', 6, 7 ,57 ,'sonu', 86 ]

n = 'python'

if search(list, n):

    print("Found at index ",list.index(n))

else:

    print("Not Found")
