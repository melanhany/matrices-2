Во входном файле "input.txt" дано две матрицы A и B размерности N*N. Найти матрицу С и записать в файл "result.txt".

Если (AE(B) == True) тогда С = op1(B) + 2A иначе С = -3B * op2(A), где

op1(X) - все простые числа в матрице возводит в квадрат (умнажает на само число)

op2(X) - находит и меняет местами строки минимальным и максимальным числом в матрице (если их несколько, выбирается с наименьшими индексами).

AЕ(X) x[i][j]: x[i][j] > 0 && x[i][j] делится на 4.

X - матрица размера N*N.




Использовать динамические массивы.

op1, op2, AE и операции над матрицами(сложение, умножение на число, умножение на матрицу) оформить в виде функций. 

