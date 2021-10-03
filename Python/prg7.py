list1=[120,243,7,544,34,76,214,571,109,79,38]

print("Maximum number using in-built method:",max(list1))    #using in-built method

maximum=0

for i in list1:    #using loops

    if(i>maximum):

        maximum=i

print("Maximum number using loops:",maximum)
