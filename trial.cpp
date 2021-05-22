#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <ostream>
#include <fstream>
using namespace std;

class Sentences {

    private:
        //string variable to store one sentence
        string sentence;
        //integer variable to store the number of words in one sentence
        int numWords;
        //boolean variable to store whether a sentence is a question
        bool isQuestion = false;
        //vector of type string to store the words in a sentence
        vector<string> words;

    public:
        Sentences();
        //Sentences(string s);
        //get and set method to retrieve a sentence and to change it
        string getSentence();
        void setSentence(string s);
        //method to return the number of words in a sentence
        int getNumWords();
        //method to determine whether a sentence is a question
        bool isSentenceAQuestion();
        //method to return all the words in a sentence (as a vector)
        vector<string> getWords();
        //sentences less than n words
        bool isSentenceLessThan(int n);
        //sentences greater than or equal to n words
        bool isSentenceGreaterThanOrEqualTo(int n);
        ~Sentences();
};

Sentences::Sentences(){}

/*Sentences::Sentences(string s){
    sentence = s;
    numWords = getNumWords();
    isQuestion = isSentenceAQuestion();
}*/

string Sentences::getSentence(){
    return sentence;
}

void Sentences::setSentence(string s){
    sentence = s;
}

int Sentences::getNumWords(){
    int numChars = sentence.length();
    vector<string> setOfWords;
    string currentWord;
    for(int i=0;i<numChars;i++){
        if(sentence[i] == ' ' && !currentWord.empty()){
            setOfWords.push_back(currentWord);
            currentWord.clear();
        }
    else{
        currentWord += sentence[i];
        }
    }

    return (setOfWords.size() + 1);
}

vector<string> Sentences::getWords(){
    int numChars = sentence.length();
    string currentWord;
    words.clear();

    for(int i=0;i<numChars;i++){
        if(sentence[i] == ' ' || sentence[i] == '.' || sentence[i] == '!' || sentence[i] == '?'){
            words.push_back(currentWord);
            currentWord.clear();
        }
        else {
            currentWord += sentence[i];
        }
    }

    return words;
}

bool Sentences::isSentenceAQuestion(){
    int numChars = sentence.length();
    if(sentence[numChars-1] == '?')
        isQuestion = true;
    return isQuestion;
}

//sentences less than n words
bool Sentences::isSentenceLessThan(int n){
    int numberWords = getNumWords();

    if(numberWords < n) {
        return true;
    }
    else {
        return false;
    }
}

//sentences greater than or equal to n words
bool Sentences::isSentenceGreaterThanOrEqualTo(int n){
    int numberWords = getNumWords();

    if(numberWords >= n) {
        return true;
    }
    else {
        return false;
    }
}

Sentences::~Sentences(){}

class Words {

    private:
        //string variable to store one word
        string word;
        //integer variable to store the number of characters in one word
        int numCharacters;
        //boolean variable to store whether a word starts with an uppercase character
        bool firstCharacterUpperCase = 0;
        //vector of type char to store the individual characters in a word
        vector<char> characters;

    public:
        Words();
        //get and set method to retrieve a sentence and to change it
        string getWord();
        void setWord(string w);
        //method to return the number of characters (length) in a sentence
        int getNumCharacters();
        //method to determine whether a word starts with an Uppercase character
        bool isFirstCharacterUpperCase();
        //method to return all the words in a sentence (as a vector)
        vector<char> getCharacters();
        ~Words();
};

Words::Words(){}

string Words::getWord(){
    return word;
}

void Words::setWord(string w){
    word = w;
}

int Words::getNumCharacters(){

    return word.length();
}

vector<char> Words::getCharacters(){

    int numChars = word.length();

    for(int i=0;i<numChars;i++){
        characters.push_back(word[i]);
    }

    return characters;
}

bool Words::isFirstCharacterUpperCase(){
    if(isupper(word[0])){
        return 1;
    }
    else {
        return 0;
    }
}

Words::~Words(){}

/*class Mapping
{
    string EnglishWord;
    string KreoleWord;
    int frequency;

public:
       Mapping();
       Mapping(string ew, string kw);
       string getEnglishWord();
       void setEnglishWord(string ew);

       string getKreoleWord();
       void setKreoleWord(string ew);

       int IncrementFrequency();

};
Mapping:: Mapping(){};
Mapping:: Mapping(string ew, string kw)
{
   EnglishWord=ew;
   KreoleWord=kw;
   frequency=1;
}


string Mapping::  getEnglishWord()
{
    return EnglishWord;
}

void Mapping:: setEnglishWord(string ew)
{
    EnglishWord=ew;
}

string Mapping::  getKreoleWord()
{
    return KreoleWord;
}

void Mapping:: setKreoleWord(string kw)
{
    KreoleWord=kw;
}

void Mapping:: IncrementFrequency()
{
    frequency++
}

int Mapping:: getFrequency()
{
    return frequency;
}
*/

int main()
{

   cout<<endl<<"MAPPING OF ENGLISH WORDS TO KREOL MORISIEN WORDS"<<endl;

   vector<string> allEnglishSentences;

   //codes to load the sentences dataset from a text file into a vector
    ifstream infileEnglish;
    string sentenceFromEnglishFile;
	//infileEnglish.open ("samplesentences.txt");
	infileEnglish.open ("1000_English_A_040521.txt");

	int countEnglishSentence = 0;

    while(!infileEnglish.eof()) {
        getline(infileEnglish,sentenceFromEnglishFile);
        allEnglishSentences.push_back(sentenceFromEnglishFile);
        countEnglishSentence++;
    }

	infileEnglish.close();

	cout<<"Number of English sentences: "<<countEnglishSentence<<endl;

    //int countEnglishSentence = 0;

	 //creating a vector of objects of type sentences
    vector<Sentences> sentEnglish(countEnglishSentence);


    //assign each extracted sentence (from dataset) to one Sentence object
    for(int i=0; i<countEnglishSentence; i++){
        sentEnglish[i].setSentence(allEnglishSentences[i]);
    }



    //display the attributes of each Sentence object
    //int dummy;
    vector<string> wordsFromEnglishSentence;
    int totalEnglishWords = 0;

    for(int i=0; i<countEnglishSentence; i++){
        //cout<<endl<<sentEnglish[i].getSentence()<<endl;
        //cout<<"Number of words in the sentence: "<<sentEnglish[i].getNumWords()<<endl;
        //cout<<"Is sentence a question: "<<sentEnglish[i].isSentenceAQuestion()<<endl;

        wordsFromEnglishSentence = sentEnglish[i].getWords();
        totalEnglishWords = totalEnglishWords + wordsFromEnglishSentence.size();
        //cout<<"Number of words: "<<wordsFromSentence.size()<<endl;
        //for(int i=0; i<wordsFromEnglishSentence.size(); i++){
            //cout<<"Words in the sentence: "<<wordsFromEnglishSentence[i]<<endl;

       // }
        //cin>>dummy;
   // }

    //cout<<endl<<"Total number of English words: "<<totalEnglishWords<<endl;






    vector<string> allKMSentences;

   //codes to load the sentences dataset from a text file into a vector
    ifstream infileKM;
    string sentenceFromKMFile;
	//infileKM.open ("samplesentences.txt");
	infileKM.open ("1000_KM_A_040521.txt");

	int countKMSentence = 0;

    while(!infileKM.eof()) {
        getline(infileKM,sentenceFromKMFile);
        allKMSentences.push_back(sentenceFromKMFile);
        countKMSentence++;
    }

	infileKM.close();

	//cout<<"Number of KM sentences: "<<countKMSentence<<endl;
    //int countKMSentence = 0;
	 //creating a vector of objects of type sentences
    vector<Sentences> sentKM(countKMSentence);


    //assign each extracted sentence (from dataset) to one Sentence object
    for(int i=0; i<countKMSentence; i++){
        sentKM[i].setSentence(allKMSentences[i]);
    }



    //display the attributes of each Sentence object
    //int dummy;
    vector<string> wordsFromKMSentence;
    int totalKMWords = 0;

    for(int i=0; i<countKMSentence; i++){
        //cout<<endl<<sentKM[i].getSentence()<<endl;
        //cout<<"Number of words in the sentence: "<<sentKM[i].getNumWords()<<endl;
        //cout<<"Is sentence a question: "<<sentKM[i].isSentenceAQuestion()<<endl;

        wordsFromKMSentence = sentKM[i].getWords();
        totalKMWords = totalKMWords + wordsFromKMSentence.size();

        //cout<<"Number of words: "<<wordsFromSentence.size()<<endl;
        //for(int i=0; i<wordsFromKMSentence.size(); i++){
            //cout<<"Words in the sentence: "<<wordsFromKMSentence[i]<<endl;

        }
        //cin>>dummy;
    }

    //cout<<endl<<"Total number of KM words: "<<totalKMWords<<endl;


    for (int i=0; i<sentEnglish.size();i++)
    {
        vector<string> English_Words = sentEnglish[i].getWords();
        for(int j=0; j<sentEnglish[i].getNumWords(); j++)
        {
            cout<<English_Words[j]<<" ";
        }
        cout<<endl;



    }
    return 0;
}