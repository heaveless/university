#include <stdio.h>

int sizeOfString(const char* source) {
  int length = 0;
  // Se realiza el conteo de caracters de un string char: --> not = [n, o, t] = 3
  while(*source != '\0') {
    source++;
    length++;
  }

  return length;
}

void copy(const char* source, char* tarjet, int length) {
  // Se copia caracter por caracter todo el texto del "source" al "tarjet"
  while(length) {
    *tarjet = *source;

    source++;
    tarjet++;

    length--;
  }   
}

void divider(char* tarjet, const char* ref) {
  int length = sizeOfString(ref);

  // Se define las variables constantes que serviran par alas evaluaciones
  const char separator = ',';
  const char space = ' ';
  const bool specialCharacter = length == 1 && *ref != separator;

  // En caso de ser un stopword especial, se le trata de una menera diferente [".", ",", ";"] 
  // Se le asigna un comodin para su posterior limpieza
  if (specialCharacter && *(tarjet - 1) != space && *(tarjet + 1) == space) {
    *tarjet = '*';
    return;
  }

  // Se remplaza los espacios sobrantes e innecesarios por comas
  tarjet--;
  if (*tarjet == space)
    *tarjet = separator;
  tarjet++;

  // Se reordena todo el texto para suplantar los stopword con los siguentes caracteres que
  // tendrian que estar, como si no existieran
  while(*tarjet != '\0') {
    *tarjet = *(tarjet + length); 

    tarjet++;
  }
}

void clean(char* tarjet) {
  const char separator = ',';
  
  // Se itera el texto buscando el caracter "*" que se le asigno de acuerdo a posiciones especiales del texto
  // para luego remplazarlo con coma(,) y a la vez se elimina las comas innecesarias
  while(*tarjet != '\0') {
    if (*tarjet == '*')
      *tarjet = separator;

    if (*tarjet == separator && *(tarjet + 1) == separator) {
      tarjet++;
      *tarjet = '\0';
    }

    tarjet++;
  }
}

bool checker(const char* current, const char* tarjet) {
  // Se compara los caracteres del stopword actual con los caracteres del texto sucesivamente
  while (*current != '\0' && *tarjet != '\0'  && *current == *tarjet) {
    current++;
    tarjet++;
  }

  // En caso de que en la compracion se haya podido hacer un match completo con el stopword se retorna un boleando
  return *tarjet == '\0';
}

int main()
{
  // definicion de tamanio de palabra y tamanio total de texto completo
  const int wordSize = 20;
  const int totalSize = 300;

  // declaracion de stopwords y texto a analizar en tipo constante (solo lectura)
  const char stopword[totalSize / wordSize][wordSize] = { "is", "not", "that", "there", "are", "many", "can", "you", "with", "one", "of", "those", ".", ",", ";" };
  const char mainText[] = "feature extraction is not that complex. there are many algorithms available that can help you with feature extraction. rapid automatic keyword extraction is one of those.";

  // declaracion de variable "text" que servida para ser manipulado
  const int textLength = sizeof(mainText) / sizeof(*mainText);
  char text[textLength];
  
  // generar copia del texto principal de solo lectura a una variable que pueda ser manipulada (mainText -> text)
  copy(mainText, text, textLength);

  // Se declara punterios constantes para los stopwords, ya que no necesitan ser modificados
  // Se declara puntero para "text", este si sera modificado desde la nueva variable "textPtr"
  const char (*stopwordPtr)[wordSize] = stopword;
  char* textPtr = text;
  int stopwordSize = sizeof(stopword)/sizeof(*stopword);
 
 // Se imprimi el texto previo a su modificacion
  printf("%s\n%s\n\n", "Texto Original:", text); 

// Se inicia iteracion del texto a modificar, mientras no se llegue al final de todo el texto
  while(*textPtr != '\0') {
    // Se verifica si existe el stopword actual del array en el texto
    // En caso de ser encontrado, se realiza la division a travez de una coma(,)
    bool isFound = checker(textPtr, *stopwordPtr);
    if(isFound) {
      divider(textPtr, *stopwordPtr);
    }
  
    textPtr++;

    // Al llegar al final del texto y haber remplazado los stopword con comas,
    // se itera al siguente stopword del array y se reinicia el puntero del texto
    if (*textPtr == '\0' && stopwordSize != 0) {
      stopwordPtr++;
      stopwordSize--;
      textPtr = text; 
    }
  }

  // Se reinicia la variable de tipo puntero con el texto que se esta modificando
  // Se limpia caracteres sobrantes
  textPtr = text; 
  clean(textPtr);

  // Se imprime el texto posteior a su modificacion
  printf("%s\n%s", "Candidate Key Phrases:", text); 

  return 0;
}
