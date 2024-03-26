#include "listaadj/Grafo.h" 
#include <fstream>
using namespace std;

void transposto (Grafo *grafo)
{
    Grafo *grafoT = grafo->grafoTransposto();
    grafoT->imprime();
}

void grafoNaoDirecionado (Grafo *grafo)
{
    Grafo *grafoND = grafo->grafoNaoDirecionado();
    grafoND->imprime();
}

void insereAresta (Grafo *grafo, int i, int j, int peso)
{
    if (grafo->existeAresta(i, j))
    {
        cout << "Aresta já existe" << endl;
    }
    else
    {
        cout << "Digite o peso da aresta: ";
        int peso;
        cin >> peso;
        grafo->insereAresta(i, j, peso);
        grafo->imprime();
    }
}

void removerAresta (Grafo *grafo, int i, int j)
{
    if (grafo->existeAresta(i, j))
    {
        grafo->retiraAresta(i, j);
        cout << "Aresta removida" << endl;
        grafo->imprime();
    }
    else
    {
        cout << "Aresta não existe" << endl;
    }
}

void listaAdjacente (Grafo *grafo, int i)
{
    vector<int> lista = grafo->listaAdj(i);
    for (int i=0; i < lista.size(); i++)
        cout << lista.at(i) << " ";
    cout << endl;
}

void caminhoEuler (Grafo *grafo)
{
    if (grafo->existeCaminhoEuler())
        cout << "Existe caminho de Euler" << endl;
    else
        cout << "Não existe caminho de Euler" << endl;
}

void cicloEuleriano (Grafo *grafo)
{
    if (grafo->existeCicloEuler())
        cout << "Existe ciclo de Euler" << endl;
    else
        cout << "Não existe ciclo de Euler" << endl;
}

void direcionado (Grafo *grafo)
{
    if (grafo->direcionado())
        cout << "Grafo direcionado" << endl;
    else
        cout << "Grafo não direcionado" << endl;
}

void autoloop (Grafo *grafo)
{
    if (grafo->autoloop())
        cout << "Existe autoloop" << endl;
    else
        cout << "Não existe autoloop" << endl;
}

void completo (Grafo *grafo)
{
    if (grafo->completo())
        cout << "Grafo completo" << endl;
    else
        cout << "Grafo não completo" << endl;
}

int main (int argc, char **argv) 
{
    ifstream in ("input.txt");
    Grafo *grafo = new Grafo (in);
    grafo->imprime ();  

    cout << endl; 

    //Ex1: criar e imprimir grafo transposto.

    //transposto(grafo);

    //Ex2: Criar e imprimir um grafo não orientado.

    //grafoNaoDirecionado(grafo);
    
    //Ex3: Ler e inserir nova aresta, verificando se ela já existe.
    int i, j;  
    /*cin >> i >> j;
    insereAresta(grafo, i, j, 0);
    
    cout << endl;
    //grafo->imprime();
   
    //Ex4: Ler e remover uma aresta, verificando se ela já existe.
    
    cin >> i >> j;
    removerAresta(grafo, 0, 1);
    

    //Ex5: Imprimir uma lista adjacente de um determinado vértices.

    listaAdjacente(grafo, 0);
    
    cout << endl;

    //Ex6: Verificando se existe caminho de euler
    caminhoEuler(grafo);
    
    
    //Ex7: Verificando se existe ciclo euleriano

    cicloEuleriano(grafo);

    //Ex7: Verificar se é direcionado

    direcionado(grafo);

    //Ex8: Verificar se existe autoloop

    autoloop(grafo);

    //Ex9: Verificar se é completo

    completo(grafo);

    //Busca profundidade

    cout << "Busca em profundidade" << endl;
    grafo->buscaprofundidade();

   //Busca em largura
   cout << "Busca em largura" << endl;
   grafo->buscaemlargura(); 

    */
   

}
