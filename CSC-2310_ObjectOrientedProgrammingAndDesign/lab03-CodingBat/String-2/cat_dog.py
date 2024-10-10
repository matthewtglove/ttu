def cat_dog(str):
    catCount = 0
    dogCount = 0
    for i in range(len(str) - 2):
        if(str[i:i+3] == 'cat'):
            catCount = catCount + 1
            continue
        if(str[i:i+3] == 'dog'):
            dogCount = dogCount + 1

    return (catCount == dogCount)

# print(cat_dog('catdogcat'))

# str = 'catcat'
# catCount = 0
# dogCount = 0
# for i in range(len(str) - 2):
#     if(str[i:i+3] == 'cat'):
#         catCount = catCount + 1
#         continue
#     if(str[i:i+3] == 'dog'):
#         dogCount = dogCount + 1

# print(catCount)
# print(dogCount)

# print(catCount == dogCount)