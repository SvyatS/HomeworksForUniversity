#include <iostream>
#include <cstring>

using namespace std;

void __qsort(char* s, int a, int b);
void chars_qsort(char* s);
 
int main(void){
    char s[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    cout << s << endl;
    chars_qsort(s);
    cout << s << endl;
    cin.get();
    return 0;
}
 
void chars_qsort(char* s){
    int n = strlen(s);
    if(n > 1) __qsort(s, 0, n - 1);
}
 
void __qsort(char* s, int a, int b){
    char k;
    int  m = s[a + (b - a) / 2];
    int  i = a;
    int  j = b;
    while(true){
        while(s[i] < m) i++;
        while(s[j] > m) j--;
        if(i > j) break;
        k = s[i];
        s[i] = s[j];
        s[j] = k;
        i++;
        j--;
    }
    if(i < b) __qsort(s, i, b);
    if(j > a) __qsort(s, a, j);
}
