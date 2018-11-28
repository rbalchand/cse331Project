from sys import argv
import os
import urllib.request
import array

def getListOfFiles(dirName):
    # create a list of file and sub directories 
    # names in the given directory 
    listOfFile = os.listdir(dirName)
    allFiles = list()
    # Iterate over all the entries
    for entry in listOfFile:
        # Create full path
        fullPath = os.path.join(dirName, entry)
        # If entry is a directory then get the list of files in this directory 
        if os.path.isdir(fullPath):
            allFiles = allFiles + getListOfFiles(fullPath)
        else:
            allFiles.append(fullPath)
                
    return allFiles 

def main():
	route = argv[1]

	temp = []
	with open("virus_base.txt","r") as f:
		line = f.readline().rstrip()
		while line:
			temp.append(line)
			line = f.readline().rstrip()
	virus = []	
	for v in temp:
		virus.append(bytes.fromhex(v))


	
	if os.path.isfile(route):
		size = os.path.getsize(route)
		with open(route,"rb") as f:
			for v in virus:
				byte = f.read(len(v))
				for i in range(1,size+1):
					if byte == v:
						print(route)
						print("found virus",v)
					f.seek(i)
					byte = f.read(len(v))


	elif os.path.isdir(route):
		listOfFile = getListOfFiles(route)
		for elem in listOfFile:
			size = os.path.getsize(elem)
			with open(elem,"rb") as f:
				for v in virus:
					byte = f.read(len(v))
					for i in range(1,size+1):
						if byte == v:
							print(elem)
							print("found virus",v)
						f.seek(i)
						byte = f.read(len(v))

	else:
		print("Directory Invalid")

if __name__ == '__main__':
    main()
