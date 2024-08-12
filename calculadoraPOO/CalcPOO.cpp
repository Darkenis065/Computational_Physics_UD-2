#include<iostream>
#include<string>

class operacion{
	public:
	
	operacion(float res, float num1, float num2):res(res),num1(num1),num1(num1){}
	void suma{
	std::cout<<"la suma es " <<num1 + num2<<std::endl;
	};
	protected:
	float res;
	float num1;
	float num2;
};
int main(){
	float a = 1;
	float b = 2;
	operacion resultado(a,b);
	resultado.suma();


return 0
}



