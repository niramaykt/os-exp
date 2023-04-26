import os

f3 = open("A.txt", "r")
data_1 = f3.read()
f4 = open("B.txt", "r")
data_2 = f4.read()

f5 = open("Merge.txt", "w")
f5.write(data_1)
f5.write(" ")
f5.write(data_2)
