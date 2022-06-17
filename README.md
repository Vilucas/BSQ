# BSQ

# BSQ is about finding the bigest square in a X by Y matrix with obstacles randomly placed into the matrix.

Created between 16 and 17 june 2022 on windows 10 using dynamic programming, we dismantle the problem into little subproblems by checking only the 3 squares around the curent square (square x-1, square y-1 and square y-1 and x-1), we then take the minimum of the 3 and add 1. 

We store the position of the largest square we found and then print the new map. The square is represented with 'x' characters.

# Download
``` git clone https://github.com/Vilucas/BSQ.git ```

# Build and create a map
``` make ; perl mapGenerator.pl 100 100 5 > map1 ``` this will build the project and create a 100x100 matrix with an obstacle density of 5 by row

# launch
```./BSQ map1 > result1 ; cat result1``` I redirect it into a file as printing on the terminal is very very slow

# This project has educative purposes in the scope of my work at European Leadership University
