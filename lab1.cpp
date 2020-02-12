
#include <iostream>   /

/*    Strings: C++ stils    */
//#include <string>
using namespace std;


class Vehicle {
   private: 
      string regNr;
      int year;
      string country
   public: 
      Vehicle(); 
      Vehicle(string, int, string);


      ~Vehicle() {
         cout << "Message from the \"Vehicle\" - destroyed!" << endl;
      }

      string GetRegNr() const;
      void SetRegNr(string);
      int GetYear() const;
      void SetYear(int);
      string GetCountry() const;
      void SetCountry(string);
      
      void Print() const;
};
//------------------------------------------------------------------------------------------

Vehicle::Vehicle() : regNr("0"), year(0), country("0") {
}

Vehicle::Vehicle(string par1, int par2, string par3){
   regNr = par1;
   year = par2;
   country = par3;
}


inline string Vehicle::GetRegNr() const {
   return regNr;
}
inline void Vehicle::SetRegNr(string regNr) {
   this->regNr = regNr;
}

inline int Vehicle::GetYear() const {
   return year;
}
inline void Vehicle::SetYear(int year) {
   this->year = year;
}

inline string Vehicle::GetCountry() const {
   return country;
}
inline void Vehicle::SetCountry(string country) {
   this->country = country;
}


inline void Vehicle::Print() const {
   cout << "registracijas nr = " << regNr << ", razosanas gads = " << year << ", valsts = " << country << endl;
}



//-------------------------------------------------------------------------------------------

void main(void) {

   Vehicle CP1;
   CP2(1,2), CP3 = Vehicle(3, 4), *CP4 = new Vehicle(5, 6), *CP5; 
   CP5 = new Vehicle(7, 8);

   clrscr(); // vienkarsi notira konsuli

   CP1.Print(); 
   cout<<endl;
   CP1.SetYear(2013);
   CP1.Vehicle::Print();cout<<endl;



   cout << endl << "**************" << endl << endl;

   (*CP4).Print();cout<<endl;
   CP4->SetCountry("LV");
   CP4->Print();cout<<endl;
   (*CP4).Vehicle::Print();cout<<endl;

   CP5->Vehicle::Print();cout<<endl;

   delete CP4;
   delete CP5;

   cin.get();

}
