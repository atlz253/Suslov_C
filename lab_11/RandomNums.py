from random import randint

n = int(input('Введите кол-во случайных элементов: '))

with open('test.txt', 'a', encoding='utf-8') as file:
    for i in range(n):
        file.write(str(randint(-10000, 10000))+'\n')
