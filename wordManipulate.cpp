#include<iostream>
#include<map>
#include<fstream>
#include<vector>
using namespace std;

class wordManipulate{
private:
    string dictionary;
    string wordToSearch;
    vector<string> wordlist;
public:

    wordManipulate()   //Default Constructor creates a vector 
    {                  //which holds the words from dictionary
        string line;
        ifstream myfile("dit.txt");

        if(myfile.is_open())
        {
            while(myfile.good())
            {
                getline(myfile,line);
                
                wordlist.push_back(line);
            }
            myfile.close();
        }
    }
    void setDictionary(string d)
    {
        dictionary=d;
    }

    void setwordToSearch(string w)
    {
        wordToSearch=w;
    }

    bool magic(string dictionary,string wordToSearch)  //time complexity O(n+m) -> O(n)
    {                                                  //n -> length of dictionary m -> length of wordToSearch
        map<char,int> availableLetters;
        for(int iterator=0;iterator<dictionary.size();iterator++)
        {
            availableLetters[dictionary[iterator]]++;
        }

        for(int iterator=0;iterator<wordToSearch.size();iterator++)
        {
            if(availableLetters[wordToSearch[iterator]]>0)
            {
                availableLetters[wordToSearch[iterator]]--;
            }
            else{

                if(availableLetters['?']>0)
                {
                    availableLetters['?']--;
                    continue;
                }
                return false;
            }
        
        }

        return true;
    } 
    
    string longest(string letters)   //time complexity O(m*n)                                
    {                                //m -> size of wordlist n -> length of the word
            map<char,int> availableLetters;

        for(int i=0;i<letters.size();i++)
        {
            availableLetters[letters[i]]++;
        }
        int maxLength=0;
        string longestWord;
        for(int i=0;i<wordlist.size();i++)
        {   
            bool properWord=true;
            map<char,int> currentWordLetters;
            string word=wordlist[i];
            int helper=0;
                if(availableLetters['?']>0)
                {
                    helper=availableLetters['?'];       //helper holds the count of '?'
                }
            for(int j=0;j<word.size();j++)
            {
                currentWordLetters[word[j]]++;
                
                if(currentWordLetters[word[j]]>availableLetters[word[j]])
                {
                    if(helper>0)
                    {
                        helper-=1;
                        continue;
                    }
                    properWord=false;
                    break;
                }
            }

            if(properWord)
            {
                if(word.size()>maxLength)            
                {
                    maxLength=word.size();
                    longestWord=word;
                }
            }

        }
            return longestWord;

    }
};

int main()
{
    wordManipulate w;
    cout<<w.magic("edzlatsh", "hazel")<<endl;
    cout<<w.magic("uwtaqicy", "watch")<<endl;
    cout<<w.magic("d??????", "code")<<endl;
    cout<<w.magic("g???", "code")<<endl;
    cout<<w.longest("uruqrnytrois")<<endl;
    cout<<w.longest("rryqeiaegicgeo??")<<endl;

}