#include<iostream>
#include<vector>
#include<memory>

//Clase abstracta:::::

class Operacion{
    public:
        virtual double calcular(double a, double b)=0;
        virtual std::string nombreOperacion() const = 0;
        virtual ~Operacion(){};
};

/*Crear nuevas clases que sean derivadas (Herencia) de la clase operaciòn
y permitan eleaborar las diferentes operaciones de la calculadora*/

//--- Suma
class Suma:public Operacion{
    public:
        double calcular(double a, double b) override{
            return a+b;
        } 
        std::string nombreOperacion() const override{
            return "Suma";
        }
};

//--- Resta
class Resta:public Operacion{
    public:
        double calcular(double a, double b) override{
            return a-b;
        } 
        std::string nombreOperacion() const override{
            return "Resta";
        }
};

//Producto
class Producto:public Operacion{
    public:
        double calcular(double a, double b) override{
            return a*b;
        } 
        std::string nombreOperacion() const override{
            return "Producto";
        }
};

//Divisiòn
class Division:public Operacion{
    public:
        double calcular(double a, double b) override{
            return a/b;
        } 
        std::string nombreOperacion() const override{
            return "Divisiòn";
        }
};

/* Una clase que gestione las operaciones disponibles*/

class Calculadora{
    private:
        std::vector<std::unique_ptr<Operacion>>operaciones;
    public:
        //Metodo constructor mas detallado
        Calculadora(){
            operaciones.push_back(std::make_unique<Suma>());
            operaciones.push_back(std::make_unique<Resta>());
            operaciones.push_back(std::make_unique<Producto>());
            operaciones.push_back(std::make_unique<Division>());       
        }
    void mostrarMenu() const{
        std::cout<<"Selecciones una operaciòn:"<<std::endl;
        for(size_t i=0;i<operaciones.size();i++){
            std::cout<<i+1<<"."<<operaciones[i]->nombreOperacion()<<std::endl;
        }
    }
    void ejecutarOperacion(int seleccion, double a, double b){
        if(seleccion<1 ||seleccion>operaciones.size()){
            std::cerr<<"Selecciòn no valida."<<std::endl;
            return;
        }
        try {
        double resultado=operaciones[seleccion-1]->calcular(a,b);
        std::cout<<"Resultado: "<<resultado<<std::endl;
        } catch(const std::exception& e){
        std::cerr<<e.what()<<std::endl;
        }
    }
};

//Interacciòn con el usuario.

int main(){

    Calculadora calc;

    double a,b;
    int seleccion;

    while(true){
    calc.mostrarMenu();    
    std::cout<<"Ingrese el nùmero de la operaciòn a realizar o 0 para salir"<<std::endl;
    std::cin>>seleccion; 
    
    if(seleccion==0){
        break;
    }

    std::cout<<"Ingrese dos nùmeros"<<std::endl;
    std::cin>> a >> b;

    calc.ejecutarOperacion(seleccion,a,b);
    }

    std::cout<<"Gracias por usar mi calculadora =)."<<std::endl;
    return 0;
}