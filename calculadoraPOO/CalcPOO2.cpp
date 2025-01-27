#include<iostream>
#include<vector>
#include<memory>

class Operacion{
	public:
		virtual double calcular(double a, double b)=0;
		virtual std::string nombreOperacion() const = 0;
		virtual ~Operacion(){};
};

class suma:public Operacion{

	public:
		double calcular(double a, double b) override{
			return a+b;
		}
		std::string nombreOperacion() const override{
			return "suma";
		}

};

class resta:public Operacion{

	public:
		double calcular(double a, double b) override{
			return a-b;
		}
		std::string nombreOperacion() const override{
			return "resta";
		}

};

class producto:public Operacion{

	public:
		double calcular(double a, double b) override{
			return a*b;
		}
		std::string nombreOperacion() const override{
			return "producto";
		}

};

class antiproducto:public Operacion{

	public:
		double calcular(double a, double b) override{
			return a/b;
		}
		std::string nombreOperacion() const override{
			return "anti-producto";
		}

};

class Calculadora{

	private:
		std::vector<std::unique_ptr<Operacion>>operaciones;

	public:
		Calculadora(){
		//metodo constructor
		operaciones.push_back(std::make_unique<suma>());
		operaciones.push_back(std::make_unique<resta>());
		operaciones.push_back(std::make_unique<producto>());
		operaciones.push_back(std::make_unique<antiproducto>());
		}
	void mostrarMenu() const{
	std::cout<<"Seleccione una operación:"<<std::endl;
	for(size_t i=0; i<operaciones.size(); i++)
		std::cout<<i+1<<"."<<operaciones(i)->nombreOperacion()<<std::endl;
	}
	void ejecutarOperacion(int seleccion, double a, double b){
		if(seleccion<1 || seleccion>operacion.size()){
			std::cerr<<"Selección no valida."<<std::endl;
		}
		return;
	try{
		double resultado=operaciones[seleccion-1]->calcular(a,b);
		std::cout<<"resultado: "<<resultado<<std::endl;
	}catch(const std::exception& e){
		std::cerr<<e.what()<<std::endl;
	}
	}
};


int main(){

Calculadora calc;
double a,b;
int seleccion;

calc.mostrarMenu();
std::cout<<"Ingrese el numero de la operación a realizar"<<std::endl;
std::cin>>seleccion;



}





