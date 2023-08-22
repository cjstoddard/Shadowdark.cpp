// ###############################
// # Shadowsdark.cpp 1.2         #
// # By Chris Stoddard, Aug 2023 #
// # Based on the Shadowdark RPG #
// # by Arcane Library           #
// # This code is licensed under #
// # the Creative Commons        #
// # Attribution-NonCommercial   #
// # 4.0 License.                #
// ###############################

// ###############################
// # Import needed libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <fstream>

using namespace std;

// ###############################
// # Define functions
// # 4d6 take the best 3 for rolling ability scores
int roll_4d6()
{
    int dieArray[4];
    const int minValue = 1;
    const int maxValue = 6;

    dieArray[0] = rand() % (maxValue - minValue + 1) + minValue;
    dieArray[1] = rand() % (maxValue - minValue + 1) + minValue;
    dieArray[2] = rand() % (maxValue - minValue + 1) + minValue;
    dieArray[3] = rand() % (maxValue - minValue + 1) + minValue;

    sort(dieArray, dieArray + 4);

    int totalRolled = dieArray[1] + dieArray[2] + dieArray[3];

    return totalRolled;
}

// ###############################
// # 3d6 for rolling ability scores
int roll_3d6()
{
    int dieArray[3];
    const int minValue = 1;
    const int maxValue = 6;

    dieArray[0] = rand() % (maxValue - minValue + 1) + minValue;
    dieArray[1] = rand() % (maxValue - minValue + 1) + minValue;
    dieArray[2] = rand() % (maxValue - minValue + 1) + minValue;

    int totalRolled = dieArray[0] + dieArray[1] + dieArray[2];

    return totalRolled;
}

// ###############################
// # 2d6 for various purposes
int roll_2d6()
{
    int dieArray[2];
    const int minValue = 1;
    const int maxValue = 6;

    dieArray[0] = rand() % (maxValue - minValue + 1) + minValue;
    dieArray[1] = rand() % (maxValue - minValue + 1) + minValue;

    int totalRolled = dieArray[0] + dieArray[1];

    // int rolled2d6Dice = roll_2d6();
    // cout << "Total Rolled: " << rolled2d6Dice << endl;

    return totalRolled;
}

// ###############################
// Determines attribute moddiers
string assign_Modifier(int temp)
{
    string temp_mod;

    if (temp == 3) {
        temp_mod = "-4";
    } else if (temp == 4 or temp == 5) {
        temp_mod = "-3";
    } else if (temp == 6 or temp == 7) {
        temp_mod = "-2";
    } else if (temp == 8 or temp == 9) {
        temp_mod = "-1";
    } else if (temp == 10 or temp == 11) {
        temp_mod = "0";
    } else if (temp == 12 or temp == 13) {
        temp_mod = "+1";
    } else if (temp == 14 or temp == 15) {
        temp_mod = "+2";
    } else if (temp == 16 or temp == 17) {
        temp_mod = "+3";
    } else if (temp == 18) {
        temp_mod = "+4";
    }
    return temp_mod;
}

// ###############################
// Deals with yes and no questions
string ask_YN(string answer)
{
    if (answer == "y") {
        answer = "Y";
    } else if (answer == "Y") {
        answer = "Y";
    } else {
        exit(0);
        // answer = "N";
    }
    return (answer);
}

// ###############################
// Main function
int main()
{
    // ###############################
    // Declare variables
    srand(time(0));

    int abilityScores[6];
    int rollChoice;
    int rolledDice;
    int HITPOINTS;
    int talent_roll_sum;
    int iBackground;
    int iEquipment_Count;
    int iEquipment_Item;
    int iStarting_Gold;

    string abilityModifier[6];
    string YN;
    string Choose_Ancestry;
    string Ancestry;
    string Language;
    string AncestryFeature;
    string Choose_Class;
    string Class;
    string Weapon;
    string Armor;
    string ClassFeature1;
    string ClassFeature2;
    string ClassFeature3;
    string ClassFeature4;
    string ClassTalent;
    string Choose_Alignment;
    string Alignment;
    string sBackground;
    string sEquipment_Item;
    string sEquipment_List;    
    string sStarting_Gold;
    string Character_name;
    
    // ###############################
    // Displays legal statement
    cout << "-------------------------------------------------------" << endl;
    cout << "Legal Statement:" << endl;
    cout << "This Shadowdark Character Generator is an independent" << endl;
    cout << "product published under the Shadowdark RPG Third-Party" << endl;
    cout << "License and is not affiliated with The Arcane Library," << endl;
    cout << "LLC. Shadowdark RPG © 2023 The Arcane Library, LLC." << endl;
    cout << "-------------------------------------------------------" << endl;

    // ###############################
    // Roll attributes
    cout << endl;
    cout << "Choose which method of attribute generation you want to use:" << endl;
    cout << " 1 Roll 3d6 for attributes" << endl;
    cout << " 2 Roll 4d6 take the best 3 for attributes" << endl;
    cout << " Choice ?";
    cin >> rollChoice;

    if (rollChoice > 2) {
        rollChoice = 1;
    }

    if (rollChoice == 1) {
        rolledDice = roll_3d6();
        abilityScores[0] = rolledDice;
        rolledDice = roll_3d6();
        abilityScores[1] = rolledDice;
        rolledDice = roll_3d6();
        abilityScores[2] = rolledDice;
        rolledDice = roll_3d6();
        abilityScores[3] = rolledDice;
        rolledDice = roll_3d6();
        abilityScores[4] = rolledDice;
        rolledDice = roll_3d6();
        abilityScores[5] = rolledDice;
        } else if (rollChoice == 2) {
            rolledDice = roll_4d6();
            abilityScores[0] = rolledDice;
            rolledDice = roll_4d6();
            abilityScores[1] = rolledDice;
            rolledDice = roll_4d6();
            abilityScores[2] = rolledDice;
            rolledDice = roll_4d6();
            abilityScores[3] = rolledDice;
            rolledDice = roll_4d6();
            abilityScores[4] = rolledDice;
            rolledDice = roll_4d6();
            abilityScores[5] = rolledDice;
        } else {
            cout << " " << endl;
            exit(0);
    }

    abilityModifier[0] = assign_Modifier(abilityScores[0]);
    abilityModifier[1] = assign_Modifier(abilityScores[1]);
    abilityModifier[2] = assign_Modifier(abilityScores[2]);
    abilityModifier[3] = assign_Modifier(abilityScores[3]);
    abilityModifier[4] = assign_Modifier(abilityScores[4]);
    abilityModifier[5] = assign_Modifier(abilityScores[5]);

    cout << "Str: " << abilityScores[0] << " / " << abilityModifier[0] << endl;
    cout << "Dex: " << abilityScores[1] << " / " << abilityModifier[1] << endl;
    cout << "Con: " << abilityScores[2] << " / " << abilityModifier[2] << endl;
    cout << "Int: " << abilityScores[3] << " / " << abilityModifier[3] << endl;
    cout << "Wis: " << abilityScores[4] << " / " << abilityModifier[4] << endl;
    cout << "Cha: " << abilityScores[5] << " / " << abilityModifier[5] << endl;

    cout << " Do you want to keep this character ?";
    cin >> YN;
    ask_YN(YN);

    // ###############################
    // # Ancestry Section
    cout << " " << endl;
    cout << "Choose an Ancestry for your character:" << endl;
    cout << " 1 Dwarf" << endl;
    cout << " 2 Elf" << endl;
    cout << " 3 Gobin" << endl;
    cout << " 4 Half-Orc" << endl;
    cout << " 5 Halfling" << endl;
    cout << " 6 Human" << endl;
    cout << "Your choice? ";
    cin >> Choose_Ancestry;

    if (Choose_Ancestry == "1") {
        Ancestry = "Dwarf";
        Language = "Common and Dwarvish";
        AncestryFeature = "Stout. +2 HP at 1st level, each level there after, roll hit points with advantage.";
    } else if (Choose_Ancestry == "2") {
        Ancestry = "Elf";
        Language = "Common, Elvish, and Sylvan";
        AncestryFeature = "Farsight. Choose; +1 bonus to ranged weapon attacks or +1 bonus to spellcasting checks.";
    } else if (Choose_Ancestry == "3") {
        Ancestry = "Goblin";
        Language = "Common and Goblin";
        AncestryFeature = "Keen Senses. Character cannot be surprised.";
    } else if (Choose_Ancestry == "4") {
        Ancestry = "Half-Orc";
        Language = "Common and Orcish";
        AncestryFeature = "Mighty. +1 bonus to hit and damage with melee weapons.";
    } else if (Choose_Ancestry == "5") {
        Ancestry = "Halfling";
        Language = "Common";
        AncestryFeature = "Stealthy. You become invisible for 3 rounds, use this ability once per day";
    } else {
        Ancestry = "Human";
        Language = "Common and one additional common language.";
        AncestryFeature = "Ambitious. Roll one additional on the talent table at 1st level.";
    }

    // ###############################
    // # Class Section
    cout << endl;
    cout << "Choose a Class for your character:" << endl;
    cout << " 1 Fighter" << endl;
    cout << " 2 Priest" << endl;
    cout << " 3 Thief" << endl;
    cout << " 4 Wizard" << endl;
    cout << " 5 Zero Level" << endl;
    cout << "Your choice? ";
    cin >> Choose_Class;

    if (Choose_Class == "1") {
        Class = "Fighter";
        HITPOINTS = rand() % (8 - 1 + 1) + 1;
        Weapon = "Weapons: All weapons";
        Armor = "Armor: All armor and shields";
        ClassFeature1 = "Hauler. You gain additional gear slots equal to you Constitution modifier, if positive.";
        ClassFeature2 = "Weapon Mastery. With one type of weapon, you gain +1 to attack and damage with that weapon type. Also, add half your level to attack and damage rolls (round down).";
        ClassFeature3 = "Grit. Choose Strength or Dexterity. You have advantage on checks based on that attribute.";
        talent_roll_sum = roll_2d6();
        if (talent_roll_sum == 2) {
            ClassTalent = "Gain Weapon Mastery with another weapon type";
        } else if (talent_roll_sum == 3 or talent_roll_sum == 4 or talent_roll_sum == 5 or talent_roll_sum == 6) {
            ClassTalent = "+1 bonus to melee and ranged attacks";
        } else if (talent_roll_sum == 7 or talent_roll_sum == 8 or talent_roll_sum == 9) {
            ClassTalent = "+2 bonus to Strength, Dexterity, or Constitution attribute";
        } else if (talent_roll_sum == 10 or talent_roll_sum == 11) {
            ClassTalent = "Choose one type of armor. You get +1 your AC when wearing that armor";
        } else if (talent_roll_sum == 12) {
            ClassTalent = "Choose a talent or +2 points to distribute to attributes";
        } 
    } else if (Choose_Class == "2") {
        Class = "Priest";
        HITPOINTS = rand() % (6 - 1 + 1) + 1;
        Weapon = "Weapons: Club, crossbow, dagger, mace, longsword, staff, warhammer";
        Armor = "Armor: All armor and shields";
        Language = Language + " and you know either Celestial, Diabolic, or Primordial.";
        ClassFeature1 = "Turn Undead. You know the turn undead spell, this does not count toward your number of known spells.";
        ClassFeature2 = "Spellcasting. You can cast priest spells you have prepared.";
        ClassFeature3 = " ";
        talent_roll_sum = (roll_2d6());
        if (talent_roll_sum == 2) {
            ClassTalent = "Gain advantage with one spell you know, when roll to cast.";
        } else if (talent_roll_sum == 3 or talent_roll_sum == 4 or talent_roll_sum == 5 or talent_roll_sum == 6) {
            ClassTalent = "+1 bonus to melee or ranged attacks";
        } else if (talent_roll_sum == 7 or talent_roll_sum == 8 or talent_roll_sum == 9) {
            ClassTalent = "+1 bonus to priest spellcasting checks";
        } else if (talent_roll_sum == 10 or talent_roll_sum == 11) {
            ClassTalent = "+2 to Strength or Wisdom attribute";
        } else if (talent_roll_sum == 12) {
            ClassTalent = "Choose a talent or +2 points to distribute to attributes";
        }
    } else if (Choose_Class == "3") {
        Class = "Thief";
        HITPOINTS = rand() % (4 - 1 + 1) + 1;
        Weapon = "Weapons: Club, crossbow, dagger, shortbow, shortsword";
        Armor = "Armor: Leather armor, mithral chainmail";
        ClassFeature1 = "Backstab. On successful attack roll, If the target is unaware of your attack, you deal an extra die of damage and an additional die of damage equal to half your level (round down).";
        ClassFeature2 = "Thievery. You are trained thieving skills and have can carry the necessary tools at no equipment slot cost.";
        ClassFeature3 = "You are adept in the skills associated with thievery, you have advantage on any associated checks";
        talent_roll_sum = (roll_2d6());
        if (talent_roll_sum == 2) {
            ClassTalent = "You have advantage on initiative rolls (reroll if duplicate)";
        } else if (talent_roll_sum == 3 or talent_roll_sum == 4 or talent_roll_sum == 5 or talent_roll_sum == 6) {
            ClassTalent = "Your Backstab deals +1 die of damage";
        } else if (talent_roll_sum == 7 or talent_roll_sum == 8 or talent_roll_sum == 9) {
            ClassTalent = "+2 bonus to Strength, Dexterity, or Charisma attribute";
        } else if (talent_roll_sum == 10 or talent_roll_sum == 11) {
            ClassTalent = "+1 bonus to melee and ranged attacks";
        } else if (talent_roll_sum == 12) {
            ClassTalent = "Choose a talent or +2 points to distribute to atributes";
        }
    } else if (Choose_Class == "4") {
        Class = "Wizard";
        HITPOINTS = rand() % (4 - 1 + 1) + 1;
        Weapon = "Weapons: Dagger, staff";
        Armor = "Armor: None";
        Language = Language + " and you know two additional common languages and two rare languages";
        ClassFeature1 = "Learning Spells. You can learn new wizard spells from a scroll by studying it for a day and succeeding on a DC 15 INT check.";
        ClassFeature2 = "Spellcasting. You can cast wizard spells you have prepared.";
        ClassFeature3 = " ";
        talent_roll_sum = (roll_2d6());
        if (talent_roll_sum == 2) {
            ClassTalent = "Make a single random magic item of a type you choose";
        } else if (talent_roll_sum == 3 or talent_roll_sum == 4 or talent_roll_sum == 5 or talent_roll_sum == 6) {
            ClassTalent = "+2 to Intelligence attribute or +1 bonus to wizard spellcasting checks";
        } else if (talent_roll_sum == 7 or talent_roll_sum == 8 or talent_roll_sum == 9) {
            ClassTalent = "Gain advantage on casting a single spell you know";
        } else if (talent_roll_sum == 10 or talent_roll_sum == 11) {
            ClassTalent = "Learn one additional wizard spell of any tier you know";
        } else if (talent_roll_sum == 12) {
            ClassTalent = "Choose a talent or +2 points to distribute to attribute";
        } 
    } else if (Choose_Class == "5") {
        Class = "Zero Level";
        HITPOINTS = 0;
        Weapon = "Weapons: All weapons until 1st level";
        Armor = "Armor: All armor and shields until 1st level";
        ClassFeature1 = "Beginner's luck, you can wield any and all equipment until 1st level.";
        ClassFeature2 = " ";
        ClassFeature3 = " ";
        ClassTalent = " ";
    }
    
    // ###############################
    // # Modify hit Points by Constitution
    if (abilityModifier[2] == "-1") {
         HITPOINTS = HITPOINTS - 1;
    } else if (abilityModifier[2] == "-2") {
        HITPOINTS = HITPOINTS - 2;
    } else if (abilityModifier[2] == "-3") {
        HITPOINTS = HITPOINTS - 3;
    } else if (abilityModifier[2] == "-4") {
        HITPOINTS = HITPOINTS - 4;
    } else if (abilityModifier[2] == "+1") {
        HITPOINTS = HITPOINTS + 1;
    } else if (abilityModifier[2] == "+2") {
        HITPOINTS = HITPOINTS + 2;
    } else if (abilityModifier[2] == "+3") {
        HITPOINTS = HITPOINTS + 3;
    } else if (abilityModifier[2] == "+4") {
        HITPOINTS = HITPOINTS + 4;
    }

    if (HITPOINTS < 1) {
        HITPOINTS = 1;
    }

    // ###############################
    // # Randomly chooses background
    const char* Random_Backgrounds[] = {"Urchin","Wanted", "Cult Initiate", "Thieves Guild", "Banished", "Orphaned", "Wizards Apprentice", "Jeweler", "Herbalist", "Barbarian", "Mercenary", "Sailor", "Alcolyte", "Soldier", "Ranger", "Scout", "Minstrel", "Scholar", "Nobel", "Chirurgeon"};
    iBackground = rand() % (20 - 1 + 1) + 1;
    sBackground = Random_Backgrounds[iBackground];

    // ###############################
    // # Choose Alignment
    cout << endl;
    cout << "Choose an Alignment for your character:" << endl;
    cout << " 1 Chaotic" << endl;
    cout << " 2 Lawful" << endl;
    cout << " 3 Neutral" << endl;
    cout << "Your choice? ";
    cin >> Choose_Alignment;

    if (Choose_Alignment == "1") {
        Alignment = "Chaotic";
    } else if (Choose_Alignment == "2") {
        Alignment = "Lawful";
    } else {
        Alignment = "Neutral";
    }

    // ###############################
    // # Generate Starting gold or random equipment for Zero level character
    sEquipment_List = (" ");
    if (Choose_Class == "5")
    {
        const char* Random_Equipment[] = {"Torch,", "Dagger,", "Pole,", "Shortbow and 5 arrows,", "60 Feet of Rope,", "Flask of Oil,", "Crowbar,", "Iron spikes x10,", "Flint and steel,", "Grappling hook,", "Club,", "Bag of Caltrops,"};
        iEquipment_Count = rand() % (4 - 1 + 1) + 1;

        for (int count = 1; count <= (iEquipment_Count); count = count + 1) 
        {
            iEquipment_Item = rand() % (12 - 1 + 1) + 1;
            sEquipment_Item = Random_Equipment[iEquipment_Item];
            sEquipment_List = (sEquipment_List + " " + sEquipment_Item);    
        } 
    } else
        {
            iStarting_Gold = (roll_2d6());
            iStarting_Gold = (iStarting_Gold * 5);
            sStarting_Gold = to_string(iStarting_Gold);
            sEquipment_List = (sStarting_Gold + " Gold Pieces");
        }

    // ###############################
    // # Prints out the finished character to the screen
    cout << endl;
    cout << "What is your characters name? ";
    cin >> Character_name;
    cout <<  endl;
    cout <<  "Shadowdark Character Sheet 1.2" << endl;
    cout <<  "------------------------------" << endl;
    cout <<  "Character Name: " << Character_name << endl;
    cout <<  "Ancestry: " << Ancestry << endl;
    cout <<  "Background: " << sBackground << endl;
    cout <<  "Alignment: " << Alignment << endl;
    cout <<  "Deity: _______________________" << endl;
    cout <<  "Character Class: " << Class  << endl;
    cout <<  "XP:    _____"  << endl;
    cout <<  "Level: _____"  << endl;
    cout <<  "------------------------------" << endl;
    cout << "Str: " << abilityScores[0] << " / " << abilityModifier[0] << endl;
    cout << "Dex: " << abilityScores[1] << " / " << abilityModifier[1] << endl;
    cout << "Con: " << abilityScores[2] << " / " << abilityModifier[2] << endl;
    cout << "Int: " << abilityScores[3] << " / " << abilityModifier[3] << endl;
    cout << "Wis: " << abilityScores[4] << " / " << abilityModifier[4] << endl;
    cout << "Cha: " << abilityScores[5] << " / " << abilityModifier[5] << endl;
    cout <<  endl;
    cout <<  "Hit Points: " << HITPOINTS << endl;
    cout <<  endl;
    cout <<  "------------------------------" << endl;
    cout <<  "Ancestry Feature: " << AncestryFeature << endl;
    cout <<  "Languages: " << Language << endl;
    cout <<  "Class Features:" << endl;
    cout <<  "     " <<  Weapon << endl;
    cout <<  "     " <<  Armor << endl;
    cout <<  "     " <<  ClassFeature1 << endl;
    cout <<  "     " <<  ClassFeature2 << endl;
    cout <<  "     " <<  ClassFeature3 << endl;
    cout <<  "Class Talent: " << ClassTalent << endl;
    cout <<  "------------------------------" << endl;
    cout <<  "EQUIPMENT:" << endl;
    cout <<  sEquipment_List  << endl;

    cout << " Do you want to save this character to a text file, Y or N ?";
    cin >> YN;
    ask_YN(YN);

    // ###############################
    // # Write character to a text file using the character name
    ofstream characterSheet;
    characterSheet.open (Character_name + ".txt");
    characterSheet << endl;
    characterSheet <<  "Shadowdark Character Sheet 1.2" << endl;
    characterSheet <<  "------------------------------" << endl;
    characterSheet <<  "Character Name: " << Character_name << endl;
    characterSheet <<  "Ancestry: " << Ancestry << endl;
    characterSheet <<  "Background: " << sBackground << endl;
    characterSheet <<  "Alignment: " << Alignment << endl;
    characterSheet <<  "Deity: _______________________" << endl;
    characterSheet <<  "Character Class: " << Class  << endl;
    characterSheet <<  "XP:    _____"  << endl;
    characterSheet <<  "Level: _____"  << endl;
    characterSheet <<  "------------------------------" << endl;
    characterSheet << "Str: " << abilityScores[0] << " / " << abilityModifier[0] << endl;
    characterSheet << "Dex: " << abilityScores[1] << " / " << abilityModifier[1] << endl;
    characterSheet << "Con: " << abilityScores[2] << " / " << abilityModifier[2] << endl;
    characterSheet << "Int: " << abilityScores[3] << " / " << abilityModifier[3] << endl;
    characterSheet << "Wis: " << abilityScores[4] << " / " << abilityModifier[4] << endl;
    characterSheet << "Cha: " << abilityScores[5] << " / " << abilityModifier[5] << endl;
    characterSheet <<  endl;
    characterSheet <<  "Hit Points: " << HITPOINTS << endl;
    characterSheet <<  endl;
    characterSheet <<  "------------------------------" << endl;
    characterSheet <<  "Ancestry Feature: " << AncestryFeature << endl;
    characterSheet <<  "Languages: " << Language << endl;
    characterSheet <<  "Class Features:" << endl;
    characterSheet <<  "     " <<  Weapon << endl;
    characterSheet <<  "     " <<  Armor << endl;
    characterSheet <<  "     " <<  ClassFeature1 << endl;
    characterSheet <<  "     " <<  ClassFeature2 << endl;
    characterSheet <<  "     " <<  ClassFeature3 << endl;
    characterSheet <<  "Class Talent: " << ClassTalent << endl;
    characterSheet <<  "------------------------------" << endl;
    characterSheet <<  "EQUIPMENT:" << endl;
    characterSheet <<  sEquipment_List  << endl;
    characterSheet.close();

    return 0;
}
