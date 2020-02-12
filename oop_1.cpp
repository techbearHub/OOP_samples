#include <iostream>   //#include <iostream.h>, C stils
#include <conio>      //#include <conio.h>, C stils

/*    Strings: C++ stils    */
//#include <string>
//using namespace std;


//klases deklaracijas. Normali sis butu header (.h), bet lai butu vienkarsak, viss ir viena. 

class CoordPoint {
   private: //privati globali mainigie. Globali tikai klasei CoordPoint. Vel tos medz devet par laukiem (fields)
   //Siem vares pieklut tikai CoordPoint ieksiene, tatad no main() nevares.
   //tapat varetu darit ar metodem- tad tas varetu izpildit tikai CoordPoint ieksa, bet no main() ne
      int X;
      int Y;
   public: //seit ir metodes un mainigie (saja piemerie gan mainigo nav), kuriem var pieklut no arpuses, tatad ari no main()
      CoordPoint(); 
      CoordPoint(int, int);

      //augsa ir divi konstruktora veidi
      //Tas, ka izskatas vienadi dod iespeju izsaucot no Main() izsaukt gan ka CoordPoint cp, gan CoordPoint cp2(3,5)
      //Varetu sarakstit cik daudz grib ar vienadiem nosaukumiem, ar dazadam parametru versijam(dazads parametru skaits, dazadi parametru tipi utt)
      //Sis saucas overloading
      //Konstruktors izpildas, kad uztaisa objektu


      ~CoordPoint() {
         cout << "Message from the \"CoordPoint\" - destroyed!" << endl;
      }
      //seit ir desktrutors. Attiecigi, kad objektu iznicina , paradas tas pazinojums. piem." delete cp2 " izsaukuma gadijuma paradisies sis
      //tas endl aiz cout panak, ka programma "uzsit" enter 

      int GetX() const {
         return X;
      }
      //ta saucamais "getteris". Sis ir labais tonis, ka pieklut privatiem mainigajiem. Ta ir publiska metode, kuru izsauc no Main()
      //ar return var dabut X vertibu.


      void SetX(int X) {
         this->X = X;
      }
      //Setteris prieks X. ar this->X tu noradi uz X no 15 rindinas un pieskir vertibu, kas padota ar SetX(). Tatad, ja Main izsauc SetX(11), lauka X vertiba ir 11, un tu to vari atgriezt
      //ar GetX

      //Implementacijas GetY ir leja, bet Strada tapat ka ar X
      //Print ir tas pats
      int GetY() const;
      void SetY(int);
      void Print() const;
};
//------------------------------------------------------------------------------------------
//definicija klases metodem

CoordPoint::CoordPoint() : X(0), Y(0) {
}

//pirma konstruktora implementacija. Tas ir tas bez parametriem. 
//pieskir X un Y vertibas 0

CoordPoint::CoordPoint(int Px, int Py) : X(Px) {
   Y = Py;
}

//Konstruktors ar parametriem
//Pasniedzejs parada ka pieskrit X un Y vertibas 2 veidos
//pirmais ir aiz // X(Px)
//Otrais ir Y = Py

//Konstruktorus biezi izmanto, lai pieskirtu laukiem(fields) defaultas vertibas


inline int CoordPoint::GetY() const {
   return Y;
}
inline void CoordPoint::SetY(int Y) {
   this->Y = Y;
}

//Setteris un Getteris Y, strada analogiski kaa X

inline void CoordPoint::Print() const {
   cout << "X = " << X << ", Y = " << Y;
}
//Implementacija print metodei- izvada X un Y

//Metodem vardini inline ir vajadzigi, lai so visu varetu samest viena faila.
//Normalos projektos to visu sadalitu, .h un .cpp failos. 



//-------------------------------------------------------------------------------------------

//Sakas Main metode. 
//Seit sakas jauna dzive, seit var pieklut tikai publiskam CoordPoint klases metodem un laukiem
//Saja piemera neviena publiska lauka nav, ir tikai privatie- X un Y, bet tiem pieklustam caur publiskajam metodem get un set. 
//get un set ir dala no enkapsulacijas- attiecigi, ka centies noslept visu, kam nevajag pieklut. To dara ar public un private 
void main(void) {
   //Sadaliju objektu izveides pa rindam, lai vieglak saprast
   CoordPoint CP1;
   CP2(1,2), CP3 = CoordPoint(3, 4); //seit ir divi veidi viena rinda, vienkarsi sadalot pazustu jega CP3 definesanai sada veida
     *CP4 = new CoordPoint(5, 6), *CP5; //Lidzigi, bet soreiz uztaisam pointerus un vertibu CP5 gadijuma pieskiram nakamaja rinda
   CP5 = new CoordPoint(7, 8);

   //ievero, ka seit izpilda abus konstruktorus (reference uz 18/19 rindu, ka ari 56 un 62)


   //pointeri norada, ka tie ir dinamiskie objekti- attiecigi tu varetu samainit uz kurieni pointeris rada
   //CP1/2/3 ir statiskie objekti. Tu nevari pateikt, ka vini rada uz citurieni. 
   //Iedomajies lielu noliktavu, ka plocka, kur katrai dala ir sava adrese(piem A3, B2 utt), pointeris butu lapina kuru tu iedod cilvekam, ar uzrakstitu adresi, lai var atrast kasti,
   //bet statiskais objekts ir jau situacija, ka cilveks stav rokas ar kasti. Var mainit kastes saturu, bet tu nevari iestastit nevienam, ka kaste A3 ir kaste B2. 

   clrscr(); // vienkarsi notira konsuli

   CP1.Print(); //Cp1 objekts izsauc print metodi
   //saja bridi izvadis, ka x ir 0, y ir 0
   cout<<endl; //uzsit enter
   CP1.SetX(1); //pasaka, ka CP1 X vertiba ir 1
   CP1.CoordPoint::Print();cout<<endl;

   //izvadis x = 1. y = 0, jo vertiba nav mainita
   //endl uzsit enter, starp citu efektivak butu 84 rindinas beigas pierakstit << endl
   //cout << "X = " << X << ", Y = " << Y << endl; -- sadi
   //jo citadak 118 un 120 rinda tas tiek darits tik un ta

   cout << endl << "**************" << endl << endl;

   (*CP4).Print();cout<<endl;
   CP4->SetY(9);
   CP4->Print();cout<<endl;
   (*CP4).CoordPoint::Print();cout<<endl;
   //Analogiski to pasu izdara ar cp4, tikai y vertiba ir 9, so izvadis x = 0, y = 9

   //izvada x = 0, y = 0
   CP5->CoordPoint::Print();cout<<endl;

   delete CP4;
   delete CP5;
   //izdzes objektus cp4 un cp5, abos gadijumos izsauks destruktoru (28. rinda)


//PIEBILDE
//seit jaizprot objekta dzives cikls
//Klase ir ka majas rasejums
//objekts ir ka maja, ko uztaisi no rasejuma
//SVARIGI, ka CP1 un CP2 un CP3 un CP4 un CP5 ir dazadi objekti.
//Pat ja metodes, lauki ir vienadi pec "planojuma", ja maini CP1 X vertibu, mainas tikai CP1 X, vertiba, parejos paliek 0
//Lidzigi, ka tad, ja rindu majas planojums ir vienads, tas, ka viena maja sienas nokraso sarkanas neko nemaina citas majas.

//Konstruktors tiek izsaukts, kad objektu uztaisi
//Talak vari pieklut un izmantot ta metodes un laukus (saja gadijuma get, set, print)
//vari pieskirt vertibas, darit kaut ko

//talaka ar delete objekti tiek dzesti no atminas
//tiek izsaukta destruktora metode
pppppp000p


//vnk lai neaizvertu konsoli (laikam). Visual studio 2019 sis rindas ir liekas!
/* Aizture: C stils */
   while (kbhit()) // C stils
      getch();     // C stils
   getch();        // C stils

/* Aizture: C++ stils */
// cin.get();

//salidzinajums starp aizturi c un c++ stilos. Logiski, ka pareizak seit butu c++ stila.
}
