f6 = open("Merge.txt", "r")
data = f6.read()

upper_count = 0
lower_count = 0
digit_count = 0

for ch in data:
	if ch.isupper():
		upper_count += 1
	elif ch.islower():
		lower_count += 1
	elif ch.isdigit():
		digit_count += 1

print("Total number of Uppercase characters are: ", upper_count)
print("Total number of lowercase characters are: ", lower_count)
print("Total number of digits are: ", digit_count)
