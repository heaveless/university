#include <iostream>
#include <math.h> 

using namespace std;

class Figura {
  public:
    Figura() { }

  double circulo(double *param) {
    return M_PI * pow(*param, 2);
  }

  double cuadrado(double *param) {
    return pow(*param, 2);
  }

  double triangulo(double *param) {
    return (*param * *(param + 1)) / 2;
  }

  // recibe el puntero array de datos para ser asignado mediante consola
  void DatosCirculo(double* datos) {
    cout << "radio = ";
    cin >> *datos;
  }

  // recibe el puntero array de datos para ser asignado mediante consola
  void DatosCuadrado(double* datos) {
    cout << "lado = ";
    cin >> *datos;
  }

  // recibe el puntero array de datos para ser asignado mediante consola
  void DatosTriangulo(double* datos) {
    cout << "base = ";
    cin >> *datos;

    // Se avanza a la siguente columna del array para recibir el siguente dato
    // posteriormente se restablece en el primer valor del array de la dimension 2 actual
    datos++;
    cout << "altura = ";
    cin >> *datos;
    datos--;
  }
};

// Se define los tipos de dato par las areas y funciones
typedef double (Figura::* FuncArea)(double*);
typedef void (Figura::* FuncDatos)(double*);

// la funcion ejecuta el metodo recivido atravez de la instancia tambien enviada
void calcular(Figura* instance, FuncArea* func, double* param) {
  cout << (instance->**func)(param) << endl;
}

int main() {
  // Se declara el las variables que definiran el tamanio de los arrays a iterar
  const int length = 3;
  const int datosLength = length * 2;

  // Se crea una instancia de figura
  Figura* figura = new Figura();

  // Se crea el array de mensajes y se crea un puntero para cada mensaje
  char mensaje[length][10] = { "circulo", "cuadrado", "triangulo" };
  char (*unMensaje)[10] = mensaje;

  // Se crea el array dinamico de tipo de dato double, junto a un puntero auxiliar
  double* datos = new double[datosLength];
  double* datosAux = datos;

  // Se crea los array de funciones respectivos para areas y datos
  FuncArea funcAreas[] = { &Figura::circulo, &Figura::cuadrado, &Figura::triangulo };
  FuncDatos funcDatos[] = { &Figura::DatosCirculo, &Figura::DatosCuadrado, &Figura::DatosTriangulo };
  
  // Se itera las funciones de solicitud de datos y al mismo tiempo se ejecuta
  for (FuncDatos* funcDatosPtr = funcDatos; funcDatosPtr < funcDatos + length; funcDatosPtr++, datosAux += 2, unMensaje++) {
    cout<<"Ingrese lo datos para calcular el área del " << *unMensaje << endl;
    (figura->**funcDatosPtr)(datosAux);
  }

  // Se reinicia las variables de datos y mensaje
  cout << endl;
  datosAux = datos;
  unMensaje = mensaje;

  // Se itera las funciones de Area y se ejecuta la funcion calcular, enviando como paramento
  // la instancia de figura, la funcion a ejecutar y los datos
  for (FuncArea* funcAreasPtr = funcAreas; funcAreasPtr < funcAreas + length; funcAreasPtr++, datosAux += 2, unMensaje++) {
    cout<< "El área del " << *unMensaje << " es ";
    calcular(figura, funcAreasPtr, datosAux);
  }

  return 0;
}