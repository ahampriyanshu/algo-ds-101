numbersArray = []
numbersSet = set()
numbersList = []
continueEntering = True
while continueEntering == True:
    print('Input a number from your dataset:')
    number = input()
    if number.isdigit():
        pass
    else:
        print('Error! You did not enter a number. Try again! What is your number?:')
        number = input()
    number = int(number)
    numbersArray.append(number)
    numbersSet.add(number)
    print('Do you have another number to enter - Y/N:')
    moreNumbers = input()
    if moreNumbers.lower() == 'y':
        pass
    elif moreNumbers.lower() == 'n':
        continueEntering = False
    elif (moreNumbers.lower() != 'n') or (moreNumbers.lower() != 'y'):
        print('Error! You did not enter "Y" or "N"!')
        print('Do you have another number to enter - Y/N:')
        moreNumbers = input()
numbersArray = sorted(numbersArray)
#print(numbersArray)
#print(numbersSet)
for i in numbersSet:
    numbersList.append([])
#print(numbersList)
if len(numbersList)>0:
    #append first number in array to list
    numbersList[0].append(numbersArray[0])
    index = 0
    for i in range(1,len(numbersArray)):    
        testNumber = numbersArray[i]
        compareNumber = numbersArray[i-1]
        if testNumber == compareNumber:
            numbersList[index].append(testNumber)
        else:
            index += 1
            numbersList[index].append(testNumber)        
    #print(numbersList)
else:
    print("Error! No numbers in dataset")
counts = []
for i in numbersList:
    count = len(i)
    counts.append(count)
#print(counts)
maxCounts = max(counts)
resultList = []
for i in range(len(counts)):
    if counts[i] == maxCounts:
        resultRow = numbersList[i]
        result = resultRow[0]
        resultList.append(result)        
print("These are your mode(s):")
print(resultList)
    
        
    