print("Write file B.txt")
filename = input("Enter the filename: ")
with open("B.txt", "w") as file:
    for i in range(3):
        line = input("Enter line " + str(i+1) + ": ")
        file.write(line + "\n")
print("The file has been created successfully!")
