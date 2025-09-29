#include <iostream>
#include <string>
#include <time.h>
#include <algorithm>
using namespace std;

int main(){
    cout << time(0);
    int n;
    cin >> n;
    string words[n];
    for(int i = 0; i < n; i++){
        cin >> words[i];
    }
    srand(time(0));
    int randomIndex = rand() % n;
    string question = words[randomIndex];
    cout << "Enter an anagram of the word " << question << ": ";
    sort(question.begin(), question.end());
    string answer;
    cin >> answer;
    sort(answer.begin(), answer.end());
    if(answer == question){ 
        cout << "Correct! :)" << endl;
    } else {
        cout << "Incorrect! :(" << endl;
    }


}