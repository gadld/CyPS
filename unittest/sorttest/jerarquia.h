#include <iostream>
using namespace std;

class Parent
{
public:
	virtual void sort(int lista[],int n)=0;
};

class Bubble :public Parent
{
public:
	void sort(int array[],int n)
	{

		int c, d, swap;
		 
		  
		 
		  for (c = 0 ; c < ( n - 1 ); c++)
		  {
		    for (d = 0 ; d < n - c - 1; d++)
		    {
		      if (array[d] > array[d+1]) /* For decreasing order use < */
		      {
		        swap       = array[d];
		        array[d]   = array[d+1];
		        array[d+1] = swap;
		      }
		    }
		  }
		 
		cout <<"Child 1" <<endl;
	}
};
class Quick :public Parent
{
public:
	void qs(int lista[],int limite_izq,int limite_der)
	{
	    int izq,der,temporal,pivote;

	    izq=limite_izq;
	    der = limite_der;
	    pivote = lista[(izq+der)/2];

	    do{
	        while(lista[izq]<pivote && izq<limite_der)izq++;
	        while(pivote<lista[der] && der > limite_izq)der--;
	        if(izq <=der)
	        {
	            temporal= lista[izq];
	            lista[izq]=lista[der];
	            lista[der]=temporal;
	            izq++;
	            der--;

	        }

	    }while(izq<=der);
	    if(limite_izq<der){qs(lista,limite_izq,der);}
	    if(limite_der>izq){qs(lista,izq,limite_der);}

	}

	void sort(int lista[],int n)
	{
	    qs(lista,0,n-1);
	}

	
};

class Child3 :public Parent
{
public:

	void doSomething()
	{
		cout<<"child3"<<endl;
	}
};
