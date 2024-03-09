#include <iostream>
#include <vector> 
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int main(){
//welcome message   
cout<<"welcome in morse code system\nyou can enter only [A:Z] OR [0:9] \n"
<<"OR [-/.] for morse code\n";

while (true){
//available letters to convert 
string morse[38]={".-","-...","-.-.","-..",".","..-.","--.","....","..",
"--.","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-",
"...-",".--","-..-","-.--","--..",".----","..---","...--","....-",".....",
"-....","--...","---..","----.","-----"," ","   "};

string alph[38]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O"
,"P","Q","R","S","T","U","V","W","X","Y","Z","1","2","3","4","5","6","7","8",
"9","0",""," "};

//menu 
cout<<"\nyou want to convert : \n1-morse->alphapet\n";
cout<<"2-alphapet->morse\n3-exit\n(1,2,3)-> "; 
string convert ;
cin>>convert;
//exit the program 
if(convert=="3"){
    cout<<"\nbye! :(";
    break;
}

//convert form Morse code to alphabet 
else if(convert=="1"){
// Ignore the newline character in the input buffer
cin.ignore(); 
string Mcode;
cout<<"\nmake sure you enter 1 space after every letter and 3 spaces after every word to get the right sentence you need\n";	

while(true){
cout<<"\nEnter a marse code sentence: ";	
//Handling String Input With Spaces
getline(cin, Mcode); 

string letter;
vector<string> word;
//is an unsigned integer
size_t found;
//Manage spaces after every word 
while ((found = Mcode.find("   ")) != string::npos) {
        Mcode.replace(found,3, " | ");}

istringstream iss(Mcode);
//creat an area of each single letter after we get space 
while (getline(iss, letter, ' ')) {
   if (letter == "|")
    word.push_back("   ");
   else
    word.push_back(letter);}

    bool valid = true;
    //check if all letter are valid
    for (const auto & x : word) {
        if (find(begin(morse), end(morse), x) == end(morse)) {
        valid = false;
        break;}}
    //convert every letter to the alphabete coby of it
    if (valid) {
        cout<<"-> ";
        for (int i = 0; i < word.size(); i++) {
            for (int j = 0; j < 39; j++) {
                if (word[i] == morse[j]) {
                    cout << alph[j];
                    break;}}}
    cout << endl;
    break;}
    // invalid input 
    else {
    cout << "\nInvalid input! Please enter characters ( . / - /space) only."<<endl;}}}
    
//convert form alphabet to Morse code 
else if (convert == "2") {
string sentence;
// Ignore the newline character in the input buffer
cin.ignore();
    while (true) {
    cout << "\nEnter a Sentence: ";
    //Handling String Input With Spaces
    getline(cin, sentence);
    //make sure all letters are capitalized 
    transform(sentence.begin(), sentence.end(), sentence.begin(), ::toupper);
    bool valid = true;
    //Make sure it's a valid input 
        for (char x : sentence) {
            if (find(begin(alph), end(alph), string(1, x)) == end(alph)) {
                valid = false;
                break;}}
    //convert every single letter to the Morse code coby of it
    if (valid) {
        cout<<"-> ";
        for (char &x : sentence) {
            for (int i = 0; i <39; i++) {
                if (alph[i] == string(1, x)) {
                    cout << morse[i] << " ";
                    break;}}}cout << endl;
            break;}    
    //invalid input         
    else {
        cout << "\nInvalid input! Please enter characters from A to Z or 0 to 9 only." << endl;}}}

//invalid input  
else{    
    cout<<"\nInvalid input!try again\n";}}}
