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

	virus = b'\x03\x00\x00\x80\x02\x00\x00\x00\x0f\x00\x00'


	if os.path.isfile(route):
		size = os.path.getsize(route)
		with open(route,"rb") as f:
				byte = f.read(len(virus))
				for i in range(1,size+1):
					if byte == virus:
						print("found")
					f.seek(i)
					byte = f.read(len(virus))


	elif os.path.isdir(route):
		listOfFile = getListOfFiles(route)
		for elem in listOfFile:
			size = os.path.getsize(elem)
			with open(elem,"rb") as f:
				byte = f.read(len(virus))
				for i in range(1,size+1):
					if byte == virus:
						print("found")
					f.seek(i)
					byte = f.read(len(virus))


if __name__ == '__main__':
    main()
