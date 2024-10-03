#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <thread> 
#include <chrono>
#include <mmsystem.h>


#pragma comment(lib, "winmm.lib")







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


//fata inainte de numirea player-ului
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

//grafica de inceput
void inceput()
{
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
}


void fatahorror() {
    std::cout << "    <#################>" << std::endl;
    std::cout << "  <#####################>" << std::endl;
    std::cout << " <#######################>" << std::endl;
    std::cout << "<#########################>" << std::endl;
    std::cout << "<#####____#########____#####>" << std::endl;
    std::cout << "<###/      \\ ### /      \\###>" << std::endl;
    std::cout << "<##|          | # |        |##>" << std::endl;  
    std::cout << "<##|    (   ) | # |  (   ) |##>" << std::endl;  
    std::cout << "<##|          | # |        |##>" << std::endl;  
    std::cout << "<## \\_______/ ### \\______/ ##>" << std::endl;
    std::cout << "  <#########   ############>" << std::endl;
    std::cout << "  <########    ###########>" << std::endl;
    std::cout << "   <######       #########>" << std::endl;
    std::cout << "   <#####       ##########>" << std::endl;
    std::cout << "     <#####       #########>" << std::endl;
    std::cout << "   <######  _____ ########>" << std::endl;
    std::cout << "   <##                #####>" << std::endl;
    std::cout << "   <####              ####>" << std::endl;
    std::cout << "     <###################>" << std::endl;
    std::cout << "      <################>" << std::endl;


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


void printWithDelay(const std::string& text, int delayMilliseconds) {
    for (char ch : text) {
        std::cout << ch; // Print each character
        std::cout.flush(); // Immediately print to console
        std::this_thread::sleep_for(std::chrono::milliseconds(delayMilliseconds)); // Delay
    }
    std::cout << std::endl; // Move to the next line after printing the message
}


void jumpscare()
{
   /* std::cout << "@@@@@@@@@@..................................J@@@@@@@@@ \n";
    std::cout << "@@@@@@@@d < ..................................., @@@@@@@@ \n";
    std::cout << "@@@@@@@d.......................................J@@@@@@\n";
    std::cout << "@@@@@@@d....................................... - @@@@@@\n";
    std::cout<<"@@@@@@a < ........................................@@@@@a \n";
    std::cout<<"@@@@@d1.........................................@@@@@M \n";
    std::cout<<"@@@@@M - .........................................@@@@@@ \n";
    std::cout<<"@@@@ / d1.........................................J@@@@@ \n";
    std::cout<<"@@@@@@@.........................................r@@@@@ \n";
    std::cout<<"@@@@M@M, .........................................@@@@@\n";
    std::cout<<"@@@@a@@, ......J@@@@@l..............c@@@@@Jl......@@@@@\n";
    std::cout<<"@@@@@@@....l@@1...@@@@ - ..........Z@@@MdZ@@@@@ < ..1@@@@@\n";
    std::cout<<"@@@@@@M.. / @@a..l... < @@@@ - ......a@@@.......@@@l..@@@@@@\n";
    std::cout<<"@@@@@@@l < @@@@..@@..1@@@@......, @@@@...@ / ..@@@@1d@@@@@@\n";
    std::cout<<"@@@@M@ad. < d@@ / < l <, r@@@@@...... - @@@@@M... - @@@@ / c@@@@@@@\n";
    std::cout<<"@@@@@@@r.....@ZJ1l....ca...........@@@M@a / .....@@@@@@@\n";
    std::cout<<"@@@@@@@Z............... / ...................... - @@@@@@@\n";
    std::cout<<"aM@@@@@@ - .............. < ......................M@@@@@@@\n";
    std::cout<<"M@@@@@@@d.............., .....................1@@@@@@@@\n";
    std::cout<<"MMM@@@@@c...................................la@@@@@@@@\n";
    std::cout<<"M@@MMM@@@1..................................Z@@@@@@@@@\n";
    std::cout<<"aMMMMM@@@d..........., M@J..................M@@@@@@@@@@\n";
    std::cout<<"@@@@@@@@@@l..........d@@aJ................d@@@@@@@@@@@\n";
    std::cout<<"@@@@@@@@@@l.........rM@@@@J..J@l..........@@@@@@@@@@@@\n";
    std::cout<<"@@@@@@@@@a - ........ < M@@@@@@@@@c...........@@@@@@@@@@@@\n";
    std::cout<<"M@@@@@@@@@r......., @@@@@@@M - , ............@@@@@@@@@@@@@\n";
    std::cout<<"M@@@@@@@@@ - ......d@@@@r..................M@aa@@@@@@@@@\n";
    std::cout<<"MM@@@@@@@@1...Z@@@@@@c..................a@@ < d@@@@@@@@@\n";
    std::cout<<"MM@@@@MMa / r, cMa@@@@@@@a@ad11 / rd@@@@@@@@@@@r, M@@@@@@@@@\n";
    std::cout<<"M@MM@@@@@ad@@@@@@@@@@@@@@@@@@@@@@@@@@@@Z / ..l@@@@@@@@@@\n";
    std::cout<<"M@@@M@@@@@@@@@@@@@@@@@@@@@@@@@@@M@@@@@M.... - Ma@@@@@@@@\n";
    std::cout<<"M@M@M@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@J......da@@@@@@@@\n";
    std::cout<<"M@@MM@@@@@@@@@@@@@@@@@@@@@@@@@@ZJ1 <, .....l..JcM@@@@@@@\n";
    std::cout<<"M@@@M@@@@@@@@@@@@@@@@@@@@@@r / -/ < / r < ..... - l.. / r@a@@@@@@\n";
    std::cout<<"M@@M@@@@@@@@@@@@@@@@@@@@@@@a@Jccc < .., 1d / l.., -r@@@@@@@@\n";
    std::cout<<"MM@MM@@@@@@@@@@@@@@@@@J......., ....lJZa1....cZ@a@@@@@@\n";
    std::cout<<"@@@@@@@@@@@@@@@@@@@@@@r.........., ZJJZdl...l - / M@@@@@@@\n";
    std::cout<<"MM@MMM@@@@@@@@@@@@@@@@@Mc, ... - / cdZccJ / ...., J / @@@@@@@@@\n";
    std::cout<<"M@@@MM@@@@@@@@@@@@@@@@@@@@@@@MrccrJrl.....rc@@@@@@@@@@\n";
    std::cout<<"dMMMMM@@@@@@@@@@@@@@@@@dMZ - ................ < d@@@@@@@@@\n";*/


        std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
        std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
        std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
        std::cout << "@@@@@@@@@@@@@@@@@@@@@@%%%%%%%%%%%%%@@@@@@@@@@@@@@@@@@@@@@@@@\n";
        std::cout << "@@@@@@@@@@@@@@@@@@@%##**++++++=++**###*##%@@@@@@@@@@@@@@@@@@\n";
        std::cout << "@@@@@@@@@@@@@@%%%#*+=:::::......::::---++*#%%@@@@@@@@@@@@@@@\n";
        std::cout << "@@@@@@@@@@@@%%#**+=:..................:::::-+###%%@@@@@@@@@@\n";
        std::cout << "@@@@@@@@@%%%#*==-:...........................:===*#%%@@@@@@@\n";
        std::cout << "@@@@@@@@%%%#**+--::.........................::-=+**%@@@@@@@@\n";
        std::cout << "@@@@@@@@%###*=-:::..........................:::-=+++#@@@@@@@\n";
        std::cout << "@@@@@@@%%#*++=--:::.........................:::--==+#@@@@@@@\n";
        std::cout << "@@@@@@@@%*++===---:::......................::----+=+*@@@@@@@\n";
        std::cout << "@@@@@@@@%**++++++=-::::::...........::--+*%@@@@@@@@@@@@@@@@@\n";
        std::cout << "@@@@@@@@@@@@@@@@@@@@@@@%+=--::::--+*#%@@@@@@@@@@@@@@@@@@@@@@\n";
        std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@%+--:=+#%@@@@@@+:::=*@@@@@@@@@@@@@\n";
        std::cout << "@@@@@@@@@@@@@@@%**-:#@@@@@@#=--=*@@@@@@%:*@@@%:*@@@@@@@@@@@@\n";
        std::cout << "@@@@@@@@@@@@@#:#@@@@::@@@@@@+::-+@@@@@@:.%@@@@+#@@@@@@@@@@@@\n";
        std::cout << "@@@@@@@@@@@@@@+#@@@@=*@@@@@@*::-+@@@@@@@@@@%@@@@@@@@@@@@@@@@\n";
        std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@%=-:-=%@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
        std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@*-:.:-*@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
        std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@%+:....-#@@@@@@@@@@@@@@@@@@@@@@@@@\n";
        std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@#=:....:-**++*###%%%%#**++=*#@@@@@\n";
        std::cout << "@@@@@@@%+=-==+**#%%%%%##%#*+:....:--:------====-:::::-+#@@@@\n";
        std::cout << "@@@@@@#=:.....:::==++*#@*==-:.....:-:::---=-::::......:=#@@@\n";
        std::cout << "@@@@%+-.........::-+*=##=+*+:......=-:::::-==-::......:-+@@@\n";
        std::cout << "@@@@*-:.......::-+##---++=%@*:::::*%-==:..::-%#--:....:-+%@@\n";
        std::cout << "@@@%*-:.....::-=*%-:.........::==::.........--=%@=::::-++#@@\n";
        std::cout << "@@@%+=-::::::-*@%-:........................:--++=#%=--=#+#@@\n";
        std::cout << "@@@%*=+--::-=%@#+--:......................:--+**+=#+--*%#%@@\n";
        std::cout << "@@@%+=**--:-%%#**++----::::.........::-=+#%@@@@@@@@--=#@#@@@\n";
        std::cout << "@@@%=--#*-:-%@@@@@@@@@@@%%@@%%@@%%%=+##%%@%@@@@@@*-::=%#%@@@\n";
        std::cout << "@@@%*--*%-:::%@@@@*##*.=:.#:....*....=:.%-+*%@@%*:..-#%#@@@@\n";
        std::cout << "@@@@#+=+%#-:.:#@#@@@@%-+-.::....:....:.-#.%@%@@=...-*@#%@@@@\n";
        std::cout << "@@@@@#+-+@*:..:+%@%*:=*@##**::::=...:#*-*=%%@+:...:+%+#@@@@@\n";
        std::cout << "@@@@@@#*+#@-....-*@@@%+#---.:-..*..*::--%@#+-.....-%#%@@@@@@\n";
        std::cout << "@@@@@@@%#*%%:....:-*#%%%@@@%##++*++==::-=--:.....:*%%@@@@@@@\n";
        std::cout << "@@@@@@@@@%%@*:.......:---=---=--:::::::::......::+@@@@@@@@@@\n";
        std::cout << "@@@@@@@@@@@@@=:..............................::+#@@@@@@@@@@@\n";
        std::cout << "@@@@@@@@@@@@@@#=-:..........................:=#@@@@@@@@@@@@@\n";
        std::cout << "@@@@@@@@@@@@@@@%*=-:......................:-+%@@@@@@@@@@@@@@\n";
        std::cout << "@@@@@@@@@@@@@@@@@@#+-:..................:-*%@@@@@@@@@@@@@@@@\n";
        std::cout << "@@@@@@@@@@@@@@@@@@@@@#=-::...........::=#@@@@@@@@@@@@@@@@@@@\n";
        std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@%#*+----::--=*%@@@@@@@@@@@@@@@@@@@@@\n";
        std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
        std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";









}


// codul pentru story-ul din actul 1
void act1(Player& player, Player& demon, Player& bff)
{
    //system("pause");
    system("cls");                                                                                            // golirea consolei
    cul(7);                                                                                                   // schimbarea culorii in terminal
    std::cout << "\n";
    printWithDelay("Este sambata seara, esti singur acasa si stai pe canapea la TV \n",75);  
    printWithDelay("Ai chef sa: \n",75);
    cul(14);
    std::cout << "Mananci (M) / Vezi un film (F) /  Sa joci ceva (J) \n";
    cul(7);
    std::cout << "\n";
    std::string action;
    std::cin >> action;
    if (action == "M" xor action == "m") {
        std::cout << "\n";
        printWithDelay("Intri in bucatarie...\n",75);
        printWithDelay("Este intuneric asa ca te impiedici de covor si pici...\n",75);
        PlaySound(TEXT("pici.wav"), NULL, 0);
        cul(4);
        std::cout << "\n";
        std::cout << "-7 HP\n";
        player.takeDamage(7);
        player.showStatus();
        cul(7);
        std::cout << "\n";
        printWithDelay("Te ridici si :\n",75);
        cul(14);
        std::cout << "Iesi din Bucatarie(I)/Aprinzi becul(L)/Injuri(F)\n";
        cul(7);
        std::cout << "\n";
        std::string decision;
        std::cin >> decision;
        if (decision == "I" xor decision == "i")
        {
            std::cout << "\n";
            printWithDelay("Te intorci in sufragerie.\n",75);
            std::cout << "\n";
        }
        else if (decision == "L" xor decision == "l") {
            std::cout << "\n";
            printWithDelay(" Aprinzi becul, deschizi frigiderul dar nu ai nimic de mancare... \n",75);
            cul(4);
            printWithDelay("Emotional Damage!\n",75);
            std::cout << "\n";
            std::cout << "-10 HP\n";
            player.takeDamage(10);
            player.showStatus();
            std::cout << "\n";
            cul(7);
            printWithDelay("Decizi sa te intorci in sufragerie\n",75);
        }
        else if (decision == "F" xor decision == "f") {
            std::cout << "\n";
            printWithDelay("Injuri si te descarci\n",75);
            std::cout << "\n";
            cul(2);
            std::cout << "+7 HP\n";
            player.healDamage(7);
            player.showStatus();
            cul(7);
            std::cout << "\n";
            printWithDelay("Te simti mai bine acum ca te-ai descarcat asa ca uiti de foame si te intorci in sufragerie.\n",75);
            std::cout << "\n";
        }
    }
    else if (action == "F" xor action == "f") {
        std::cout << "\n";
        printWithDelay("Stai si te gandesti ce ai vrea sa vezi.\n",75);
        printWithDelay("Te ridici si cauti prin filmele pe care le ai disponibile.\n",75);
        printWithDelay("Observi un Blu-Ray ciudat pe care nu l-ai mai vazut niciodata.\n",75);
        printWithDelay("Inspectezi mai in deaprope. Descrierea de pe spatele case-ului este scrisa intr-un dialect necunoscut.\n",75);
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
            printWithDelay(": In sfarsit am fost eliberat!!! Muhahaha (ras malefic)\n",50);
            cul(3);
            std::cout << player.name;
            cul(7);
            printWithDelay(":Ce vrei de la mine?!\n",50);
            cul(12);
            std::cout << demon.name;
            cul(7);
            printWithDelay(": TU!\n",200);

            std::cout << "\n";
            printWithDelay("Te uiti in jur si vezi o icoana, un crucifix si un Snikers.\n",75);
            printWithDelay("Cu ce alegi sa te aperi?\n",75);
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
                printWithDelay(": Chiar crezi ca o sa te ajute?! Te crezi in filme horror? Ce o sa imi faci? O incantatie?\n",50);
                cul(3);
                std::cout << player.name;
                cul(7);
                printWithDelay(":Aaa, da? \n",50);
                printWithDelay("Vezi ca nu este outcome-ul pe care l-ai asteptat asa ca ... Arunci cu icoana dupa el.\n",75);
                cul(6);
                std::cout << "Inafective....who would it taught...\n";
                cul(12);
                std::cout << demon.name;
                cul(7);
                printWithDelay(":WTF dude?! \n",50);
                cul(12);
                std::cout << demon.name;
                cul(7);
                printWithDelay(":Ce prost crescut... \n", 50);
                cul(12);
                std::cout << demon.name ;
                cul(7);
                printWithDelay(" left the chat...\n",50);
                std::cout << "\n";
                std::cout << "\n";
                std::cout << "\n";
                printWithDelay("Te reintorci in sufragerie bulversat de ceea ce tocmai ai trait \n",75);
                std::cout << "\n";
            }
            else if (decision2 == "S" xor decision2 == "s") {
                std::cout << "\n";
                printWithDelay("Aparent Demonului doar ii era foame asa ca te lasa in pace si pleaca\n",75);
                printWithDelay("Cine se astepta la asta?\n",75);
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
                printWithDelay(": Dude... Serios? Ceva mai cliseic nu ai gasit?\n",50);
                std::cout << "\n";
                printWithDelay("*Nu a avut efectul dorit de tine* \n",75);
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
            printWithDelay("Toate semnele indica ca nu ar fi o idee buna sa il vizionezi.\n",75);
            printWithDelay("Pentru prima oara in istoria cinematografiei Horror, cand ceva pare dubas cineva a decis sa aleaga varianta smart.\n",75);
            std::cout << "\n";
            cul(2);
            player.healDamage(100);
            player.showStatus();
            std::cout << "bonus de la developer pentru ca nu ti-ai satisfacut curiozitatea (ai viata full ) ;) \n";
            std::cout << "\n";
            cul(7);
            printWithDelay("Te reintorci in sufragerie. \n",75);
            std::cout << "\n";
        }
    }
    else if (action == "J" xor action == "j") {
        std::cout << "\n";
        printWithDelay("Ai chef de un shooter dar... Nu ai PC...\n",75);
        cul(4);
        std::cout << "\n";
        std::cout << "Emotional Damage!\n";
        std::cout << "-20 HP\n";
        player.takeDamage(20);
        player.showStatus();
        std::cout << "\n";
        cul(7);
        printWithDelay("Te reintorci in sufragerie. \n",75);
        std::cout << "\n";
    }
   
    
    
}



//codul pentru actul 2
void act2(Player& player, Player& demon, Player& bff)
{
    
   
    std::cout << "\n";
    system("cls");
    std::cout << "\n";
    printWithDelay("Asa cum am spus, te intorci in sufragerie.\n",75);
    printWithDelay("Care este urmatorul lucru pe care il faci?\n",75);
    cul(14);
    std::cout << "Iti suni cel mai bun prieten ca sa ii povestesti ce ai patit (S) / Fumezi o tigara (F) / Iesi un pic sa te plimbi ca sa te linistesti (I)\n";
    std::string action;
    cul(7);
    std::cout << "\n";
    std::cin >> action;
 
    std::cout << "\n";
    if (action == "S" xor action == "s")
    {
        std::cout << "\n";
        printWithDelay("Iti cauti telefonul dar nu il gasesti\n",75);
        cul(14);
        std::cout << "Cauti sub pernele canapelei (C) / Aprinzi Flashligh-ul si il cauti sub canapea (A)\n";
        std::string action2;
        cul(7);
        std::cout << "\n";
        std::cin >> action2;
        
        std::cout << "\n";
        if (action2 == "C" xor action2 == "c")
        {
            std::cout << "\n";
            printWithDelay("Bingoo! L-ai gasit.\n",75);
            cul(3);
            player.addItem("Telefon");
            cul(7);
            std::cout << "\n";
            printWithDelay("Selectezi ",75);
            cul(11);
            std::cout << bff.name;
            cul(7);
            printWithDelay(" din agenda si apelezi.\n",75);
            printWithDelay("......\n",75);
            printWithDelay(".......\n",75);
            printWithDelay("........\n",75);
            PlaySound(TEXT("sunettelefon.wav"), NULL, 0);
            printWithDelay("'Abonatul apelat .....\n",75);
            cul(3);
            std::cout << player.name;
            cul(7);
            printWithDelay(":Perfect, nu raspunde. De ce nu ma mira?\n",75);
        }
        else if (action2 == "A" xor action2 == "a")
        {
            std::cout << "\n";
            printWithDelay("Cum ai aprins flashlight-ul TELEFONULUI daca se presupune ca tu 'nu iti gasesti telefonul?\n",75);
            printWithDelay("De rusine ai renuntat la telefon pentru restul jocului \n",75);
            std::cout << "\n";
        }
    }
    else if (action == "F" xor action == "f")
    {
        std::cout << "\n";
        printWithDelay("Scoti o tigara din pachet, o pui in gura si ti-o aprinzi\n",75);
        std::cout << "\n";
        cul(4);
        std::cout << "-10 HP\n";
        player.takeDamage(10);
        player.showStatus();
        std::cout << "\n";
        printWithDelay("Fumatul dauneaza grav sanatatii tale si a celor din jur!\n",75);
        std::cout << "\n";
        cul(7);

    }
    else if (action == "I" xor action == "i")
    {
        printWithDelay("Pui mana pe clanta ca sa iesi din casa dar te gandesti daca iti iei telefonul cu tine sau nu.\n",75);
        cul(14);
        std::cout << "\n";
        std::cout << "Il iei? Yes (Y) / No (N) \n";
        std::string action3;
        cul(7);
        std::cout << "\n";
        std::cin >> action3;
        std::cout << "\n";

        if (action3 == "Y" xor action3 == "y")
        {
            std::cout << "\n";
            printWithDelay("Te-ai intors si ti-ai luat telefonul de sub pernele de pe canapea.\n",75);
            std::cout << "\n";
            cul(3);
            player.addItem("Telefon");
            std::cout << "\n";
            cul(7);
         

        }
        else if (action3 == "N" xor action3 == "n")
        {
            std::cout << "\n";
            printWithDelay("Ai decis ca in acesata lume extrem de interconenctata mai ai nevoie si de o pauza de la technologie asa ca il lasi acasa\n",75);
            std::cout << "\n";
        }
        

    }

   
}


//codul pentru actul 3
void act3(Player& player, Player& demon, Player& bff)
{
    std::cout << "\n";
    printWithDelay("Iesi pe usa apartamentului si te duci sa te plimbi\n",75);
    PlaySound(TEXT("doorclose.wav"), NULL, 0);
    std::cout << "\n";
    printWithDelay("Te simti urmarit...\n",75);
    printWithDelay("Te uiti in dreapta....stanga...spate ...\n",75);
    std::cout << "Nimic\n";
    cul(3);
    std::cout << player.name ;
    cul(7);
    printWithDelay(" :sunt doar paranoic!\n",50);
    cul(3);
    std::cout << player.name;
    cul(7);
    printWithDelay(" :Credeam ca aerul curat te ajuta sa te simti mai bine\n",50);
    cul(11);
    std::cout << "....";
    cul(7);
    printWithDelay(":ce zici ca faci?\n",50);
    std::cout << "\n";
    printWithDelay("Simiti o mana ce te antinge pe umarul drept.\n", 75);
    printWithDelay("Tresari initial dar realizezi ca este ",75);
    cul(11);
    std::cout << bff.name << "\n";
    cul(3);
    std::cout << "\n";
    std::cout << player.name;
    cul(7);
    printWithDelay(" :Ce m-ai speriat!\n",50);
    cul(11);
    std::cout << bff.name ;
    cul(7);
    printWithDelay(" :Ce tressari asa ? Esti ok?\n",50);
    cul(3);
    std::cout << player.name;
    cul(7);
    printWithDelay(" :Da...Cred ca sunt doar un pic paranoic.\n",50);
    cul(11);
    std::cout << bff.name ;
    cul(7);
    printWithDelay(" :Pai?\n",50);
    cul(3);
    std::cout << player.name;
    cul(7);
    printWithDelay(" :Mi se parea ca sunt urmarit....\n",50);
    cul(11);
    std::cout << bff.name ;
    cul(7);
    printWithDelay(" :...\n",50);
    cul(3);
    std::cout << player.name;
    cul(7);
    printWithDelay(" :...\n",50);
    std::cout << "\n";
    printWithDelay("O ceata deasa incepe sa se lase in jurul vostru.\n",75);
    printWithDelay("Simtiati ca ceva nu este ok.\n",75);
    std::cout << "\n";
    std::cout << "\n";
    cul(10);
    jumpscare();
    cul(7);
    std::cout << "\n";
    std::cout << "\n";
    Sleep(500);
    //cul(12);
    //std::cout << demon.name;
    //cul(7);
    //std::cout << ":Muhuhahaha \n";
    cul(11);
    std::cout << bff.name;
    cul(7);
    printWithDelay(" :E cineva acolo?\n",50);
    cul(3);
    std::cout << player.name;
    cul(7);
    printWithDelay(" Hai sa plecam de aici!\n",50);
    cul(12);
    std::cout << demon.name;
    cul(7);
    printWithDelay(":Nimeni nu pleaca nicaieri! \n",50);
    std::cout << "\n";
    std::cout << "\n";
    printWithDelay("In fata voastra apare o umbra inalta, fara fata, ce va inducea un sentiment neplacut.\n",75);
    cul(3);
    std::cout << player.name;
    cul(7);
    printWithDelay(" Ce esti?\n",50);
    cul(11);
    std::cout << bff.name;
    cul(7);
    printWithDelay(" :Ce vrei?\n",50);
    std::cout << "\n";
    printWithDelay("Brusc, figura aparuta se repede catre voi.\n",75);
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
        printWithDelay(": Serios bro?\n",50);
        cul(3);
        std::cout << player.name;
        cul(7);
        printWithDelay(": Fiecare pentru el!\n",50);
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
        //std::cout << "          ######################################################\n";
       // std::cout << "          #                                                    #\n";
        //std::cout << "          #                  Lessons learned!                  #\n";
        //std::cout << "          #         In viata trebuie sa ai integritate         #\n";
        //std::cout << "          #          si sa iti lasi loc de buna-ziua!          #\n";
       // std::cout << "          #                                                    #\n";
       // std::cout << "          ######################################################\n";
    }

   
    if (decision == "G" xor decision == "g") {

        cul(3);
        std::cout << player.name;
        cul(7);
        std::cout << ": ";
        cul(11);
        std::cout << bff.name;
        cul(7);
        printWithDelay(" pune-te in spatele meu!!\n",50);
        cul(3);
        std::cout << player.name;
        cul(7);
        printWithDelay(": it's not my first rodeo...\n",50);
        cul(3);
        std::cout << player.name;
        cul(7);
        std::cout << ": ";
        cul(12);
        std::cout << demon.name;
        cul(7);
        printWithDelay(" zi ce vrei!\n",50);
        std::cout << "\n";
        printWithDelay("Incepi sa cauti prin buzunare sa vezi daca ai ceva la tine sa te ajute\n",75);
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
            printWithDelay("Iti scoti portofel din buzunar, in dechizi si scoti o bancnota de 10 lei si o intinzi catre el.\n",75);
            std::cout << "\n";
            cul(3);
            std::cout << player.name;
            cul(7);
            printWithDelay(":Ajung de o bere!\n",50);
            cul(12);
            std::cout << demon.name;
            cul(7);
            printWithDelay(": CE?\n",50);
            cul(3);
            std::cout << player.name;
            cul(7);
            printWithDelay(":Ia de aici si dui de aici!\n",50);
            cul(12);
            std::cout << demon.name;
            cul(7);
            printWithDelay(":Omule, ce drac zici?! *Pun intended*\n",50);
            cul(3);
            std::cout << "\n";
            std::cout << "\n";
            std::cout << bff.name;
            cul(7);
            std::cout << ": ";
            cul(11);
            std::cout <<  player.name;
            cul(7);
            printWithDelay(" ce faci? crezi ca ajuta cu ceva?\n",50);
            cul(11);
            std::cout << player.name;
            cul(7);
            printWithDelay(": Watch and learn!\n",50);
            std::cout << "\n";
            std::cout << "\n";
            cul(3);
            std::cout << player.name;
            cul(7);
            printWithDelay(": Traiesti in Romania?!\n",50);
            cul(12);
            std::cout << demon.name;
            cul(7);
            printWithDelay(": CE?\n",50);
            cul(3);
            std::cout << player.name;
            cul(7);
            printWithDelay(": TRAIESTI in Romania?!\n",50);
            cul(12);
            std::cout << demon.name;
            cul(7);
            printWithDelay(": Da?\n",50);
            cul(3);
            std::cout << player.name;
            cul(7);
            printWithDelay(": Oreste ceata!\n",50);
            cul(3);
            std::cout << player.name;
            cul(7);
            printWithDelay(": OPRESTE CEATA!\n",50);
            cul(12);
            std::cout << demon.name;
            cul(7);
            printWithDelay(":Nu mai inteleg nimic....\n",50);
            std::cout << "\n";
            std::cout << "\n";
            printWithDelay("Bulversat, ",75);
            cul(12);
            std::cout << demon.name;
            cul(7);
            printWithDelay(" pleca neintelegand ce s-a intamplat.\n",75);
            std::cout << "\n";
            std::cout << "\n";
            cul(11);
            std::cout << player.name;
            cul(7);
            printWithDelay(":Ti-am zis ca stiu ce fac!\n",50);
            cul(11);
            std::cout << bff.name;
            cul(7);
            printWithDelay(": What did I just witnesed?!\n",50);

           /* if (choice == "Telefon" xor choice == "telefon")
            {
                player.useItem("Telefon");

            }*/
        }
        
        else
        {
            printWithDelay("Nope, nu ajuta! \n",75);
            printWithDelay("Ne prefacem ca ai ales 'Portofel' si continuma story-ul. \n",75);
            std::cout << "\n";
            std::cout << "\n";
            std::cout << "\n";
            printWithDelay("Iti scoti portofel din buzunar, in dechizi si scoti o bancnota de 10 lei si o intinzi catre el.\n", 75);
            std::cout << "\n";
            cul(3);
            std::cout << player.name;
            cul(7);
            printWithDelay(":Ajung de o bere!\n", 50);
            cul(12);
            std::cout << demon.name;
            cul(7);
            printWithDelay(": CE?\n", 50);
            cul(3);
            std::cout << player.name;
            cul(7);
            printWithDelay(":Ia de aici si dui de aici!\n", 50);
            cul(12);
            std::cout << demon.name;
            cul(7);
            printWithDelay(":Omule, ce drac zici?! *Pun intended*\n", 50);
            cul(3);
            std::cout << "\n";
            std::cout << "\n";
            std::cout << bff.name;
            cul(7);
            std::cout << ": ";
            cul(11);
            std::cout << player.name;
            cul(7);
            printWithDelay(" ce faci? crezi ca ajuta cu ceva?\n", 50);
            cul(11);
            std::cout << player.name;
            cul(7);
            printWithDelay(": Watch and learn!\n", 50);
            std::cout << "\n";
            std::cout << "\n";
            cul(3);
            std::cout << player.name;
            cul(7);
            printWithDelay(": Traiesti in Romania?!\n", 50);
            cul(12);
            std::cout << demon.name;
            cul(7);
            printWithDelay(": CE?\n", 50);
            cul(3);
            std::cout << player.name;
            cul(7);
            printWithDelay(": TRAIESTI in Romania?!\n", 50);
            cul(12);
            std::cout << demon.name;
            cul(7);
            printWithDelay(": Da?\n", 50);
            cul(3);
            std::cout << player.name;
            cul(7);
            printWithDelay(": Oreste ceata!\n", 50);
            cul(3);
            std::cout << player.name;
            cul(7);
            printWithDelay(": OPRESTE CEATA!\n", 50);
            cul(12);
            std::cout << demon.name;
            cul(7);
            printWithDelay(":Nu mai inteleg nimic....\n", 50);
            std::cout << "\n";
            std::cout << "\n";
            printWithDelay("Bulversat, ", 75);
            cul(12);
            std::cout << demon.name;
            cul(7);
            printWithDelay(" pleca neintelegand ce s-a intamplat.\n", 75);
            std::cout << "\n";
            std::cout << "\n";
            cul(11);
            std::cout << player.name;
            cul(7);
            printWithDelay(":Ti-am zis ca stiu ce fac!\n", 50);
            cul(11);
            std::cout << bff.name;
            cul(7);
            printWithDelay(": What did I just witnesed?!\n", 50);
        }
              

    }
}


//codul pentru finalul jocului
void final2()
{
    std::cout << "\n";
    std::cout << "\n";
    printWithDelay("Auzi o alarma!\n",75);
    std::cout << "\n";
    PlaySound(TEXT("alarma.wav"), NULL, 0);
    printWithDelay("Trrr!\n",125);
    std::cout << "\n";
    PlaySound(TEXT("alarma.wav"), NULL, 0);
    printWithDelay("Trrr!\n",125);
    std::cout << "\n";
    PlaySound(TEXT("alarma.wav"), NULL, 0);
    printWithDelay("Trrr!\n",125);
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
    printWithDelay("Deschizi ochii si realizezi ca totul a fost doar un vis!\n",75);
    std::cout << "\n";
    std::cout << "\n";
}


//finalul daca mori in actul 1
void final1(Player& player, Player& demon) 
{
    std::cout << "\n";
    printWithDelay("Sa spunem ca din pacate, ",75);
    cul(12);
    std::cout << demon.name;
    cul(7);
    printWithDelay(" a fost prea puternic pentru tine\n ",75);
    printWithDelay("(Ca sa nu ne reamintim de cliseul care te-a omorat) ",75);
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
    inceput();




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


    Sleep(5600);
    system("cls");
    cul(10);
    fatahorror();
    PlaySound(TEXT("scarysound.wav"), NULL, 0);
    cul(7);
    //verific daca a murit jucatorul dupla actul 1

    if (player.health > 0)
    {
        cul(14);
        std::cout << "\n";
        //system("pause"); // trebuie dat un imput ca sa se treaca la urmatorul act ca sa nu dispara story-ul din terminal deoarece am folosit "cls" la inceputul actului 2
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


            Sleep(5600);
            system("cls");
            cul(10);
            fatahorror();
            PlaySound(TEXT("scarysound.wav"), NULL, 0);
            cul(7);

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


                gata();

            }









        }
    }
}