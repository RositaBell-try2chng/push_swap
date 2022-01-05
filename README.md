# push_swap
school 42 21. push_swap
На вход программе подается стек из целых чисел. Если подано не целое число или оно больше инта, программа выдает ошибку.
у нас есть 2 стека. а - то что подано на вход в программу. б - пустой стек.
программа может использовать следующие команды:
sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there
is only one or no elements).
sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there
is only one or no elements).
ss : sa and sb at the same time.
pa : push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.
pb : push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.
ra : rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.
rb : rotate b - shift up all elements of stack b by 1. The first element becomes
the last one.
rr : ra and rb at the same time.
rra : reverse rotate a - shift down all elements of stack a by 1. The last element
becomes the first one.
rrb : reverse rotate b - shift down all elements of stack b by 1. The last element
becomes the first one.
rrr : rra and rrb at the same time.

программа сортирует стек а с помощью указанных команд. выдает на стандартный аутпут все выполненные команды через '\n'.
5 элементов сортируются не более чем за 12 команд.
100 элементов сортируются не более чем за 700 команд.
500 элементов сортируются не более чем за 6500 команд.
