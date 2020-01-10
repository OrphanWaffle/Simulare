#include "clase.h"
#include <typeinfo>

using namespace std;

istream& operator >>(istream& in,Candidat& a)
{
    cout<<"Nume candidat";
    in>>a.nume;
    cout<<"nota la bac";
    in>>a.nota_bac;
    char x;
    cout<<"A terminat o a doua facultate ?(d/n) ";
    cin>>x;
    if(x=='d')
    {
        cout<<"ce progr au terminat :";
        in>>a.program_terminat;
        cout<<"cu ce nota aterminat programu ;";
        in>>a.program_terminat_nota;
    }
    return in;
}

ostream& operator <<(ostream& out,Candidat& a)
{
    out<<"Nume ";
    out<<a.nume<<"\n";
    out<<"nota la bac";
    out<<a.nota_bac<<"\n";
    if(a.program_terminat_nota!=0)
    {
        out<<"progr au terminat :";
        out<<a.program_terminat<<"\n";
        out<<"cu ce nota aterminat programu ;";
        out<<a.program_terminat_nota<<"\n";
    }
    return out;
}
///--------------------------
istream& operator>>(istream& in,IF& a)
{
    in>>(Candidat&)a;
    cout<<"Nota scris: ";
    a.cod=++a.n;
    in>>a.nota_scris;
    return in;
}

ostream& operator <<(ostream& out,IF& a)
{
    if(a.get_ptn()==0)
    {
        out<<"Legitimatie : IF_"<<a.cod<<"  ";
        out<<"nota s1 : "<<a.s1<<"\n";
        out<<"nota s2 : "<<a.s2<<"\n";
        a.nota_scris=(a.s1+a.s2)/2;
    }
    else
    {   out<<"Legitimatie : IF2_"<<a.cod<<"  ";
        out<<"nota scris : "<<a.nota_oral<<"\n";
    }
    out<<(Candidat&)a;
    return out;
}
///-------------------------
istream& operator>>(istream& in,ID& a)
{
    in>>(Candidat&)a;
    cout<<"Nota scris: ";
    a.cod=++a.m;
    in>>a.nota_oral;
    return in;
}

ostream& operator <<(ostream& out,ID& a)
{
    if(a.get_ptn()==0) out<<"Legitimatie : ID_"<<a.cod<<"  ";
    else  out<<"Legitimatie : ID2_"<<a.cod<<"  ";
    out<<(Candidat&)a;
    out<<"nota scris : "<<a.nota_oral<<"\n";
    return out;
}
///---------------
istream& operator>>(istream& in,Facultate& F)
{
    cout<<"Nr_if: ";
    in>>F.nr_if;
    cout<<"Nr_id: ";
    in>>F.nr_id;
    int x;
    cout<<"1.ID\n2,IF;\n0.exit";
    vector<Candidat *>::iterator it;
    cin>>x;
    while(x)
    {
    switch (x)
    {
    case 1:
        F.C.push_back(new ID);
        it=(F.C.end()-1);
        in >> *dynamic_cast<Candidat* >(*it);
        break;
    case 2:
        F.C.push_back(new IF);
        it=(F.C.end()-1);
        in >> *dynamic_cast<Candidat* >(*it);
        break;
    }
    cin>>x;
    }
    return in;
}

ostream& operator<<(ostream& out,Facultate& F)
{
    out<<"Nr_if: "<<F.nr_if<<endl;
    out<<"Nr_id: "<<F.nr_id<<endl;
    vector<Candidat *>::iterator it;
    for(it=F.C.begin();it!=F.C.end();it++)
    {
        if(typeid(**it)==typeid(ID)) out<<*dynamic_cast<ID* >(*it);
        if(typeid(**it)==typeid(IF)) out<<*dynamic_cast<IF* >(*it);
    }
    return out;
}
