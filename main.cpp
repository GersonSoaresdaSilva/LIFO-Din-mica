/*1. Considere o programa interativo da aula, codifique a function main inserindo um menu para controlar a LIFO.
2. Usando malloc e ponteiros, codifique o Código Fonte (CF) de uma LIFO dinâmica para empilhar nomes e salários de uma pessoa qualquer. Use menu de controle para chamar as funções da LIFO.*/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int cont;

typedef struct lifo pilha;
struct lifo {
  string nome;
  double sal;
  pilha *ant;
};
pilha *topo;
pilha *ultimoNo;

void empilhar ();
void desempilhar ();
void destruir ();
bool pilha_Construtor ();
bool pilha_Destrutor ();
bool pilha_Vazia ();
int pilha_Tamanho ();
string ler_nome ();
double ler_sal ();
bool pilha_Push ();
bool pilha_Pop ();
void exibir ();
void controle ();

int main () {
  setlocale(LC_ALL, "Portuguese");
  controle ();
  return 0;
}

void empilhar () {
  if (topo == NULL) {
    pilha_Construtor ();
  }
  if (pilha_Push () == true) {
    cout << "\nDados empilhados com Sucesso!" << endl;
  }
  else {
    cout << "\nNão há memória disponível!" << endl;
  }
  system ("sleep 4");
}

void desempilhar () {
  if (pilha_Pop () == true) {
    cout << "\nValor desempilhado com Sucesso!" << endl;
  }
  else {
    cout << "\nERRO: Não há valores para desempilhar!" << endl;
  }
  system ("sleep 4");
}

void destruir () {
  if (pilha_Destrutor () == true) {
    cout << "\nPilha Destruida com Sucesso!" << endl;
  }
  else {
    cout << "\nPilha Vazia" << endl;
  }
  system ("sleep 4");
}

bool pilha_Construtor () {
  topo = NULL;
  cont = 0;
  return true;
}

bool pilha_Destrutor () {
  pilha *temp;
  if (pilha_Vazia () == true) {
    return false;
  }
  else {
    while (topo != NULL) {
      temp = topo;
      temp->ant = NULL;
      topo = topo-> ant;
      free (temp);
    }
    cont = 0;
    return true;
  }
}

bool pilha_Vazia () {
  if (topo == NULL) {
    return true;
  }
  else {
    return false;
  }
}

int pilha_Tamanho () {
  return cont;
}

string ler_nome () {
  string aux_nom;
  cin.ignore();
  cout << "\nInforme o nome.: ";
  getline(cin, aux_nom);
  return aux_nom;
}

double ler_sal () {
  double aux_sal;
  cout << "\nInforme o salário.: ";
  cin >> aux_sal;
  return aux_sal;
}

bool pilha_Push () {
  pilha *novaLifo = new pilha ();

  if (novaLifo == NULL) {
    return false;
  }
  else {
    if (cont == 0) {
      novaLifo-> ant = NULL;
      novaLifo-> nome = ler_nome ();
      novaLifo-> sal = ler_sal ();
      topo = novaLifo;
    }
    else {
      novaLifo-> ant = topo;
      novaLifo-> nome = ler_nome ();
      novaLifo-> sal = ler_sal ();
      topo = novaLifo;
    }
    cont ++;
    return true;
  }
}

bool pilha_Pop () {
  if (pilha_Vazia () == true) {
    return false;
  }
  else {
    string temp_nome;
    double temp_sal;
    pilha *temp; 
    
    temp = topo;
    temp_nome = topo-> nome;
    temp_sal = topo-> sal;

    free (temp);
    topo = topo->ant;
    cont --;
    return true;
  }
}

void exibir () {
  if (pilha_Vazia ()== true) {
    cout << "\nPilha Vazia!" << endl;
  }
  else {
    pilha *temp;
    temp = topo;
    while (temp != NULL) {
      cout << "\nNome: " << temp-> nome << "\nSalario: " << temp-> sal << endl;
      temp= temp->ant;
    }  
  }
  system ("sleep 4");
}

void controle () {
  int opcMenu;
  while (true) {
    system ("clear");
    cout << "\n*** Menu de Controle ***";
    cout << "\n1 - Empilhar \n2 - Desempilhar \n3 - Exibir \n4 - Sair \nOpção.: ";
    cin >> opcMenu;
    switch (opcMenu) {
      case 1: empilhar (); break;
      case 2: desempilhar (); break;
      case 3: exibir (); break;
      case 4: destruir (); exit (0); break;
      default: cout << "\nOpção Inválida!" << endl; system ("sleep 4");
    }
  }
}