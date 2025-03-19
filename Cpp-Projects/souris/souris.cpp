#include <iostream>
#include <string>
using namespace std;

class Souris
{
    /*****************************************************
      Complétez le code à partir d'ici
    ******************************************************/
private:
    double poids;
    string couleur;
    unsigned int age;
    unsigned int esperance_vie;
    bool clonee = false;

public:
    // Constructeur
    Souris(double p, string c, unsigned int a = 0, unsigned int ev = 36)
        : poids(p), couleur(c), age(a), esperance_vie(ev)
    {
        cout << "Une nouvelle souris !" << endl;
    }

    // Constructeur de copie
    Souris(Souris const& clone)
        : poids(clone.poids), couleur(clone.couleur), age(clone.age), esperance_vie(clone.esperance_vie * 0.8)
    {
        cout << "Clonage d'une souris !" << endl;
        clonee = true;
    }

    // Méthode pour afficher les informations de la souris
    void afficher()
    {
        if (clonee == false)
        {
            cout << "Une souris " << couleur << " de " << age << " mois et pesant " << poids << " grammes" << endl;
        }
        else
        {
            cout << "Une souris " << couleur << ", clonee, de " << age << " mois et pesant " << poids << " grammes" << endl;
        }
    }

    // Méthode pour faire vieillir la souris
    void vieillir()
    {
        age++;
        if (clonee == true && age > 0.5 * esperance_vie)
        {
            couleur = "verte";
        }
    }

    // Méthode pour faire évoluer la souris jusqu'à son espérance de vie
    void evolue()
    {
        while (age < esperance_vie)
        {
            vieillir();
        }
    }

    // Destructeur
    ~Souris() { cout << "Fin d'une souris..." << endl; }
    /*******************************************
     * Ne rien modifier après cette ligne.
     *******************************************/

}; // fin de la classe Souris

int main()
{
    Souris s1(50.0, "blanche", 2);
    Souris s2(45.0, "grise");
    Souris s3(s2);  // Clonage de s2

    s1.afficher();
    s2.afficher();
    s3.afficher();

    s1.evolue();
    s2.evolue();
    s3.evolue();

    s1.afficher();
    s2.afficher();
    s3.afficher();

    return 0;
}
