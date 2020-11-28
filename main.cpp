#include <stdio.h> 
#include <math.h>
#include <iostream>

using namespace std;

/*
Problema 3

Método de Simpson 1/3, con n=2 */


double evaluate_problem3(float x){
    double result = sqrt(2+pow(x,2)) / sqrt(2-pow(x,2));
    return result;
}

void problem3_simpson(double  x_1, double  x_f, double  n){


    double h = abs((x_f -x_1)/n);

    double y_1 = evaluate_problem3(x_1);

    double first_sumatory=0;
    double second_sumatory=0;
    double y_i=0;
    double x_i=x_1;

    for(int i=2; i<= n+1; i++){
      x_i = x_i + h;
      y_i= evaluate_problem3(x_i);
      //Sumatoria de los resultados para iteraciones pares
      if (i%2==0){
        first_sumatory += y_i;
      }

      //Sumatoria que empieza a partir del y_3
       if (i%2!=0 && i!=n+1){
        second_sumatory += y_i;
      }

    }

    //Cuando sale del for el y_i final es el y de n+1

    double integral_result= (h/3)*(y_1 + 4*first_sumatory + 2*second_sumatory + y_i);

    cout<<"El resultado de la integral es: "<<integral_result;

}


/*
Problema 4

y' = x^4 + 0.4 x^2 -12x

Método de Euler: */

float evaluate(float x){
    float result = pow(x,4) + 0.4 * pow(x,2) - 12 * x;
    return result;
}

void problem4_euler(float x_0, float y_0, float x_f, float h){

    float* y_results = new float[int((x_f-x_0)/h)]; //Se crea el vector de resultados y
    float* x_results = new float[int((x_f-x_0)/h)]; //Se crea el vector para las x de cada y
    float x_i = x_0; 
    float y_i = y_0;

    y_results[0] = y_i;
    x_results[0] = x_i;
    float function_evaluated = evaluate(x_i); //Función evaluada en el x_0
    cout<<"x: "<<x_i <<" y: "<<y_i<<"\n";
    for(int i=0; i< int(x_f/h); i++){
        x_i = x_i + h;
        y_i = y_i + h * function_evaluated; //Aquí es la función evaluada en el paso anterior
        y_results[i+1] = y_i;
        x_results[i+1] = x_i;
        //cout<<"x: "<<x_i <<" y: "<<y_i<<"\n";
        cout<<y_i<<"\n";
        function_evaluated = evaluate(x_i); //Aquí se actualiza la función evaluada con el x actual, para la siguiente iteración
    }

}

/*Método de Runge-Kutta de cuarto orden*/

void problem4_runge(float x_0, float y_0, float x_f, float h){

    float* y_results = new float[int((x_f-x_0)/h)]; //Se crea el vector de resultados y
    float* x_results = new float[int((x_f-x_0)/h)]; //Se crea el vector para las x de cada y
    float x_i = x_0; 
    float y_i = y_0;

    y_results[0] = y_i;
    x_results[0] = x_i;
    float k1 = evaluate(x_i); //Función evaluada en el x_0
    float k2 = evaluate(x_i+(h/2));
    float k3 = evaluate(x_i+(h/2));
    float k4 = evaluate(x_i+h);

    cout<<y_i<<"\n";
    for(int i=0; i< int(x_f/h); i++){
        x_i = x_i + h;
        y_i = y_i + (h/6) *(k1 + 2*k2 + 2*k3 + k4); //Aquí es la función evaluada en el paso anterior con los valores de k de la iteración anterior
        y_results[i+1] = y_i;
        x_results[i+1] = x_i;
        //cout<<"x: "<<x_i <<" y: "<<y_i<<"\n";
        cout<<y_i<<"\n";

        //Aquí se actualiza k1, k2, k3, k4 con el x actual, para la siguiente iteración

        k1 = evaluate(x_i);
        k2 = evaluate(x_i+(h/2));
        k3 = evaluate(x_i+(h/2));
        k4 = evaluate(x_i+h);

    }

}



int main(int argc, char* argv[]){
    //problem4_euler(0,1,10,1);
    //problem4_runge(0,1,10,0.1);
    problem3_simpson(-1, 1, 10);
    return 0;
}