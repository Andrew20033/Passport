#include "passport.h"

Passport::Passport(const string& _name, const string& _lname, const string& _patron, const string& _serial)
{
    name = _name;
    lname = _lname;
    patron = _patron;
    serial = _serial;
}
void Passport::Show() const
{
    cout << "Name: " << name << endl;
    cout << "Surname: " << lname << endl;
    cout << "middle name : " << patron << endl;
    cout << "Serial number: " << serial << endl;
}
ForeignPassport::ForeignPassport(const string& name, const string& lname, const string& patron, const string& serial, const string* _visa, const string& _id)
    :Passport(name, lname, patron, serial)
{
    for (int i = 0; i < VisaSize; ++i)
        visa[i] = _visa[i];
    id = _id;
}
ForeignPassport::ForeignPassport(const Passport& p, const string* _visa, const string& _id)
    :Passport(p)
{
    for (int i = 0; i < VisaSize; ++i)
        visa[i] = _visa[i];
    id = _id;
}
void ForeignPassport::Show() const
{
    Passport::Show();
    cout << "Foreign number passports: " << id << endl;
    cout << "Available visas: " << endl;
    for (int i = 0; i < VisaSize; ++i)
        if (visa[i] != "")
            cout << visa[i] << endl;
}