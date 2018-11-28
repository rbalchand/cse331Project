from sys import argv
import os

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

	if os.path.isfile(route):
		with open(route,"rb") as f:
				byte = f.read(10)
				while byte:
					byte = f.read(10)
					print(byte)
	elif os.path.isdir(route):
		listOfFile = getListOfFiles(route)
		for elem in listOfFile:
			with open(elem,"rb") as f:
				byte = f.read(1)
				while byte:
					byte = f.read(1)
					print(byte)


if __name__ == '__main__':
    main()
