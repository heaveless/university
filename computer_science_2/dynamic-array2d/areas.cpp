#include <iostream>
#include <math.h> 

using namespace std;

double circulo(double *param)
{
  return M_PI * pow(*param,2);
}

double cuadrado(double *param)
{
  return pow(*param,2);
}

double triangulo(double *param)
{
  return (*param * *(param+1))/2;
}

void calcular(double(*area)(double*), double* param)
{
  cout<<area(param)<<endl;
}

typedef double (*Arr[3])(double*);

int main() {
  char mensaje[3][10] = {"circulo","cuadrado","triangulo"};
  double datos[3][2];
  Arr areas = {circulo,cuadrado,triangulo};

  //Ingreso de datos
  for(int i=0; i <3; i++)
    {
      cout<<"Ingrese lo datos para calcular el área del "<<mensaje[i]<<endl;
      switch(i)
        {  case 0:
              cout<<"radio = ";
              cin>>datos[i][0];
            break;
          case 1:
              cout<<"lado = ";
              cin>>datos[i][0];
            break;
          case 2:
              cout<<"base = ";
              cin>>datos[i][0];
              cout<<"altura = ";
              cin>>datos[i][1];
            break;
        }
    }
  cout<<endl<<endl;
  //Cálculo de áreas
  for(int i=0; i<3;i++)
    {
      cout<<"El área del "<<mensaje[i]<<" es ";
      calcular(areas[i],*(datos+i));
    }
  cout<<endl<<endl;
  return 0;
}