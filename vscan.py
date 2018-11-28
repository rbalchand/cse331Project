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

	if route == "antivirus-update":
		url = "https://raw.githubusercontent.com/ganixil/virus_database/master/virus_base.txt"
		with urllib.request.urlopen(url) as response, open("virus_base", 'wb') as out_file:
			data = response.read()
			out_file.write(data)
	else:
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
			infected = False
			with open(route,"rb") as f:
				for v in virus:
					byte = f.read(len(v))
					for i in range(1,size+1):
						if byte == v:
							os.rename(route,route+".infected")
							os.chmod(route+".infected",0o000)
							infected = True
							print("found virus",v,"at file",route)
						if infected:
							break
						f.seek(i)
						byte = f.read(len(v))
					if infected:
						break


		elif os.path.isdir(route):
			listOfFile = getListOfFiles(route)
			for elem in listOfFile:
				infected = False
				size = os.path.getsize(elem)
				with open(elem,"rb") as f:
					for v in virus:
						byte = f.read(len(v))
						for i in range(1,size+1):
							if byte == v:
								os.rename(elem,elem+".infected")
								os.chmod(elem+".infected",0o000)
								infected = True
								print("found virus",v,"at file",elem)
							if infected:
								break
							f.seek(i)
							byte = f.read(len(v))
						if infected:
							break

		else:
			print("Directory Invalid")

if __name__ == '__main__':
    main()
