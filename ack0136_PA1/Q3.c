#include <stdio.h>
#include <stdlib.h>

int main ()
{
	printf("Enter the sentence: "); //prompts for user input
	char str[255];
	scanf("%[^\n]s",str);
	
	int32_t w = 0; //count of three letter words
	int32_t wl = 0; // length of current word
	int32_t v = 0; //count of vowels, counting y
	int32_t l = 0; //length of sentence in number of characters
	while(str[l] != '\0'){ //loops for each character in str
		char c = str[l];
		if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y')
			v = v + 1; //increment vowels, user input determines if y counts as a vowel
		if(c > 64 && c < 91 || c > 96 && c < 123) //a valid character is any letter
		//apostrophes ( ' ) are not counted despite the existance of contractions like "won't" because the prompt specifies counting words of just letters
			wl = wl + 1; //increments length of current word 
		else if(wl == 3){
			w = w + 1; //counts three lettered words
			wl = 0;
		}
		else
			wl = 0; //resets word length count if word ends
		l = l + 1; //length of str
	}	
	printf("There are %d three-letter words, %d vowels, and the sentence is %d characters long. %s",w,v,l,str);
	return 0;
}