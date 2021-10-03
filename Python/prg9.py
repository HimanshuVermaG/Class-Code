# Binary search in python
def binarySearch(array, x, low, high):

    if high >= low:

        mid = low + (high - low)//2
        # If found at mid, then return it
        if array[mid] == x:
            return mid
        # Search the left half
        elif array[mid] > x:
            return binarySearch(array, x, low, mid-1)
        # Search the right half
        else:
            return binarySearch(array, x, mid + 1, high)
    else:
        return -1
array = [8,10,11,15,17,20,25,70]
x = 17

result = binarySearch(array, x, 0, len(array)-1)

if result != -1:
    print("Element is present at index " + str(result))
else:
    print("Not found")
