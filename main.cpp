#include<iostream>
#include<iomanip>
#include<cmath>
#include "trapecio.h"
#include "simpson.h"
#include "RombergMethod.h"




using std::cout;
using std::cin;
using std::endl;

const double ACCURACY = 1e-4;
const double STEP_SIZE = 1e-4;

int main (int argc, char *argv[]) {
	
	int n;
	trapecio t;
	double resultado =  t.integrar (
						[] (double x) -> double {
							return exp(x * x);
						}, 
						0.0f,
						1.0f,
						100
						); 
	
	cout << "INTEGRAL DE TRAPECIO " << std::setprecision(10) << resultado <<endl;
	cout << "------------------------------------------------------" <<endl;
	
	simpson s([] (double x) -> double {
		return exp(x * x);
		}, 
		0.0f,
		1.0f
		);
	
	
	cout << "\nINTEGRAL DE SIMPSON 1/3 " <<endl;
	do {
	cout << "Ingrese la cantidad de intervalos (debe ser par) " <<endl;
	cin >> n;
	} while(n <= 0 || (n %2 != 0));
	
	cout << "El resultado es: " << std::setprecision(10) << s.un_tercio(n) <<endl;
	
	cout << "------------------------------------------------------" <<endl;
	cout << "\nINTEGRAL DE SIMPSON 3/8 " <<endl;
	do {
		cout << "Ingrese la cantidad de intervalos (debe ser impar) " <<endl;
		cin >> n;
	} while(n <= 0 || (n %1 != 0));
	
	cout << "El resultado es: " << std::setprecision(10) << s.tres_octavos(n) <<endl;
	return 0;
	
	RombergMethod r(ACCURACY);
	double resultado_romberg = r.calculate([] (double x) -> double {
											return exp(x * x);
											},
										   0.0f,
										   1.0f
										   );
	cout << "INTEGRAL DE ROMBERG " << std::setprecision(10) << resultado_romberg <<endl;
	cout << "------------------------------------------------------" <<endl;
}

