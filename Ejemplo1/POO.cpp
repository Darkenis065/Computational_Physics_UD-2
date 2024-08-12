#include<iostream>
#include<string>

class Animal{
	public:
	//aqui van los metodos
	void hacersonido() const{
		std::cout<<nombre<<" hace "<<sonido<<std::endl;
		
	 }
	//Este es el metodo constructor
	Animal(std::string nombre, std::string sonido):nombre(nombre), sonido(sonido){}
	std::string nombre;
	protected:
	//aqui van los atributos
	std::string sonido;
};
class Perro: public Animal{
	public:
		Perro(std::string nombre):Animal(nombre,"Waos"){}
};

class Gato: public Animal{
	public:
	Gato(std::string nombre):Animal(nombre,"Nya"){}

};


int main(){
	Animal Leon("Alex","Grrr");
	Animal perro("Ignacio","Waos");
	Leon.hacersonido();
	perro.hacersonido();
	
	Perro Miperro("Aquiles");
	Gato Migato("Maxwell");
	Miperro.hacersonido();
	Migato.hacersonido();
//accediend a atriutos

	std::cout<<"Mi perro se llama "<<perro.nombre<<std::endl;
	return 0;
}
