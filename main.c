#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>
#define eps 0.00001 //�������


double left_rectangles(double a, double b, unsigned int N);     //�������� ������� ������� ���� ������������
double right_rectangles(double a, double b, unsigned int N);    //�������� ������� ������� ������ ������������
double trapezium (double a, double b, unsigned int N);          //�������� ������� ������� ��������
double simpson (double a, double b, unsigned int N);            //�������� ������� ������� ѳ������
double integral(double);                                        //�������� ������� ����������� ���������


int main()  // ������� ���������
{
    double a, b;
    int N, variant;
    double integral_sqare;


do // ����� �� �������� ���� ������������
    {
    printf("\nEnter left limit:");
    scanf("%lf", &a);
    printf("\nEnter right limit:");
    scanf("%lf", &b);
    }
while(a==b);

do // ����� �� �������� ������� �����
    {
    printf("\nEnter N(>0):");
    scanf("%u", &N);
    }
while(N<=0);

system("cls");
//----------------------------------------------------------------------------

    do {    // ���� ������
        printf("\nChoose method:\n");
        printf("\n1 = Left Rectangles method:");
        printf("\n2 = Right Rectangles method:");
        printf("\n3 = Trapezium method:");
        printf("\n4 = Simpson method:");
        printf("\nVariant:");
        scanf("%u", &variant);
    }
    while (variant!=1 &&variant!=2 &&variant!=3 &&variant!=4 );
system("cls");

//----------------------------------------------------------------------------

    switch(variant) // ���� ������ ������� �� ���������� �������
      {
          case 1:
              {
                  integral_sqare = left_rectangles(a, b, N);
                  printf("\n_________Left Rectangles method_________");
                  printf("\na = %.2lf \nb = %.2lf \nIntegral = %.5lf \nN = %d",a, b, integral_sqare, N);
              }
          break;


          case 2:
              {
                  integral_sqare = right_rectangles(a, b, N);
                  printf("\n_________Right Rectangles method_________");
                  printf("\na = %.2lf \nb = %.2lf \nIntegral = %.5lf \nN = %d",a, b, integral_sqare, N);
              }
          break;


          case 3:
              {
                  integral_sqare = trapezium(a, b, N);
                  printf("\n_________Trapezium method_________");
                  printf("\na = %.2lf \nb = %.2lf \nIntegral = %.5lf \nN = %d",a, b, integral_sqare, N);
              }
          break;


          case 4:
              {
                  integral_sqare = simpson(a, b, N);
                  printf("\n_________Simpson method_________");
                  printf("\na = %.2lf \nb = %.2lf \nIntegral = %.5lf \nN = %d",a, b, integral_sqare, N);
              }
          break;
            }
        return 0;
}


//------------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------------


double integral( double x ) // ������� ���������� ���������
        {
            return (0.25*pow(x,5)+4*pow((x+20),4)-2*x);
        }

//------------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------------


double left_rectangles(double a, double b, unsigned int N) //������� ������ ���� ������������
        {
            double integral_sqare, x, h;
            unsigned int i;
            h = (b - a) / N;
            x = a;
            for (i = 0; i < N; i++)
                { x += h; integral_sqare += integral(x);}
            return integral_sqare*h;
        }

//------------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------------


double right_rectangles(double a, double b, unsigned int N) //������� ������ ������ ������������
        {
            double integral_sqare, x, h;
            unsigned int i;
            h = (b - a) / N;
            x = a + h;
            for (i = 0; i <= N; i++)
                { x += h; integral_sqare += integral(x);}
            return integral_sqare * h;

        }

//------------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------------


double trapezium (double a, double b, unsigned int N) //������� ������ ��������
        {
            double integral_sqare, x , h;
            unsigned int i;
            h = (b - a) / N;
            x = a + h;
            for (i = 0; i <= (N - 1); i++)
                {x += h; integral_sqare += (integral(x) + integral(x + h)) / 2;}
            return integral_sqare * h;
        }

//------------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------------


double simpson (double a, double b, unsigned int N)  // ������ ������ �������
        {
            double sum1 , sum2 , h ;
            h = (b - a) / N;
            for (int i = 1; i <= (N - 1); i++)
                {
                    if (i%2!=0)
                    sum1 += integral(a + h * i);
                    else
                    sum2 += integral(a+ h * i);
                }
  return ((h / 3)*(integral(a) + integral(b) + 4 * sum1 + 2 * sum2));
        }
