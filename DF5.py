print("Q. Write a program to know cursor position in a file and print text according to:")
print("a. Print initial position")
print("b. Move cursor to 4th position")
print("c. Display next 5 characters")
print("d. Move cursor to next 10 characters")
print("e. Print current cursor position")
print("")
filename = input("Enter the filename: ")
with open("abc.txt", "r") as file:
    # a) print initial position
    print("Initial position:", file.tell())
    print("zeroth position", file.read(0))

    # b) move the cursor to 4th position
    file.seek(4, 0)
    print("Cursor moved to 4th position")
    # c) display the next 5 characters from the cursor
    print("Next 5 characters:", file.read(5))
    # d) move cursor to 19th character
    file.seek(19)
    print("Cursor moved to 19th character from current position")
    # e) print current cursor position
    print("Current position:", file.tell())
