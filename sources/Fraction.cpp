#include "Fraction.hpp"
#include <cstring>
#include <cmath>
using namespace std;

// using namespace ariel;

namespace ariel{


   Fraction::Fraction(int numerator,int denomirator):_numerator(numerator),_denomirator(denomirator){

         
            if(this->_denomirator==0 && this->_numerator==0)
                throw runtime_error("zero zero !!");
            
            // this->_numerator = numerator;
            // this->_denomirator = denomirator;

        };


  Fraction::~Fraction()
        {
        }



// Recursive function to
// return GCD of a and b

int gcd(int a, int b) {
   int minN = min(a,b);
    int res = 1;

    for(int i=1; i<=minN; i++){
        if(a%i==0 && b%i==0)
            res =i;
    }

    return res;

}


Fraction decimalToFraction(double number, int cycles = 10, double precision = 5e-2){
    int sign  = number > 0 ? 1 : -1;
    number = number * sign; //abs(number);
    double new_number,whole_part;
    double decimal_part =  number - (int)number;
    int counter = 0;
    
    valarray<double> vec_1{double((int) number), 1}, vec_2{1,0}, temporary;
    
    while(decimal_part > precision & counter < cycles){
        new_number = 1 / decimal_part;
        whole_part = (int) new_number;
        
        temporary = vec_1;
        vec_1 = whole_part * vec_1 + vec_2;
        vec_2 = temporary;
        
        decimal_part = new_number - whole_part;
        counter += 1;
    }

    // cout<<"x: "<< number <<"\tFraction: " << sign * vec_1[0]<<'/'<< vec_1[1]<<endl;
    double nur = sign * vec_1[0];
    double deno = vec_1[1];

    //cout << nur << "/" << deno<<endl;
   
    return  Fraction(nur,deno);
}



///////////////////////////////


    bool Fraction::operator!() const{ // to check if the mekhni equal to zero or ont
            return _numerator==0;
        }

       



    Fraction& Fraction::operator++(){ // ++n
            
            this->_numerator = this->_numerator + this->_denomirator;

            return *this;

         }
            
           
    Fraction Fraction::operator++(int){ // n++

            Fraction cpy = *this;
            this->_numerator = this->_numerator + this->_denomirator;
            return cpy;

         } 


    Fraction& Fraction::operator--(){ // --n
            
            this->_numerator = this->_numerator - this->_denomirator;

            return *this;

         }
            
           
    Fraction Fraction::operator--(int){ // n--

            Fraction cpy = *this;
            this->_numerator = this->_numerator - this->_denomirator;
            return cpy;

         } 




//////////////////////////////  operator +


   Fraction Fraction::operator+(ariel::Fraction const &f){

            int new_numerator1 = this->getNumerator()  * f.getDenomirator();
            int new_numerator2 = f.getNumerator()* this->getDenomirator();
            int new_numerator = new_numerator1 + new_numerator2;
            int new_denomirator = this->getDenomirator() * f.getDenomirator();

           int l = gcd(new_denomirator,new_numerator);

        return Fraction(new_numerator/l,new_denomirator/l);

         }

     Fraction operator+(float number,Fraction const &f){

       
        Fraction f2 =  decimalToFraction(number);
        Fraction f3  (f2.getNumerator(),f2.getDenomirator());

          int new_numerator1 = f3.getNumerator()  * f.getDenomirator();
            int new_numerator2 = f.getNumerator()* f3.getDenomirator();
            int new_numerator = new_numerator1 + new_numerator2;
            int new_denomirator = f3.getDenomirator() * f.getDenomirator();

           int l = gcd(new_denomirator,new_numerator);

        return Fraction(new_numerator/l,new_denomirator/l);


     }

     Fraction operator+(Fraction const &f,float number){

        
        return operator+(number,f);

     }


///////////////////////////////////////// operator -
      Fraction Fraction::operator-(ariel::Fraction const &f){

            int new_numerator1 = this->getNumerator()  * f.getDenomirator();
            int new_numerator2 = f.getNumerator()* this->getDenomirator();
            int new_numerator = new_numerator1 - new_numerator2;
            int new_denomirator = this->getDenomirator() * f.getDenomirator();
           int l = gcd(new_denomirator,new_numerator);

        return Fraction(new_numerator/l,new_denomirator/l);
}

    Fraction operator-(float number,Fraction const &f){

        Fraction f2 =  decimalToFraction(number);

        return (f2).operator-(f);

     }

   Fraction operator-(Fraction const &f,float number){

        Fraction f2 =  decimalToFraction(number);

        Fraction res =  operator-(number,f);
            Fraction meunsOne (-1,1);

             res = res.operator*(meunsOne);

        return res;

        // return Fraction(new_numerator/l,new_denomirator/l);

     }



///////////////////////////////////////// operator *




    Fraction Fraction::operator*(ariel::Fraction const &f){

             if((*this).getDenomirator()==0 || f.getDenomirator()==0)
                throw runtime_error("Error get denomrator equal to zero!! "); 

           int l = gcd(this->getNumerator()*f.getNumerator(),this->getDenomirator()*f.getDenomirator());

         return Fraction((this->getNumerator()*f.getNumerator())/l,(this->getDenomirator()*f.getDenomirator())/l);

         }


 Fraction operator*(float number,ariel::Fraction const &f){

     Fraction f2 =  decimalToFraction(number);
        
        return (f2).operator*(f);

     }

 Fraction operator*(ariel::Fraction const &f,float number){

        return operator*(number,f);
        
     }


///////////////////////////////////////// operator /





    Fraction Fraction::operator/(ariel::Fraction const &f){

             if((*this).getDenomirator()==0 || f.getDenomirator()==0 || !f)
                throw runtime_error("Error get denomrator equal to zero!! "); 

            int l = gcd(this->getNumerator()*f.getDenomirator(),this->getDenomirator()*f.getNumerator());


            return Fraction((this->getNumerator()*f.getDenomirator())/l,(this->getDenomirator()*f.getNumerator())/l);

         }

   
    Fraction operator/(float number,ariel::Fraction const &f){

            Fraction f2 =  decimalToFraction(number);
        
        return (f2).operator/(f);

     }

    ariel::Fraction operator/(const ariel::Fraction &f, float number){

         Fraction f2 =  decimalToFraction(number);

        if(f2.getDenomirator()==0 || f.getDenomirator()==0)
              throw runtime_error("Error get denomrator equal to zero!! "); 



         int l = gcd(f.getNumerator()*f2.getDenomirator(),f.getDenomirator()*f2.getNumerator());


    return Fraction((f.getNumerator()*f2.getDenomirator())/l,(f.getDenomirator()*f2.getNumerator())/l);

        
     }

/////////////////////////////////////////  operator==



    bool Fraction::operator==(const ariel::Fraction &f){

            if(this->getNumerator()==f.getNumerator()&&f.getNumerator()==0)
                return true;
            return (this->getDenomirator()==f.getDenomirator() && this->getNumerator()==f.getNumerator());

         }

  bool operator==(const ariel::Fraction &f, float number){

     Fraction f2 =  decimalToFraction(number);

       
         return f2.operator==(f);
           
         }


    bool operator==(float number, const ariel::Fraction &f){

        Fraction f2 =  decimalToFraction(number);

            return f2.operator==(f);
           
         }


/////////////////////////////////////// operator>

    bool Fraction::operator>(const ariel::Fraction &f){

         Fraction res = (*this).operator-(f);
         
        Fraction orgN(this->getNumerator()*f.getDenomirator(),this->getDenomirator()*f.getDenomirator());
        Fraction num(f.getNumerator()*this->getDenomirator(),this->getDenomirator()*f.getDenomirator());


        //return res.getNumerator()>0? true : false;

    return orgN.getNumerator()>num.getNumerator() ? true : false;


    }


    bool operator>(const ariel::Fraction &f, float number){

         Fraction f2 =  decimalToFraction(number);

        Fraction orgN(f.getNumerator()*f2.getDenomirator(),f.getDenomirator()*f2.getDenomirator());
        Fraction num(f2.getNumerator()*f.getDenomirator(),f.getDenomirator()*f2.getDenomirator());

         
     return orgN.getNumerator()>num.getNumerator() ? true : false;
           
         }


    bool operator>(float number, const ariel::Fraction &f){

            Fraction f2 =  decimalToFraction(number);

            return operator>(f2,((float)f.getNumerator()/(float)f.getDenomirator()));
           
         }



/////////////////////////////////////////////// operator >=

    bool Fraction::operator>=(const ariel::Fraction &f){

        Fraction num(f.getNumerator()*(*this).getDenomirator(),f.getDenomirator()*(*this).getDenomirator());
        Fraction orgN((*this).getNumerator()*f.getDenomirator(),f.getDenomirator()*(*this).getDenomirator());

    // if(f.getNumerator()==(*this).getNumerator()&&f.getDenomirator()==(*this).getDenomirator())
    //         return true;

          if(orgN.operator==(num))
                return true;

     return orgN.getNumerator()>num.getNumerator() ? true : false;


    }



     bool operator>=(const ariel::Fraction &f, float number){

         Fraction f2 =  decimalToFraction(number);

        Fraction orgN(f.getNumerator()*f2.getDenomirator(),f.getDenomirator()*f2.getDenomirator());
        Fraction num(f2.getNumerator()*f.getDenomirator(),f.getDenomirator()*f2.getDenomirator());

        //  if(f.getNumerator()==f2.getNumerator()&&f.getDenomirator()==f2.getDenomirator())
        //     return true;

          if(orgN.operator==(num))
            return true;

     return orgN.getNumerator()>num.getNumerator() ? true : false;
           
         }


    bool operator>=(float number, const ariel::Fraction &f){

            Fraction f2 =  decimalToFraction(number);

        //   if(f.getNumerator()==f2.getNumerator()&&f.getDenomirator()==f2.getDenomirator())
        //       return true;

          if(f2.operator==(f))
             return true;

         return operator>(f2,((float)f.getNumerator()/(float)f.getDenomirator()));
           
         }

/////////////////////////////////// operator <

    
    bool Fraction::operator<(const ariel::Fraction &f){

         Fraction res = (*this).operator-(f);
         
        Fraction orgN(this->getNumerator()*f.getDenomirator(),this->getDenomirator()*f.getDenomirator());
        Fraction num(f.getNumerator()*this->getDenomirator(),this->getDenomirator()*f.getDenomirator());

    return orgN.getNumerator()<num.getNumerator() ? true : false;

    }


    bool operator<(const ariel::Fraction &f, float number){

         Fraction f2 =  decimalToFraction(number);

        Fraction orgN(f.getNumerator()*f2.getDenomirator(),f.getDenomirator()*f2.getDenomirator());
        Fraction num(f2.getNumerator()*f.getDenomirator(),f.getDenomirator()*f2.getDenomirator());

         
     return orgN.getNumerator()<num.getNumerator() ? true : false;
           
         }


    bool operator<(float number, const ariel::Fraction &f){


            Fraction f2 =  decimalToFraction(number);

     return operator<(f2,((float)f.getNumerator()/(float)f.getDenomirator()));
           
    }

////////////////////////////////////////////////// operator <=


    bool Fraction::operator<=(const Fraction &f){

        Fraction num(f.getNumerator()*(*this).getDenomirator(),f.getDenomirator()*(*this).getDenomirator());
        Fraction orgN((*this).getNumerator()*f.getDenomirator(),f.getDenomirator()*(*this).getDenomirator());

        // if(f.getNumerator()==(*this).getNumerator()&&f.getDenomirator()==(*this).getDenomirator())
        //     return true;

          if(orgN.operator==(num))
                return true;

     return orgN.getNumerator()<num.getNumerator() ? true : false;


    }

     bool operator<=(const ariel::Fraction &f, float number){

         Fraction f2 =  decimalToFraction(number);

        Fraction orgN(f.getNumerator()*f2.getDenomirator(),f.getDenomirator()*f2.getDenomirator());
        Fraction num(f2.getNumerator()*f.getDenomirator(),f.getDenomirator()*f2.getDenomirator());

        // if(f.getNumerator()==f2.getNumerator()&&f.getDenomirator()==f2.getDenomirator())
        //     return true;

          if(orgN.operator==(num))
            return true;
         
     return orgN.getNumerator()<num.getNumerator() ? true : false;
           
         }


    bool operator<=(float number, const ariel::Fraction &f){

     Fraction f2 =  decimalToFraction(number);

    //   if(f.getNumerator()==f2.getNumerator()&&f.getDenomirator()==f2.getDenomirator())
    //         return true;

        if(f2.operator==(f))
             return true;

     return operator<(f2,((float)f.getNumerator()/(float)f.getDenomirator()));
           
    }



///////////////////////////////////////////////



    ostream& operator << (ostream& output, const Fraction& f){

        return (output << f.getNumerator() << "/" << f.getDenomirator());

    }


};
       