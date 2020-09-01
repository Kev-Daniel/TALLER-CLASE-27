#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;


void dividir(int a[], int inicial, int final);

void fusionar(int a[], int pinicial, int pfinal, int medio);





int main()
{

    int numeros[10];

    srand(time(0));// GENERAR UNA SEMILLA
      ofstream archivo ;
      archivo.open("mergesort.txt"); 
    for (int i=0; i<6;i++)
    {
        //LLENAR ELEMENTOS AL ARREGLO EN UN INTERVALO DE 1-20
        numeros[i]=1+rand()%(50-1);
    }

    archivo<< "Arreglo original : ";

    for (int i=0; i<6;i++)
    {

        cout<<numeros[i]<<" ";
        archivo<<numeros[i]<<" ";
    }

    dividir(numeros,0,6);

    cout<<endl;
    archivo<<endl;
    archivo<< "Arreglo ordenado : ";

    for (int i=0; i<6;i++)
    {
     

        cout<<numeros[i]<<" ";
        archivo<<numeros[i]<<" ";
       
     
    }

   archivo.close();

    return 0;
}


void dividir(int a[], int inicial, int final)
{

    int mitad;

    if (inicial<final)
    {
        mitad=(inicial+final)/2;

        dividir(a,inicial,mitad);

        dividir(a,mitad+1,final);

        fusionar(a,inicial,final,mitad);
    }

}

void fusionar(int a[], int pinicial, int pfinal, int medio)
{
    int i, j, k, temp[pfinal-pinicial+1];
	i = pinicial;
	k = 0;
	j = medio + 1;

	while (i <= medio && j <= pfinal)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}

	while (i <= medio)
	{
		temp[k] = a[i];
		k++;
		i++;
	}

	while (j <=pfinal)
	{
		temp[k] = a[j];
		k++;
		j++;
	}

	for (i = pinicial; i <= pfinal; i++)
	{
		a[i] = temp[i-pinicial];
	}
}
