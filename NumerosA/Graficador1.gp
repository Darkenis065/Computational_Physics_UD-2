set term png 
set xlabel 'n' 
set ylabel 'RandomN' 
set title 'Numeros RAND' 
set output 'GráficasRAND.png' 
plot 'NumerosAleatorios1.dat' u 1:2 w p pt 9 lc rgb 'blue' t 'randBase', 'NumerosAleatorios1.dat' u 1:3 w p pt 7 lc rgb 'red' t 'srand(65)', 'NumerosAleatorios1.dat' u 1:4 w p pt 13 lc rgb 'dark-violet' t 'srand(time(NULL))'