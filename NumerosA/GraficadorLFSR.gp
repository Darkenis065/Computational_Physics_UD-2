set term png 
set xlabel 'n' 
set ylabel 'RandomN' 
set title 'Numeros LFSR'  
set output 'GráficasLFSR.png' 
plot 'lfsr_output.dat' u 1:2 w p pt 8 lc rgb 'blue' t 'LFSR'
