#include <stdio.h>
#include <string.h>

#define TXT 1024
#define WORD 30

int Anagram(char *ch, char *word) {
    char copy[WORD] = "";
    strcpy(copy, word);
    int space = 0;
    int bool = 0;
    int enter = 0;
    int first = 0;
    int size = strlen(ch);
    for (int i = 0; i < size && i < TXT - 1; i++) {
        enter = 0;
        if (ch[i] == '~') {
            break;
        }
        for (int j = 0; j < strlen(copy) + space && j < WORD - 1; j++) {
            if (ch[i] == copy[j]) {
                bool++;
                enter = 1;
                copy[j] = "";
                break;
            } else {
                if (ch[i] == ' ') {
                    space++;
                    break;
                }
            }
            if ((space != 0 || bool != 0) && enter == 0 && j + 1 == strlen(copy)) {
                i = i - bool;
                bool = 0;
                space = 0;
                strcpy(copy, word);
            }
        }
        if (bool == strlen(word)) {
            first++;
            if (first > 1) {
                printf("~");
            }
            for (int k = i - space - bool + 1; k <= i; k++) {
                if (k == i - space - bool + 1 && ch[k] == ' ') {
                } else {
                    printf("%c", ch[k]);
                }

            }
            i = i - 2;
            strcpy(copy, word);
            space = 0;
            bool = 0;
        }
    }
    return 0;
}

int Gimetria(char *ch, char *word) {

    int target = 0;
    int size = strlen(word);
    for (int i = 0; i < size; i++) {
        if ((int) word[i] >= 65 && (int) word[i] <= 90) {
            target = target + ((int) word[i] - 64);
        } else {
            if ((int) word[i] >= 97 && (int) word[i] <= 122) {
                target = target + ((int) word[i] - 96);
            }
        }
    }
    int tmp = 0;
    int counter = 0;
    size = strlen(ch);
    int last_indx = 0;
    //int wordSize = sizeof(word) / sizeof(char);
    for (int i = 0; i < size && i < TXT - 1; i++) {
        tmp = 0;
        if (ch[i] == '~') {
            i = TXT - 1;
        }
        for (int j = i; j < i + WORD - 1; j++) {
            if (ch[j] == '~') {
                i = TXT - 1;
                break;
            }
            if (tmp == target &&
                (((int) ch[i] >= 65 && (int) ch[j] <= 90) || ((int) ch[i] >= 97 && (int) ch[j] <= 122))) {
                if (counter >= 1) {
                    printf("~");
                }
                counter++;
                for (int k = i; k <= last_indx; k++) {
                    printf("%c", ch[k]);
                }
                break;
            } else {
                if (tmp > target) {
                    break;
                }
            }
            if ((int) ch[j] >= 65 && (int) ch[j] <= 90) {
                if (tmp < target) {
                    tmp = tmp + ((int) ch[j] - 64);
                    last_indx = j;
                } else {
                    break;
                }
            } else {
                if ((int) ch[j] >= 97 && (int) ch[j] <= 122) {
                    if (tmp < target) {
                        tmp = tmp + ((int) ch[j] - 96);
                        last_indx = j;
                    }
                }
            }
        }
    }
    return 0;
}

char MakeItAtbash(char c) {
    int ascii = c;
    if (ascii >= 97 && ascii <= 122) {
        if (ascii > 110) {
            ascii = ascii - (122 - ascii);
        }
        if (ascii <= 110) {
            ascii = 122 - (ascii - 97);
        }
    }
    if (ascii >= 65 && ascii <= 90) {
        if (ascii > 78) {
            ascii = ascii - (90 - ascii);
        }
        if (ascii <= 78) {
            ascii = 90 - (ascii - 65);
        }
    }
    return ascii;
}

int Atbash(char *ch, char *word) {
    int sizeword = strlen(word);
    int sizech = strlen(ch);
    char tmpWORD[WORD];
    for (int i = 0; i < sizeword; i++) {
        word[i] = MakeItAtbash(word[i]);
    }
//    for (int i = 0; i < sizech; i++) {
//        ch[i] = MakeItAtbash(ch[i]);
//    }
    for (int i = 0; i < sizech; i++) {
        if (ch[i] == word[0]) {
            for (int j = 0; j < sizeword; j++) {
                if (ch[i + j] == word[j]) {
                    tmpWORD[j] = word[j];
                } else { memset(tmpWORD, 0, sizeword); }
            }
            if (strlen(tmpWORD) == sizeword) {
                for (int j = 0; j < sizeword; j++) {
                    printf("%c", tmpWORD[j]);
                    tmpWORD[j] = "";
                }
            }
        }
        if (ch[i] == word[sizeword]) {
            for (int j = 0; j < sizeword; j++) {
                if (ch[sizeword - i] == word[sizeword - j]) {
                    tmpWORD[j] = word[sizeword - j];
                } else { memset(tmpWORD, 0, sizeword); }
            }
            if (strlen(tmpWORD) == sizeword) {
                for (int j = 0; j < sizeword; j++) {
                    printf("%c", tmpWORD[j]);
                    tmpWORD[j] = "";
                }
            }
        }
    }
}

int main() {

    char word[WORD] = "Head";
    //char copy[WORD] = "";
    //strcpy(copy, word);
    char ch[TXT] = "Head, shoulders, knees and toes,\n"
                   "Knees and toes.\n"
                   "Head, shoulders, knees and toes,\n"
                   "Knees and toes.\n"
                   "And eyes, and ears, and mouth, and nose.\n"
                   "Head, shoulders, knees and toes,\n"
                   "Knees and toes.~";
    char *ptrCh = &ch[0];
    char *ptrWord = &word[0];
    Anagram(ptrCh, ptrWord);
    printf("\n");

    char word2[WORD] = "abcd";
    char ch2[TXT] = "AbcdaBcf74'dsGsxyzw6ab Dc4";
//
    char *ptrCh2 = &ch2[0];
    char *ptrWord2 = &word2[0];

    Gimetria(ptrCh, ptrWord);
    printf("\n");
    //Atbash(ptrCh2, ptrWord2);

    return 0;

}