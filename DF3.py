print("Merging files A.txt and B.txt")
with open("A.txt") as file1, open("B.txt") as file2, open("merge.txt", "w") as merge_file:
        file1_content = file1.read()
        file2_content = file2.read()
        merge_file.write(file1_content + "\n" + file2_content)
print("The contents of A.txt and B.txt have been merged into merge.txt successfully!")