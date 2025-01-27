#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<time.h>

int* RandN(){
	static int randnorm[1000];
	for(int i = 0;i < 1000; i++)
	{
		randnorm[i] = rand();
	}
	return randnorm;
}
int* RandS(){
	srand(65);
	static int randseed[1000];
	for(int i = 0;i <1000; i++){
		randseed[i] = rand();
	}
	return randseed;
}
int* RandT(){
	srand(time(NULL));
	static int randtime[1000];
	for(int i = 0;i <1000; i++){
		randtime[i] = rand();
	}
	return randtime;
}
int main(){
	int *puntero1;
	int *puntero2;
	int *puntero3;
	puntero1 = RandN();
	puntero2 = RandS();
	puntero3 = RandT();

	std::ofstream RandDat("NumerosAleatorios1.dat");
	RandDat <<"n"<<"\t"<<"RandBase"<<"\t"<<"RandSeed"<<"\t"<<"RandTime"<<"\n";
	for(int j = 0; j <1000; j++){
		RandDat << j <<"\t"<< puntero1[j] <<"\t"<< puntero2[j] <<"\t"<< puntero3[j]<<"\n";
	}
	RandDat.close();
	std::ofstream Plot("Graficador1.gp");
	Plot << "set term png \n";
	Plot << "set xlabel 'n' \n";
	Plot << "set ylabel 'RandomN' \n";
	Plot << "set title 'Numeros RAND' \n";
	Plot << "set output 'GráficasRAND.png' \n";
	Plot << "plot 'NumerosAleatorios1.dat' u 1:2 w p pt 9 lc rgb 'blue' t 'randBase', 'NumerosAleatorios1.dat' u 1:3 w p pt 7 lc rgb 'red' t 'srand(65)', 'NumerosAleatorios1.dat' u 1:4 w p pt 13 lc rgb 'dark-violet' t 'srand(time(NULL))'";
	Plot.close();
	system("gnuplot Graficador1.gp");
return 0;
}
