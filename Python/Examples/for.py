mylist = [1, 2, 3, 4, 6, 5, 7, 88, 9, 9, 0]
a = 0

for i in mylist:
    if (a % 2 == 0):
        print('{} -- {}'.format(i, a))
    a = a+1
b = 0

for num in mylist:
    b = b+num

print(b)

newlist = [(1, 2), (3, 4), (5, 6), (7, 8)]
for (c, d) in newlist:
    print(f'{c} -- {d}')
