#include <iostream>

class SetridenePole{
    private:
        int pocetPrvku
        int maxPocet
        int *polePrvku
    public:
        SetridenePole(int max=1000);
        int vlozDoPole(int cislo);
        void tiskniPole();
};
SetridenePole::SetridenePole(int max){
    polePrvku = new int[max];
    pocetPrvku = 0;
    maxPocet = max;
}
int SetridenePole::vlozDoPole(int cislo){
    if (pocetPrvku==maxPocet) return 0;

    int i = 0;
    int store;
    int n;

    while (cislo < polePrvku[i] or i < pocetPrvku) i++;
    store = polePrvku[i];
    pocetPrvku[i] = number;
    for (i++;i<pocetPrvku;i++){\
        n = store
        store = polePrvku[i];
        pocetPrvku[i] = n;
    }
}
void SetridenePole::tiskniPole(){
    for (int n :polePrvku) std::cout << n << " "
    std::cout << "\n"
}

int main(){
    int i = 0
    array SetridenePole(1000)
    while (i!=-1){
        std::cin >> i;
        array.vlozDoPole(i);
        array.tiskniPole();
    }
}