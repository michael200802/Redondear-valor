#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;


long double redondear_valor(string&x);

int main(){
	//Declaramos una string
	string x;
	cout<<"Digite la cifra: ";
	//Ingresamos el valor
	cin>>x;
	fflush(stdin);
	//Pasamos a la string a la funcion
	cout<<redondear_valor(x);
	getch();
	return 0;
}

long double redondear_valor(string&x){
	//Size de un futuro array aux
	int size = 0;
	//Variable que devolveremos
	long double num_aux = 0;
	
	//Ciclo for
	for(int i = 0; i < x.length(); i++)
	{
		//Se cumple si se encuentra un punto o una coma entre los caracteres del array
		if(x[i] == '.' && i + 1 < x.length() || x[i] == ',' && i + 1 < x.length())
		{
			//por si encontrasemos una coma, la reemplazamos con un punto
			x[i] = '.';
			//Otro ciclo for
			//Pero la variable de este se inicializa una posicion despues del punto/coma
			for(int I = i+1; I + 1 < x.length(); I++)
			{
				//Este ciclo inicia si se repite un digito dos veces (a == b)
				//Inicia en la pocision, del digito anterior (poscicion de a)
				for(int j = I; x[j] == x[j+1] ; j++)
				{
					//Si el ciclo for no se ha roto
					//Y j + 2 es igual al numero de elementos de x
					if(j+2 == x.length())
					{
						//Size se hace igual a el valor de I
						size = I;
						//A I y i los igualamos a c.length para romper sus bucles una vez que salgamos de este
						I = x.length();
						i = I;
						//Rompemos el bucle for en el que estamos atrapados
						break;
					}
				}
			}
		}
	}
	//Si size es diferente de cero, significa que se puede redondear una parte
	if(size != 0)
	{
		//Creamos el array de caracteres auxiliar
		char aux[size+1];
		//Rellenamos a aux con los elementos de x, hasta lo que nos permite size
		for(int i = 0; i < size+1; i++)
		{
			aux[i] = x[i];
		}
		//Al ultimo elemento de aux, se le aumenta 1
		aux[size] = aux[size] + 1;
		//num_aux es igual al valor de atof(aux)
		num_aux = atof(aux);
		//En el caso de que el ultimo elemento de aux hubiera sido un 9
		//Eso significaria que al sumarle 1 a ese caracter
		//El resultado hubiera sido un ':'
		//En esos casos se inicia el ciclo for
		for(int p = size; aux[p] == ':' && p >= 0; p = p - 1)
		{
			//Se elimina el ':'
			aux[p] = ' ';
			if(aux[p-1] == '.')
			{
				//Si despues del ':' nos toparamos con un punto
				//Lo eliminamos
				aux[p-1] = ' ';
				//Ahora hacemos que num_aux sea igual al valor de atof(aux)
				num_aux =  atof(aux);
				//como tenemos que redondear, aumentamos a num_aux en 1
				num_aux = num_aux + 1;
			}
			else
			{
				//Si no nos encontramos con un '.'
				//pues aumentamos el valor a el caracter anterior a la posicion del ya muerto :
				aux[p-1] = aux[p-1] + 1;
				//num_aux es igual al valor de atof(aux)
				num_aux = atof(aux);				
			}
		}
	}
	else
	{
		//si size es igual a zero
		//significa que no hay nada que redondear
		//por lo que igualamos a num_aux a atof(x.c_str)
		num_aux = atof(x.c_str());
	}

	return num_aux;
}

