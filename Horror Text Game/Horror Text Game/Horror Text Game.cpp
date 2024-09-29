#include <iostream>
#include <string>
#include <vector>
#include <windows.h>


// Creerea bibliotecii Player
class Player { 
public:
    int health; // initializarea vietii
   // int mind; // initializarea sanity-ului
    std::string name;
    std::vector<std::string> inventory;

    Player(std::string playerName) : health(100), name(playerName) {}

    void showStatus() {
        std::cout << name << "'s Health: " << health << "\n"; // arata viata playerului
        //std::cout << name << "'s Inventory" << "\n";
       // std::cout << name << "'s Health: " << mind << "\n";
    }

    void takeDamage(int damage) {  // functie de damage 
        health -= damage;
        if (health < 0) health = 0;
    }
    //void healSanity(int sanity)
   /* {
        mind += sanity;
            if (mind > 100) mind = 100;
    }*/
    void healDamage(int heal) { // functie de heal
        health += heal;
        if (health > 100) health = 100;
    }
    void addItem(std::string item) { //funtie de adaugare item
        inventory.push_back(item);
        std::cout << item << " added to your inventory.\n";
    }

        void showInventory() { // aratarea inventorului
            std::cout << name << "'s Inventory: ";
            if (inventory.empty()) {
                std::cout << "Inventory is Empty\n"; // mesaj de empty
            }
            else {
                for (const std::string& item : inventory) {
                    std::cout << item << " ";
                }
                std::cout << "\n";
            }
        }

        bool hasItem(const std::string & item) {
            for (const std::string& invItem : inventory) {
                if (invItem == item) {
                    return true;
                }
            }
            return false;
        }

        void useItem(const std::string & item) {
            auto it = std::find(inventory.begin(), inventory.end(), item);
            if (it != inventory.end()) {
                inventory.erase(it);
                std::cout << item << " used.\n";
                if (item == "Telefon") {
                    healDamage(20);
                    std::cout << "Folosind telefonul, ti-ai ridicat nivelul de serotnina si asta ti-a dat un heal de 20.\n";
                }
                //if (item == "Lanterna") {
                   // healSanity(20);
                   // std::cout << "Folosind lanterna, ti-ai ridicat moralul si asta ti-a dat un heal de 20 asupra nivelului de sanity.\n";
               // }
            }
            else {
                std::cout << "You don't have " << item << " in your inventory.\n";
            }
        }
};


///fata inainte de numirea player-ului
void fatainchis()
{

    std::cout << "                               #|||||||#           \n";
    std::cout << "                              #         #         \n";
    std::cout << "                             #  -    -   #        \n";
    std::cout << "                             #     l     #         \n";
    std::cout << "                              # |-----| #          \n";
    std::cout << "                               #       #          \n";
    std::cout << "                                 # # #            \n";
}
   
///fata dupa numirea player-ului
void fatadeschis() 
{
    
    std::cout << "                               #|||||||#           \n";
    std::cout << "                              #         #         \n";
    std::cout << "                             #  0    0   #        \n";
    std::cout << "                             #     l     #         \n";
    std::cout << "                              # |-----| #          \n";
    std::cout << "                               #       #          \n";
    std::cout << "                                 # # #            \n";
   
}
///fata inainte de numirea sidekick
void fatainchis2()
{

    std::cout << "                               #8888888#           \n";
    std::cout << "                              #         #         \n";
    std::cout << "                             #  -    -   #        \n";
    std::cout << "                             #     l     #         \n";
    std::cout << "                              # |-----| #          \n";
    std::cout << "                               #       #          \n";
    std::cout << "                                 # # #            \n";
}
   
///fata dupa numirea sidekick
void fatadeschis2()
{

    std::cout << "                                #8888888#           \n";
    std::cout << "                               #         #         \n";
    std::cout << "                              #  0    0   #        \n";
    std::cout << "                              #     l     #         \n";
    std::cout << "                               # |-----| #          \n";
    std::cout << "                                #       #          \n";
    std::cout << "                                  # # #            \n";
}
    

//COLORS LIST
//1: Blue
//2: Green
//3: Cyan
//4: Red
//5: Purple
//6: Yellow (Dark)
//7: Default white
//8: Gray/Grey
//9: Bright blue
//10: Brigth green
//11: Bright cyan
//12: Bright red
//13: Pink/Magenta
//14: Yellow
//15: Bright white

//funtia apelata pentru schimbarea culorii textului
void cul(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}







// codul pentru story-ul din actul 1
void act1(Player& player, Player& demon, Player& bff)
{
    system("pause");
    system("cls");                                                                                            // golirea consolei
    cul(7);                                                                                                   // schimbarea culorii in terminal
    std::cout << "\n";
    std::cout << "Este sambata seara, esti singur acasa si stai pe canapea la TV \n";  
    std::cout << "Ai chef sa: \n";
    cul(14);
    std::cout << "Mananci (M) / Vezi un film (F) / Iesi in oras (I) / Sa joci ceva (J) \n";
    cul(7);
    std::cout << "\n";
    std::string action;
    std::cin >> action;
    if (action == "M" xor action == "m") {
        std::cout << "\n";
        std::cout << "Intri in bucatarie...\n";
        std::cout << "Este intuneric asa ca te impiedici de covor si pici...\n";
        cul(4);
        std::cout << "\n";
        std::cout << "-7 HP\n";
        player.takeDamage(7);
        player.showStatus();
        cul(7);
        std::cout << "\n";
        std::cout << "Te ridici si :\n";
        cul(14);
        std::cout << "Iesi din Bucatarie(I)/Aprinzi becul(L)/Injuri(F)\n";
        cul(7);
        std::cout << "\n";
        std::string decision;
        std::cin >> decision;
        if (decision == "I" xor decision == "i")
        {
            std::cout << "\n";
            std::cout << "Te intorci in sufragerie.\n";
            std::cout << "\n";
        }
        else if (decision == "L" xor decision == "l") {
            std::cout << "\n";
            std::cout << " Aprinzi becul, deschizi frigiderul dar nu ai nimic de mancare... \n";
            cul(4);
            std::cout << "Emotional Damage!\n";
            std::cout << "\n";
            std::cout << "-10 HP\n";
            player.takeDamage(10);
            player.showStatus();
            std::cout << "\n";
            cul(7);
            std::cout << "Decizi sa te intorci in sufragerie\n";
        }
        else if (decision == "F" xor decision == "f") {
            std::cout << "\n";
            std::cout << "Injuri si te descarci\n";
            std::cout << "\n";
            cul(2);
            std::cout << "+7 HP\n";
            player.healDamage(7);
            player.showStatus();
            cul(7);
            std::cout << "\n";
            std::cout << "Te simti mai bine acum ca te-ai descarcat asa ca uiti de foame si te intorci in sufragerie.\n";
            std::cout << "\n";
        }
    }
    else if (action == "F" xor action == "f") {
        std::cout << "\n";
        std::cout << "Stai si te gandesti ce ai vrea sa vezi.\n";
        std::cout << "Te ridici si cauti prin filmele pe care le ai disponibile.\n";
        std::cout << "Observi un Blu-Ray ciudat pe care nu l-ai mai vazut niciodata.\n";
        std::cout << "Inspectezi mai in deaprope. Descrierea de pe spatele Case-ului este scrisa intr-un dialect ciudat plin de incritii dubiose. \n";
        cul(14);
        std::cout << "Decizi sa il vizionezi? (Y/N)\n";
        cul(7);
        std::cout << "\n";
        std::string decision;
        std::cin >> decision;
        std::cout << "\n";
        if (decision == "Y" xor decision == "y")
        {
            
            std::cout << "\n";
            std::cout << "Prosta decizie. ai dezlantuit un demon ce iti vrea sufletul.\n";
            cul(12);
            std::cout << demon.name;
            cul(7);
            std::cout << ": In sfarsit am fost eliberat!!! Muhahaha (ras malefic)\n";
            cul(3);
            std::cout << player.name;
            cul(7);
            std::cout<<":Ce vrei de la mine?!\n";
            cul(12);
            std::cout << demon.name;
            cul(7);
            std::cout<< ": TOTUL!\n";
            std::cout << "\n";
            std::cout << "Te uiti in jur si vezi o icoana, un crucifix si un Snikers.\n";
            std::cout << "Cu ce alegi sa te aperi?\n";
            cul(14);
            std::cout << "Icoana (I) / Crucufix (C) / Snikers (S)\n";
            std::cout << "\n";
            cul(7);
            std::string decision2;
            std::cin >> decision2;
            if (decision2 == "I" xor decision2 == "i") {
                
                std::cout << "\n";
                cul(12);
                std::cout << demon.name;
                cul(7);
                std::cout << ": Chiar crezi ca o sa te ajute? Te crezi in filme horror? Ce o sa imi faci? O incantatie?\n";
                cul(3);
                std::cout << player.name;
                cul(7);
                std::cout << ":Aaa, da? \n";
                std::cout << "Vezi ca nu este outcome-ul pe care l-ai asteptat asa ca ... Arunci cu icoana dupa el.\n";
                cul(6);
                std::cout << "Inafective....who would it taught...\n";
                cul(12);
                std::cout << demon.name;
                cul(7);
                std::cout << ":hai ca m-ai plictisit , revin cand devii relevant :P \n";
                cul(12);
                std::cout << demon.name ;
                cul(7);
                std::cout << " left the chat...\n";
                std::cout << "\n";
                std::cout << "\n";
                std::cout << "\n";
                std::cout << "Te reintorci in sufragerie bulversat de ceea ce tocmai ai trait \n";
                std::cout << "\n";
            }
            else if (decision2 == "S" xor decision2 == "s") {
                std::cout << "\n";
                std::cout << "Aparent Demonului doar ii era foame asa ca te lasa in pace si pleaca\n";
                std::cout << "Cine se astepta la asta?\n";
                std::cout << "\n";
                cul(2);
                std::cout << "HP fully restored\n";
                player.healDamage(100);
                player.showStatus();
                cul(7);
                std::cout << "\n";
            }
            else if (decision2 == "C" xor decision2 == "c") {
                std::cout << "\n";
                cul(12);
                std::cout << demon.name;
                cul(7);
                std::cout << ": Dude... Serios? Ceva mai cliseic nu ai gasit?\n";
                std::cout << "\n";
                std::cout << "*Nu a avut efectul dorit de tine* \n";
                std::cout << "\n";
                cul(4);
                std::cout << "Ai fost blestemat\n";
                std::cout << "\n";
                player.takeDamage(100);
                player.showStatus();
                std::cout << "\n";
                cul(7);
            }

        }
        else if (decision == "N" xor decision == "n") {
            std::cout << "\n";
            std::cout << "Toate semnele indica ca nu ar fi o idee buna sa il vizionezi.\n";
            std::cout << "Pentru prima oara in istoria cinematografiei Horror, cand ceva pare dubas cineva a decis sa aleaga varianta smart.\n";
            std::cout << "\n";
            cul(2);
            player.healDamage(100);
            player.showStatus();
            std::cout << "bosnus de la developer pentru ca nu ti-ai satisfacut curiozitatea (ai viata full ) ;) \n";
            std::cout << "\n";
            cul(7);
            std::cout << "Te reintorci in sufragerie. \n";
            std::cout << "\n";
        }
    }
    else if (action == "J" xor action == "j") {
        std::cout << "\n";
        std::cout << "Ai chef de un shooter dar... Nu ai PC...\n";
        cul(4);
        std::cout << "\n";
        std::cout << "Emotional Damage!\n";
        std::cout << "-20 HP\n";
        player.takeDamage(20);
        player.showStatus();
        std::cout << "\n";
        cul(7);
        std::cout << "Te reintorci in sufragerie. \n";
        std::cout << "\n";
    }
    else if (action == "I" xor action == "i") {
        std::cout << "\n";
        std::cout << "Ahhh....Ce pacat. Ca prin minune usa de la intrare este blocata si nu se poate deschide. (Oricum nu aveai bani)\n";
        std::cout << "Te duci si te asezi pe canapea in sufragerie.\n";
    }
    
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
    
    
}



//codul pentru actul 2
void act2(Player& player, Player& demon, Player& bff)
{
    
   
    std::cout << "\n";
    system("cls");
    std::cout << "Actul 2\n";
    std::cout << "\n";
    std::cout << "Asa cum am spus in finalul actului 1, te intorci in sufragerie.\n";
    std::cout << "Care este urmatorul lucru pe care il faci?\n";
    cul(14);
    std::cout << "Iti suni cel mai bun prieten ca sa ii povestesti ce ai patit (S) / Fumezi o tigara (F) / Iesi un pic sa te plimbi ca sa te linistesti (I)\n";
    std::string action;
    std::cin >> action;
    cul(7);
    std::cout << "\n";
    if (action == "S" xor action == "s")
    {
        std::cout << "\n";
        std::cout << "Iti cauti telefonul dar nu il gasesti\n";
        cul(14);
        std::cout << "Cauti sub pernele canapelei (C) / Aprinzi Flashligh-ul si il cauti sub canapea (A)\n";
        std::string action2;
        std::cin >> action2;
        cul(7);
        std::cout << "\n";
        if (action2 == "C" xor action2 == "c")
        {
            std::cout << "\n";
            std::cout << "Bingoo! L-ai gasit.\n";
            cul(3);
            player.addItem("Telefon");
            cul(7);
            std::cout << "\n";
            std::cout << "Selectezi ";
            cul(11);
            std::cout << bff.name;
            cul(7);
            std::cout << " din agenda si apelezi.\n";
            std::cout << "......\n";
            std::cout << ".......\n";
            std::cout << "........\n";
            std::cout << "'Abonatul apelat .....\n";
            cul(3);
            std::cout << player.name;
            cul(7);
            std::cout << ":Perfect, nu raspunde. De ce nu ma mira?\n";
        }
        else if (action2 == "A" xor action2 == "a")
        {
            std::cout << "\n";
            std::cout << "Cum ai aprins flashlight-ul TELEFONULUI daca se presupune ca tu 'nu iti gasesti telefonul'?\n";
            std::cout << "De rusine ai renuntat la telefon pentru restul jocului \n";
            std::cout << "\n";
        }
    }
    else if (action == "F" xor action == "f")
    {
        std::cout << "\n";
        std::cout << "Scoti o tigara din pachet, o pui in gura si ti-o aprinzi\n";
        std::cout << "\n";
        cul(4);
        std::cout << "-10 HP\n";
        player.takeDamage(10);
        player.showStatus();
        std::cout << "\n";
        std::cout << "Fumatul dauneaza grav sanatatii tale si a celor din jur!\n";
        std::cout << "\n";
        cul(7);

    }
    else if (action == "I" xor action == "i")
    {
        std::cout << "Pui mana pe clanta ca sa iesi din casa dar te gandesti daca iti iei telefonul cu tine sau nu.\n";
        cul(14);
        std::cout << "\n";
        std::cout << "Il iei? Yes (Y) / No (N) \n";
        cul(7);
        std::string action3;
        std::cin >> action3;
        std::cout << "\n";

        if (action3 == "Y" xor action3 == "y")
        {
            std::cout << "\n";
            std::cout << "Te-ai intors si ti-ai luat telefonul de sub pernele de pe canapea.\n";
            std::cout << "\n";
            cul(3);
            player.addItem("Telefon");
            std::cout << "\n";
            cul(7);
         

        }
        else if (action3 == "N" xor action3 == "n")
        {
            std::cout << "\n";
            std::cout << "Ai decis ca in acesata lume extrem de interconenctata mai ai nevoie si de o pauza de la technologie asa ca il lasi acasa\n";
            std::cout << "\n";
        }
        

    }

   
}


//codul pentru actul 3
void act3(Player& player, Player& demon, Player& bff)
{
    std::cout << "\n";
    std::cout << "Iesi pe usa apartamentului si te duci sa te plimbi\n";
    std::cout << "\n";
    std::cout << "Te simti urmarit...\n";
    std::cout << "Te uiti in dreapta....stanga...spate ...\n";
    std::cout << "Nimic\n";
    cul(3);
    std::cout << player.name ;
    cul(7);
    std::cout << " :sunt doar paranoic!\n";
    cul(3);
    std::cout << player.name;
    cul(7);
    std::cout << " :Credeam ca aerul curat te ajuta sa te simti mai bine\n";
    cul(11);
    std::cout << "....";
    cul(7);
    std::cout << ":ce zici ca faci?\n";
    std::cout << "\n";
    std::cout << "Tresari initial dar realizezi ca este ";
    cul(11);
    std::cout << bff.name << "\n";
    cul(3);
    std::cout << player.name;
    cul(7);
    std::cout << " :Ce m-ai speriat!\n";
    cul(11);
    std::cout << bff.name ;
    cul(7);
    std::cout << " :Ce tressari asa ? Esti ok?\n";
    cul(3);
    std::cout << player.name;
    cul(7);
    std::cout << " :Da...Cred ca sunt doar un pic paranoic.\n";
    cul(11);
    std::cout << bff.name ;
    cul(7);
    std::cout << " :Pai?\n";
    cul(3);
    std::cout << player.name;
    cul(7);
    std::cout << " :Mi se parea ca sunt urmarit....\n";
    cul(11);
    std::cout << bff.name ;
    cul(7);
    std::cout << " :...\n";
    cul(3);
    std::cout << player.name;
    cul(7);
    std::cout << " :...\n";
    std::cout << "\n";
    std::cout << " O ceata deasa incepe sa se lase in jurul vostru.\n";
    std::cout << " Simtiati ca ceva nu este ok.\n";
    std::cout << "\n";
    std::cout << "\n";
    cul(12);
    std::cout << demon.name;
    cul(7);
    std::cout << ":Muhuhahaha \n";
    cul(11);
    std::cout << bff.name;
    cul(7);
    std::cout << " :E cineva acolo?\n";
    cul(3);
    std::cout << player.name;
    cul(7);
    std::cout << " Hai sa plecam de aici!\n";
    cul(12);
    std::cout << demon.name;
    cul(7);
    std::cout << ":Nimeni nu pleaca nicaieri! \n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "In fata voastra apare o umbra inalta, cu o fata distorsionata ce iti inducea un sentiment neplacut.\n";
    cul(3);
    std::cout << player.name;
    cul(7);
    std::cout << " Ce esti?\n";
    cul(11);
    std::cout << bff.name;
    cul(7);
    std::cout << " :Ce vrei?\n";
    std::cout << "\n";
    std::cout << "Brusc, figura aparuta se repede catre voi.\n";
    std::cout << "\n";
    std::cout << "Ce decizi sa faci?.\n";
    cul(14);
    std::cout << "Fugi lasandu-ti prientenul in spate (F) / Te pui in garda (G)\n";
    cul(7);
    std::cout << "\n";
    std::string decision;
    std::cin >> decision;
    std::cout << "\n";
    if (decision == "F" xor decision == "f") {
        std::cout << "\n";
        cul(11);
        std::cout << bff.name;
        cul(7);
        std::cout << "Serios bro?\n";
        cul(3);
        std::cout << player.name;
        cul(7);
        std::cout << " Fiecare pentru el!\n";
        std::cout << "\n";
        std::cout << "\n";
        cul(15);
        std::cout << "          ######################################################\n";
        std::cout << "          #                                                    #\n";
        std::cout << "          #      Datorita faptului ca ai fugit ca un las       #\n";
        std::cout << "          #    si ti-ai abandonat prientenul ca ultimul om     #\n";
        std::cout << "          #        Demonul a decis sa te omoare pe loc         #\n";
        std::cout << "          #                                                    #\n";
        std::cout << "          ######################################################\n";
        std::cout << "\n";
        std::cout << "\n";
        cul(4);
        player.takeDamage(100);
        player.showStatus();
        cul(15);
        std::cout << "\n";
        std::cout << "\n";
        std::cout << "          ######################################################\n";
        std::cout << "          #                                                    #\n";
        std::cout << "          #                  Lessons learned!                  #\n";
        std::cout << "          #         In viata trebuie sa ai integritate         #\n";
        std::cout << "          #          si sa iti lasi loc de buna-ziua!          #\n";
        std::cout << "          #                                                    #\n";
        std::cout << "          ######################################################\n";
    }
    if (decision == "G" xor decision == "g") {

        cul(3);
        std::cout << player.name;
        cul(7);
        std::cout << " : ";
        cul(11);
        std::cout << bff.name;
        cul(7);
        std::cout << " pune-te in spatele meu!!\n";
        cul(3);
        std::cout << player.name;
        cul(7);
        std::cout << ": it's not my first rodeo...\n";
        cul(3);
        std::cout << player.name;
        cul(7);
        std::cout << ": ";
        cul(12);
        std::cout << demon.name;
        cul(7);
        std::cout << " zi ce vrei!\n";
        std::cout << "\n";
        std::cout << "Incepi sa cauti prin buzunare sa vezi daca ai ceva la tine sa te ajute\n";
        std::cout << "\n";
        std::cout << "\n";
        player.showInventory();
        std::cout << "\n";
        std::cout << "\n";
        cul(14);
        std::cout << "Ce vrei sa folosesti?\n";
        std::cout << "\n";
        cul(7);
        std::string choice;
        std::cin >> choice;
        if (choice == "Portofel" xor choice == "portofel")
        {
            std::cout << "\n";
            std::cout << "Iti scoti portofel din buzunar, in dechizi si scoti o bancnota de 10 lei si o intinzi catre el.\n";
            std::cout << "\n";
            cul(3);
            std::cout << player.name;
            cul(7);
            std::cout << ":Ajung de o bere!\n";
            cul(12);
            std::cout << demon.name;
            cul(7);
            std::cout << ": CE?\n";
            cul(3);
            std::cout << player.name;
            cul(7);
            std::cout << ":Ia de aici si dui de aici!\n";
            cul(12);
            std::cout << demon.name;
            cul(7);
            std::cout << ":Omule, ce drac zici?! *Pun intended*\n";
            cul(3);
            std::cout << "\n";
            std::cout << "\n";
            std::cout << bff.name;
            cul(7);
            std::cout << " : ";
            cul(11);
            std::cout <<  player.name;
            cul(7);
            std::cout << " ce faci? crezi ca ajuta cu ceva?\n";
            cul(11);
            std::cout << player.name;
            cul(7);
            std::cout << ": Watch and learn!\n";
            std::cout << "\n";
            std::cout << "\n";
            cul(3);
            std::cout << player.name;
            cul(7);
            std::cout << ": Traiesti in Romania?!\n";
            cul(12);
            std::cout << demon.name;
            cul(7);
            std::cout << ": CE?\n";
            cul(3);
            std::cout << player.name;
            cul(7);
            std::cout << ": TRAIESTI in Romania?!\n";
            cul(12);
            std::cout << demon.name;
            cul(7);
            std::cout << ": Da?\n";
            cul(3);
            std::cout << player.name;
            cul(7);
            std::cout << ": Oreste ceata!\n";
            cul(3);
            std::cout << player.name;
            cul(7);
            std::cout << ": OPRESTE CEATA!\n";
            cul(12);
            std::cout << demon.name;
            cul(7);
            std::cout << ":Nu mai inteleg nimic....\n";
            std::cout << "\n";
            std::cout << "\n";
            std::cout << "Bulversat, ";
            cul(12);
            std::cout << demon.name;
            cul(7);
            std::cout << " pleca neintelegand ce s-a intamplat.\n";
            std::cout << "\n";
            std::cout << "\n";
            cul(11);
            std::cout << player.name;
            cul(7);
            std::cout << ":Ti-am zis ca stiu ce fac!\n";
            cul(11);
            std::cout << bff.name;
            cul(7);
            std::cout << ": What did I just witnesed?!\n";

        }
        else
        {
            std::cout << "Nope, nu ajuta! \n";
            std::cout << "Ne prefacem ca ai ales 'Portofel' si continuma story-ul. \n";
            std::cout << "\n";
            std::cout << "\n";
            std::cout << "\n";
            std::cout << "Iti scoti portofel din buzunar, in dechizi si scoti o bancnota de 10 lei si o intinzi catre el.\n";
            std::cout << "\n";
            cul(3);
            std::cout << player.name;
            cul(7);
            std::cout << ":Ajung de o bere!\n";
            cul(12);
            std::cout << demon.name;
            cul(7);
            std::cout << ": CE?\n";
            cul(3);
            std::cout << player.name;
            cul(7);
            std::cout << ":Ia de aici si dui de aici!\n";
            cul(12);
            std::cout << demon.name;
            cul(7);
            std::cout << ":Omule, ce drac zici?! *Pun intended*\n";
            cul(3);
            std::cout << "\n";
            std::cout << "\n";
            std::cout << bff.name;
            cul(7);
            std::cout << " : ";
            cul(11);
            std::cout << player.name;
            cul(7);
            std::cout << " ce faci? crezi ca ajuta cu ceva?\n";
            cul(11);
            std::cout << player.name;
            cul(7);
            std::cout << ": Watch and learn!\n";
            std::cout << "\n";
            std::cout << "\n";
            cul(3);
            std::cout << player.name;
            cul(7);
            std::cout << ": Traiesti in Romania?!\n";
            cul(12);
            std::cout << demon.name;
            cul(7);
            std::cout << ": CE?\n";
            cul(3);
            std::cout << player.name;
            cul(7);
            std::cout << ": TRAIESTI in Romania?!\n";
            cul(12);
            std::cout << demon.name;
            cul(7);
            std::cout << ": Da?\n";
            cul(3);
            std::cout << player.name;
            cul(7);
            std::cout << ": Oreste ceata!\n";
            cul(3);
            std::cout << player.name;
            cul(7);
            std::cout << ": OPRESTE CEATA!\n";
            cul(12);
            std::cout << demon.name;
            cul(7);
            std::cout << ":Nu mai inteleg nimic....\n";
            std::cout << "\n";
            std::cout << "\n";
            std::cout << "Bulversat, ";
            cul(12);
            std::cout << demon.name;
            cul(7);
            std::cout << " pleca neintelegand ce s-a intamplat.\n";
            std::cout << "\n";
            std::cout << "\n";
            cul(11);
            std::cout << player.name;
            cul(7);
            std::cout << ":Ti-am zis ca stiu ce fac!\n";
            cul(11);
            std::cout << bff.name;
            cul(7);
            std::cout << ": What did I just witnesed?!\n";
        }
              

    }
}


//codul pentru finalul jocului
void final2()
{
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "Auzi o alarma!\n";
    std::cout << "\n";
    std::cout << "Trrr!\n";
    std::cout << "\n";
    std::cout << "Trrr!\n";
    std::cout << "\n";
    std::cout << "Trrr!\n";
    std::cout << "\n";
    std::cout << "Trrr!\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "Deschizi ochii si realizezi ca totul a fost doar un vis!\n";
    std::cout << "\n";
    std::cout << "\n";
}


//finalul daca mori in actul 1
void final1(Player& player, Player& demon) 
{
    std::cout << "\n";
    std::cout << "Sa spunem ca din pacate, ";
    cul(12);
    std::cout << demon.name;
    cul(7);
    std::cout << " a fost prea puternic pentru tine\n ";
    std::cout << "(Ca sa nu ne reamintim de cliseul care te-a omorat) ";
    std::cout << "\n";
} 

//Imaginea de Game over
void gameover()
{
    std::cout << "                                                                                \n";
    std::cout << "                                                                                \n";
    cul(4);
    std::cout << "        ####                ####            ##        ##       ##########       \n";
    std::cout << "      ##     ##            ##  ##           ## ##  ## ##       ##               \n";
    std::cout << "     ##                   ##    ##          ##   ##   ##       ##               \n";
    std::cout << "     ##     ####         ##########         ##        ##       ##########       \n";
    std::cout << "      ##      ##        ##        ##        ##        ##       ##               \n";
    std::cout << "       #######         ##          ##       ##        ##       ##########       \n";
    std::cout << "                                                                                \n";
    std::cout << "                                                                                \n";
    std::cout << "                                                                                \n";
    std::cout << "        #####          ##          ##        ###########       ##########       \n";
    std::cout << "      ##      ##        ##        ##         ##                ##      ##       \n";
    std::cout << "     ##        ##        ##      ##          ##                ##      ##       \n";
    std::cout << "     ##        ##         ##    ##           ##########        ## #### ##       \n";
    std::cout << "      ##      ##           ##  ##            ##                ##    ##         \n";
    std::cout << "        ######              ####             ###########       ##      ##       \n";
    cul(7);
    std::cout << "                                                                                \n";
    std::cout << "                                                                                \n";
    
}

void gata()
{
    cul(1);
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "          #################################################################################################\n";
    std::cout << "          #                                                                                               #\n";
    std::cout << "          #           ########   ##   ##    ######          ######     ##       ##    ######              #\n";
    std::cout << "          #              ##      ##   ##    ##              ##         ## ##    ##    ##    ##            #\n";
    std::cout << "          #              ##      #######    ######          ######     ##   ##  ##    ##     ##           #\n";
    std::cout << "          #              ##      ##   ##    ##              ##         ##    ## ##    ##    ##            #\n";
    std::cout << "          #              ##      ##   ##    ######          ######     ##       ##    #######             #\n";
    std::cout << "          #                                                                                               #\n";
    std::cout << "          #################################################################################################\n";
    std::cout << "\n";
    std::cout << "\n";
    cul(7);
}



//Programul principal
int main()
{

    // numele jocului
    cul(3);
    std::cout << "                   ********************************* \n";
    std::cout << "                   **             **              ** \n";
    std::cout << "                   **                             ** \n";
    std::cout << "                   **      Un proiect final ;)    ** \n";
    std::cout << "                   **                             ** \n";
    std::cout << "                   **                             ** \n";
    std::cout << "                   **       @Ungureanu Raul       ** \n";
    std::cout << "                   **                             ** \n";
    std::cout << "                   **            2024             ** \n";
    std::cout << "                   **                             ** \n";
    std::cout << "                   **             **              ** \n";
    std::cout << "                   ********************************* \n";




    //initializez caracterele din poveste





    //player-ul principal
    cul(7);
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "############################################################################## \n";
    std::cout << "#                                                                            # \n";
    std::cout << "#         Salut, ai amnezie si ai uitat cum te numesti. Dati un nume:        # \n";
    std::cout << "#                                                                            # \n";
    std::cout << "############################################################################## \n";
    std::cout << "\n";
    std::cout << "\n";
    fatainchis();
    cul(5);
    std::cout << "\n";
    std::cout << "\n";
    std::string playerName;
    std::cin >> playerName;
    std::cout << "\n";
    std::cout << "\n";
    cul(7);
    fatadeschis();


    //sidekick-ul
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "############################################################################## \n";
    std::cout << "#                                                                            # \n";
    std::cout << "#              Aaa, si daca ai avea un prieten, cum l-ar chema?              # \n";
    std::cout << "#                                                                            # \n";
    std::cout << "############################################################################## \n";
    std::cout << "\n";
    std::cout << "\n";
    fatainchis2();
    cul(5);
    std::cout << "\n";
    std::cout << "\n";
    std::string bffName;
    std::cin >> bffName;
    std::cout << "\n";
    std::cout << "\n";
    cul(7);
    fatadeschis2();
    std::cout << "\n";
    std::cout << "\n";

    Player player(playerName);
    Player bff(bffName);

    //Vilan-ul
    Player demon("AsHaLiSaLaMdArNaM");


    player.addItem("Portofel");


    //incepe poveste cu act-ul 1
    act1(player, demon, bff);

    //verific daca a murit jucatorul dupla actul 1

    if (player.health > 0)
    {
        cul(14);
        std::cout << "\n";
        system("pause"); // trebuie dat un imput ca sa se treaca la urmatorul act ca sa nu dispara story-ul din terminal deoarece am folosit "cls" la inceputul actului 2
        cul(7);
        //Daca nu, trec mai departe
        act2(player, demon, bff);
        act3(player, demon, bff);
        final2();
        std::cout << "\n";
        gata();

    }


    else
    {

        //daca da e game over
        final1(player, demon);
        std::cout << "\n";
        gameover();

        //posibilitate de restart
        std::cout << "\n";
        std::cout << "\n";
        std::cout << "\n";
        cul(5);
        std::cout << "Vrei sa mai joci o data?\n";
        std::cout << "\n";
        cul(14);
        std::cout << "Yes (Y) / No (N)\n";
        cul(7);
        std::cout << "\n";
        std::string action6;
        std::cin >> action6;
        std::cout << "\n";

        if (action6 == "Y" xor action6 == "y")
        {
            system("cls");
            system("pause");
            //player-ul principal
            cul(7);
            std::cout << "\n";
            std::cout << "\n";
            std::cout << "############################################################################## \n";
            std::cout << "#                                                                            # \n";
            std::cout << "#         Salut, ai amnezie si ai uitat cum te numesti. Dati un nume:        # \n";
            std::cout << "#                                                                            # \n";
            std::cout << "############################################################################## \n";
            std::cout << "\n";
            std::cout << "\n";
            fatainchis();
            cul(5);
            std::cout << "\n";
            std::cout << "\n";
            std::string playerName;
            std::cin >> playerName;
            std::cout << "\n";
            std::cout << "\n";
            cul(7);
            fatadeschis();


            //sidekick-ul
            std::cout << "\n";
            std::cout << "\n";
            std::cout << "############################################################################## \n";
            std::cout << "#                                                                            # \n";
            std::cout << "#              Aaa, si daca ai avea un prieten, cum l-ar chema?              # \n";
            std::cout << "#                                                                            # \n";
            std::cout << "############################################################################## \n";
            std::cout << "\n";
            std::cout << "\n";
            fatainchis2();
            cul(5);
            std::cout << "\n";
            std::cout << "\n";
            std::string bffName;
            std::cin >> bffName;
            std::cout << "\n";
            std::cout << "\n";
            cul(7);
            fatadeschis2();
            std::cout << "\n";
            std::cout << "\n";

            Player player(playerName);
            Player bff(bffName);

            //Vilan-ul
            Player demon("AsHaLiSaLaMdArNaM");


            player.addItem("Portofel");


            //incepe poveste cu act-ul 1
            act1(player, demon, bff);

            //verific daca a murit jucatorul dupla actul 1

            if (player.health > 0)
            {
                cul(14);
                std::cout << "\n";
                system("pause"); // trebuie dat un imput ca sa se treaca la urmatorul act ca sa nu dispara story-ul din terminal deoarece am folosit "cls" la inceputul actului 2
                cul(7);
                //Daca nu, trec mai departe
                act2(player, demon, bff);
                act3(player, demon, bff);
                final2();
                std::cout << "\n";
                gata();

            }


            else
            {

                //daca da e game over
                final1(player, demon);
                std::cout << "\n";
                gameover();

                //posibilitate de restart
                std::cout << "\n";
                std::cout << "\n";
                std::cout << "\n";
                cul(5);
                std::cout << "Vrei sa mai joci o data?\n";
                std::cout << "\n";
                cul(14);
                std::cout << "Yes (Y) / No (N)\n";
                cul(7);
                std::cout << "\n";
                std::string action6;
                std::cin >> action6;
                std::cout << "\n";

                if (action6 == "Y" xor action6 == "y")
                {

                }

            }
            if (action6 == "n" xor action6 == "N") {


                gata();
            }


        }
    }
}
