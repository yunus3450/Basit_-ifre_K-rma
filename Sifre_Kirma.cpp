/*
Bu C++ programı, basit bir şifre kırma simülasyonu gerçekleştirir. Başlangıçta, belirli bir şifre belirlenir.
Kullanıcıya, şifreyi kırmak için bir tuşa basması gerektiği söylenir. Ardından, bir while döngüsü başlatılır ve her döngüde program,
rastgele karakterlerden oluşan bir tahmin üretir ve bu tahmini gerçek şifre ile karşılaştırır. Tahmin doğru değilse, bir sonraki tahmin üretilir ve bu işlem tekrarlanır. 
Doğru tahmin yapıldığında, program tahmini ekrana yazdırır ve işlemi tamamlar. Bu program, basit bir brute-force (kaba kuvvet) saldırısı örneği sunar,
çünkü her döngüde rastgele bir tahmin üretilerek şifre kırılmaya çalışılır. Ancak, gerçek dünya senaryolarında, 
daha karmaşık şifreler ve daha sofistike yöntemler kullanıldığı için bu yaklaşım etkili olmayabilir.*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

string TahminUret(int uzunluk) {
    string tahmin = "";
    string karakterSeti = "ABCDEFĞGHIİJKLMNOÖPRSŞTUÜVYZWXabcdefğghıijklmnoöprsştuüvyzwx0123456789.,";
    for (int i = 0; i < uzunluk; i++) {
        tahmin += karakterSeti[rand() % karakterSeti.length()];
    }
    return tahmin;
}

int main() {
    cout << "Basit Şifre Kırma Programı" << endl;
    string sifre = "E35";
    string tahmin = "";
    cout << "Şifre Kırma İşlemini Başlatmak İçin Bir Tuşa Basınız." << endl;
    cin.get();

    int i = 0;
    while (tahmin != sifre) {
        i++;
        tahmin = TahminUret(sifre.length());
        cout << i << ". Tahmin Edilen Şifre: " << tahmin << endl;

        if (tahmin == sifre)
            break;
    }

    cout << "Şifre Kırma İşlemi Başarılı. Şifre: " << tahmin << endl;

    return 0;
}
