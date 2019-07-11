#include <iostream>
#include <iomanip>
#include<stdio.h>

using namespace std; 
class Cajero
{
	private: 
        double Saldo; 
		double Depositar; 
		double Retirar; 
		int Opcion;
	public: 
	    Cajero(double saldo=0,double depositar=0,double retirar=0,int opcion=0); 
		double saldo(double retiro,double deposito,double saldot); 
		double deposit(double saldot); 
		double retiro(double saldot); 
		double Option(int optionl,double saldot); 
		double saldot(void);
		double transferencia(double saldot);
		double pagserv(double saldot ); 
		double reccel(double saldot );
		void Ejecutar (void); 
};//fin de La cLase 
Cajero::Cajero(double saldo,double depositar,double retirar,int opcion):Saldo(saldo),Depositar(depositar),Retirar(retirar),Opcion(opcion) 

{
 }//fin del. constructor  

double Cajero::saldo(double retiro, double deposito, double saldot)
{	system( "cls");
	saldot=saldot+deposito-retiro;
	return saldot;
	
} //fin del saldo
double Cajero::deposit(double saldot)
{
	double dep=0;
	char sn;
	do 
	{
LDeposito:
	system("cls");
	cout<<"ingrese cantidad a depositar:  ";
	cin>>dep;
	while(dep<=0)
	{
		cout<<"dese ingresar un valor valido s=si n=no:  ";
		cin>>sn;
		if(sn=='S'||sn=='s')
		     goto LDeposito;
		else 
		     exit(0);
			      
	}	
	saldot=saldo(0,dep,saldot);
	cout<<"desea realizar otro deposito s=si n=no";cin>>sn;
	
	}while(sn=='S'||sn=='s');

return saldot;	
}//fin del depocito
double Cajero::retiro(double saldot )
{
	double retir=0;
	char sn;
	system("cls");
	if (saldot==0)
	{
		cout<<"Ud. no cuenta con saldo \n";
		cout<<"desea realizar la operacion s/S n/N:  ";cin>>sn;
		if(sn=='S'||sn=='s')
		{
			system("cls");
			Ejecutar();
			
		}
		else 
		exit(0);
		
	
	}
	do
	{Lretir:
		system("cls");
		cout<<"Ingrese cantidad a retirar";
		cin>>retir ;
		 while(saldot<retir)
		 {
		 	cout<<"Ud. no cuenta con saldo sufiente para hacer ese retiro \n";
		 	goto reintentar;
		 	
		 }
		 while(retir<=0)
		 {
		 	reintentar:
		 		cout<<"desea ingresar un valor valido s=si n=no";
		 		cin>>sn;
		 		if(sn=='S'||sn=='s')
		 		   goto Lretir;
		 		else
				 exit(0);    
		 			
		 }
		 saldot=saldo(retir,0,saldot);
		 cout<<"desea realizar otra retiro s=si n=no:  :";cin>>sn;
		
	}while(sn=='S'||sn=='s');
return saldot;	
}
double Cajero::Option(int option1,double saldot)
{
switch(option1)	
	{
	 case 1:saldot=deposit(saldot);break;
	 case 2:saldot=retiro(saldot);break;
	 case 3:saldot=transferencia(saldot);break;
	 case 4:saldot=pagserv(saldot);break;
	 case 5:saldot=reccel(saldot);break;
	 case 6: {
	 	saldot=saldo(0,0,saldot);
	 	cout<<"usted cuenta con : "<<saldot<<" soles \n";
	 	
	 }break;
	 case 7:{system("cls");cout<<"cerrando sistema.......¡¡ GRACIAS POR UTILIZAR NUESTRO CAJERO BCP";exit(0); }break;
		
	}
return saldot;	
}
 double Cajero::transferencia(double saldot )
 {
 	double trans=0;
 	char sn;
 	double usseles;
 	system("cls");
 	if(saldot==0)
 	{cout<<"Ud. no cuenta con saldo \n ";
 	    cout<<"desea realizar otra operacion s=si n=no ";cin>>sn;
 	    if(sn=='S'||sn=='s')
 	    {
 	    	system("cls ");
 	    	Ejecutar();
 	    	
		 }
		 else
		 exit(0);
	 }
	 do
	 {
	 	LTrans:
	 		system("cls");
	 		cout<<"Ingrese el numero de la cuenta a la que decea transferir: ";
	 		cin>>usseles;
	 		cout<<"Ingrese la cantidad a transferir: ";
	 		cin>>trans;
	 		while(saldot<trans)
	 		{
	 			cout<<"usted no cuenta con saldo suficiente para hacer la transferencia \n";
	 			goto reintentar;
	 			
			 }
			 while(trans<=0)
			 {
			 	reintentar:
			 		cout<<"decea Ingresar un valor valido? s=si n=no";
			 		cin>>sn;
			 		if(sn=='S'||sn=='s')
			 		   goto LTrans;
			 		else
					   exit(0);
					      
			 }
			 saldot=saldo(trans,0,saldot);
			 cout<<"desea realizar otra trasferencia? s=si n=no :  ";
			 cin>>sn;
	 }while (sn=='s'||sn=='S');
return saldot;
	 
 }//fin de la transferencia
double Cajero::pagserv(double saldot)
{
	double pago=0;
	       char sn;
	       int q,ser;
	       double useles;
	       
	       
	       system("cls");
	       do{
	       	seleccc:
	       		cout<<"que servicio decea pagar "<<endl<<endl;
	       		cout<<"1. recibo de luz "<<endl;
	       		cout<<"2. recibo de telefono "<<endl;
	       		cin>>q;
	       		
	       		if(q==1)
	       		   {
	       		   	system("cls");
	       		   	cout<<"ELECTRO PUNO S.A.\n";
	       		   	cout<<"Ingrese su numero de sevicio: ";
	       		   	cin>>useles;
					  }
				if(q==2)
				    {
				    system("cls");
					Selec:
					cout<<"1. tv claro"<<endl;
					cout<<"2. directv"<<endl;
					cout<<"3. telmex"<<endl;
					cout<<"4. movistar tv"<<endl;
					
					cin>>ser;
					
					if(ser=1)
					{
						cout<<"\t\trecibo de tv claro"<<endl;
						cout<<"Ingresee su numero claro: ";
						cin>>useles;
					}
					
					if(ser=2)
					{
						cout<<"\t\trecibo de directv"<<endl;
						cout<<"Ingresee su numero de cuenta: ";
						cin>>useles;
					}
					
					if(ser=3)
					{
						cout<<"\t\trecibo de telmex"<<endl;
						cout<<"Ingresee su telefono: ";
						cin>>useles;
					}
					
					if(ser=4)
					{
						cout<<"\t\trecibo de movistar tv"<<endl;
						cout<<"Ingresee su numero movistar: ";
						cin>>useles;
					}
					
					if(ser>4||ser<1)
					{
						cout<<"Intentelo de nuevo"<<endl<<endl;
						goto Selec;
					}
					
						
					}
					
				if(q>2||q<1)
				{
					cout<<"Intentelo de nuevo"<<endl<<endl;
					goto seleccc;
				}
					
						  
				if(saldot==0)
				{cout<<"UD: no cuenta con saldo\n";
				    cout<<"desea realizar otra operacion s=si n=no : ";cin>>sn;
				    if(sn=='S'||sn=='s')
				    {
					system("cls");
				    Ejecutar();				    
				    }
				    else
				    exit(0);
			}
			
			LPago:
				cout<<"Ingrese cantidad a pagara: ";
				cin>>pago;
				
				while(saldot<pago)
				{
					cout<<"UD. no cuenta con saldo suficiente para hacer el pago \n";
					goto reintentar;
				}
				while(pago<=0)
				{
					reintentar:
						cout<<"desea ingresar un valor valido s=si n=no";
						cin>>sn;
						if(sn=='S'||sn=='s')
						    goto LPago;
						    
						else exit(0);    
				}
				saldot=saldo(pago,0,saldot);
				cout<<"desea realizar otro pago? s=si n=no ";cin>>sn;
								  	  
	       		
		   }while(sn=='s'||sn=='S');
return saldot;		   
}//fin de la transferencia
double Cajero::reccel(double saldot)
{
	
	double recarga=0;
	    char sn;
	    int q,ser;
	    double useles;
	    
	    system("cls");
	    do{
	    	Selec:
	    		
	    	cout<<"selecionar compañia \n";
	    	cout<<"1. movistar"<<endl;
	    	cout<<"2. claro"<<endl;
	    	cout<<"3. bitel"<<endl;
	    	cin>>ser;
	    	
	    	if(ser==1)
	    	{
	    		cout<<"\t\tMOVISTAR\t\t "<<endl;
	    		cout<<"ingrese su numero  "<<endl;
	    		cin>>useles;
			}
			
			if(ser==2)
	    	{
	    		cout<<"\t\tCLARO\t\t "<<endl;
	    		cout<<"ingrese su numero  "<<endl;
	    		cin>>useles;
			}
			
			if(ser==3)
	    	{
	    		cout<<"\t\tBITEL\t\t "<<endl;
	    		cout<<"ingrese su numero  "<<endl;
	    		cin>>useles;
			}
			if(ser>3||ser>1)
			{
	    		cout<<"intentelo de nuevo "<<endl<<endl;
	    		goto Selec;
						
			}
			
		if(saldot==0)
		{
			cout<<"Ud. no cuenta con saldo \n";
			cout<<"desea realisar otra operacion s=si n=no ";cin>>sn;
			if(sn=='S'||sn=='s')
			{
			system("cls");
			Ejecutar();
			
			}
			else
			exit(0);
					
		}
		    LPago:
		    cout<<"ingrese cantidad a abonar. ";
		    cin>>recarga;
		    while(saldot<recarga)
			{
				cout<<"Ud. no cuenta con saldo suficiente para realizar la recarga \n";
				goto reintentar;
				
			}
			while(recarga<=0)
			{
				reintentar:
					cout<<"desea ingresar un valor valido? s=si n=no ";
					cin>>sn;
					if(sn=='S'||sn=='s')
					   goto LPago;
					else 
					   exit(0);
					      
			}
			saldot=saldo(recarga,0,saldot);
			cout<<"desea realizar otra recarga? s=si n=n0 :  ";cin>>sn;
						
		}while(sn=='s'||sn=='S');
		
return saldot;		
}

void Cajero::Ejecutar(void)
{
	
	
	int opt;
	char sn;
	double saldot=0;
	
	do
	{
	system("cls");
	cout<<"\t\t\tOPERACIONES BANCARIAS\n ";
	cout<<"\t\t1. DEPOSITO \n ";
	cout<<"\t\t2. RETIRO\n ";
	cout<<"\t\t3. TRANSFERENCIA\n ";
	cout<<"\t\t4. PAGAR SERVICIO\n ";
	cout<<"\t\t5. RECARGAR CELULAR\n ";
	cout<<"\t\t6. saldo\n ";
	cout<<"\t\t7. salir\n\n ";
	
	cout<<"\t\t 5Elija un numero de la opcion";
	cin>>opt;
	saldot=Option(opt,saldot);
	cout<<"desea continuar con otra operacion s=si n=no :  ";
	cin>>sn;
		 	
	}while(sn=='s'||sn=='S');
	system ("cls");
	cout<<"cerrando el sistema.......¡¡GRACIAS POR UTILIZAR NUESTRO CAJERO BCN\n";exit(0);
	
}
system (color “color de 2” “color de 1”);
int main(void)
{
	
	Cajero C;
	C.Ejecutar();
	
	
	return 0;
}
