set term png 
set xlabel 'Paso' 
set ylabel 'Producto medio' 
set title 'Metodo del producto medio' 
set output 'GráficasPMedio.png' 
plot 'NumerosAleatorios2.dat' u 1:4 w p pt 8 lc rgb 'blue' t 'PM' 