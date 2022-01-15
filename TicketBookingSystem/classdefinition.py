file1 = open('Myfile.txt', 'r')
count = 0
 
while True:
    count += 1
 
    # Get next line from file
    line = file1.readline()
 
    # if line is empty
    # end of file is reached
    if not line:
        break
    line = line.strip()
    if(len(line) > 15):
        line = line[len(line)-11 :len(line)-2]
        print(line)
        num = line[:len(line)-1]
    # print(num)
    # if(num == "checkBox"):
    #     print(num)
file1.close()