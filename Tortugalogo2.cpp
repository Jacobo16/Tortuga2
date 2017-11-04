#include<iostream>
int menu();
void mostrartablero(int tablero[][20], int rt);
void avanzar(int tablero[][20], int rt, int&dir, bool&pluma, int avance, int&x, int&y);
using namespace std;
int main () {
    int coordenadax=0, coordenaday=0, opcion, avance;
    bool pluma=false;
    int direccion=2; //Inicio a la tortuga viendo a la derecha.
    int pizarron[20][20]={0};

    do
    {
        opcion=menu();

        switch(opcion)
        {
        case 1:
            pluma=false;

            cout<<"La pluma esta arriba!<<"<<endl;
            cout<<endl;
            break;

        case 2:
            pluma=true;

            cout<<"La pluma esta abajo!<<"<<endl;
            cout<<endl;
            break;

        case 3:
            if(direccion!=4)
            {
                direccion++;
            }
            else
            {
                direccion=1;
            }

            cout<<"La tortuga giro a la derecha"<<endl;
            cout<<endl;
            break;

        case 4:
            if(direccion!=1)
            {
                direccion--;
            }
            else
            {
                direccion=4;
            }
            cout<<"La tortuga giro a la izquierda"<<endl;
            cout<<endl;
            break;

        case 5:

            avanzar(pizarron,20,direccion,pluma,5,coordenadax, coordenaday);
            break;

        case 6:
            mostrartablero(pizarron,20);
            break;

        case 7:
            cout<<"La tortuga esta mirando al:"<<direccion<<endl;
            cout<<endl;
        case 8:
            cout<<"Mostrar coordenadas X:"<<coordenadax<<" Y:"<<coordenaday<<endl;
            cout<<endl;
            break;

        }
    }while(opcion!=9);

    return 0;
}

int menu()
{
    cout<<"NOTA: 1.Norte. 2.Este. 3.Sur. 4.Oeste"<<endl;
    cout<<"1.Pluma arriba"<<endl;
    cout<<"2.Pluma abajo"<<endl;
    cout<<"3.Gira a la drecha"<<endl;
    cout<<"4.Gira a la izquierdda"<<endl;
    cout<<"5.avanzar"<<endl;
    cout<<"6.Mostrar tablero"<<endl;
    cout<<"7.Mostrar hacia donde mira"<<endl;
    cout<<"8.Mostrar posicion de la tortuga"<<endl;
    cout<<"8.salir"<<endl;

    int m;

    cin>>m;
    cout<<endl;

    return m;
}

void avanzar(int tablero[][20], int rt, int&dir, bool&pluma, int avance, int x, int y)
{
    switch(dir)
    {
    case 1://Para que la tortuga avance hacia el Norte
        {
            int i = 0;
            while(i <= avance)
            {
                if(pluma == 1)
                    tablero[x][y]=1;
                else
                    tablero[x][y]=0;

            if(x > 0)
					x--;
				i++;
        }
        if(x == 0)
				cout << ">> Has llegado al limite!"<<endl;

			break;
		}


    case 2://Para que la tortuga avance hacia el Este
        {
            int i=0;
            while(i<avance)
            {
                if(pluma==true)
                    tablero[x][y]=1;
                else
                    tablero[x][y]=0;

            if(y<19)
                y++;
            i++;
            }
            if(y==19)
                cout<<"Llegaste al limite del pizarron"<<endl;
                cout<<endl;
                break;
        }

    case 3://Hacia el Sur
        {
            int i=0;
            while(i<avance)
            {
                if(pluma==true)
                    tablero[x][y]=1;
                else
                    tablero[x][y]=0;

                if(x<19)
                    x++;
                i++;
            }
            if(x==19)
                cout<<"Llegaste al limite del pizzaron"<<endl;
            break;
        }
    case 4://hacia el Oeste
        {
            int i = 0;
			while(i <= avance)
            {
				if(pluma == 1)
					tablero[x][y] = 1;
				else
					tablero[x][y] = 0;

				if(y > 0)
					y--;
				i++;
			}
            if(y == 0)
				cout << ">> Has llegado al limite!"<<endl;
			break;
		}
    }
}

void mostrartablero(int tablero[][20], int rt)
{
    for(int r=0; r<20; r++)
    {
        for(int c=0; c<20; c++)
        {
            if(1==tablero[r][c])
                cout<<"*";
            else
                cout<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
