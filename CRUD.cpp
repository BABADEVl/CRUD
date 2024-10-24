#include <iostream>
#include <vector>
#include <string>

class Etudiant 
{
private:
    std::string nom;
    std::string prenom;
    int age;
    std::vector<float> notes;

public:

    Etudiant(std::string nom, std::string prenom, int age) : nom(nom), prenom(prenom), age(age) {}

    // Ajouter note
    void ajouterNote(float note) 
    {
        notes.push_back(note);
    }

    // Calculer moyenne eleve
    float calculerMoyenne() const 
    {
        if (notes.empty()) 
            return 0.0;

        float somme = 0;
        for (float note : notes) 
        {
            somme += note;
        }
        return somme / notes.size();
    }

    // Accesseur
    std::string getNom() const { return nom; }
    std::string getPrenom() const { return prenom; }

    // Afficher infos eleve
    void afficherInfos() const 
    {
        std::cout << "Nom: " << nom << ", Prenom: " << prenom << ", Age: " << age <<"ans" << ", Moyenne: " << calculerMoyenne() << std::endl;
    }
};

class Classe 
{
private:
    std::vector<Etudiant> etudiants;
    std::string nomClasse;

public:

    Classe(std::string nomClasse) : nomClasse(nomClasse) {}

    // Faire l'appel
    void faireAppel() const 
    {
        std::cout << "Liste des eleves de la classe " << nomClasse << " : " << std::endl;
        for (const Etudiant& etudiant : etudiants) 
        {
            std::cout << etudiant.getNom() << " " << etudiant.getPrenom() << std::endl;
        }
    }

    // Ajouter  éeleve
    void ajouterEleve(const Etudiant& etudiant) 
    {
        etudiants.push_back(etudiant);
    }

    // Enlever  élève
    void enleverEleve(const std::string& nom, const std::string& prenom) 
    {
        for (auto it = etudiants.begin(); it != etudiants.end(); ++it) 
        {
            if (it->getNom() == nom && it->getPrenom() == prenom) 
            {
                etudiants.erase(it);
                std::cout << "L'eleve " << nom << " " << prenom << " a ete retirer." << std::endl;
                return;
            }
        }
        std::cout << "Aucun eleve trouver avec ce nom et prenom." << std::endl;
    }

    // Calculer moyenne classe
    void calculerlaMoyenneClasse() const 
    {
        if (etudiants.empty()) 
        {
            std::cout << "Aucun eleve dans la classe." << std::endl;
            return;
        }

        float somme = 0;
        for (const Etudiant& etudiant : etudiants) 
        {
            somme += etudiant.calculerMoyenne();
        }
        std::cout << "Moyenne de la classe: " << somme / etudiants.size() << std::endl;
    }

    // Afficher le meilleur 
    void afficherMeilleurEleve() const 
    {
        if (etudiants.empty()) 
        {
            std::cout << "Aucun eleve dans la classe." << std::endl;
            return;
        }

        const Etudiant* meilleur = &etudiants[0];
        for (const Etudiant& etudiant : etudiants) 
        {
            if (etudiant.calculerMoyenne() > meilleur->calculerMoyenne()) 
            {
                meilleur = &etudiant;
            }
        }
        std::cout << "Le meilleur eleve est : "; meilleur->afficherInfos();
    }

    // Afficher tout eleve
    void afficherToutEleve() const 
    {
        for (const Etudiant& etudiant : etudiants) 
        {
            etudiant.afficherInfos();
        }
    }

    // Ajouter note tout eleve
    void ajouterNoteEleve(float note) 
    {
        for (Etudiant& etudiant : etudiants) 
        {
            etudiant.ajouterNote(note);
        }
    }
};

int main() 
{

    Classe classe("Bachelor 2 IT");

    Etudiant e1("Branet", "Mathis", 14);
    Etudiant e2("Demachintruc", "Simon", 21);
    Etudiant e3("Brule", "Basil", 21);

    classe.ajouterEleve(e1);
    classe.ajouterEleve(e2);
    classe.ajouterEleve(e3);

    classe.ajouterNoteEleve(15.0);
    classe.ajouterNoteEleve(12.5);
    classe.ajouterNoteEleve(14.0);

    classe.afficherToutEleve();

    classe.calculerlaMoyenneClasse();

    classe.afficherMeilleurEleve();

    classe.enleverEleve("Branet", "Mathis");

    classe.faireAppel();

    return 0;
}
