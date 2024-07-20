#include <iostream>
#include <list>
#include <thread>
#include <chrono>
#include <string>

using namespace std;
// Clasa Resursa reprezint? o entitate care con?ine informa?ii despre o anumit? resurs?.
class Resursa
{
public:
    // Numele resursei, de exemplu "Apa" sau "Cafea".
    string nume;
    // Cantitatea disponibil? pentru resursa respectiv?.
    int cantitate;
    // Constructorul clasei Resursa, care ini?ializeaz? numele ?i cantitatea resursei.
    Resursa(string n, int q) : nume(n), cantitate(q) {}
};
// Clasa abstract? Reteta reprezint? un ?ablon pentru diferite re?ete de b?uturi.
class Reteta
{
public:
    // Destructorul virtual pentru a asigura eliberarea corect? a resurselor în cazul derivatelor.
    virtual ~Reteta() {}
    virtual string getNume() const = 0;
    virtual list<Resursa> getResurseNecesare() const = 0;
    virtual void prepara(list<Resursa>& resurse) = 0;
};
// Clasa RetetaEspresso implementeaz? o re?et? specific? pentru cafea espresso.
class RetetaEspresso : public Reteta
{
private:
    list<Resursa> resurseNecesare;
public:
    RetetaEspresso(list<Resursa> resurse) : resurseNecesare(resurse) {}
    string getNume() const
    {
        return "Espresso";
    }
    list<Resursa> getResurseNecesare() const
    {
        return resurseNecesare;
    }
    void prepara(list<Resursa>& resurse) override
    {
        fierbeApa();
        macinaCafea();
        cout << "Espresso este gata!\n";
    }
private:
    void fierbeApa()
    {
        cout << "Fierbem apa pentru espresso...\n";
        this_thread::sleep_for(chrono::seconds(3));
        cout << "Apa fierbinte pentru espresso este gata!\n";
    }
    void macinaCafea()
    {
        cout << "Macinam cafeaua pentru espresso...\n";
        this_thread::sleep_for(chrono::seconds(2));
        cout << "Cafeaua macinata pentru espresso este gata!\n";
    }
};

class RetetaLongEspresso : public Reteta
{
private:
    list<Resursa> resurseNecesare;
public:
    RetetaLongEspresso(list<Resursa> resurse) : resurseNecesare(resurse) {}
    string getNume() const
    {
        return "Long Espresso";
    }
    list<Resursa> getResurseNecesare() const
    {
        return resurseNecesare;
    }
    void prepara(list<Resursa>& resurse) override
    {
        fierbeApa();
        macinaCafea();
        cout << "Long Espresso este gata!\n";
    }
private:
    void fierbeApa()
    {
        cout << "Fierbem apa pentru long espresso...\n";
        this_thread::sleep_for(chrono::seconds(4));
        cout << "Apa fierbinte pentru long espresso este gata!\n";
    }
    void macinaCafea()
    {
        cout << "Macinam cafeaua pentru long espresso...\n";
        this_thread::sleep_for(chrono::seconds(3));
        cout << "Cafeaua macinata pentru long espresso este gata!\n";
    }
};
// Asemanator pentru RetetaLongEspresso, RetetaCappuccino, RetetaLatteMacchiato, RetetaApa, RetetaCeai...
class RetetaCappuccino : public Reteta
{
private:
    list<Resursa> resurseNecesare;
public:
    RetetaCappuccino(list<Resursa> resurse) : resurseNecesare(resurse) {}
    string getNume() const
    {
        return "Cappuccino";
    }
    list<Resursa> getResurseNecesare() const
    {
        return resurseNecesare;
    }
    void prepara(list<Resursa>& resurse) override
    {
        fierbeApa();
        aburificaLaptele();
        macinaCafea();
        cout << "Cappuccino este gata!\n";
    }
private:
    void fierbeApa()
    {
        cout << "Fierbem apa pentru cappuccino...\n";
        this_thread::sleep_for(chrono::seconds(3));
        cout << "Apa fierbinte pentru cappuccino este gata!\n";
    }
    void aburificaLaptele()
    {
        cout << "Facem spuma de lapte pentru cappuccino...\n";
        this_thread::sleep_for(chrono::seconds(5));
        cout << "Spuma de lapte pentru cappuccino este gata!\n";
    }
    void macinaCafea()
    {
        cout << "Macinam cafeaua pentru cappuccino...\n";
        this_thread::sleep_for(chrono::seconds(2));
        cout << "Cafeaua macinata pentru cappuccino este gata!\n";
    }
};

class RetetaLatteMacchiato : public Reteta
{
private:
    list<Resursa> resurseNecesare;
public:
    RetetaLatteMacchiato(list<Resursa> resurse) : resurseNecesare(resurse) {}
    string getNume() const
    {
        return "Latte Macchiato";
    }
    list<Resursa> getResurseNecesare() const
    {
        return resurseNecesare;
    }
    void prepara(list<Resursa>& resurse) override
    {
        fierbeApa();
        aburificaLaptele();
        cout << "Latte Macchiato este gata!\n";
    }
private:
    void fierbeApa()
    {
        cout << "Fierbem apa pentru latte macchiato...\n";
        this_thread::sleep_for(chrono::seconds(3));
        cout << "Apa fierbinte pentru latte macchiato este gata!\n";
    }
    void aburificaLaptele()
    {
        cout << "Facem spuma de lapte pentru latte macchiato...\n";
        this_thread::sleep_for(chrono::seconds(4));
        cout << "Spuma de lapte pentru latte macchiato este gata!\n";
    }
};

class RetetaApa : public Reteta
{
private:
    list<Resursa> resurseNecesare;
public:
    RetetaApa(list<Resursa> resurse) : resurseNecesare(resurse) {}
    string getNume() const
    {
        return "Apa";
    }
    list<Resursa> getResurseNecesare() const
    {
        return resurseNecesare;
    }
    void prepara(list<Resursa>& resurse) override
    {
        fierbeApa();
        cout << "Apa este gata!\n";
    }
private:
    void fierbeApa()
    {
        cout << "Fierbem apa...\n";
        this_thread::sleep_for(chrono::seconds(2));
        cout << "Apa fierbinte este gata!\n";
    }
};

class RetetaCeai : public Reteta
{
private:
    list<Resursa> resurseNecesare;
public:
    RetetaCeai(list<Resursa> resurse) : resurseNecesare(resurse) {}
    string getNume() const
    {
        return "Ceai";
    }
    list<Resursa> getResurseNecesare() const
    {
        return resurseNecesare;
    }
    void prepara(list<Resursa>& resurse) override
    {
        fierbeApa();
        cout << "Ceaiul este gata!\n";
    }
private:
    void fierbeApa()
    {
        cout << "Fierbem apa pentru ceai...\n";
        this_thread::sleep_for(chrono::seconds(3));
        cout << "Apa fierbinte pentru ceai este gata!\n";
    }
};
// Clasa ManipulatorResurse se ocup? de gestionarea resurselor necesare pentru preg?tirea re?etelor.

class ManipulatorResurse
{
private:
    list<Resursa> containere;

public:
    ManipulatorResurse()
    {
        // Ini?ializ?m containerele cu cantit??i prestabilite de ap?, lapte ?i cafea.
        containere.push_back(Resursa("Apa", 150));
        containere.push_back(Resursa("Lapte", 50));
        containere.push_back(Resursa("Cafea", 20));
    }

    bool verificareResurse(list<Resursa> resurseNecesare)
    {
        while (true)
        {
            bool succes = true;
            // Verific?m disponibilitatea fiec?rei resurse necesare în lista de containere.
            for (Resursa necesara : resurseNecesare)
            {
                bool gasita = false;
                // C?ut?m resursa în fiecare container.
                for (auto& container : containere)
                {
                    if (container.nume == necesara.nume && container.cantitate >= necesara.cantitate)
                    {
                        gasita = true;
                        break;
                    }
                }
                // Dac? resursa nu a fost g?sit?, re?eta nu poate fi preparat? cu resursele curente.
                if (!gasita)
                {
                    succes = false;
                    break;
                }
            }
            // Dac? toate resursele sunt disponibile, return?m succesul.
            if (succes)
            {
                return true;
            }
            cout << "Resurse insuficiente. Reincarcare...\n";
            reincarcareResurse();
        }
    }
    // Metoda efectueaz? reincarcarea resurselor, simulând un proces care dureaz? 3 secunde.
    void reincarcareResurse()
    {
        cout << "Reincarcarea resurselor...\n";
        this_thread::sleep_for(chrono::seconds(3));
        // Se cur??? lista de containere ?i se adaug? resursele reinc?rcate.
        containere.clear();
        containere.push_back(Resursa("Apa", 100));
        containere.push_back(Resursa("Lapte", 50));
        containere.push_back(Resursa("Cafea", 20));

        cout << "Resurse reincarcate!\n";
    }
};
// Clasa ManagerComenzi coordoneaz? preg?tirea ?i procesarea comenzilor de re?ete.
class ManagerComenzi
{
private:
    ManipulatorResurse manipulatorResurse;
public:
    // Metoda proceseaz? comanda pentru o anumit? re?et?, gestionând resursele necesare.
    void procesareComanda(Reteta& reteta)
    {
        try
        {
            list<Resursa> resurseNecesare = reteta.getResurseNecesare();
            // Verific?m disponibilitatea resurselor ?i reinc?rc?m în cazul insuficien?ei.
            while (!manipulatorResurse.verificareResurse(resurseNecesare))
            {
                manipulatorResurse.reincarcareResurse();
            }
            // Preg?tim re?eta cu resursele disponibile.
            reteta.prepara(resurseNecesare);
            cout << "Comanda finalizata!\n";
        }
        catch (const exception& e)
        {
            cerr << "Eroare: " << e.what() << endl;
        }
    }
};
// Clasa PanouComenzi con?ine o serie de re?ete ?i ofer? interfa?a pentru procesarea comenzilor utilizatorului.
class PanouComenzi
{
private:
    Reteta* retete[6];
    ManagerComenzi managerComenzi;
public:
    // Constructorul initializeaz? re?etele disponibile.
    PanouComenzi()
    {
        retete[0] = new RetetaEspresso({ Resursa("Apa", 50), Resursa("Cafea", 10) });
        retete[1] = new RetetaLongEspresso({ Resursa("Apa", 75), Resursa("Cafea", 15) });
        retete[2] = new RetetaCappuccino({ Resursa("Apa", 50), Resursa("Lapte", 30), Resursa("Cafea", 15) });
        retete[3] = new RetetaLatteMacchiato({ Resursa("Apa", 50), Resursa("Lapte", 40) });
        retete[4] = new RetetaApa({ Resursa("Apa", 100) });
        retete[5] = new RetetaCeai({ Resursa("Apa", 150) });
    }
    // Metoda gestioneaz? inputul utilizatorului ?i proceseaz? comenzile.
    void procesareInputUtilizator()
    {
        while (true)
        {
            afisareMeniu();
            string inputUtilizator;
            cout << "Introduceti comanda (1-6 pentru alegere, 0 pentru iesire): ";
            getline(cin, inputUtilizator);
            if (inputUtilizator == "0")
            {
                cout << "Programul se inchide. La revedere!\n";
                break;
            }
            else if (inputUtilizator >= "1" && inputUtilizator <= "6")
            {
                procesareComanda(inputUtilizator);
            }
            else
            {
                cout << "Comanda invalida. Va rugam sa reintroduceti.\n";
            }
        }
    }
private:
    // Metoda afi?eaz? meniul de op?iuni disponibile.
    void afisareMeniu() const
    {
        cout << "Meniu:\n";
        cout << "0. Iesire\n";
        cout << "1. Cafea espresso\n";
        cout << "2. Cafea lunga (espresso dublu)\n";
        cout << "3. Cappuccino\n";
        cout << "4. Latte Macchiato\n";
        cout << "5. Apa\n";
        cout << "6. Ceai\n";
    }
    // Metoda proceseaz? comanda în func?ie de inputul utilizatorului.
    void procesareComanda(const string& inputUtilizator)
    {
        if (inputUtilizator.length() == 1 && inputUtilizator[0] >= '1' && inputUtilizator[0] <= '6')
        {
            int index = inputUtilizator[0] - '0';
            --index;
            managerComenzi.procesareComanda(*retete[index]);
        }
        else
        {
            cout << "Comanda invalida. Va rugam introduceti un numar intre 1 si 6.\n";
        }
    }
};

int main()
{
    PanouComenzi panouComenzi;
    panouComenzi.procesareInputUtilizator();
    return 0;
}
