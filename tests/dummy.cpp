#include "doctest.h"
#include "Vector.h"
#include "prostopadloscian.h"
#include "Matrix.h"
#include <sstream>

TEST_CASE("konstruktor domyslny wektor")
{
  Vector< 3> wek1;
  Vector< 3> wek2;
  wek1[0] = 0;
  wek1[1] = 0;
  wek1[2] = 0;

  CHECK_EQ(wek1, wek2);
}
TEST_CASE("konstruktor parametryczny  wektor")
{
  double a[3] = {1,1,2};
  Vector< 3> wek1;
  Vector< 3> wek2(a);
  
  wek1[0] = 1;
  wek1[1] = 1;
  wek1[2] = 2;

  CHECK_EQ(wek1, wek2);
}
TEST_CASE("<<")
{
  std::stringstream ss;

  Vector< 3> wek1;
  ss <<wek1;
  

  CHECK_EQ(ss.str(), "0 0 0 ");
}
TEST_CASE(">>")
{
  std::stringstream ss;

  Vector< 3> wek1;
  Vector< 3> wek2;
  ss <<"2 2 3 ";
  ss >> wek1;
  wek2[0] = 2;
  wek2[1] = 2;
  wek2[2] = 3;
  

  CHECK_EQ(wek1, wek2);
}
TEST_CASE("ideks")
{
  Vector< 3> wek2;
  wek2[0] = 2;
  wek2[1] = 2;
  wek2[2] = 3;
  CHECK_EQ(wek2[2], 3);
}
TEST_CASE("poza indeksem")
{
  Vector< 3> wek2;
  wek2[0] = 2;
  wek2[1] = 2;
  wek2[2] = 3;
  WARN_THROWS(wek2[3]);
}
TEST_CASE(" indeks z constem")
{
  Vector< 3> wek2;
  const double b = wek2[0];
  CHECK_EQ(b, 0);
}
TEST_CASE("Macierz domyslny")
{
  Matrix< 3> m1, m2;
  m2(0,0) = 0;
  m2(0,1) = 0;
  m2(0,2) = 0;
  m2(1,0) = 0;
  m2(1,1) = 0;
  m2(1,2) = 0;
  m2(2,0) = 0;
  m2(2,1) = 0;
  m2(2,2) = 0;
  CHECK_EQ(m1, m2);
}
TEST_CASE("Macierz parametryczna")
{
  double dwu[3][3];
  dwu[0][0] = 0;
  dwu[0][1] = 0;
  dwu[0][2] = 0;
  dwu[1][0] = 0;
  dwu[1][1] = 0;
  dwu[1][2] = 0;
  dwu[2][0] = 0;
  dwu[2][1] = 0;
  dwu[2][2] = 0;
  Matrix< 3> m1,m2(dwu);
  
  CHECK_EQ(m1, m2);
}
TEST_CASE("Macierz x Wektor")
{
  Matrix< 3> m1;
  Vector< 3> a1, wynik;
  wynik[0] = 14;
  wynik[1] = 21;
  wynik[2] = 11;
  a1[0] = 2;
  a1[1] = 3;
  a1[2] = 2;
  m1(0,0) = 1;
  m1(0,1) = 2;
  m1(0,2) = 3;
  m1(1,0) = 4;
  m1(1,1) = 3;
  m1(1,2) = 2;
  m1(2,0) = 2;
  m1(2,1) = 1;
  m1(2,2) = 2;
  CHECK_EQ(m1*a1, wynik);
}
TEST_CASE("Macierz indeks bez const")
{
  Matrix< 3> m1;
  m1(0,0) = 1;
  m1(0,1) = 2;
  m1(1,0) = 3;
  m1(1,1) = 2;

  CHECK_EQ(m1(1,0), 3);
}
TEST_CASE("Macierz indeks z consta")
{
  Matrix< 3> m1;
  const double b = m1(0,0);
 
  CHECK_EQ(b, 0);
}

TEST_CASE("Macierz x Macierz")
{
  Matrix< 3> mat1, mat2, mat3;
  mat1(0,0) = 1;
  mat1(0,1) = 2;
  mat1(0,2) = 3;
  mat1(1,0) = 4;
  mat1(1,1) = 3;
  mat1(1,2) = 2;
  mat1(2,0) = 2;
  mat1(2,1) = 1;
  mat1(2,2) = 2;

  mat2(0,0) = 2;
  mat2(0,1) = 4;
  mat2(0,2) = 3;
  mat2(1,0) = 3;
  mat2(1,1) = 2;
  mat2(1,2) = 2;
  mat2(2,0) = 2;
  mat2(2,1) = 1;
  mat2(2,2) = 1;

  mat3(0,0) = 14;
  mat3(0,1) = 11;
  mat3(0,2) = 10;
  mat3(1,0) = 21;
  mat3(1,1) = 24;
  mat3(1,2) = 20;
  mat3(2,0) = 11;
  mat3(2,1) = 12;
  mat3(2,2) = 10;

  CHECK_EQ(mat1*mat2, mat3);
}