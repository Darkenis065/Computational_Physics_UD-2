#include<iostrean>
#include<vector>
#include<memory>

class Operacion{
	public:
		virtual double calcular(double a, double b)=0;
		virtual std::string nombreOperacion() const = 0;
		virtual =Operacion()();
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

class anti-producto:public Operacion{

	public:
		double calcular(double a, double b) override{
			return a/b;
		}
		std::string nombreOperacion() const override{
			return "anti-producto";
		}

};

class Calculadora{

	public:
		Calcuadora(){
		//metodo constructor
		}

};








