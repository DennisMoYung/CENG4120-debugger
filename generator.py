import numpy as np

##update the flag if you want
displayOnTerminal = False
writeOnFile = True

##range of the expected size (since it will removes the duplicate row, please set a little bit bigger if you need)
## since the online tools only can display 24 upper letter, so maximum of m (width) is 24 
width = np.random.randint(1, 24)
height = np.random.randint(1, 2000)

arr = np.random.randint(3, size=(height, width))

new = [tuple(row) for row in arr]
res = np.unique(new,axis=0)

width = res.shape[1]
height = res.shape[0]

result = str(width) + "\n" + str(height) + "\n"


if displayOnTerminal :
  print(width)
  print(height)

for y in range(0, height):
  for x in range(0, width):

    result += str(res[y,x])

    if displayOnTerminal :
      print(res[y,x], end='')
    
  result += "\n"
  if displayOnTerminal :
    print()

if writeOnFile:
  f = open("demofile3.txt", "w")
  f.write(result)
  f.close()