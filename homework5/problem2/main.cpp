#include "BinarySearchTree.h"

int main() {
    int n, num, I, a, b, x, y;
    BinarySearchTree *T;
    T = new BinarySearchTree();
    char s[81];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        cin.get();
        cin.getline(s, 80);
        T->insert(num, s);
    }

    cin >> I >> a >> b >> x >> y;
    T->find_i(I);
    T->deleteInRange(a, b);
    T->midOrder();
    cout << endl;
    T->deleteSmaller(x);
    T->midOrder();
    cout << endl;
    T->deleteLarger(y);
    T->midOrder();
    cout << endl;


    delete T;
    return 0;
}