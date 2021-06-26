#pragma once/**
@file Matrix.h
@brief Tutaj znajduje sie Matrix wraz z definicja.
*/

#include <iostream>
#include <cstdlib>
#include <cmath>


#define MIN 0.0000000001
template<int SIZE>
class Matrix {

private:
    double value[SIZE][SIZE];               ///< Wartosci macierzy

public:
    /**
    @brief konstruktor parametryczny
    @return Macierz wypelniona wartosciami podanymi w argumencie.  

    */
   
    Matrix(double [SIZE][SIZE]);            
     /**
    @brief konstruktor domyslny 
    @return Macierz wypelniona zerami 

    */
    Matrix();    

    Matrix(char wybor,double kat);                          

    Matrix operator + (Matrix tmp);  ///< przeciazony operator dodawania macierzy 

    Matrix operator * (Matrix tmp); ///< przeciazony operator mnozenia macierzy 
    /**
    @brief indeks macierzy 
    @return Wartosc macierzy w danym miejscu tablicy. 

    */    
    double  &operator () (unsigned int row, unsigned int column);
    template<int SIZE1>
    friend bool operator == (Matrix<SIZE1> mat1, Matrix<SIZE1> mat2); ///< przeciazony operator porownania macierzy 
    /**
    @brief indeks macierzy 
    @return Wartosc macierzy w danym miejscu tablicy jako stala.

    */  
    const double &operator () (unsigned int row, unsigned int column) const;

    void wsp_x(double kat);
    void wsp_y(double kat);
    void wsp_z(double kat);

    double wyznacznik_macierzy()const;

};
template<int SIZE>
std::istream &operator>>(std::istream &in, Matrix<SIZE> &mat);  ///< przeciazony operator wypisywania dla macierzy 
template<int SIZE>
std::ostream &operator<<(std::ostream &out, Matrix<SIZE> const &mat); ///< przeciazony operator wczytywania dla macierzy 


template<int SIZE>
Matrix<SIZE>::Matrix() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            value[i][j] = 0;
        }
    }
}


template<int SIZE>
Matrix<SIZE>::Matrix(double tmp[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            value[i][j] = tmp[i][j];
        }
    }
}

template<int SIZE>
double &Matrix<SIZE>::operator()(unsigned int row, unsigned int column) {

    if (row >= SIZE) {
       throw std::out_of_range("Error: Macierz jest poza zasiegiem");
    }

    if (column >= SIZE) {
        throw std::out_of_range("Error: Macierz jest poza zasiegiem");
    }

    return value[row][column];
}


template<int SIZE>
const double &Matrix<SIZE>::operator () (unsigned int row, unsigned int column) const {

    if (row >= SIZE) {
           throw std::out_of_range("Error: Macierz jest poza zasiegiem");
    }

    if (column >= SIZE) {
          throw std::out_of_range("Error: Macierz jest poza zasiegiem");
    }

    return value[row][column];
}


template<int SIZE>
Matrix<SIZE> Matrix<SIZE>::operator + (Matrix<SIZE> tmp) {
    Matrix<SIZE> result;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result(i, j) = this->value[i][j] + tmp(i, j);
        }
    }
    return result;
}
template<int SIZE>
Matrix<SIZE> Matrix<SIZE>::operator * (Matrix<SIZE> tmp){
Matrix<SIZE> wynik;
for (int i = 0; i < SIZE; ++i)
{
    for (int j = 0; j < SIZE; ++j)
    {
        for (int k = 0; k < SIZE; ++k)
        {
            wynik(i,j) += value[i][k] * tmp(k,j);
        }
    }
}
 return wynik;
}

template<int SIZE>
std::istream &operator>>(std::istream &in, Matrix<SIZE> &mat) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            in >> mat(i, j);
        }
    }
    return in;
}


template<int SIZE>
std::ostream &operator<<(std::ostream &out, const Matrix<SIZE> &mat) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            out << "| " << mat(i, j) << " | "; 
        }
        std::cout << std::endl;
    }
    return out;
}
template<int SIZE>
bool operator == (Matrix<SIZE> mat1, Matrix<SIZE> mat2)
{
    for (int i=0 ; i <SIZE ;i++)
    {
        for (int j=0 ; j <SIZE ;j++)
        {
            if (abs(mat1(i,j) - mat2(i,j)) > MIN)
            {   
                return false;
            }
        
        }
    }
    return true;
}
template <int SIZE>
void Matrix<SIZE> ::wsp_x(double kat){
double kat_radian;
kat_radian = M_PI * kat/180;

value[0][0]=1;
value[0][1]=0;
value[0][2]=0;
value[1][0]=0;
value[1][1]=cos(kat_radian);
value[1][2]=-sin(kat_radian);
value[2][0]=0;
value[2][1]=sin(kat_radian);
value[2][2]=cos(kat_radian);
}
template <int SIZE>
void Matrix<SIZE> ::wsp_y(double kat){
double kat_radian;
kat_radian = M_PI * kat/180;

value[0][0]=cos(kat_radian);
value[0][1]=0;
value[0][2]=sin(kat_radian);
value[1][0]=0;
value[1][1]=1;
value[1][2]=0;
value[2][0]=-sin(kat_radian);
value[2][1]=0;
value[2][2]=cos(kat_radian);
}

template <int SIZE>
void Matrix<SIZE> ::wsp_z(double kat){
double kat_radian;
kat_radian = M_PI * kat/180;

value[0][0]=cos(kat_radian);
value[0][1]=-sin(kat_radian);
value[0][2]=0;
value[1][0]=sin(kat_radian);
value[1][1]=cos(kat_radian);
value[1][2]=0;
value[2][0]=0;
value[2][1]=0;
value[2][2]=1;
}
template <int SIZE>
Matrix<SIZE>::Matrix(char wybor,double kat){
switch (wybor)
{
    case 'x':
        wsp_x(kat);
        break;
    case 'y':
        wsp_y(kat);
        break;
    case 'z':
        wsp_z(kat);
        break;
    default:
        break;
}
}
template <int SIZE>
double Matrix<SIZE> ::wyznacznik_macierzy()const{
double zmienna[SIZE][SIZE], wyznacznik;
double wynik = 1;
for(int i=0;i<SIZE;i++){
	for(int j=0;j<SIZE;j++){ 
		zmienna[i][j]=value[i][j];     
		}
	}
for(int i=0;i<SIZE;i++){
	if(zmienna[i][i] == 0.0){
		throw std::out_of_range("Blad liczenia macierzy");
		}
	for(int j=i+1;j<SIZE;j++){
		wyznacznik = zmienna[j][i]/zmienna[i][i];
	    for(int k=0;k<SIZE;k++){
		    zmienna[j][k] = zmienna[j][k] - wyznacznik*zmienna[i][k];         
		    }
	}
}
for(int i=0;i<SIZE;i++)
{	   
	wynik=zmienna[i][i]*wynik;  
}
return wynik;
}