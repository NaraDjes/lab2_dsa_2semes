import random
from itertools import product
abc = "abcdefghijklmnopqrstuvwxyz"
count = 0

stroki = list(product(list(abs), repeat = 10))

with open("my_dict.txt", "w") as file:
    while count != 200000:
        file.write(stroki[count] + "\n")
    
