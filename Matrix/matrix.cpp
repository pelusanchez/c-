#include <iostream>
#include <vector>

class Matrix;


/**
	 m=1 m=2 m=3
 n = 1 | X   X   X |
 n = 2 | X   X   X |

std::vector<std::vector<float>> matriz = | std::vector<float> std::vector<float> std::vector<float> |

*/
class Matrix {
	std::vector<std::vector<float>> matriz; // Matriz
	int _m, _n; // Column, rows
	public:
		Matrix(std::vector<std::vector<float>> a);
		Matrix(int m, int n); // Crear matriz de mxn elementos
		float at(int m, int n); // Obtener elemento de la matrix m, n
		bool set(int m, int n, float data); // Poner data en la matrix m, n
		float det(); // Return determinant
		static float det(Matrix a){ // Return determinant
			std::cout<<"C: "<<a._n<<", R: "<<a._m<<"\n";
		}
		Matrix& operator+(const Matrix& elm2){
			Matrix *rtn = new Matrix(2,2);
			return *rtn;
		}
};

Matrix::Matrix(int m, int n){
	_m = m;
	_n = n;

	//Fill with zeroes
	matriz.resize(m);
	std::vector<float> c (n); // Fila para rellenar
	for(int mi = 0; mi<m; mi++){
		matriz.at(mi) = c;
	}
}

Matrix::Matrix(std::vector<std::vector<float>> a){
	matriz = a;
}

float Matrix::at(int m, int n){
	if(matriz.size()<=m && matriz.at(m).size()<=n){
		return matriz.at(m).at(n);
	}
}

bool Matrix::set(int m, int n, float data){
	if(matriz.size()<=m && matriz.at(m).size()<=n){
		matriz.at(m).at(n) = data;
		return true;
	}
	return false;
}


int main(){
	Matrix A(2,2);
	Matrix::det(A);
	return 0;
}
