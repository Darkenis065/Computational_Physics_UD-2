#include<iostream>
#include<vector>
#include<memory>

//Clase abstracta:::::

class Operacion{
    public:
        virtual double calcular(double a, double b)=0;
	virtual double calcular1(double c)=0;
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

//--- Sin
class Sin:public Operacion{
    public:
        double calcular1(double c) override{
            return std::sin(c);
        } 
        std::string nombreOperacion() const override{
            return "Sen";
        }
};

//--- Cos
class Cos:public Operacion{
    public:
        double calcular1(double c) override{
            return std::cos(c);
        } 
        std::string nombreOperacion() const override{
            return "Cos";
        }
};

//--- Tan
class Tan:public Operacion{
    public:
        double calcular1(double c) override{
            return std::tan(c);
        } 
        std::string nombreOperacion() const override{
            return "Tan";
        }
};

//--- sqrt
class Sqrt:public Operacion{
    public:
        double calcular1(double c) override{
            return sqrt(c);
        } 
        std::string nombreOperacion() const override{
            return "Sqrt";
        }
};

//--- Square
class Square:public Operacion{
    public:
        double calcular1(double c) override{
            return c*c;
        } 
        std::string nombreOperacion() const override{
            return "Cuadrado";
        }
};

//--- ArcSin
class ArcSin:public Operacion{
    public:
        double calcular1(double c) override{
            return asin(c);
        } 
        std::string nombreOperacion() const override{
            return "ArcSen";
        }
};

//--- ArcCos
class ArcCos:public Operacion{
    public:
        double calcular1(double c) override{
            return acos(c);
        } 
        std::string nombreOperacion() const override{
            return "ArcCos";
        }
};

//--- ArcTan
class ArcTan:public Operacion{
    public:
        double calcular1(double c) override{
            return atan(c);
        } 
        std::string nombreOperacion() const override{
            return "ArcTan";
        }
};


//--- Exponent
class Exponent:public Operacion{
    public:
        double calcular(double a, double b) override{
            return pow(a,b);
        } 
        std::string nombreOperacion() const override{
            return "Suma";
        }
};


//--- Permutación
class Perm:public Operacion{
    public:
        double calcular(double a, double b) override{
            return (tgamma(a+1))/(tgamma(a-b+1));
        } 
        std::string nombreOperacion() const override{
            return "Permutación";
        }
};

//--- Combinación
class Comb:public Operacion{
    public:
        double calcular(double a, double b) override{
            return (tgamma(a+1))/(tgamma(a-b+1)*tgamma(b+1));
        } 
        std::string nombreOperacion() const override{
            return "Combinación";
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
        	operaciones.push_back(std::make_unique<Sin>());    
        	operaciones.push_back(std::make_unique<Cos>());    
		operaciones.push_back(std::make_unique<Tan>());    
		operaciones.push_back(std::make_unique<Sqrt>());    
        	operaciones.push_back(std::make_unique<Square>());    
           	operaciones.push_back(std::make_unique<ArcSin>());    
           	operaciones.push_back(std::make_unique<ArcCos>());    
           	operaciones.push_back(std::make_unique<ArcTan>());    
           	operaciones.push_back(std::make_unique<Exponent>());    
           	operaciones.push_back(std::make_unique<Perm>());    
           	operaciones.push_back(std::make_unique<Comb>());    
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
