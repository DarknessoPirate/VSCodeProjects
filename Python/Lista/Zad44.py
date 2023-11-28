def fillMatrix(n):
    matrix2d = []
    for i in range(n):
        matrix1d = []
        for j in range(n+1):
            if(j == n):
                matrix1d.append(int(input(f"Podaj wyraz wolny [{i+1}] : ")))
            else:
                matrix1d.append(int(input(f"Podaj element [{i}][{j}]: ")))

        matrix2d.append(matrix1d)
    return matrix2d

def printMatrix(matrix,n):
    for i in range(n):
        print(matrix[i],end ='\n')

def gaussElimination(matrix,n):
    for i in range(n):
        if matrix[i][i] == 0:
            print("Incorrect matrix (Division by zero)")
            return
        for j in range(i+1,n):
            ratio = matrix[j][i]/matrix[i][i]
            
            for k in range(n):
                matrix[j][k] = matrix[j][k] - ratio*matrix[i][k]

    return matrix

def solveUpperMattrix(matrix,n):
    solutions = [None for _ in range(n)]
    solutions[n-1] = matrix[n-1][n]/matrix[n-1][n-1]
    for i in range(n-2,-1,-1):
        solutions[i] = matrix[i][n]

        for j in range(i+1,n):
            solutions[i] -= matrix[i][j] * solutions[j]

        solutions[i] = solutions[i]/matrix[i][i]
    return solutions

#m = fillMatrix(3)
#g = gaussElimination(m,3)
#printMatrix(g,3)
r = [[1,1,1,9],[2,-3,4,13],[3,4,5,40]]
print("Przed eliminacja: ")
printMatrix(r,3)
r = gaussElimination(r,3)
print("Po eliminacji: ")
printMatrix(r,3)
solutions = solveUpperMattrix(r,3)
j = 1
for i in solutions:
    print(f"x{j} = {i}")
    j +=1
            