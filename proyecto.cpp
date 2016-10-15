//: C02:Hello.cpp
// Saying Hello with C++
#include <iostream> // Stream declarations
#include <fstream>
#include <stack>
#include <list>
#include <stdlib.h>  
#include <stdio.h> 
using namespace std;


 /**
 * hora de llegada del cliente a segundos
 *
 */
int sacarSegundosDeHora(string hora ){
  string hoora= hora.substr (4,2);
  string min = hora.substr (7,2);
  string seg = hora.substr (10,2);
  //cambiamos a numero
  int temHora = atoi(hoora.c_str());
  int personaColaMin =atoi(min.c_str());
  int personaColaSeg =atoi(seg.c_str());

   personaColaMin = (temHora*60)+personaColaMin;
   //cout<<"segunf: "<<personaColaSeg<<endl;
   return personaColaSeg = (personaColaMin*60)+personaColaSeg;
  
}

/**
* hora que tarda el cliente a segundos 
* @ hora un persona 
* @ return personaColaSeg convercion de segundos total
*/
int sacarSegundosTiempo(string hora){
string min = hora.substr (13,2);
string seg = hora.substr (16,2);
// hacemos el cambioa numeros
int personaColaMin =atoi(min.c_str());
int personaColaSeg =atoi(seg.c_str());
//sacamos  los segundos 1 min = 60 seg 
// sumamos a aloq ue ya teniamaos 
   return personaColaSeg =(personaColaMin*60)+personaColaSeg;

}

int sacarSegundosSalida(string b ){

  string hoora= b.substr (19,2);
  string min = b.substr (22,2);
  string seg = b.substr (25,2);
  //cambiamos a numero
  int temHora = atoi(hoora.c_str());
  int personaColaMin =atoi(min.c_str());
  int personaColaSeg =atoi(seg.c_str());
  personaColaMin = (temHora*60)+personaColaMin;
   //cout<<"segunf: "<<personaColaSeg<<endl;
   return personaColaSeg = (personaColaMin*60)+personaColaSeg;
}


/*
* saca el timepo a string para guardar en la lista
* @ seg total de segundos
* @ string hora hora en string
*/
string sacarHoraDeSegundos(int seg){
  string hora ;
  int horas = seg/3600;
  int minutos= (seg-(3600*horas))/60;
  int segundos =seg-((horas*3600)+(minutos*60));
  string h =to_string(horas);
  string m=to_string(minutos);;
  string s=to_string(segundos);;
  if(horas<10){
    h="0";
    string t= to_string(horas);
    h+=t;
  } 
  if(minutos<10){
    m="0";
    string t= to_string(minutos);
    m+=t;
  }
  if(segundos<10){
    s="0";
    string t= to_string(segundos);
    s+=t;
  }
  //cout<<h<<"-"<<m<<"-"<<s<<endl;
  hora =h+":"+m+":"+s;
  return hora;
  

}



/*
*
* modela un cajero  
* donde va contener un una lista de personas 
* id del cajero 
* obe
*
*/
class cajero {
  int idCajero ;
   list<string> listaPersonas;
   /**
   * metodods de la clase
   */
public:

  /*
  *  asigna un id a el objeto
  */
  void setIdCajero(int id ){
      idCajero = id;
  }

  /*
  *  obtiene el primer elemento sin eliminar
  *  por que vamos a meter elemtnos por enfrente 
  */
  string getU(){
    string t =listaPersonas.front(); 
    
   return t;

  }

  /*
  *  agrega un elemento al frente de la lista
  */
  void add( string cadena){
    listaPersonas.push_front(cadena);
  }

  /*
  * tamaño de la lista
  */
  int tamaño(){

    return listaPersonas.size();
  }


  /*
  * mostrar los elementos de la lista
  */
  void mostrarLista(){
     list<string>::iterator it = listaPersonas.begin();
    cout <<"-------"<<idCajero<<endl;
    while( it != listaPersonas.end() ){
      
      cout <<"" << *it++ << endl;

    }
    cout <<"*******"<<endl;
  }

  /*
  * 
  */
  int scarPromedio(){

    return 1;
  }


  /*
  * escribir un arichivo txt con el id de cada clase
  */
  void escribir(){
    ofstream fichero( "test-"+to_string(idCajero)+".txt");
    list<string>::iterator it = listaPersonas.begin();
    while( it != listaPersonas.end() ){
      fichero <<*it++<<endl; // escibe e incrementa 
    }
    fichero.close();
  }

  /*
  * muestra orden por  tipo de cliente  
  * con un pequeño formato en consola
  */
  void mostrar(){
    cout<<"----clientes: premium"<<endl;
    list<string>::iterator it = listaPersonas.begin();
    while( it != listaPersonas.end() ){
        string p = personaCola.substr(2,1);
        if( p == "P"){
          cout<<*it<<endl;
        }  
      it++;
    }
    fichero.close();
    


    cout<<"----clientes: normales"<<endl;
    list<string>::iterator it = listaPersonas.begin();
    while( it != listaPersonas.end() ){
        string p = personaCola.substr(2,1);
        if( p == "C"){
          cout<<*it<<endl;
        }  
      it++;
    }

    cout<<"----clientes: no clientes"<<endl;
    
    list<string>::iterator it = listaPersonas.begin();
    while( it != listaPersonas.end() ){
        string p = personaCola.substr(2,1);
        if(  == "N"){
          cout<<*it<<endl;
        }  
      it++;
    }
  }

};

// main 
int main(int argc, char **argv) {
  // atributos 
    string nombreFichero = argv[1];
    fstream ficheroEntrada;
    
    string frase;
    list<string> clientes;
    list<cajero> cajeros ;
    
    //10 min = 600 s
    // 30 min 1800 s
    
  
    /*
    * guarda la primer lia de el archivo que es el numero de 
    * cajeros 
    */ 
    ficheroEntrada.open (nombreFichero);
    getline(ficheroEntrada, frase);
    int numCajeros =atoi(frase.c_str());
    
     // arregllo de cajeros
    /*
    * guarda la segunda linea que es el numero de personas
    */
    getline(ficheroEntrada, frase);
    int personas =atoi(frase.c_str());
    // leer y guardar en un lista 
    for (int i = 0; i < personas; i++){
        getline(ficheroEntrada, frase);
        clientes.push_back(frase);  
    }
    /*
    * agrego a la lista  los primeros elentos
    */
    for (int i = 0; i < numCajeros; i++){ 
        cajero ca;
        ca.setIdCajero(i); // agrego id 
        string a = clientes.front();// persona       
        int timepoLLegada = sacarSegundosDeHora(a); 
        int timpoTarda = sacarSegundosTiempo(a);
        int tiempoSalida = timepoLLegada +timpoTarda;
        a+="-"+sacarHoraDeSegundos(tiempoSalida);
        ca.add(a);
        cout<<"per:"<<a<<endl;
        cajeros.push_front(ca); // meto un elemtno a  un cajero
        
        clientes.pop_front(); // elimino el ultimo , actilizo la lista
        
    }
    cout<<"tamño cajeros : "<<cajeros.size()<<endl;

    /**
    *  intentar recorrer
    */
    
    /*
    * acomodar por cajeros
    *
    **/


    list<string>::iterator it =clientes.begin();
    


    while(it != clientes.end() ){ // clientes se acaben  n 
      // *it  = valor iterador
      //list<string> l;
      //cout <<"s: "<< *it <<endl;
      list<cajero>::iterator itCajeros = cajeros.begin();
      while( itCajeros != cajeros.end()){ // recorrer numero cajeros m
            /**
            *
            *   datos de cliente de la cola
            */
            string personaCola = *it;
            int timepoLLegada = sacarSegundosDeHora(personaCola);
            int timpoMax =timepoLLegada-1; // mas una hora
            int timpoTarda = sacarSegundosTiempo(personaCola);
            string p = personaCola.substr(2,1); 
            if(p=="P"){
              timpoMax += 600;  
            }
            if(p== "C"){
              timpoMax += 1800;
            }
            /*
            * datos de el ultimo que esta usando el cajero
            */
            cajero te = *itCajeros;
            string x = te.getU(); // saca el ulitmo de del enfrete de la lista
            int ultimoSale = sacarSegundosSalida(x);

              
            cout <<"per: " <<x << " tarda en salir: " <<sacarHoraDeSegundos(ultimoSale)<<endl;
              //cout<<ultimoSale<<">"<<timpoMax<<endl;
            if(timpoMax > ultimoSale){

                        
            }else{
              
            }
            
        
        itCajeros++;
      }
      it++; // incrementa el iterador 
    }

    
    
    cout << nombreFichero<<endl;
  
  return 0;
} ///:~

/**
* 1 - num cajeros
* 2 - numero clientes
* 3-n clientes	
*/