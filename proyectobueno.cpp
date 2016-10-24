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
    string sacarHoraDeSegundos(int seg);
    string sacarMinDeSegundos(int seg);

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
* cambiar segundos a horas
* @ seg total de segundos
* @ string hora hora en string
* @ complejidad  O()=O(c) por que solo hace operaciones elementales
*/
string cliente::sacarHoraDeSegundos(int seg){
  string hora ;
  int horas = seg/3600; // 2 
  int minutos= (seg-(3600*horas))/60; //4
  int segundos =seg-((horas*3600)+(minutos*60)); //
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
* sacar el numero de segundos a minutos
* @ seg total de segundos
* @ string hora hora en string
* @ complejidad O(c) por que hace operaciones elementales
*/
string cliente::sacarMinDeSegundos(int seg){
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
  hora = m+":"+s;
  return hora;

}
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
* @ complejidad O(c) solo hace asignaciones 
*/
cliente::cliente( int id, string tipo, string hora, string tiemOp)
{
    //cout << "Se está creando un cliente" << endl;
    idCliente = id;
    tipoCliente = tipo;
    horaLlegada = hora;
    tiempoOperacion = tiemOp;
}


/*
* @return id del cleinte
* @ complejidad O(c) hace una asiganacion 
*/
int cliente::getId( void )
{
    return idCliente;
}

/*
* @return tipo de clinte
* @ complejidad O(c)
*/
string cliente::getTipoCliente ( void )
{
    return tipoCliente;
}

/*
* @return hora en que llego  el cliente
* @ complejidad O(c)
*/
string cliente::getHoraLlegada ( void )
{
  int a =atoi(horaLlegada.c_str());
  return sacarHoraDeSegundos(a);
    
}

/*
* @return tiempo que tarda el cliente en realizar la operacion 
* @ complejidad O(c)
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
    void crearArchivo(void); 
    void mostrar(void);

    
    

/*
* atributos de la clase
*/
private:
    int idcajero;
    int tiempoDeEspera;
    
    list<cliente> listaPersonas;
};

/**
* muestra los elementos de los cajeros segun su tipo
* @ complejidad O(3n) = O(n) 

*/
void cajero::mostrar(){
    cout<<"cajero con el id:"<<getId()<<endl;
    cout<<"-------premium---------"<<endl;
// O(n)   recorre toda la lista que tiene tamaño n 
  for (std::list<cliente>::iterator it = listaPersonas.begin();  it != listaPersonas.end(); ++it){
    cliente t =*it;
    string tipo =t.getTipoCliente();
    if(tipo=="P"){
       int a =atoi(t.getTiempoOp().c_str());
        string tempor = t.sacarMinDeSegundos(a);
      cout<<to_string(t.getId())+","+t.getHoraLlegada()+","+tempor+","+t.getTipoCliente()<<endl;
    }

    }
    cout<<"-------Clientes---------"<<endl;
    // O(n)   recorre toda la lista que tiene tamaño n 
    for (std::list<cliente>::iterator it = listaPersonas.begin();  it != listaPersonas.end(); ++it){
    cliente t =*it;
    string tipo =t.getTipoCliente();
    if(tipo=="C"){
      int a =atoi(t.getTiempoOp().c_str());
        string tempor = t.sacarMinDeSegundos(a);
      cout<<to_string(t.getId())+","+t.getHoraLlegada()+","+tempor+","+t.getTipoCliente()<<endl;
    }

    }

    cout<<"-------No-Clientes---------"<<endl;
    // O(n)   recorre toda la lista que tiene tamaño n 
    for (std::list<cliente>::iterator it = listaPersonas.begin();  it != listaPersonas.end(); ++it){
    cliente t =*it;
    string tipo =t.getTipoCliente();
    if(tipo=="N"){
      int a =atoi(t.getTiempoOp().c_str());
        string tempor = t.sacarMinDeSegundos(a);
      cout<<to_string(t.getId())+","+t.getHoraLlegada()+","+tempor+","+t.getTipoCliente()<<endl;
    }

    }
}
/*
*
* creacion de el archivo con todos los elemtnos de la lista
* @ complejidad O(2n)
*/

void cajero::crearArchivo(void )
{
  string nombreArchivo = "cajero"+to_string(getId())+".txt";

  ofstream escribir (nombreArchivo); // se crear archivo
  // recorrer la lista y escribir

// suponemos que la reversa cuesta n 
  listaPersonas.reverse();

// @ complejidad O(n) recorremos la lista 
  for (std::list<cliente>::iterator it = listaPersonas.begin();  it != listaPersonas.end(); ++it){
    
    cliente t = *it;
    int a =atoi(t.getTiempoOp().c_str());
        string tempor = t.sacarMinDeSegundos(a);
    string x =   to_string(t.getId())+","+t.getHoraLlegada()+","+tempor+","+t.getTipoCliente();
    
   // cout <<x<<endl;
    escribir <<x<<endl;  
  }
  
  escribir.close();

}



/*
*  contructor de la clase 
* @param id numero de cajero
* @param tiempoEspera tiempor que va a tardar un cliente 
* @ complejidad O(c)
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
* @ complejidad O(c)
*/
int cajero::getId ( void )
{
    return idcajero;
}

/*
* @return un tiempo de espera
* @ complejidad O(c)
*/
int cajero::getTiempoEspera( void )
{
    return tiempoDeEspera;
}
/*
* @return la lista que contiene todos los clientes
* @ complejidad O(c)
*/
list<cliente> cajero::getListaPersonas ( void )
{
    return listaPersonas;
}

/*
* 
*  @param agrega a un cliente a la 
* @ complejidad O(c)
*/
void cajero::add( cliente cl)
{
    listaPersonas.push_front(cl);
 
}

/*
*  @param aumenta al tiempo de espero el timepo que tarda 
* @ complejidad O(c)
*/
void cajero::masT( int tiem )
{
    tiempoDeEspera += tiem;
}
/*
* @return regrelsa 
* @ complejidad O(c)
*/
cliente cajero::getU ( void )
{
    return listaPersonas.front();
}
/*
* @return regresa el tamaño de la lista 
* @ complejidad O(c)
*/
int cajero::tam ( void )
{
    return listaPersonas.size();
}


/*
* @return regresa el menor de la lista 
* @ complejidad O(m)
*/
cajero getMenorT( list<cajero> a )
{
    cajero resultado(-1, -1); // crear un objeto vac
    for (std::list<cajero>::iterator it=a.begin(); it != a.end(); ++it){
        int tmp = resultado.getTiempoEspera(); // asigno valor a 
        cajero tmp3 = *it;
        if(tmp != -1){
            int tmp1 = tmp3.getTiempoEspera();
            //cout<<"El tiempo de espera para " << tmp3.getId() << " es igual a "<< tmp3.getTiempoEspera()<<endl;
            if(tmp1 < tmp){
                resultado = tmp3;
            }
        }else{
            resultado = tmp3;
            //cout<<"El tiempo de espera para " << tmp3.getId() << " es igual a "<< tmp3.getTiempoEspera()<<endl;
        }
    }
    return resultado;
}


/*
* @return la lista con cajeros acomodados 
* @ complejidad O(n)
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
*  tomar el primer cliente que llega al mismo tiempo segun el tipo de cliente
* @return el cliente segun el quien llega primero
* @ complejidad O(n) 
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
* tomar 
* @return  segundos 
* @ complejidad O(m)
*/
int getPrimeraHora(int id, list<cajero> a)
{
  int resultado;
  for (std::list<cajero>::iterator it=a.begin(); it != a.end(); ++it)
  {
    if((*it).getId() == id){
      list<cliente> tmp = (*it).getListaPersonas();
      cliente tmp1 = tmp.front();
      cliente tmp2 = tmp.back();
      int primero = std::stoi(tmp1.getHoraLlegada());
      int ultimo = std::stoi(tmp2.getHoraLlegada());
      int espera = (*it).getTiempoEspera();
      resultado = (primero + espera) - ultimo;
    }
  }
  return resultado;
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
    list<cajero> cajeros;
    int suma = 0;
    float promedio = 0.0;
    
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
             // cout <<"a es :"<< a <<endl;
              i = i.erase(0, e+1);
              v.push_back(a);
              e = i.find(",");
              //cout<<e<<endl;
            }
            //cout<<i<<endl;
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
    * 
    */
    for (int i = 0; i < numCajeros; i++){ 
        cajero ca(i, 0);
        cajeros.push_back(ca);
    }
    /*
    * recorro la lista de clientes 
    * @ complejidad O(n)
    */
    while(!(clientes.empty())){
        cliente primero = getPrimero( clientes );
        clientes.remove(primero);
        cajeros = acomoda(cajeros, clientes, primero);
        
       // cout<< primero.getTipoCliente() <<endl;
    }


    for(int r = 0; r < numCajeros; r++)
    {
      int hora = getPrimeraHora(r, cajeros);
      suma = suma + hora;
    }
    promedio = suma/numCajeros;
    int minuto = promedio/60;
    promedio = promedio - (minuto*60);
    cout<< "--------------promedio general---------------"<<endl;
    cout<<"En promedio tomará : "<< minuto << " minutos y "<<promedio<<" segundos" <<endl;
    
    // clase cajero
    // recorrer list<cajero> cajeros;
    cout<<"::::::::::::::::::::mostrar por tipo de cleinte en cada cajero:::::::::::::::::::"<<endl;
    //* @ complejidad O(m*n^2)
    for (std::list<cajero>::iterator it = cajeros.begin();  it != cajeros.end(); ++it){
      //  m en recorrer cajeros
      
      cajero x = *it;
    x.crearArchivo(); // n clientes
    x.mostrar(); // 3n  clientes
    }
    cout<<":............Comeplidad...........:"<<endl;
    cout<<"O(m*n^2)\ndonde m son los cajeros y n los clientes"<<endl;
  
  
  return 0;
}