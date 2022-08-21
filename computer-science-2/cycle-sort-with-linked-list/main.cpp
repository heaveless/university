#include <iostream>

template<class T>
class Node {
  public:
    T data;
    Node<T>* next;

    Node(T d, Node<T>* n = NULL) {
      data = d;
      next = n;
    }

    void print() {
      std::cout << data;
    }
};

template<class T>
class List {
  public:
    Node<T>* head;
    Node<T>* end;
    int length;

  List() {
    head = NULL;
    end = NULL;
    length = 0;
  }

  ~List() {
    std::cout << "Destruyendo lista" << std::endl;
    Node<T>* p = head;

    while(p) {
      p = p->next;
      delete head;
      head = p;
    }
  }

  void add(T d) {
    Node<T>* new_node = new Node<T>(d);
    if (head)
      end->next = new_node;
    else
      head = new_node;
    end = new_node;

    length++;
  }

  void print() {
    Node<T>* p = head;
    while(p) {
      std::cout << p->data << ",";
      p = p->next;
    }
    std::cout << std::endl;
  }

  bool find(T d, Node<T>*& ant) {
    ant = NULL;
    if (head->data == d) {
      ant = NULL;
      return true;
    }

    for(ant = head;(ant->next) && ant->next->data != d; ant = ant->next);

    if(ant->next)
      return true;
    return false;
  }

  bool insert(T d, T pos) {
    Node<T>* ant;

    if(find(pos, ant)) {
      if(!ant) {
        Node<T>* new_node = new Node<T>(d, head);
        head = new_node;
      } else {
        Node<T>* new_node = new Node<T>(d, ant->next);
        ant->next = new_node;
      }

      return true;
    }

    return false;
  }

  bool del(T d) {
    Node<T>* ant;
   
    if(find(d, ant)) {
      if(!ant) {
        head = head->next;
        delete ant;
      } else {
        Node<T>* aux = ant->next->next;
        delete ant->next;
        ant->next = aux;
      }
    } else 
      return false;

    return true;
  }

  void __sort(Node<T>* node, int len) {
    // Se crea una variable temporal para el cambio de datos
    int tmp;

    // Se crea un limite de la recursividad
    if (len == 1)
      return;

    // Se itera a travez de los nodos buscando el numero mayor al siguente 
    for(Node<T>* inode = node; inode; inode = inode->next) {
      if (inode->next && inode->data > inode->next->data) {
        // En caso de encontrar el valor deseado se utiliza la variable temporal para realizar el intercambio
        tmp = inode->data;
        inode->data = inode->next->data;
        inode->next->data = tmp;
      }
    }

    // Se reduce el tamanio de la lista y se usa recursividad para volver a buscar en el siguente nodo
    len--;
    __sort(node, len);
  }

  void sort() {
    __sort(head, length);
  }
};

int main() {
  List<int> l;
  l.add(2);
  l.add(4);
  l.add(5);
  l.add(1);
  l.add(3);
  l.sort();
  l.print();





















  // Node<char>* ant;
  // if(l.find('g', ant))
  //   std::cout << "Existe" << std::endl;
  // else
  //   std::cout << "No Existe" << std::endl;

  // if(l.del('x'))
  //   std::cout << "Eliminado" << std::endl;
  // else
  //   std::cout << "No Existe" << std::endl;
  // l.print();

  // if(l.insert('h', 'c'))
  //   std::cout << "Insertado" << std::endl;
  // else
  //   std::cout << "No Existe" << std::endl;
  // l.print();
}