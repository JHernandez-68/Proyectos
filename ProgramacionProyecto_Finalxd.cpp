#include <iostream>
#include <stdio.h>
#include <dos.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include<stdlib.h>
#include<fstream>
#include  <string.h>
#include<locale>
using namespace std;
struct habitacion
{
	int numero, camas, aire, precio;
	string estado;
}ha[10];
void borrar()
{
    fstream stud;
    fstream temp;
    stud.open("hotel.txt",ios::in);
    temp.open("temp.txt",ios::out);
    char name [25];
    char age[25];
    char phone [25];
    char room[25];
    char cod[25];
    char day4[25];
    char a[25];
    cin.ignore();
    cout<<" \n\t Digite cualquier numero para borrar todo el registro: ";
    cout<<"NOTA: Cerrar el programa y abrir de nuevo"<<endl;
    cin.getline(a,25);
    while(!stud.eof())
    {
        stud.getline(name,25,'|');
        stud.getline(phone,25,'|');
        stud.getline(age,25,'|');
        stud.getline(room,25,'|');
        stud.getline(cod,25,'|');
        if(strcmp(phone,a)==0)
        {
            break;
        }
        else
        {
            temp<<name<<'|'<<phone<<'|'<<age<<'|'<<room<<'|'<<cod<<'|'<<day4<<'\n';
        }
    }
    temp.close();
    stud.close();
    stud.open("hotel.txt",ios::out);
    temp.open("temp.txt",ios::in);
    while(!temp.eof())
    {
        stud.getline(name,25,'|');
        stud.getline(phone,25,'|');
        stud.getline(age,25,'|');
        stud.getline(room,25,'|');
        stud.getline(cod,25,'|');
        stud.getline(day4,25);
        stud<<name<<'|'<<phone<<'|'<<age<<'|'<<room<<'|'<<cod<<'|'<<day4<<'\n';
        
    }
    temp.close();
    stud.close();
    remove("temp.txt");
    cout<<"\n Datos cargados exitosamente !!! \n";
	}
void actualizar()
{
    fstream stud;
    fstream temp;

    stud.open("hotel.txt",ios::in);
    temp.open("temp.txt",ios::out);
    char name [25];
    char age[25];
    char phone [25];
    char a[25];
    cin.ignore();
    cout<<" \n\t Escribe el codigo para actualizar los datos del usuario : ";
    cin.getline(a,25);
    while(!stud.eof())
    {
        stud.getline(name,25,'|');
        stud.getline(phone,25,'|');
        stud.getline(age,25);
        if(strcmp(phone,a)==0)
        {   
		    cout<<"\n Inserta los nuevos datos del usuario  \n ";
            cout<<" \n Nombre y apellido : ";
            cin.getline(name,25);
            cout<<" \n Codigo : ";
            cin.getline(phone,25);
            cout<<" \n Edad : ";
            cin.getline(age,25);
            temp<< name<<'|'<<phone<<'|'<<age<<'\n';
        }
        else
        {
            temp<< name<<'|'<<phone<<'|'<<age<<'\n';
        }
    }
    temp.close();
    stud.close();

    stud.open("hotel.txt",ios::out);
    temp.open("temp.txt",ios::in);
    while(!temp.eof())
    {
        temp.getline(name,25,'|');
        temp.getline(phone,25,'|');
        temp.getline(age,25);
        stud<< name<<'|'<<phone<<'|'<<age<<'\n';
    }
    temp.close();
    stud.close();
    remove("temp.txt");
    cout<<"\n Datos cargados exitosamente !!! \n";
}
void mostrar()
{
    char name [25];
    char age[25];
    char phone [25];
    char room[25];
    char cod[25];
    char day4[25];
    fstream stud;
    stud.open("hotel.txt",ios::in);
    cout<< " \n\t Nombre y apellido  Cod \t Edad \t Habitacion \t Telefono \t dias "<<endl;
    while(!stud.eof())
    {
        stud.getline(name,25,'|');
        stud.getline(phone,25,'|');
        stud.getline(age,25,'|');
        stud.getline(room,25,'|');
        stud.getline(cod,25,'|');
        stud.getline(day4,25);
        cout<<"\n \t "<<name<<"\t"<<phone<<"\t"<<age<<"\t"<<room<<"\t"<<cod<<"\t"<<day4<<endl;
    }
}
void  check_in()
{
    char name [25];
    char age[25];
    char phone [25];
    char room[25];
    char cod[25];
    char day[25];
    char day2[25];
    char day4[25];
    char mon[25];
    char mon2[25];
    char estado[25];
    int day3;
    int lol;
    fstream stud;
    stud.open("hotel.txt", ios::app);
    cin.ignore();
	cout<<"\n Inserte el numero de la habitacion";
    cin.getline(room, 25);
    int prueba=atoi(room);
    cout<<" \n Inserte el  nombre  y el apellido del cliente : ";
    cin.getline(name,25);
    cout<<" \n Inserte el codigo del cliente : ";
    cin.getline(phone,25);
    cout<<" \n Inserte la edad del cliente : ";
    cin.getline(age,25);
    cout<<"\n Inserte el numero del cliente: ";
    cin.getline(cod,25);
    cout<<"\n Digite el numero de dias que el usuario va a estar"<<endl;
    cin.getline(day4,25);
    int dia4=atoi(day4);
    for(int i=0; i<10;i++)
    {
    	if(ha[i].numero==prueba)
    	{
    		lol=ha[i].precio*dia4;
    		i=11;
		}
	}
	int cambio, cuantia, sum=0;
    stud<< name<<'|'<<phone<<'|'<<age<<'|'<<room<<'|'<<cod<<'|'<<day4<<'\n';
    cout<<"\n el costo es de: "<<lol<<endl;
    cout<<"Digite la cuantia con la que el usuario pago"<<endl;
    cin>>cuantia;
    cambio=cuantia-lol;
    sum=sum+lol;
    cout<<"-------------------------------------------"<<endl;
    cout<<"Su cambio es de"<<cambio<<endl;
    cout<<"-------------------------------------------"<<endl;
    cout<<"Las ganancias por el dia de hoy son"<<sum<<endl;
    cout<< "Datos cargados exitosamente !"<<endl;
    stud.close();
} 

int main()
{
//DATOS DE LAS HABITACIONES
//HABITACION 1
ha[0].aire=1;
ha[0].camas=1;
ha[0].numero=1;
ha[0].precio=11000;
ha[0].estado="D";
//HABITACION 2
ha[1].aire=1;
ha[1].camas=2;
ha[1].numero=2;
ha[1].precio=21000;
ha[1].estado="D";
//HABITACION 3
ha[2].aire=1;
ha[2].camas=3;
ha[2].numero=3;
ha[2].precio=73000;
ha[2].estado="D";
//HABITACION 4
ha[3].aire=1;
ha[3].camas=4;
ha[3].numero=4;
ha[3].precio=80000;
ha[3].estado="D";
//HABITACION 5
ha[4].aire=1;
ha[4].camas=5;
ha[4].numero=5;
ha[4].precio=65000;
ha[4].estado="D";
//HABITACION 6
ha[5].aire=2;
ha[5].camas=1;
ha[5].numero=6;
ha[5].precio=70000;
ha[7].estado="D";
//HABITACION 7
ha[6].aire=2;
ha[6].camas=2;
ha[6].numero=7;
ha[6].precio=45000;
ha[6].estado="D";
//HABITACION 8
ha[7].aire=2;
ha[7].camas=3;
ha[7].numero=8;
ha[7].precio=30000;
ha[7].estado="D";
//HABITACION 9
ha[8].aire=2;
ha[8].camas=4;
ha[8].numero=9;
ha[8].precio=20000;
ha[8].estado="D";
//HABITACION 10
ha[9].aire=2;
ha[9].camas=5;
ha[9].numero=10;
ha[9].precio=15000;
ha[9].estado="D";
setlocale(LC_ALL, "spanish");
	time_t t,i;
	char *p;
	i = time (&t);
	p = ctime (&i); 
    bool flag=true;
    while (flag)
    {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	cout<<"\t\t*******************************************************"<<endl;
	cout<<"\t\t*             H O T E L C A S C A D A                 *"<<endl;
	cout<<"\t\t*******************************************************"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	cout<<"\t\t*******************************************************"<<endl;
	cout<<"\t\t*Digite (1) para realizar un CHECK IN                 *"<<endl;
	cout<<"\t\t*******************************************************"<<endl;
	cout<<"\t\t*Digite (2) para realizar un CHECK OUT                *"<<endl;
	cout<<"\t\t*******************************************************"<<endl;
	cout<<"\t\t*Digite (3) para consultar las habitaciones reservadas*"<<endl;
	cout<<"\t\t*******************************************************"<<endl;
	cout<<"\t\t*Digite (4) para actualizar los datos de un usuario   *"<<endl;
	cout<<"\t\t*******************************************************"<<endl;
	cout<<"\t\t*Digite (5) para salir del programa                   *"<<endl;
	cout<<"\t\t*******************************************************"<<endl;
	int op, op1, op2;
	cin>>op;
	system("cls");
        switch (op)
        {
        case 1 :
        	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
        	cout<<"Digite (1) para ver las habitaciones y sus especificaciones"<<endl;
        	cout<<"Digite (2) para realizar un check in dependiendo de la habitacion"<<endl;
        	cin>>op1;
        	if(op1==1)
        	{
        		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
        		for(int i=0;i<10;i++)
        		{
        			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
        			cout<<"-------------------------------------------"<<endl;
        			cout<<"La habitacion #"<<ha[i].numero<<"contiene: "<<endl;
        			cout<<"Camas: "<<ha[i].camas<<endl;
        			cout<<"Aire acondicionado: "<<ha[i].aire<<endl;
        			cout<<"El precio por dia es de: "<<ha[i].precio<<endl;
        			cout<<"-------------------------------------------"<<endl;
				}
				cout<<"*************************************************************************"<<endl;
        		cout<<"NOTA: Para el aire acondicionado (1) significa 'si' y (2) significa 'no' "<<endl;
        		cout<<"NOTA: Para el estado (D) significa 'Desocupada' y (A) significa 'Activa' "<<endl;
        		cout<<"NOTA: En la parte superior se muestran las condiciones de cada habitacion"<<endl;
        		cout<<"*************************************************************************"<<endl;
			if(op1==2)
			{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout<<"HORA DE REGISTRO DEL CLIENTE :";	
	        printf ("%s",p);
	        cout<<endl;
			check_in();	
			}
            break;
        case 2 :
            borrar();
            break;
        case 3:
            mostrar();
            break;
        case 4 :
            actualizar();
            break;
        case 5:
        	exit(1);
        	break;
        default :
            cout << " \n Opcion incorrecta \n";
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
        cout << " Si deseas volver al menu principal presiona 's', si quieres salir presiona 'n'"<<endl;
        char f;
        cin>>f;
        if(f!='s')
        {
            flag=false;
        }
    }
}
    return 0;
}

