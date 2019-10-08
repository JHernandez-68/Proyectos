#include <iostream>
#include <locale.h>
#include <string.h>
#include <windows.h>
using namespace std;
int ganancias=0, IVAt;
//Creacion del objeto producto (prdeterminado de 4 para la tienda)
struct tienda{
	
	string nombre;
	int tipo, cantidad , cantidad_minima , precio_base, ID, ventas;
}producto[4];

//Función para visualizar la información de los productos
void visualizar(){
	int op1, op2;
	cout<<"------------------------------------------------------------------------------------------\n ";	
	cout<<"Usted ha escogido la opción de visualizar la información de los productos\n";
	cout<<"------------------------------------------------------------------------------------------\n ";	
	cout<<"Digite (1) para ver la información de un producto en específico\n";
	cout<<"------------------------------------------------------------------------------------------\n ";	
	cout<<"Digite (2) para ver la información de todos los productos\n";
	cout<<"------------------------------------------------------------------------------------------\n ";
		cin>>op1;
	if(op1==1){
			cout<<"¿De qué producto desea ver la información?\n";
				cin>>op2;
					
			for(int i=0 ; i<4; i++){
						if(i==op2-1){
								cout<<"Nombre del producto: "<<producto[op2-1].nombre<<endl;
								cout<<"ID del producto: "<<producto[i].ID<<endl;
								cout<<"Tipo del producto: "<<producto[op2-1].tipo<<endl;
								cout<<"Cantidad del producto: "<<producto[op2-1].cantidad<<endl;
								cout<<"Cantidad mínima del producto: "<<producto[op2-1].cantidad_minima<<endl;
								cout<<"Precio base del producto: "<<producto[op2-1].precio_base<<endl;
						}
				}
					
	}
	if(op1==2){
		int cont=1;
		for(int i=0; i<4 ; i++){
			cout<<"----------------------------------------------------\n";
			cout<<"\t PRODUCTO #  "<<cont<<endl;
			cout<<"Nombre del producto: "<<producto[i].nombre<<endl;
			cout<<"ID del producto: "<<producto[i].ID<<endl;
			cout<<"Tipo del producto: "<<producto[i].tipo<<endl;
			cout<<"Cantidad del producto: "<<producto[i].cantidad<<endl;
			cout<<"Cantidad mínima del producto: "<<producto[i].cantidad_minima<<endl;
			cout<<"Precio base del producto: "<<producto[i].precio_base<<endl;
			cout<<"----------------------------------------------------\n";
			cont++;
		}	
	}
}
//Funcion para calcular el iva
/*NOTA: Para el tipo de producto se maneja que:
	Tipo 1=Drogueria 12%
	Tipo 2=Papelería 16%
	Tipo 3= Supermercado 4%
*/
void IVA(int x, int y){
		if(x==1){
			IVAt = (12 * y) / 100;
		}
		if(x==2){
			IVAt = (16 * y) / 100;
		}
		if(x==3){
			IVAt = (4 * y) / 100;
		}
}
//Función para venta de un producto
void vender(){
	int op3, unidades, dinero, cambio;
	cout<<"Usted ha escogido la opción de vender un producto\n";
	cout<<"¿Qué producto desea vender?"<<endl;
		cin>>op3;
	cout<<"Cuantas unidades desea vender?"<<endl;
		cin>>unidades;
		
	//Se calcula la nueva cantidad del producto en inventario
	producto[op3-1].cantidad = producto[op3-1].cantidad - unidades;
	
	//Se calcula el valor total de la venta
	producto[op3-1].precio_base = producto[op3-1].precio_base * unidades;
	
	//Se entra a la funcion de IVA
	IVA(producto[op3-1].tipo, producto[op3-1].precio_base);
	
	//Se muestra el costo total en pantalla
	cout<<"El costo es de "<<producto[op3-1].precio_base + IVAt<<endl;
	cout<<"¿Con cuanto pagó el cliente? "<<endl;
		cin>>dinero;
		
	//Se calcula el cambio del cliente
	cambio = dinero - producto[op3-1].precio_base;
	cout<<"------------------------------------------------------------------------------------------\n ";
	cout<<"El cambio es de "<<cambio<<endl;
	cout<<"------------------------------------------------------------------------------------------\n ";
	cout<<"Nueva cantidad del producto # "<<op3<<" es "<<producto[op3-1].cantidad<<endl;
	cout<<"------------------------------------------------------------------------------------------\n ";	
	//Se calcula las ganancias que va ganando la tienda.
		ganancias = ganancias + (producto[op3-1].precio_base + IVAt) ;
		
	//Se agrega la cantidad de ventas que ha tenido el producto
	producto[op3-1].ventas=producto[op3-1].ventas + unidades;
}


//Función para abastecer la tienda con un producto
//La cantidad máxima que se puede tener de un producto es de 50.
void abastecer(){
	int op4; 
	cout<<"Usted ha escogido la opción de abastecer la tienda con un producto\n";
	cout<<"¿Qué producto desea abastecer? \n";
		cin>>op4;
		producto[op4-1].cantidad=50;
	cout<<"------------------------------------------------------------------------------------------\n ";
	cout<<"El producto se ha abastecido con una totalidad de "<<producto[op4-1].cantidad<<endl;
	cout<<"------------------------------------------------------------------------------------------\n ";	
}

//Función para cambiar un producto
void cambiar(){
	int op5, op6 , cambioP, cambio2;
	cout<<"Usted ha escogido la opción de cambiar un producto\n";
	cout<<"Digite (1) para cambiar solo un atributo del producto\n";
	cout<<"Digite (2) para cambiar todos los atributos de un produto\n";
		cin>>op5;
	if(op5==1){
		cout<<"Digite la ID del producto que desea cambiar?";
			cin>>cambioP;
				for(int i=0 ; i<4 ; i++){
					if(cambioP==producto[i].ID){
							cout<<"(1) para cambiar el nombre\n";
							cout<<"(2) para cambiar la ID\n";
							cout<<"(3) para cambiar el precio base\n";
							cout<<"(4) para cambiar el tipo\n";
							cout<<"(5) para cambiar la cantidad mínima\n";
								cin>>op6;
									switch(op6){
										case 1:
											cout<<"Digite el nuevo nombre\n";
												cin>>producto[i].nombre;
											break;
										case 2:
											cout<<"Digite la nueva ID\n";
												cin>>producto[i].ID;
											break;
										case 3:
											cout<<"Digite el nuevo precio base\n";
												cin>>producto[i].precio_base;
											break;
										case 4:
											cout<<"Digite el nuevo tipo\n";
											cout<<"Recuerde que los tipos son: \n";
											cout<<"(1) Drogueria\n";
											cout<<"(2) Papelería\n";
											cout<<"(3) Supermercado\n";
												cin>>producto[i].tipo;
											break;
										case 5:
											cout<<"Digite la nueva cantidad mínima\n";
												cin>>producto[i].cantidad_minima;
											break;
									}
					}
				}
	}
	if(op5==2){
		cout<<"Digite la ID del producto del cual desea cambiar todos sus atributos\n";
			cin>>cambioP;
				for( int i=0 ; i<4 ; i++){
					if(cambioP==producto[i].ID){
						cout<<"------------------------------------------------------------------------------------------\n ";
					
						cout<<"Digite el nuevo nombre\n";
							cin>>producto[i].nombre;
					
						cout<<"------------------------------------------------------------------------------------------\n ";					
						
						cout<<"Digite la nueva ID\n";
							cin>>producto[i].ID;
						
						cout<<"------------------------------------------------------------------------------------------\n ";	
						
						cout<<"Digite el nuevo precio base\n";
							cin>>producto[i].precio_base;
						
						cout<<"------------------------------------------------------------------------------------------\n ";	
					
						cout<<"Digite el nuevo tipo\n";
						cout<<"Recuerde que los tipos son: \n";
						cout<<"(1) Drogueria\n";
						cout<<"(2) Papelería\n";
						cout<<"(3) Supermercado\n";
							cin>>producto[i].tipo;
							
						cout<<"------------------------------------------------------------------------------------------\n ";	
					
						cout<<"Digite la nueva cantidad mínima\n";
							cin>>producto[i].cantidad_minima;
						cout<<"------------------------------------------------------------------------------------------\n ";
					}
				}
	}
}

//Función para calcular las estadisticas de ventas de la tienda
void calcular(){
	int opf, mvendido=0, cantidad, menor;
	string nombre;
	cout<<"------------------------------------------------------------------------------------------\n ";
	cout<<"Usted ha escogido la opción de calcular las estadisticas de ventas\n";
	cout<<"------------------------------------------------------------------------------------------\n ";
	cout<<"Digite (1) para ver el producto más vendido\n";
	cout<<"------------------------------------------------------------------------------------------\n ";
	cout<<"Digite (2) para ver el producto menos vendido\n";
	cout<<"------------------------------------------------------------------------------------------\n ";
	cout<<"Digite (3) para ver la cantidad de dinero obtenido por ventas\n";
	cout<<"------------------------------------------------------------------------------------------\n ";
	cout<<"Digite (4) para ver la cantidad de dinero promedio obtenido por unidad de producto vendida.\n";
	cout<<"------------------------------------------------------------------------------------------\n ";
		cin>>opf;
							system("cls");
				switch(opf){
							case 1:
								for(int i=0 ; i<4 ; i++){
									
									if(producto[i].ventas > mvendido){
										mvendido=producto[i].ventas;
										nombre=producto[i].nombre;
									}
								}
								if(mvendido>0){
									cout<<"--------------------------------------------------------------------------\n ";
									cout<<"El producto más vendido es"<<nombre<<"con una cantidad de : "<<mvendido;
									cout<<"--------------------------------------------------------------------------\n ";
								}
								if(mvendido==0){
									cout<<"--------------------------------------------------------------------------\n ";
									cout<<"No se ha vendido ningun producto\n";
									cout<<"--------------------------------------------------------------------------\n ";
								}
								break;
							case 2:
								for(int i=0 ; i<4 ; i++){	
									if(producto[i].ventas < menor){
										menor=producto[i].ventas;
										nombre=producto[i].nombre;
									}
								}
								if(menor >= 0 ){
									cout<<"--------------------------------------------------------------------------\n ";
									cout<<"El producto menos vendido es" <<nombre<< " con una cantidad de "<<menor;
									cout<<"--------------------------------------------------------------------------\n ";
								}

								break;
							case 3:
								cout<<"--------------------------------------------------------------------------\n ";
								cout<<"Cantidad de dinero obtenido por ventas "<<ganancias;
								cout<<"--------------------------------------------------------------------------\n ";
								break;
							case 4:
								cantidad = producto[0].ventas + producto[1].ventas + producto[2].ventas + producto[3].ventas;
								ganancias= ganancias/cantidad;
								cout<<"--------------------------------------------------------------------------\n ";
								cout<<"Cantidad de dinero promedio obtenido por unidad de producto vendida"<<ganancias;
								cout<<"--------------------------------------------------------------------------\n ";
								break;
							default:
						cout<<"Opción erronea"; 
						system("pause");
						system("cls");
						calcular();
	}
	
}

int main(){
	setlocale(LC_ALL, "SPANISH");
	int op;
	/*NOTA: Para el tipo de producto se maneja que:
	Tipo 1=Drogueria
	Tipo 2=Papelería
	Tipo 3= Supermercado*/
	//DECLARACIÓN DE LOS PRODUCTOS
	//PRODUCTO 1
	producto[0].nombre="Producto 1 xd";
	producto[0].ID=1;
	producto[0].tipo=1;
	producto[0].cantidad=30;
	producto[0].cantidad_minima=10;
	producto[0].precio_base=2000;
	producto[0].ventas=0;
	//PRODUCTO 2
	producto[1].nombre="Producto 2 xd";
	producto[1].ID=2;
	producto[1].tipo=2;
	producto[1].cantidad=25;
	producto[1].cantidad_minima=10;
	producto[1].precio_base=2000;
	producto[1].ventas=0;
	//PRODUCTO 3
	producto[2].nombre="Producto 3 xd";
	producto[2].ID=3;
	producto[2].tipo=3;
	producto[2].cantidad=24;
	producto[2].cantidad_minima=10;
	producto[2].precio_base=2000;
	producto[2].ventas=0;
	//PRODUCTO 4
	producto[3].nombre="Producto 4 xd";
	producto[3].ID=4;
	producto[3].tipo=1;
	producto[3].cantidad=40;
	producto[3].cantidad_minima=15;
	producto[3].precio_base=2000;
	producto[3].ventas=0;
	bool menu=true;
	int f;
	do{
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	cout<<"-----------------------------------------------------------\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	cout<<"\tNOMBRE DE LA TIENDA\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	cout<<"-----------------------------------------------------------\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	cout<<"Digite la opción que desea realizar\n";
	cout<<"(1) Visualizar la información de los productos\n";
	cout<<"(2) Vender un producto\n";
	cout<<"(3) Abastecer la tienda con un producto\n";
	cout<<"(4) Cambiar un producto\n";
	cout<<"(5) Calcular estadisticas de ventas\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	cout<<"-----------------------------------------------------------\n";
		cin>>op;
			switch(op){
				case 1:
					system("cls");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
						visualizar();
					break;
				case 2:
					system("cls");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
						vender();
					break;
				case 3:
					system("cls");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
						abastecer();
					break;
				case 4:
					system("cls");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
						cambiar();
					break;
				case 5:
					system("cls");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
						calcular();
					break;
					
				default:
					system("cls");
					cout<<"Opción erronea\n";
			}
	cout<<"-----------------------------------------------------------\n";
	cout<<"Presione '1' si desea volver al menu principal\n";
	cout<<"Si desea salir del programa presione cualquier otra letra \n";
	cin>>f;
	if(f!=1){
		menu=false;
	}
	}while(menu);
	cout<<"-----------------------------------------------------------\n";
	return 0;
}
