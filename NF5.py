f6 = open("ABC.txt", "r")

print("Q.1. Write a program to know cursor position in a file and print text according to: ")

print("a. Print initial position")

print("Initial Position", f6.tell())
print("Zeroth Psition", f6.read(0))

print("b. Move cursor to 4th position")
f6.seek(4, 0)
print("Cursor moved to 4th position")

print("c. Display next 5 characters")
print("Next 5 characters: ", f6.read(5))

print("d. Move cursor to next 10 characters")
f6.seek(19, 0)
print("Cursor moved to 19th character from current position")

print("e. Print current cursor position")
print("Current position: ", f6.tell())
print("")


