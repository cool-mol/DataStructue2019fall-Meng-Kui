#include <iostream>
#include "sLinkString.h"

int main() {
    sLinkString word1, word2;
    char a[1000],b[1000];
    cin >> a >> b;
    word1.inputWord(a);
    word2.inputWord(b);

    printSameSuffix(word1,word2);

    return 0;
}
