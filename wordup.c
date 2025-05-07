//Julian Shahin
//Project 10
//4/29/2025

#define WORD 5
#define TRY 6
#include <stdio.h>
#include <stdbool.h>

char CUpper(char c);
void CAns(char *dst, char *src);
void DisplayG(char *guess, char *mystery);
void ToLower(char *str);
bool MysteryT(const char *filename, char *word);
bool Guesses(char *guess);
bool Capletter(char c);
bool WordMatch(char *a, char *b);

int main(){
	char mystery[WORD + 1];
	char guess[WORD + 1];
	char allguess[TRY][WORD + 1];
	int attempts = 0;
	
	if(!MysteryT("mysteryword.txt", mystery)){
		printf("Error loading mysteryword.txt.\n");
return 1;
	}
	printf("	WELCOME TO WORDUP! Try and guess the 5 letter word in %d tries\n", TRY);
	
while(attempts < TRY){
	if(!Guesses(guess)){
		printf("Invalid input. Please enter a 5 letter word with an alphabetical\n");
	continue;
	}
	while(getchar() != '\n');
		ToLower(guess);
		DisplayG(guess, mystery);
		CAns(allguess[attempts], guess);
		
	if(WordMatch(guess, mystery)){
		printf("		CONGRATULATIONS!!!\n		'%s' was the right answer\n		You won in %d amount of guesses!\n",mystery, attempts + 1);
return 0;	} attempts++;
		}
	printf("You lost, better luck next time!\n");
return 0;
}

char CUpper(char c){
	if(c >= 'a' && c <= 'z')
	return c - 'a' + 'A';
	return c;
}
void CAns(char *dst, char *src){
	for(int i = 0; i< WORD; i++){
	dst[i] = src[i];
	}
	dst[WORD]= '\0';
}

void DisplayG(char *guess, char *mystery){
	char line1[WORD + 1];
	char line2[WORD + 1];
	bool used[WORD] = {false};

for(int i = 0; i < WORD; i++){
	if (guess[i] == mystery[i]){
		line1[i] = CUpper(guess[i]);
		used[i] = true;	
	}else {
            line1[i] = guess[i];
        }
        line2[i] = ' ';
    }

    for (int i = 0; i < WORD; i++) {
        if (guess[i] == mystery[i]) continue;

        for (int j = 0; j < WORD; j++) {
            if (!used[j] && guess[i] == mystery[j]) {
                line2[i] = '^';
                used[j] = true;
                break;
            }
        }
    }

    line1[WORD] = '\0';
    line2[WORD] = '\0';

    printf("%s\n", line1);
    printf("%s\n\n", line2);
}

void ToLower(char *str){
    for (int i = 0; i < WORD; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] - 'A' + 'a';
        }
    }
}
bool MysteryT(const char *filename, char *word){
	FILE *fp = fopen(filename, "r");
if(!fp) return false;
	int i = 0;
	char c;
while(i < WORD && (c = fgetc(fp)) != EOF){
        if(Capletter(c)){
		word[i++] = c;
        }
    }
    word[i] = '\0';

    fclose(fp);
    return (i == WORD);
}
bool Guesses(char *guess){
	int len = 0;
	printf("Enter guess: ");
	scanf("%5s", guess);

}
bool Capletter(char c){
	return(c >= 'a' && c <= 'z')||(c >= 'A' && c <= 'Z');
}
	
bool WordMatch(char *a, char *b){
	for (int i = 0; i < WORD; i++){
	if(a[i] != b[i]) return false;
    }
    return true;
}

