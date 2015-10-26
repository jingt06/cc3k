#include"print.h"
#include<iostream>
using namespace std;
void printRace(){
	cout<<"please select your race"<<endl;
	cout<<"h: Human----- Humans were primarily a scattered and tribal people for several millennia, until the rising strength of the troll empire forced their strategic unification. "<<endl;// initial HP: 140, Atk: 20, Def:20 
	cout<<endl<<endl;
	cout<<"e: Elves-----The Elves are not subject to disease or physical aging, though they could be killed by violence or by wasting away and losing the will to live. They were otherwise essentially immortalinitial"<<endl;// HP: 140, Atk: 30, Def:10
	cout<<endl<<endl;
	cout<<"d: Dwarf-----Dwarves are an ancient race of robust humanoids who live beneath the snow-capped mountains "<<endl;//initial HP: 100, Atk: 20, Def:30,gold is doubled in value
	cout<<endl<<endl;
	cout<<"o: Orc-----. Orcs are no longer driven by dreams of conquest, they stand ready to destroy all who would challenge their sovereignty or their supremacyinitial"<<endl;// HP: 180, Atk: 30, Def:25,gold is worth half value
	cout<<endl<<endl;
}


void printLogo(){
cout<<"$$$$$$$$$$$$$$$$\"\"$o$o$o$o$o$oo$$\"\"$$$$$$$$$$$$$$$"<<endl;
cout<<"$$$$$$$$$$$$\"\"o$$$$$$$$$$\"$\"$$$$$$$o$\"$$$$$$$$$$$$"<<endl;
cout<<"$$$$$$$$$\"$o$$$$\"\"$oo $ \"\"      \"\"\"$$$oo\"$$$$$$$$$"<<endl;
cout<<"$$$$$$$\"o$$$$\"   \"\"o  $oo o o       \"\"$$$o\"$$$$$$$"<<endl;
cout<<"$$$$$\"o$$$\"       oo$$$$$$$$$$o        \"$$$o\"$$$$$"<<endl;
cout<<"$$$$\"o$$$  $  o$$$$$$$$$$$$$$\"$$oo       \"$$$ $$$$"<<endl;
cout<<"$$$\"$$$\"   \"$$$$$$$$$$$$$$$$o$o$$$\"        $$$o$$$"<<endl;
cout<<"$$ $$$    o$$$$$$$$$$$$$$$$$$$$$$$$o o   o  \"$$o\"$"<<endl;
cout<<"$\"$$$\"    o$$$$$$$$$\"$$$$$$\"\" \"$$$$$$\"$$$$$  $$$\"$"<<endl;
cout<<"$o$$\"    o$$$$$$$$$$o\"\"$$$\"\"\"\"ooo\"$$$$$$$$\"   $$$\""<<endl;
cout<<"$o$$\"    o$$$$$$$$$$            \"\"oo\"$\"$o\"\"   $$$o"<<endl;
cout<<"o$$$     o$$$$$$$$$$                \"\"\"\"\"$    o$$o"<<endl;
cout<<"o$$$    o$$$$$$$$$$$$o                   \"o \"oo$$o"<<endl;
cout<<"o$$$  oo$$$$$$$$$$$$$$$$ooooooo$$$$$oo    $\"$ \"$$o"<<endl;
cout<<"o$$$\"  \"\"  $$$$$$$$$$$$$$$$$$$$$$$$$$$$o    \" $$$"<<endl;
cout<<"$ $$$       \"$$$$$$$$$$$$$$$$$$$$$$$$$$$o    o$$\"$"<<endl;
cout<<"$$\"$$o       \"$$$$$$$$$$$$$$$$$$$$$$$$$$$o   $$$o$"<<endl;
cout<<"$$o$$$o       $$\"\"$$$$$$$$$$$$$$$$$$$$$$$o  $$$ $$"<<endl;
cout<<"$$$o\"$$o    \"$\"\"  \"$\"\"$$$$$$$$$$$$$$$$$$$oo$$$\"$$$"<<endl;
cout<<"$$$$o\"$$$o        \"     $$$$$$$$$$$$$$$$$o$$\"o$$$$"<<endl;
cout<<"$$$$$$o\"$$$o         oo$$$$$$$$$$$$$$$$$$$$\"o$$$$$"<<endl;
cout<<"$$$$$$$$o\"$$$$ooooo$$$$$$$$$$$$$$$$$$$$$$\"o$$$$$$$"<<endl;
cout<<"$$$$$$$$$$o\"\"$$$$$$$$$$$$$$$$$$$$$$$$$\"oo$$$$$$$$$"<<endl;
cout<<"$$$$$$$$$$$$$o$\"\"$$$$$$$$$$$$$$$$$\"\"oo$$$$$$$$$$$$"<<endl;
cout<<"$$$$$$$$$$$$$$$$$$o$o$\"$\"$\"$\"$oo$o$$$$$$$$$$$$$$$$"<<endl;
cout<<endl<<"enter anything to continue"<<endl;
}

void printstory(){
	cout<<"long time ago........"<<endl;
}
void printName(){
cout<<"    _____                                          "<<endl;
cout<<"   (, /   )                             /)   /)    "<<endl;
cout<<"    _/__ / __   _  _    _ __  _/_  _  _(/   (/_    "<<endl;
cout<<"    /     / (__(/_/_)__(/_/ (_(___(/_(_(_  /_) (_/_"<<endl;
cout<<" ) /                                          .-/  "<<endl;
cout<<"(_/                                          (_/   "<<endl;
cout<<"      _____                            __     __)     "<<endl;
cout<<"     (, /  ,                     /)   (, )   /        "<<endl;
cout<<"       /    __   _     _  __   _(/      /   /       _ "<<endl;
cout<<"   ___/___(_/ (_(_/_  (_(_/ (_(_(_     (___/_ (_(__(/_"<<endl;
cout<<" /   /         .-/                    )   /           "<<endl;
cout<<"(__ /         (_/                    (__ /            "<<endl;
cout<<endl<<"enter anything to continue"<<endl;
}
void printOptions(){
cout<<"_____________________________________\n"<<endl;
cout<<"|Options                            |\n"<<endl;
cout<<"|? :list all options and command    |\n"<<endl;
cout<<"|dir: ea/so/we/no/ne/se/sw/nw       |\n"<<endl;
cout<<"|[dir]:Control directions           |\n"<<endl;
cout<<"|a [dir]: attack an enemy:          |\n"<<endl;
cout<<"|I: list inventory                  |\n"<<endl;
cout<<"|u [num]: use item                  |\n"<<endl;
cout<<"|s: list skills                     |\n"<<endl;
cout<<"|us1: use racial skills             |\n"<<endl;
cout<<"|us2: use class skill 1             |\n"<<endl;
cout<<"|us3: use class skill 2             |\n"<<endl;
cout<<"|usu: use ultimate skill            |\n"<<endl;
cout<<"|___________________________________|\n"<<endl;
}
void printClassOption(){
cout<<"Congratulations, you are power enough to choose a class"<<endl;
cout<<"M:Mage______Mages demolish their foes with arcane incantations. Although they wield powerful offensive spells, mages are fragile and lightly armored"<<endl;
cout<<"            Skills:Frost Nova, Fire Blast"<<endl;
cout<<"            Advanced class:Spirit Healer, Blood Mage"<<endl;
cout<<endl;
cout<<"W:Warrior______Warriors equip themselves carefully for combat and engage their enemies head-on, letting attacks glance off their heavy armor."<<endl;
cout<<"              Skills:Whirlwind, Demoralizing Shout"<<endl;
cout<<"              Advanced class:Ranger , Berserker"<<endl;
cout<<endl;
cout<<"K:Knight______Knight stand directly in front of their enemies, relying on heavy armor and healing in order to survive incoming attacks"<<endl;
cout<<"              Skills:Slam, Spiritual Healing"<<endl;
cout<<"              Advanced class:Death Knight , Paladin"<<endl;
       
}
void printGameOver(){
cout<<"                                   .::!!!!!!!:."<<endl;
cout<<"  .!!!!!:.                        .:!!!!!!!!!!!!"<<endl;
cout<<"  ~~~~!!!!!!.                 .:!!!!!!!!!UWWW$$$ "<<endl;
cout<<"      :$$NWX!!:           .:!!!!!!XUWW$$$$$$$$$P "<<endl;
cout<<"      $$$$$##WX!:      .<!!!!UW$$$$\"  $$$$$$$$# "<<endl;
cout<<"      $$$$$  $$$UX   :!!UW$$$$$$$$$   4$$$$$* "<<endl;
cout<<"      ^$$$B  $$$$\\     $$$$$$$$$$$$   d$$R\" "<<endl;
cout<<"        \"*$bd$$$$      \'*$$$$$$$$$$$o+#\" "<<endl;
cout<<"             \"\"\"\"          \"\"\"\"\"\"\" "<<endl;
cout<<"  ____    _    __  __ _____    _____     _______ ____  "<<endl;
cout<<" / ___|  / \\  |  \\/  | ____|  / _ \\ \\   / / ____|  _ \\ "<<endl;
cout<<"| |  _  / _ \\ | |\\/| |  _|   | | | \\ \\ / /|  _| | |_) |"<<endl;
cout<<"| |_| |/ ___ \\| |  | | |___  | |_| |\\ V / | |___|  _ < "<<endl;
cout<<" \\____/_/   \\_\\_|  |_|_____|  \\___/  \\_/  |_____|_| \\_\\"<<endl;
cout<<endl;
cout<<"q: Quit"<<endl;
cout<<"r: Restart"<<endl;                                                      
}

void printWon(){
cout<<"------------------------------------------------------"<<endl;
cout<<"m     m  mmmm  m    m       m     m  mmmm  mm   m"<<endl;
cout<<" \"m m\"  m\"  \"m #    #       #  #  # m\"  \"m #\"m  #"<<endl;
cout<<"  \"#\"   #    # #    #       \" #\"# # #    # # #m #"<<endl;
cout<<"   #    #    # #    #        ## ##\" #    # #  # #"<<endl;
cout<<"   #     #mm#  \"mmmm\"        #   #   #mm#  #   ##"<<endl;
cout<<"------------------------------------------------------"<<endl;
cout<<"      \\                    / \\  //\\"<<endl;
cout<<"       \\    |\\___/|      /   \\//  \\\\"<<endl;
cout<<"            /0  0  \\__  /    //  | \\ \\    "<<endl;
cout<<"           /     /  \\/_/    //   |  \\  \\  "<<endl;
cout<<"           @_^_@'/   \\/_   //    |   \\   \\ "<<endl;
cout<<"           //_^_/     \\/_ //     |    \\    \\"<<endl;
cout<<"        ( //) |        \\///      |     \\     \\"<<endl;
cout<<"      ( / /) _|_ /   )  //       |      \\     _\\"<<endl;
cout<<"    ( // /) '/,_ _ _/  ( ; -.    |    _ _\\.-~        .-~~~^-."<<endl;
cout<<"  (( / / )) ,-{        _      `-.|.-~-.           .~         `."<<endl;
cout<<" (( // / ))  '/\\      /                 ~-. _ .-~      .-~^-.  \\"<<endl;
cout<<" (( /// ))      `.   {            }                   /      \\  \\"<<endl;
cout<<"  (( / ))     .----~-.\\        \\-'                 .~         \\  `. \\^-."<<endl;
cout<<"             ///.----..>        \\             _ -~             `.  ^-`  ^-_"<<endl;
cout<<"               ///-._ _ _ _ _ _ _}^ - - - - ~                     ~-- ,.-~"<<endl;
cout<<"                                                                  /.-~"<<endl;
                                                                  
}

