print("Q1. Find total number of uppercase characters in merge.txt")
print("Q2. Find total number of lowercase characters in merge.txt")
print("Q3. Count number of digits in merge.txt")
filename = input("Enter the filename: ")
with open("merge.txt") as file:
    file_content = file.read()
    upper_count = 0
    lower_count = 0
    digit_count = 0
for char in file_content:
    if char.isupper():
        upper_count += 1
    elif char.islower():
        lower_count += 1
    elif char.isdigit():
        digit_count += 1
print("Upper case letters:", upper_count)
print("Lower case letters:", lower_count)
print("Digits:", digit_count)