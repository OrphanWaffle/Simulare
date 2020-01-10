#pragma once
#include <iostream>
#include <string.h>
#include <vector>
#include <typeinfo>
using namespace std;

class Candidat
{
    string nume, program_terminat;
    int nota_bac, program_terminat_nota;
public:
    Candidat() { nume='\0'; nota_bac=0; program_terminat='\0'; program_terminat_nota=0;}
    friend istream& operator >>(istream& ,Candidat& );
    friend ostream& operator <<(ostream& ,Candidat& );
    int get_ptn(){return program_terminat_nota;}
};

class IF : public Candidat
{
    static int n;
    int cod,nota_scris,nota_oral,s1,s2;
public:
    IF (){cod=nota_scris=nota_oral=0; s1=0;s2=0;}
    friend istream& operator >>(istream& ,IF& );
    friend ostream& operator <<(ostream& ,IF& );
    void set_n(int x){n=0;}
};

class ID : public Candidat
{
    static int m;
    int cod,nota_oral;
public:
    ID(){cod=nota_oral=0;}
    friend istream& operator >>(istream& ,ID& );
    friend ostream& operator <<(ostream& ,ID& );
    void set_n(int x){m=0;}
};

class Facultate
{
    int nr_if,nr_id;
    vector<Candidat *> C;
public:
    Facultate(){nr_if=nr_id=0;}
    friend istream& operator >>(istream&,Facultate&);
    friend ostream& operator <<(ostream&,Facultate&);
};
