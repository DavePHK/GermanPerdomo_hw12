#include <iostream>

using std::cout;
using std::endl;

//Se definen funciones
void cond_in(double *y, double x_min, double dx, int n);
void evolucion(double *Y, double *y_old, int n, double dx, double dt, double c);
void copia(double *Y, double *y_old, int n);

//Condicion inicial
void cond_in(double *y, double x_min, double dx, int n){
  int i;
  double x;
  for(i=0;i<n;i++){
    x = x_min +  i * dx;
    if(x<0.5 && x>-0.5){
      y[i] = 0.5;
    }else{
      y[i] = 0.0;
    }
  }
}

//Evoluciona la funcion. Se utiliza un arreglo diferente para guardar los valores modificados
void evolucion(double *Y, double *y_old, int n, double dx, double dt, double c){
  int i;
  for(i=1;i<n-1;i++){
    Y[i] = y_old[i] - c*(dt/dx)*(y_old[i] - y_old[i-1]);
  }
}

//explicacion en el main
void copia(double *y1, double *y2, int n){
  int i;
  for(i=0;i<n;i++){
    y1[i] = y2[i];
  }
}
 //Funcion main
int main(){
  //Definicion de variables
  double x_min=-2.0, x_max=2.0;
  double dt = 0.001, dx=0.002; 
  int Nx = (x_max -x_min)/dx + 1;
  int Nt=700;
  double t=0.0;
  double c=1.0;  
  double * y_old = new double[Nx];
  double * Y = new double[Nx];
  //inicializa la condicion inicial en u_old
  cond_in(y_old, x_min, dx, Nx);

  for(int i = 0;i<Nt;i++){
    if((i%(700/4))==0){
      for(int j=0;j<Nx;j++){
        cout<<y_old[j]<<" ";
      }
      cout<< endl;
    }
    evolucion(Y, y_old, Nx, dx, dt, c);
    //ahora u_old va a ser la evolucion en un tiempo j+1, para modificar j+2
    copia(y_old, Y, Nx);    
    t += dt;    
  }
  
  return 0;
}
