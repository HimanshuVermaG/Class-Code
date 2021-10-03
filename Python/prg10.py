a = [56, 34, 25, 82, 17, 69, 9, 22, 101, 90, 97]

for i in range(len(a)):

    b = i

    for j in range(i + 1, len(a)):

        if a[b] > a[j]:
            b = j

    a[i], a[b] = a[b], a[i]

print(a)

