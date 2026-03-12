#include <stdio.h>

int main(void){
    char text[5];
    char inverse[5];
    
    printf("Entrez un mot de 4 lettre: ");
    scanf("%s", text);
    for(int i = 0; i < 4; i++){
        inverse[i] = text[3-i];
    }
    inverse[4] = '\0';
    
    printf("L'inverse du mot %s est %s\n", text, inverse);
    
    return 0;
}
