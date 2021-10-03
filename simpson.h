#ifndef SIMPSON_H
#define SIMPSON_H

#include <functional>

using::function;

class simpson {
public:
	
	simpson(function<double(double)> p_f,
			double p_a,
			double p_b): f(p_f), a(p_a), b(p_b) {
		
	}
	
	/**
	* @brief Calcula el valor de la integral usando el metodo de Simpson 1/3
	* @param n Cantidad de intervalos. Debe ser par
	* @return Valor de la integral con cantidad de intervalos especificados 
	*/
	double un_tercio(int n) {
		double resultado {0.0f};
		
		double x = a;
		double h = (b - a)/n;
		
		double s_impares = 0.0f;
		double s_pares = 0.0f;
		int cont;

		for(x = a + h, cont = 1; cont < n; cont++) {
			double y = f(x);
			
			if(cont %2 == 0) {
				s_pares += y;
			}else {
				s_impares += y;
			}
			x += h;
		}
		
		resultado = (h/3)*(f(a)+(4*s_impares)+(2*s_pares)+ f(b));
		
		return resultado;
	}
	
	/**
	* @brief Calcula el valor de la integral usando el metodo de Simpson 3/8
	* @param n Cantidad de intervalos. Debe ser impar
	* @return Valor de la integral con cantidad de intervalos especificados 
	*/
	
	double tres_octavos(int n) {
		double resultado {0.0f};
		
		double x = a;
		double h = (b - a)/n;
		
		double s_impares = 0.0f;
		double s_pares = 0.0f;
		int cont;
		
		for(x = a + h, cont = 1; cont < n; cont++) {
			double y = f(x);
			
			if(cont %3 == 0) {
				s_pares += y;
			}else {
				s_impares += y;
			}
			x += h;
		}
		
		resultado = ((3*h)/8)*(f(a)+(3*s_impares)+(2*s_pares)+ f(b));
		
		return resultado;
	}
	
private:
		function<double(double)> f;
			double a;
			double b;
			int n;
			
};
#endif
