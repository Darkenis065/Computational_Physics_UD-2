#include<iostream>
#include<cmath>
#include<string>
#include<fstream>
#include<eigen3/Eigen/Dense>

using Eigen::MatrixXd;
using Eigen::VectorXd;

class Polinomios{

	private:
	int n;
	public:
	VectorXd X;
	VectorXd Y;
	Polinomios(int size) : n(size), Y(VectorXd::Zero(n)), X(VectorXd::Zero(n)){
		for(int i = 0 ; i<=n ; i++ ){
			std::cout<<"Por favor introduzca el "<<i<<" valor de X"<<std::endl;
			std::cin>>X(i);
			std::cout<<"Por favor introduzca el valor de Y en: X["<<i<<"]"<<std::endl;
			std::cin>>Y(i);
		}
	}
	double Cardinales(int k,int m, double x){
		double product = 1;
		double aux = 0;
		for(int i = 0; i<m ; i++){
			if(k != i){
				aux = (x-X[i])/(X[k]-X[i]);
			}
			else{
				aux = 1;
			}
			product = product*aux;
		}
		return product;
	}
	double Interpolante(int k,int m, int j, double x){
		double sum = 0;
		double aux1 = 0;
		for(int k = 0; k<m ; k++){
			aux1 = Y[j]*Cardinales(k,m,x);
			sum = sum + aux1;
		}
		return sum;
	}
};
class Impresion{
	private:

	public:

ear

};


class Graficas{
	private:
	
	public:
		

};

int main(){
int size;

}
