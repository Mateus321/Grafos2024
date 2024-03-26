#include "Lista.h" 
#include "FPHeapMinIndireto.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <array>
#include <cstring>
#include <float.h>
using namespace std;

	class Grafo {
	public:
		class Aresta {
	  private:
	    int v1, v2, peso; 
	  public: 
	    Aresta (int v1, int v2, int peso) {
	      this->v1 = v1; this->v2 = v2; this->peso = peso;
	    }
	    int _peso () { return this->peso; }
	    int _v1 () { return this->v1; }
	    int _v2 () { return this->v2; }
	    ~Aresta(){}
	  };
	private:	
		class Celula {
    friend class Grafo;
    friend ostream& operator<< (ostream& out, const Celula& celula) {
      out << "vertice:" << celula.vertice << endl;
      out << "peso:"    << celula.peso    << endl;
      return out;
    }    
		private:	
	    int vertice, peso;
	  public:
	    Celula (int v, int p) {
	    	this->vertice = v; this->peso = p;
	    }
	    Celula (const Celula& cel) { *this = cel; }      
      bool operator== (const Celula& celula) const {
        return this->vertice == celula.vertice;
      }
      bool operator!= (const Celula& celula) const {
        return this->vertice != celula.vertice;
      }
      const Celula& operator= (const Celula& cel) {     
        this->vertice = cel.vertice; this->peso = cel.peso;
        return *this; // @{\it permite atribui\c{c}\~oes encadeadas}@
      }      
      ~Celula () {}	    
	  }; 
    Lista<Celula> *adj; 
    int numVertices;
  public:
    Grafo( istream &in );
    Grafo (int numVertices);	  
    Grafo (int numVertices, int numArestas);	  
	  void insereAresta (int v1, int v2, int peso);
	  bool existeAresta (int v1, int v2) const;
	  bool listaAdjVazia (int v) const;
    Aresta *lerAresta ();
	  Aresta *primeiroListaAdj (int v);
	  Aresta *proxAdj (int v);
	  Aresta *retiraAresta (int v1, int v2);
	  void imprime () const ;
	  int _numVertices () const;
	  Grafo *grafoTransposto ();
    Grafo *grafoNaoDirecionado();
    vector<int> listaAdj(int v);
    bool existeCaminhoEuler();
    bool existeCicloEuler();
    bool direcionado();
    bool autoloop();
    bool completo();
    void buscaprofundidade();//FALTA
    void visitaDFS(int u, int antecessor[], int cor[]);//FALTA
    void buscaemlargura();//FALTA
    void visitaBFS(int u, int antecessor[], int dist[], int cor[]);//FALTA
    ~Grafo ();//FALTA
	};

  Grafo::Grafo( istream &in )
  {
   int v1, v2, peso, numVertices;
   in >> numVertices;
  
   this->adj = new Lista<Celula>[numVertices]; 
   this->numVertices = numVertices; 	  	  	
   
    while (in>>v1>>v2>>peso) {
      Grafo::Aresta *a = new Grafo::Aresta (v1, v2, peso);
      this->insereAresta (a->_v1 (), a->_v2 (), a->_peso ()); 
      delete a;
    }
  }

  Grafo::Grafo (int numVertices) {
  	this->adj = new Lista<Celula>[numVertices]; 
  	this->numVertices = numVertices; 	  	
  }	  
  Grafo::Grafo (int numVertices, int numArestas) {
  	this->adj = new Lista<Celula>[numVertices]; 
  	this->numVertices = numVertices; 	  	
  }	  

  Grafo::Aresta *lerAresta () {
    cout << "Aresta:" << endl;
    cout << "  V1:"; int v1 = 0;
    cin >> v1;
    cout << "  V2:"; int v2 = 0;
    cin >> v2;
    cout << "  Peso:"; int peso = 0;
    cin >> peso;
    return new Grafo::Aresta (v1, v2, peso);
  }

  void Grafo::insereAresta (int v1, int v2, int peso) {
    if(!this->existeAresta(v1,v2)){
      Celula item (v2, peso); 
      this->adj[v1].insere (item);
    } 
  }


  bool Grafo::existeAresta (int v1, int v2) const {
    Celula item (v2, 0);
    return (this->adj[v1].pesquisa (item) != NULL);
  }
  bool Grafo::listaAdjVazia (int v) const {
		return this->adj[v].vazia ();  
  }	  
  Grafo::Aresta *Grafo::primeiroListaAdj (int v) {
    // @{\it Retorna a primeira aresta que o v\'ertice v participa ou}@
    // @{\it {\bf NULL} se a lista de adjac\^encia de v for vazia}@ 
    Celula *item = this->adj[v]._primeiro ();    
    return item != NULL ? new Aresta(v,item->vertice,item->peso) : NULL;
  }
  Grafo::Aresta *Grafo::proxAdj (int v) {
    // @{\it Retorna a pr\'oxima aresta que o v\'ertice v participa ou}@
    // @{\it {\bf NULL} se a lista de adjac\^encia de v estiver no fim}@
    Celula *item = this->adj[v].proximo ();    
    return item != NULL ? new Aresta(v,item->vertice,item->peso) : NULL;
  }
  Grafo::Aresta *Grafo::retiraAresta (int v1, int v2) {
    Celula chave (v2, 0);
    Celula *item = this->adj[v1].retira (chave);
    Aresta *aresta = item != NULL ? new Aresta(v1,v2,item->peso) : NULL;
    delete item; return aresta;
  }
  void Grafo::imprime () const {
    for (int i = 0; i < this->numVertices; i++) { 
      cout << i << ":";
      Celula *item = this->adj[i]._primeiro ();
      while (item != NULL) {
        cout << "  " << item->vertice << " (" <<item->peso<< ")";
        item = this->adj[i].proximo ();
      }
      cout << endl;
    }
  }
  int Grafo::_numVertices () const { return this->numVertices; }
  Grafo *Grafo::grafoTransposto () {  	
    Grafo *grafoT = new Grafo (this->numVertices); 
    for (int v = 0; v < this->numVertices; v++)
      if (!this->listaAdjVazia (v)) {
        Aresta *adj = this->primeiroListaAdj (v);
        while (adj != NULL) {
          grafoT->insereAresta (adj->_v2 (), adj->_v1 (), adj->_peso ());
          delete adj;
          adj = this->proxAdj (v);
        }
      }
    return grafoT;
  }


  Grafo *Grafo::grafoNaoDirecionado () {
    Grafo *grafoND = new Grafo (this->numVertices); 
    for (int i= 0; i < this->numVertices; i++) {
      Celula *item = this->adj[i]._primeiro ();
      while (item != NULL) {
        grafoND->insereAresta (i, item->vertice, item->peso);
        grafoND->insereAresta (item->vertice, i, item->peso);
        item = this->adj[i].proximo ();
      }
    }
    return grafoND;
  }

  vector<int> Grafo::listaAdj(int v) {
    vector<int> lista;
    Celula *item = this->adj[v]._primeiro ();
    while (item != NULL) {
      lista.push_back(item->vertice);
      item = this->adj[v].proximo ();
    }
    return lista;
  }

  bool Grafo::existeCaminhoEuler(){
    for(int i = 0; i < this->numVertices; i++){
      if(this->listaAdj(i).size() % 2 != 0){
        return false;
      }
    }
    return true;
  }

  bool Grafo::existeCicloEuler(){
    for(int i = 0; i < this->numVertices; i++){
      if(this->listaAdj(i).size() == 0){
        return false;
      }
    }
    return true;
  }

  bool Grafo::direcionado(){
    for(int i = 0; i < this->numVertices; i++){
      Celula *item = this->adj[i]._primeiro ();
      while (item != NULL) {
        if(!this->existeAresta(item->vertice, i)){
          return true;
        }
        item = this->adj[i].proximo ();
      }
    }
    return false;
  }

  bool Grafo::autoloop(){
    for(int i = 0; i < this->numVertices; i++){
      if(this->existeAresta(i, i)){
        return true;
      }
    }
    return false;
  }

  bool Grafo::completo(){
    for(int i = 0; i < this->numVertices; i++){
      for(int j = 0; j < this->numVertices; j++){
        if(i != j){
          if(!this->existeAresta(i, j)){
            return false;
          }
        }
      }
    }
    return true;
  }

  void Grafo::buscaprofundidade(){ 
    int cor[this->numVertices], antecessor[this->numVertices];
    for (int i = 0; i < this->numVertices; i++)
    {
      cor[i] = 0;
      antecessor[i] = -1;
    }
    for(int i = 0; i < this->numVertices; i++){
      if(cor[i] == 0){
        visitaDFS(i, antecessor, cor);
      }
    }
  }

  void Grafo::visitaDFS(int u, int antecessor[], int cor[]){
    cor[u] = 1;
    cout << "Visitou: " << u << endl;
    vector<int> lista = this->listaAdj(u);
    for(int i = 0; i < lista.size(); i++){
      if(cor[lista.at(i)] == 0){
        antecessor[lista.at(i)] = u;
        visitaDFS(lista.at(i), antecessor, cor);
      }
    }
    cor[u] = 2;
    
  }

  void Grafo::buscaemlargura(){
    int cor[this->numVertices], antecessor[this->numVertices], dist[this->numVertices];
    for (int i = 0; i < this->numVertices; i++)
    {
      cor[i] = 0;
      dist[i] = 999;
      antecessor[i] = -1;
    }

    for(int i = 0; i < this->numVertices; i++){
      if(cor[i] == 0){
        visitaBFS(i, antecessor, dist, cor);
      }
    }
  }

  void Grafo::visitaBFS(int u, int antecessor[], int dist[], int cor[]){
    cor[u] = 1;
    dist[u] = 0;
    queue<int> fila;
    fila.push(u);
    cout << "Visitou: " << u <<endl;
    while(!fila.empty()){
      int v = fila.front();
      fila.pop();
      vector<int> lista = this->listaAdj(v);
      for(int i = 0; i < lista.size(); i++){
        if(cor[lista.at(i)] == 0){
          cout << "Visitou: " << lista.at(i)<<endl;
          cor[lista.at(i)] = 1;
          dist[lista.at(i)] = dist[v] + 1;
          antecessor[lista.at(i)] = v;
          fila.push(lista.at(i));
        }
      }
      cor[v] = 2;
    }
  }



  Grafo::~Grafo () {
    delete [] this->adj;
  }	  


		
