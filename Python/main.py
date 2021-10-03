import sys

print("\n\n\t Script Name : ",sys.argv[0])

print("\n")

le=len(sys.argv)

for i in range(1,le):

   print("\t Word : ",i," : ", sys.argv[i])

print("\n\n\t Word Count : ", len(sys.argv)-1)
