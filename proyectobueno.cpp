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
class cajero;


/*
*
* Definir una clase que emule a un cliente 
*/
class cliente {
    

public:
    bool operator == (const cliente& s) const { return idCliente == s.idCliente && tipoCliente == s.tipoCliente; }
    int getId ( void );
    string getTipoCliente ( void );
    string getHoraLlegada ( void );
    string getTiempoOp ( void );
    string toString(void);
    cliente(int id, string tipo, string hora, string tiemOp);
    cliente( void );

/*
* atributos de la clase 
*/
private:
    int idCliente;
    string tipoCliente;
    string horaLlegada;
    string tiempoOperacion;




};
/*
*   constructor de la clase que no recibe parametros
*/
cliente::cliente( void ){
    // cout << "Se está creando un cliente" << endl; 
    idCliente = -1;  
}
/*
*   constructor de la clase que recibe parametros
* @param id  su identificador 
* @param tipo que tipo de cliente es 
* @param hora en que llega el cliente 
* @param tiem0p que tarda
*/
cliente::cliente( int id, string tipo, string hora, string tiemOp)
{
    //cout << "Se está creando un cliente" << endl;
    idCliente = id;
    tipoCliente = tipo;
    horaLlegada = hora;
    tiempoOperacion = tiemOp;
}
string toString(void)
{

   //string a =
return "" ;

}

/*
* @return id del cleinte
*/
int cliente::getId( void )
{
    return idCliente;
}

/*
* @return tipo de clinte
*/
string cliente::getTipoCliente ( void )
{
    return tipoCliente;
}

/*
* @return hora en que llego  el cliente
*/
string cliente::getHoraLlegada ( void )
{
    return horaLlegada;
}

/*
* @return tiempo que tarda el cliente en realizar la operacion 
*/
string cliente::getTiempoOp ( void )
{
    return tiempoOperacion;
}

/*
* clase que modela el cajero que va contener clientes
*/
class cajero {

/*
* metodos de la clase 
*/
public:
    int getId( void );
    int getTiempoEspera( void );
    list<cliente> getPersonas ( void );
    void add( cliente cl );
    void masT( int tiem );
    cliente getU ( void );
    int tam ( void );
    cajero (int id, int tiempoEspera);
    list<cliente> getListaPersonas( void );
    void crearArchivo(); 
    

/*
* atributos de la clase
*/
private:
    int idcajero;
    int tiempoDeEspera;
    
    list<cliente> listaPersonas;
};

/*
*
* creacion de el archivo con todos los elemtnos de la lista
*/

void cajero::crearArchivo()
{
  string nombreArchivo = "cajero"+to_string(getId())+".txt";

  ofstream escribir (nombreArchivo); // se crear archivo
  // recorrer la lista y escribir
  


  for (std::list<cliente>::iterator it = listaPersonas.begin();  it != listaPersonas.end(); ++it){
    
    cliente t = *it;
    
    string x = to_string(t.getId())+","+t.getHoraLlegada()+","+t.getTiempoOp()+","+t.getTipoCliente();
    cout <<x<<endl;
    escribir <<x<<endl;  
  }
  


  escribir.close();


}


/*
*  contructor de la clase 
* @param id numero de cajero
* @param tiempoEspera tiempor que va a tardar un cliente 
*/
cajero::cajero( int id, int tiempoEspera )
{
    //cout << "Se está creando una cajero" << endl;
    idcajero = id;
    tiempoDeEspera = tiempoEspera;

}
/*
* 
* @return regresa el numero de el cajero
*/
int cajero::getId ( void )
{
    return idcajero;
}

/*
* @return un tiempo de espera
*/
int cajero::getTiempoEspera( void )
{
    return tiempoDeEspera;
}
/*
* @return la lista que contiene todos los clientes
*/
list<cliente> cajero::getListaPersonas ( void )
{
    return listaPersonas;
}

/*
* 
*  @param agrega a un cliente a la 
*/
void cajero::add( cliente cl)
{
    listaPersonas.push_front(cl);
 
}

/*
*  @param aumenta al tiempo de espero el timepo que tarda 
*/
void cajero::masT( int tiem )
{
    tiempoDeEspera += tiem;
}
/*
* @return regrelsa 
*/
cliente cajero::getU ( void )
{
    return listaPersonas.front();
}
/*
* @return regresa el tamaño de la lista 
*/
int cajero::tam ( void )
{
    return listaPersonas.size();
}


/*
* @return regresa el menor de la lista 
*/
cajero getMenorT( list<cajero> a )
{
    cajero resultado(-1, -1); // crear un objeto vac
    for (std::list<cajero>::iterator it=a.begin(); it != a.end(); ++it){
        int tmp = resultado.getTiempoEspera(); // asigno valor a 
        cajero tmp3 = *it;
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


/*
* @return
*/
list<cajero> acomoda( list<cajero> caj, list<cliente> clis, cliente cli)
{
    cajero tmp = getMenorT(caj);
    int id = tmp.getId();
    int a = tmp.getId();
    int b = cli.getId();
    int f = std::stoi(cli.getTiempoOp());
    for (std::list<cajero>::iterator it=caj.begin(); it != caj.end(); ++it)
    {
      if((*it).getId() == id){
        (*it).add(cli);
        (*it).masT(f);
      }
    }
    cout<<"Se agrega el cliente con id "<< b << " en la cajero con id " << a << " se añade " << f << " segundos al tiempo de espera"  <<endl;
    return caj;
    

}



/*
*  tomar 
* @return
*/
cliente getPrimero( list<cliente> a )
{
    
    cliente resultado;
    for (std::list<cliente>::iterator it=a.begin(); it != a.end(); ++it){ // recorido de los clientes 
        cliente tmp = *it; // tomar un temporal 
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
 * @return
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



/*
*
* man 
*/

int main(int argc, char **argv) {
  // atributos 
    string nombreFichero = argv[1];
    fstream ficheroEntrada;
    std::vector<string> v;
    int i = 0;
    string arr[4];
    string frase;
    list<cliente> clientes;
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
    for (int t = 0; t < personas; t++){
        getline(ficheroEntrada, frase);
        std::stringstream ss(frase);
        string i;
        while (ss >> i)
        {
            std::string::size_type e = i.find(",");
            while(e != std::string::npos){
              string a = i.substr(0, e);
              cout << a <<endl;
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
        cajero ca(i, 0);
        cajeros.push_back(ca);
    }
    /*
    * recorro la lista de clientes 
    */
    while(!(clientes.empty())){
        cliente primero = getPrimero( clientes );
        clientes.remove(primero);
        cajeros = acomoda(cajeros, clientes, primero);
        cout<< primero.getTipoCliente() <<endl;
    }
    cout<<"tamño cajeros : "<< cajeros.size()<<endl;
  
  
  return 0;
}