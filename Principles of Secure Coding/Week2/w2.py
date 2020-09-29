import os

filename = "sa-1-testfile.dms"

f = open(filename)
os.chmod(filename, 000)
print(f.read())
