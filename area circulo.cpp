#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double radio, area;
	
	cout <<"introduce el radio del circulo a continuacion: ";
	cin >> radio;
	
	//comentario chistoso
	area = M_PI * pow(radio, 2);
	
	cout <<"el area del circulo es: " << area << endl;
	
	return 0;
}
