#ifndef FRACTION_H_
#define FRACTION_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <bits/stdc++.h>
using namespace std;




namespace ariel{

    class Fraction
    {
    private:
        /* data */

        int _denomirator; // mekhni
        int _numerator; // moni

    public:

        Fraction(int numerator,int denomirator);
        ~Fraction();
        

        int getDenomirator() const{
            return this->_denomirator;
        }

        int getNumerator() const{
            return this->_numerator;
        }


        

        bool operator!() const;   
        Fraction& operator++();    
        Fraction operator++(int);
        Fraction& operator--();
        Fraction operator--(int);

        Fraction operator+(Fraction const &f);
        Fraction operator-(Fraction const &f);
        Fraction operator* (Fraction const &f);
        Fraction operator/ (Fraction const &f);


        bool operator== (const Fraction& f);
        bool operator>= (const Fraction& f1);
        bool operator> (const Fraction& f1);
        bool operator<(const Fraction& f1);
        bool operator<= (const Fraction& f);



        friend Fraction operator*(float number,Fraction const &f);
        friend Fraction operator*(Fraction const &f,float number);
        friend Fraction operator+(float number,Fraction const &f);
        friend Fraction operator+(Fraction const &f,float number);
        friend Fraction operator-(float number,Fraction const &f);
        friend Fraction operator-(Fraction const &f,float number);
        friend Fraction operator/(float number,Fraction const &f);
        friend Fraction operator/(Fraction const &f,float number);

        bool compare_float(float x, float y, float epsilon);


      

        friend bool operator>(const Fraction &f, float number);
        friend bool operator>(float number ,const Fraction &f);

        friend bool operator<(const Fraction &f, float number);
        friend bool operator<(float number, const Fraction &f);


        friend bool operator<=(float number,Fraction const &f);
        friend bool operator<=(Fraction const &f,float number);

      
        friend bool operator>=(float number,Fraction const &f);
        friend bool operator>=(Fraction const &f,float number);

        friend bool operator==(float number,Fraction const &f);
        friend bool operator==(Fraction const &f,float number);

        friend ostream& operator<< (ostream& output, const Fraction& f);


    };
    
   

};
#endif