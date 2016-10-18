#include <iostream> // Stream declarations
#include <sstream>
#include <fstream>
#include <stack>
#include <list>
#include <stdlib.h>  
#include <stdio.h> 
#include <vector>
using namespace std;

class cliente;
class caja;



class cliente {
    

public:
    bool operator == (const cliente& s) const { return idCliente == s.idCliente && tipoCliente == s.tipoCliente; }
    int getId ( void );
    string getTipoCliente ( void );
    string getHoraLlegada ( void );
    string getTiempoOp ( void );
    cliente(int id, string tipo, string hora, string tiemOp);
    cliente( void );

private:
    int idCliente;
    string tipoCliente;
    string horaLlegada;
    string tiempoOperacion;




};

cliente::cliente( void ){
    cout << "Se está creando un cliente" << endl; 
    idCliente = -1;  
}

cliente::cliente( int id, string tipo, string hora, string tiemOp)
{
    cout << "Se está creando un cliente" << endl;
    idCliente = id;
    tipoCliente = tipo;
    horaLlegada = hora;
    tiempoOperacion = tiemOp;
}
 
int cliente::getId( void )
{
    return idCliente;
}

string cliente::getTipoCliente ( void )
{
    return tipoCliente;
}

string cliente::getHoraLlegada ( void )
{
    return horaLlegada;
}

string cliente::getTiempoOp ( void )
{
    return tiempoOperacion;
}

class caja {

public:
    int getId( void );
    int getTiempoEspera( void );
    list<cliente> getPersonas ( void );
    void add( cliente cl );
    void masT( int tiem );
    cliente getU ( void );
    int tam ( void );
    caja (int id, int tiempoEspera);
    list<cliente> getListaPersonas( void );
private:
    int idCaja;
    int tiempoDeEspera;
    list<cliente> listaPersonas;
};

caja::caja( int id, int tiempoEspera )
{
    cout << "Se está creando una caja" << endl;
    idCaja = id;
    tiempoDeEspera = tiempoEspera;

}

int caja::getId ( void )
{
    return idCaja;
}

int caja::getTiempoEspera( void )
{
    return tiempoDeEspera;
}

list<cliente> caja::getListaPersonas ( void )
{
    return listaPersonas;
}

void caja::add( cliente cl)
{
    listaPersonas.push_front(cl);
}

void caja::masT( int tiem )
{
    tiempoDeEspera += tiem;
}

cliente caja::getU ( void )
{
    return listaPersonas.front();
}

int caja::tam ( void )
{
    return listaPersonas.size();
}

  /*
  * mostrar los elementos de la lista
  */
/*void caja::mostrarLista( void ){
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
/*int caja::scarPromedio( void ){

    return 1;
  }


  /*
  * escribir un arichivo txt con el id de cada clase
  */
/*void caja::escribir(){
    ofstream fichero( "test-"+to_string(idCajero)+".txt");
    list<string>::iterator it = listaPersonas.begin();
    while( it != listaPersonas.end() ){
      fichero <<*it++<<endl; // escibe e incrementa 
    }
    fichero.close();
  }*/

  /*
  * muestra orden por  tipo de cliente  
  * con un pequeño formato en consola
  */
/*void caja::mostrar(){
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
  }*/

caja getMenorT( list<caja> a )
{
    caja resultado(-1, -1);
    for (std::list<caja>::iterator it=a.begin(); it != a.end(); ++it){
        int tmp = resultado.getTiempoEspera();
        caja tmp3 = *it;
        if(tmp != -1){
            int tmp1 = tmp3.getTiempoEspera();
            cout<<"El tiempo de espera para " << tmp3.getId() << " es igual a "<< tmp3.getTiempoEspera()<<endl;
            if(tmp1 < tmp){
                resultado = tmp3;
            }
        }else{
            resultado = tmp3;
            cout<<"El tiempo de espera para " << tmp3.getId() << " es igual a "<< tmp3.getTiempoEspera()<<endl;
        }
    }
    return resultado;
}



list<caja> acomoda( list<caja> caj, list<cliente> clis, cliente cli)
{
    caja tmp = getMenorT(caj);
    int id = tmp.getId();
    int a = tmp.getId();
    int b = cli.getId();
    int f = std::stoi(cli.getTiempoOp());
    for (std::list<caja>::iterator it=caj.begin(); it != caj.end(); ++it)
    {
      if((*it).getId() == id){
        (*it).add(cli);
        (*it).masT(f);
      }
    }
    cout<<"Se agrega el cliente con id "<< b << " en la caja con id " << a << " se añade " << f << " segundos al tiempo de espera"  <<endl;
    return caj;
    /*switch ( cli.getTipoCliente() )
                          {
                             case "P":
                                acomodaP(caj, clis, cli);
                                break;
                             case "C":
                                acomodaC(caj, clis, cli);
                                break;
                             case "N":
                                acomodaN(caj, clis, cli);
                             default:
                                cout<<"Error"<<endl;
                                exit(1);
                          }*/

}

/*void acomodaP( list<caja> caj, list<cliente> clis, cliente cli){
    for (std::list<string>::iterator it=caj.begin(); it != caj.end(); ++it){
        //int esp = it*.getTiempoEspera();
        if((it*.getU()).empty()){
            it*.add(cli);
            it*.masT(cli.getTiempoOp());
        }
    }
    caja min = getMenorT(caj);
    if(min.getTiempoEspera() < 6000){
        min.add(cli);
    }else{
        acomodaD("P", min, cli);
    }

}

void acomodaC( list<caja> caj, list<cliente> clis, cliente cli){

}

void acomodaN( list<caja> caj, list<cliente> clis, cliente cli){

}*/

cliente getPrimero( list<cliente> a )
{
    int menor = 86399;
    cliente resultado;
    for (std::list<cliente>::iterator it=a.begin(); it != a.end(); ++it){
        cliente tmp = *it;
        int b = std::stoi(tmp.getHoraLlegada());
        int c = resultado.getId();
        if(c != -1){
            if(tmp.getHoraLlegada() == resultado.getHoraLlegada()){//Si llegan a la misma hora vemos quien tiene prioridad
                string ti = resultado.getTipoCliente();
                int tip;
                if(ti == "C"){
                    tip = 2;
                }else{
                    tip = 3;
                }
                switch ( tip )
                {//Si es de tipo P entonces se queda 
                    case 2:
                        if( tmp.getTipoCliente() == "P"){
                            resultado = tmp;    //Si es tipo C y el otro es P entonces se cambian
                        }
                        break;
                    case 3:
                        if(tmp.getTipoCliente() != "N"){
                            resultado = tmp;    //Si es tipo N entonces cualquiera que no sea de su tipo pasa antes
                        }
                        break;
                    default:
                        cout<<"Error en el tipo"<<endl;
                        exit(1);
                }
                

            }else{
                if(tmp.getHoraLlegada() < resultado.getHoraLlegada()){
                    resultado = tmp;
                }
            }
            
        }else{
            resultado = tmp;
        }
    }
    return resultado;

}

 /**
 * hora de llegada del cliente a segundos
 *
 */
int sacarSegundosDeHora(string hora ){
  string hoora= hora.substr (0,2);
  string min = hora.substr (3,2);
  string seg = hora.substr (6,2);
  //cambiamos a numero
  int temHora = atoi(hoora.c_str());
  int personaColaMin =atoi(min.c_str());
  int personaColaSeg =atoi(seg.c_str());

   //cout<<"segunf: "<<personaColaSeg<<endl;
   return personaColaSeg+(personaColaMin*60)+(temHora*3600);
  
}

/**
* hora que tarda el cliente a segundos 
* @ hora un persona 
* @ return personaColaSeg convercion de segundos total
*/
int sacarSegundosTiempo(string hora){
string min = hora.substr (0,2);
string seg = hora.substr (3,2);
// hacemos el cambioa numeros
int personaColaMin =atoi(min.c_str());
int personaColaSeg =atoi(seg.c_str());
//sacamos  los segundos 1 min = 60 seg 
// sumamos a aloq ue ya teniamaos 
   return personaColaSeg+(personaColaMin*60);

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

int main(int argc, char **argv) {
  // atributos 
    string nombreFichero = argv[1];
    fstream ficheroEntrada;
    std::vector<string> v;
    int i = 0;
    string arr[4];
    string frase;
    list<cliente> clientes;
    list<caja> cajeros ;
    
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
    for (int t = 0; t < personas; t++){
        getline(ficheroEntrada, frase);
        std::stringstream ss(frase);
        string i;
        while (ss >> i)
        {
            std::string::size_type e = i.find(",");
            while(e != std::string::npos){
              string a = i.substr(0, e);
              i = i.erase(0, e+1);
              v.push_back(a);
              e = i.find(",");
            }
            v.push_back(i);
        }
        int id = std::stoi( v.at(0) );
        int tiempo1 = sacarSegundosDeHora( v.at(2) );
        int tiempo2 = sacarSegundosTiempo( v.at(3) );
        string tipoCliente = v.at(1);
        cliente cl(id, tipoCliente, std::to_string(tiempo1), std::to_string(tiempo2));
        clientes.push_back(cl); 
        v.clear() ;
    }
    /*
    * agrego a la lista  los primeros elentos
    */
    for (int i = 0; i < numCajeros; i++){ 
        caja ca(i, 0);
        cajeros.push_back(ca);
        /*string a = clientes.front();// persona 
        int id = sacarId(a);
        int timepoLLegada = sacarSegundosDeHora(a); 
        int timpoTarda = sacarSegundosTiempo(a);
        string tipoCliente = sacarTipoCliente(a);      
        /*ca.setIdCajero(i); // agrego id 
        
        
        int tiempoSalida = timepoLLegada +timpoTarda;
        a+="-"+sacarHoraDeSegundos(tiempoSalida);
        ca.add(a);
        cout<<"per:"<<a<<endl;
        cajeros.push_front(ca); // meto un elemtno a  un cajero
        
        clientes.pop_front(); // elimino el ultimo , actilizo la lista*/
        
    }

    while(!(clientes.empty())){
        cliente primero = getPrimero( clientes );
        clientes.remove(primero);
        cajeros = acomoda(cajeros, clientes, primero);
        cout<< primero.getTipoCliente() <<endl;
    }
    cout<<"tamño cajeros : "<< cajeros.size()<<endl;
    /*caja a = cajeros.pop_front();
    list<cliente> b = a.getU();
    cliente c = b.pop_front();
    cliente d = b.pop_back();
    int e = c.getId();
    int f = d.getId();
    cout<< e <<endl;
    cout<< f <<endl;

    /**
    *  intentar recorrer
    */
    
    /*
    * acomodar por cajeros
    *
    **/


    /*list<string>::iterator it =clientes.begin();
    


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
            /*string personaCola = *it;
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
            /*cajero te = *itCajeros;
            string x = te.getU(); // saca el ulitmo de del enfrete de la lista
            int ultimoSale = sacarSegundosSalida(x);

              
            cout <<"per: " <<x << " tarda en salir: " <<sacarHoraDeSegundos(ultimoSale)<<endl;
              //cout<<ultimoSale<<">"<<timpoMax<<endl;
            if(timpoMax > ultimoSale){

                        
            }else{
              
            }
            
        
        itCajeros++;*/
      //}
      //it++; // incrementa el iterador 
    //}

    
    
    //cout << nombreFichero<<endl;
  
  return 0;
}