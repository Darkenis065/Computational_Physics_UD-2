set term png 
set xlabel 'Paso' 
set ylabel 'Numero CMP' 
set title 'Metodo congruencial multiplicativo'
set output 'GráficaCMP.png' 
plot 'RandomNCMP.dat' u 1:2 w p pt 4 lc rgb 'red' t 'CMP'