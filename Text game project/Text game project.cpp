#include <iostream>
using namespace std;

class Character {
public:
	int health = 100;
	int damage = 0;
	int rangedDamage = 0;
	int magicDamage = 0;
	int armory = 0;
	int agility = 0;
	int mana = 0;
	int money = 0;
	int experience = 0;
	int level = 1;
	Character(int hp, int dmg, int mDmg, int arm, int rangedDmg, int agi, int mp, int mon, int exp, int lvl) {
		hp = health;
		dmg = damage;
		rangedDmg = rangedDamage;
		arm = armory;
		agi = agility;
		mDmg = magicDamage;
		mp = mana;
		mon = money;
	}
};

string weapons(string weapon) {
	if (weapon == "Sword" || weapon == "Bow" || weapon == "Staff" || weapon == "Daggers")
		return weapon;
}
string armor(string armor) {
	if (armor == "Light" || armor == "Medium" || armor == "Heavy")
		return armor;
}
int main()
{
	Character character1(0, 0, 0, 0, 0, 0, 0, 0, 0, 1);
	weapons("Sword");
	weapons("Bow");
	weapons("Staff");
	weapons("Daggers");
	string wpn;
	string val;
	cout << "                                         --------WELCOME TO THE TEXT GAME-----------" << endl;
	cout << "Do you want to play?" << endl;
	cin >> val;
	if (val == "Yes" || val == "yes") {
		a:cout << "Choose a weapon: " << endl;
		cout << "-Sword (Attack +10)" << endl;
		cout << "-Bow (Ranged Attack +10)" << endl;
		cout << "-Staff (Magic Attack +15, Mana +50)" << endl;
		cout << "-Daggers (Attack +7, Agility +10)" << endl;
		cout << endl;
		cin >> wpn;
		if (wpn == "Sword") {
			cout << "You have chosen Sword!" << endl;
			character1.damage += 10;
		}
		else if (wpn == "Bow") {
			cout << "You have chosen Bow!" << endl;
			character1.rangedDamage += 10;
		}
		else if (wpn == "Staff") {
			cout << "You have chosen Staff!" << endl;
			character1.magicDamage += 15;
			character1.mana += 50;
		}
		else if (wpn == "Daggers") {
			cout << "You have chosen Daggers!" << endl;
			character1.damage += 7;
			character1.agility += 10;
		}
		else {
			cout << "There is no such weapon!" << endl;
			goto a;
		}
		string arm;
		b:cout << "What armor do you choose? " << endl;
		cout << "-Heavy (Health +20, Armor +30, Agility -10)" << endl;
		cout << "-Medium (Health 20, Armor +20, Agility +5)" << endl;
		cout << "-Light (Health + 10, Armor +10, Agility +10)" << endl;
		cout << endl;
		cin >> arm;
		if (arm == "Light") {
			cout << "You have chosen " << arm << " Armor" << endl;
			character1.health -= 10;
			character1.armory += 10;
			character1.agility += 10;
		}
		else if (arm == "Medium") {
			cout << "You have chosen " << arm << " Armor" << endl;
			character1.armory += 20;
			character1.health += 10;
			character1.agility += 5;
		}
		else if (arm == "Heavy") {
			cout << "You have chosen " << arm << " Armor" << endl;
			character1.health += 20;
			character1.armory += 30;
			character1.agility -= 10;
		}
		else if (arm != "Light" || arm!= "Medium" || arm!= "Heavy") {
			cout << "There is no such armor!" << endl;
			goto b;
		}
		cout << "Your characters starts with: " << endl;
		cout << wpn << " and " << arm << " armor." << endl;
		cout << "Health: " << character1.health << endl;
		cout << "Attack: " << character1.damage << endl;
		cout << "Armor: " << character1.armory << endl;
		cout << "Ranged Attack: " << character1.rangedDamage << endl;
		cout << "Magic attack: " << character1.magicDamage << endl;
		cout << "Agility : " << character1.agility << endl;
		cout << "Mana: " << character1.mana << endl;
		cout << "Money: " << character1.money << endl;
		cout << "Exp: " << character1.experience << endl;
		cout << "Level " << character1.level << endl;
		cout << "                                 --------GAME START!--------" << endl;

		cout << "            DAY1" << endl;
		string choice1;
		cout << "You are traveling through thick forest just outside the city on the beatiful morning. " << endl; 
		cout << "When you are still on the main road nothing, as expected, happens." << endl; 
		cout << "After going for about 30 minutes on the main road, you decide to go a bit deeper into the forest. " << endl;
		cout << "Twenty minutes off the main road and you already spot 1st enemy - orc (Level 2, 50 Hp, 20 Attack)." << endl;
		c:cout << "What do you do?" << endl;
		cout << "1" << "-Fight." << endl;
		cout << "2" << "-Run." << endl;
		cin >> choice1;
		if (choice1 == "Fight" && wpn == "Sword") {
			cout << "You fought against your enemy with your sword but you lost 12 hp." << endl;
			cout << "Loot: 20 exp, 30 gold" << endl;
			character1.health -= 12;
			character1.money += 30;
			character1.experience += 20;
		}
		else if (choice1 == "1" && wpn == "Bow") {
			cout << "You sniped down your enemy with your bow without losing any hp!" << endl;
			cout << "Loot: 20 exp, 30 gold" << endl;
			character1.money += 30;
			character1.experience += 20;
		}
		else if (choice1 == "1t" && wpn == "Staff" && character1.mana != 0) {
			cout << "You blasted your enemy with magic spell (20 mana) without losing any hp." << endl;
			cout << "Loot: 20 exp, 30 gold" << endl;
			character1.mana -= 20;
			character1.money += 30;
			character1.experience += 20;
		}
		else if (choice1 == "1") {
			cout << "With great agility you managed to outmanouver your enemy and kill it, but you lost 5 hp." << endl;
			cout << "**Loot: 20 exp, 30 gold" << endl;
			character1.health -= 5;
			character1.money += 30;
			character1.experience += 20;
		}
		else if (choice1 == "2" && character1.agility >= 0) {
			cout << "Not wanting to risk your life at such early stage u decide to run for your life." << endl;
		}
		else if (choice1 == "2" && character1.agility <= 0) {
			cout << "Not wanting to risk your life at such early stage you decide to run for your life, " << endl;
			cout << "but because of your heavy armor you lost 20 hp." << endl;
			character1.health -= 20;
		}
		else if (choice1 != "1" || choice1 != "Run") {
			cout << "There is no such option!" << endl;
			goto c;
		}
		string choice2;
		cout << "Continuing your journey, you'are lucky enought to find a hidden treasure chest under the old tree trunk." << endl;
		cout << "Loot: 60 gold, Slightly improved sword (+8 Attack)" << endl;
		character1.money += 60;
		if (wpn == "Sword") {
			character1.damage += 8;
		}
		cout << "The sun is already quite low, but you decided to keep going. 'For the glory and money!' as they say in adventurers guild in the city " << endl;
		cout << "You spot a fire quite a bit off the road and being quite curious as to who would start a fire in such place " << endl;
		cout << " you sneak just enough to see 3 trolls (Level 2, 30 Hp, 20 Attack)" << endl;
		cout << "Two of them are sleeping while the other trying to keep watch, although you can see that the one keeping the watch is almost sleeping aswell." << endl;
		d:cout << "Few options come to your mind. What do you do?" << endl;
		cout << "1" << "-Rush them" << endl;
		cout << "2" << "-Shoot them down (Requiers Bow)" << endl;
		cout << "3" << "-Blast them (Requiers Staff and at least 30 mana)" << endl;
		cout << "4" << "-Kill them silently (Requiers Daggers and it would be safer to have at least 12 agility)" << endl;
		cin >> choice2;
		if (choice2 == "1" && character1.health != 0) {
			cout << "Counting on element of surprise you decide to attack them head on. After a bit of struggle you lose 40 hp " << endl;
			cout << "but you manage to win this fight!" << endl;
			cout << "Loot: 70 exp, 80 gold." << endl;
			character1.experience += 70;
			character1.money += 80;
			character1.health -= 40;
		}
		else if (choice2 == "2" && character1.health != 0 && wpn == "Bow") {
			cout << "According to your calculations you should be able to kill them with your bow " << endl;
			cout << "without giving them a chance to even see where attack is coming from." << endl;
			cout << "You wait a bit for the troll that is keeping the watch to fall asleep and you begin to rain them down." << endl;
			cout << "As you expected they have no idea where is the attack coming from. You managed to win this fight easily!" << endl;
			cout << "Loot: 70 exp, 80 gold." << endl;
			character1.experience += 70;
			character1.money += 80;
			character1.health -= 40;
		}
		else if (choice2 == "2" && wpn != "Bow") {
			cout << "This option requiers Bow!" << endl;
			goto d;
		}
		else if (choice2 == "3" && wpn == "Staff" && character1.mana != 0) {
			cout << "With your staff and magic u learned from mages guild you decided to test a bigger spell that might kill them at once (30 mana)." << endl;
			cout << "You wait a bit for the troll that is keeping the watch to fall asleep and you begin your incantation." << endl;
			cout << "When you finish your incantation a seemingly small spark flies from your staff only to transform into big fireball " << endl;
			cout << "that kills all of trolls in an instance" << endl;
			cout << "Exhausted, but satisfied you sit on the ground and you admire your work" << endl;
			cout << "Loot: 70 exp, 80 gold." << endl;
			character1.mana -= 30;
			character1.experience += 70;
			character1.money += 80;
		}
		else if (choice2 == "3" && wpn != "Staff") {
			cout << "This option requiers Staff!" << endl;
			goto d;
		}
		else if (choice2 == "3" && wpn == "Staff" && character1.mana <= 30) {
			cout << "Not enough mana!" << endl;
			goto d;
		}
		else if (choice2 == "4" && wpn == "Daggers" && character1.agility >= 12) {
			cout << "With daggers in your hands you feel like you should be able to kill them quietly without waking up any of them." << endl;
			cout << "You wait a bit for the troll that is keeping the watch to fall asleep and you creep to their camp." << endl;
			cout << "Without any trouble you manage to finish it quickly!" << endl;
			cout << "Loot: 70 exp, 80 gold." << endl;
		}
		else if (choice2 == "4" && wpn != "Daggers") {
			cout << "This option requiers Daggers!" << endl;
			goto d;
		}
		else if (choice2 == "4" && wpn == "Daggers" && character1.agility <= 12) {
			cout << "With daggers in your hands you feel like you should be able to kill them quietly without waking up any of them." << endl;
			cout << "You wait a bit for the troll that is keeping the watch to fall asleep and you creep to their camp." << endl;
			cout << "Probably because of your slightly heavy armor last troll wakes up when you finish killing 2nd one." << endl;
			cout << "You lost a bit of health (20) but you manage to win the fight!" << endl;
			cout << "Loot: 70 exp, 80 gold." << endl;
			character1.health -= 20;
			character1.experience += 70;
			character1.money += 80;
		}
		else if (choice2 != "1" || choice2 != "2" || choice2 != "3" || choice2 != "4") {
			cout << "There is no such option!" << endl;
			goto d;
		}
				string choice3;
				e:cout << "The night is coming. Do you want to rest or keep on going?" << endl;
				cout << "1" << "-Camp" << endl;
				cout << "2" << "-Go" << endl;
				cin >> choice3;
				if (choice3 == "1") {
					cout << "You manage to safely sleep through the night and u wake up well rested (15 health and 30 mana restored)!" << endl;
					character1.health += 15;
					character1.mana += 30;
				}
				else if (choice3 == "2") {
					cout << "You decided to keep on travelling..." << endl;
					cout << "Unfortunately you have been attacked by a pack of goblins (3x, Level 1, 20 hp, 7 attack)" << endl;
					cout << "You lost a bit of hp but you managed to win the fight and earned 15 gold and 25 experience!" << endl;
					cout << "**Loot: 15 gold, 25 exp" << endl;
					character1.health -= 20;
					character1.money += 15;
					character1.experience += 25;
				}
				else if (choice3 != "1" || choice3 != "2") {
					cout << "There is no such option" << endl;
					goto e;
				}
				cout << endl;
				cout << "------------END OF DAY1!------------" << endl;
				cout << endl;
				if (character1.experience >= 100) {
					cout << "Congratulations! You leveled up!" << endl;
					cout << "Level 2, Hp + 50, Mana + 50, Attack/Ranged Attack/Magic Damage + 15, Agility + 10" << endl;
					character1.level += 1;
					character1.health += 50;
					character1.mana += 50;
					character1.agility += 10;
					if (wpn == "Sword" || wpn == "Daggers") {
						character1.damage += 15;
					}
					if (wpn == "Bow") {
						character1.rangedDamage += 15;
					}
					if (wpn == "Staff") {
						character1.magicDamage += 15;
					}
				}
				cout << "Health: " << character1.health << endl;
				cout << "Attack: " << character1.damage << endl;
				cout << "Armor: " << character1.armory << endl;
				cout << "Ranged Attack: " << character1.rangedDamage << endl;
				cout << "Magic attack: " << character1.magicDamage << endl;
				cout << "Agility : " << character1.agility << endl;
				cout << "Mana: " << character1.mana << endl;
				cout << "Money: " << character1.money << endl;
				cout << "Exp: " << character1.experience << endl;
				cout << "Level " << character1.level << endl;		
	}
	else if (val != "Yes") {
		cout << "Goodbye" << endl;
	}
}