#include "sLinkList.h"
#include <cstring>
int main() {
    sLinkList list;
    int num, x, y;
    while(cin >> num){
        list.pushBack(num);
        char ch = getchar();//通过getchar()来判断最后输入回车符结束
        if(ch == '\n')
            break;
    }
    cin >> x >> y;
    list.erase(x, y);
    list.print();
    cout << endl;


    return 0;
}



