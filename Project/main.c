#define LoadImageA LoadImage
#define DrawTextA DrawText
#define DrawTextExA DrawTextEx
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <curl/curl.h>
#define PlaySoundA PlaySound
#include <raylib.h>




#define MAX_SATIR 10 // Ekranda en fazla 10 satırda asker yerleştirilebilir.
#define MAX_SUTUN 10 // Ekranda en fazla 10 sütunda asker yerleştirilebilir.
#define MAX_ASKER 100 // Asker sayısı için maksimum değer
#define IzgaraBoyutu 14
#define HucreBoyutu 64 // Hücre boyutu (px)


// Gelen veriyi tutmak için yapı
struct bellekStruct {
    char *bellek;
    size_t size;
};



void savasmekanigi(); // prototip
typedef struct {
    double piyadesaldirigucu;
    double okcusaldirigucu;
    double suvarisaldirigucu;
    double kusatmamakinelerisaldirigucu;
    double orkdovusculerisaldirigucu;
    double mizrakcilarsaldirigucu;
    double vargbinicilerisaldirigucu;
    double trollersaldirigucu;
}SaldiriGuc;

typedef struct {
    double piyadesavunmagucu;
    double okcusavunmagucu;
    double suvarisavunmagucu;
    double kusatmamakinelerisavunmagucu;
    double orkdovusculerisavunmagucu;
    double mizrakcilarsavunmagucu;
    double vargbinicilerisavunmagucu;
    double trollersavunmagucu;
}SavunmaGuc;

typedef struct {
    double piyadekritikvurusadim;
    double okcukritikvurusadim;
    double suvarikritikvurusadim;
    double kusatmamakinelerikritikvurusadim;
    double orkdovusculerikritikvurusadim;
    double mizrakcilarkritikvurusadim;
    double vargbinicilerikritikvurusadim;
    double trollerkritikvurusadim;
}KritikVurusAdim;

typedef struct {
    double piyadekritikvurus;
    double okcukritikvurus;
    double suvarikritikvurus;
    double kusatmamakinelerikritikvurus;
    double orkdovusculerikritikvurus;
    double mizrakcilarkritikvurus;
    double vargbinicilerikritikvurus;
    double trollerkritikvurus;
}KritikVurusHasar;



typedef struct {
    SaldiriGuc saldiriguc;
    SavunmaGuc savunmaguc;
    KritikVurusAdim kritikvurusadim;
    KritikVurusHasar kritikvurushasar;
}SavasVerileri;



typedef struct { // Birlikler icin
    double saldiri;
    double savunma;
    double maksimumsaglik;
    double kritik_sans;
    int askersayi;
} Birlik;
typedef struct { // İnsan imp. ait Birlik bilgileri
    Birlik piyadeler;
    Birlik okcular;
    Birlik suvariler;
    Birlik kusatma_makineleri;
} InsanImparatorluguBirlikleri;
typedef struct { // Ork Legine ait Birlik bilgileri
    Birlik ork_dovusculeri;
    Birlik mizrakcilar;
    Birlik varg_binicileri;
    Birlik troller;
} OrkLegiBirlikleri;



typedef struct { // Canavarlar icin etki bilgileri
   char etki_degeri[10]; // Etki degeri
   char etki_turu[20]; //Etki türü(saldırı,savunma,kritik_sans)
   char aciklama[100]; // Aciklama
   char aciklamaetki[30];
   double etkideger; // Etki degerinin inte donmus hali
} Etki;
typedef struct{  // İnsan imp. ait Canavar bilgileri
  Etki Ejderha;
  Etki Agri_Dagi_Devleri;
  Etki Tepegoz;
  Etki Karakurt;
  Etki Samur;
  char canavarsecilen[3][30];
}InsanImparatorluguCanavarlari;
typedef struct{ //Ork Legine ait Canavar bilgileri
  Etki Kara_troll;
  Etki Golge_kurtlari;
  Etki Camur_devleri;
  Etki Ates_iblisi;
  Etki Makrog_Savas_Beyi;
  Etki Buz_Devleri;
  char canavarsecilen[3][30];
}OrkLegiCanavarlari;



typedef struct{ // Kahramanlar icin bonus bilgileri
 char bonus_turu[20]; // Bonus türü
 char bonus_degeri[10]; // Bonus degeri
 char aciklama[100]; // Aciklama
 char aciklamaetki[30];
 double bonusdeger; // bonus degerinin inte donmus hali

}Bonus;
typedef struct{ // İnsan imp. ait kahraman bilgileri
  Bonus Alparslan;
  Bonus Fatih_Sultan_Mehmet;
  Bonus Mete_Han;
  Bonus Yavuz_Sultan_Selim;
  Bonus Tugrul_Bey;
  char kahramansecilen[3][30];
}InsanImparatorluguKahramanlari;
typedef struct{ // Ork Legine ait Kahraman Bilgileri
  Bonus Goruk_Vahsi;
  Bonus Thruk_Kemikkiran;
  Bonus Vrog_Kafakiran;
  Bonus Ugar_Zalim;
char kahramansecilen[3][30];
}OrkLegiKahramanlari;

int orksaldiriarastirma;
int orksavunmaarastirma;
int orkelitarastirma;
int insansaldiriarastirma;
int insansavunmaarastirma;
int insanelitarastirma;
int insankusatmaarastirma;

typedef struct{ // Araştırmaları tutan yapi
  char deger[10]; // Arastirma degeri
  char aciklama[100]; // Aciklama;
  char aciklamaetki[30];
  double arastirmadeger;
}ArastirmaSeviyesi;
typedef struct{
    ArastirmaSeviyesi seviye_1;
    ArastirmaSeviyesi seviye_2;
    ArastirmaSeviyesi seviye_3;
    ArastirmaSeviyesi seviyebelirle;
}Arastirma;
typedef struct{
  Arastirma savunma_ustaligi;
  Arastirma saldiri_gelistirilmesi;
  Arastirma elit_egitim;
  Arastirma kusatma_ustaligi;

}TumArastirmalar;


typedef struct {
    InsanImparatorluguBirlikleri insan_imparatorlugubirlik;
    OrkLegiBirlikleri ork_legibirlik;
    InsanImparatorluguCanavarlari insan_imparatorlugucanavar;
    OrkLegiCanavarlari ork_legicanavar;
    InsanImparatorluguKahramanlari Insan_imparatorluguKahraman;
    OrkLegiKahramanlari ork_legikahraman;
    TumArastirmalar arastirmalar;

} TumBirlikler;


TumBirlikler birlikler = {0}; // Global değişken


typedef struct {
    double maxHealth;
    double health;
    int soldierCount; // Asker sayısı
    Texture2D texture; // Birim görseli
} Unit;


int savassonuc;


// Gelen veriyi yazmak için callback fonksiyonu
size_t BellegeYaz(void *contents, size_t size, size_t nmemb, struct bellekStruct *userp) {
    size_t realsize = size * nmemb;

    // Bellek ayır
    userp->bellek = realloc(userp->bellek, userp->size + realsize + 1);
    if (userp->bellek == NULL) {
        printf("Yeterli bellek yok (realloc NULL döndü)\n");
        return 0; // Bellek tahsisi başarısız
    }

    // Veriyi belleğe kopyala
    memcpy(&(userp->bellek[userp->size]), contents, realsize);
    userp->size += realsize;
    userp->bellek[userp->size] = 0; // Null terminator ekle
    return realsize;
}

double kalanpiyade;
double kalanokcu;
double kalansuvari;
double kalankusatmamakineleri;
double kalanorkdovusculeri;
double kalanmizrakcilar;
double kalanvargbinicileri;
double kalantroller;


double piyadeilkgorselsayi;
double suvariilkgorselsayi;
double okcuilkgorselsayi;
double kusatmailkgorselsayi;

double orkilkgorselsayi;
double vargilkgorselsayi;
double mizrakciilkgorselsayi;
double trolilkgorselsayi;


int gelenkahramanalparslan=0;
int gelenkahramanfatih=0;
int gelenkahramanmetehan=0;
int gelenkahramanyavuz=0;
int gelenkahramantugrul=0;
int gelenkahramangorukvahsi=0;
int gelenkahramanthrukkemikkiran=0;
int gelenkahramanvrogkafakiran=0;
int gelenkahramanugarzalim=0;


int gelencanavarejderha=0;
int gelencanavaragridagidevi=0;
int gelencanavartepegoz=0;
int gelencanavarkarakurt=0;
int gelencanavarsamur=0;
int gelencanavarkaratroll=0;
int gelencanavargolgekurtlari=0;
int gelencanavarcamurdevleri=0;
int gelencanavaratesiblisi=0;
int gelencanavarmakrogsavasbeyi=0;
int gelencanavarbuzdevleri=0;




void unittypes_readparse() {

    const char *dosya_yolu ="files\\unit_types.json"; // Dosya yolu belirt


    FILE *dosya = fopen(dosya_yolu, "r"); // Dosya açma
    if (dosya == NULL) {
        printf("Dosya 'files\\unit_types.json' bulunamadi. Lutfen dosyanin doğru isimde ve dogru dizinde oldugundan emin olun.\n");
        return;
    }

    fseek(dosya, 0, SEEK_END); // Dosya sonuna git
    int dosya_boyut = ftell(dosya); // Boyut al
    fseek(dosya, 0, SEEK_SET); // Dosya başına geri dön

    char *json_unittypesstr = malloc(dosya_boyut + 1); // Yeterli bellek ayırma +1 NULL
    if (json_unittypesstr == NULL) {
        printf("Bellek ayirma hatasi\n");
        fclose(dosya);
        return;
    }

    size_t index = 0;
    int c;
    while (index < dosya_boyut) {
        c = getc(dosya); // Sirasi ile alip char dizisine yazdir.
        json_unittypesstr[index++] = c;
    }
    json_unittypesstr[index] = '\0'; // NULL karakter ekle

    fclose(dosya);




// JSON verilerini Parse edip structlara atma.


const char *unittypesanahtarlar[] = {"saldiri", "savunma", "saglik", "kritik_sans"};
const char *birlikAnahtarlar[] = {
    "ork_dovusculeri",
    "mizrakcilar",
    "varg_binicileri",
    "troller",
    "piyadeler",
    "okcular",
    "suvariler",
    "kusatma_makineleri"
};

double **degerler[] = {
    (double *[]){&birlikler.ork_legibirlik.ork_dovusculeri.saldiri,
               &birlikler.ork_legibirlik.ork_dovusculeri.savunma,
               &birlikler.ork_legibirlik.ork_dovusculeri.maksimumsaglik,
               &birlikler.ork_legibirlik.ork_dovusculeri.kritik_sans},
    (double *[]){&birlikler.ork_legibirlik.mizrakcilar.saldiri,
               &birlikler.ork_legibirlik.mizrakcilar.savunma,
               &birlikler.ork_legibirlik.mizrakcilar.maksimumsaglik,
               &birlikler.ork_legibirlik.mizrakcilar.kritik_sans},
    (double *[]){&birlikler.ork_legibirlik.varg_binicileri.saldiri,
               &birlikler.ork_legibirlik.varg_binicileri.savunma,
               &birlikler.ork_legibirlik.varg_binicileri.maksimumsaglik,
               &birlikler.ork_legibirlik.varg_binicileri.kritik_sans},
    (double *[]){&birlikler.ork_legibirlik.troller.saldiri,
               &birlikler.ork_legibirlik.troller.savunma,
               &birlikler.ork_legibirlik.troller.maksimumsaglik,
               &birlikler.ork_legibirlik.troller.kritik_sans},
    (double *[]){&birlikler.insan_imparatorlugubirlik.piyadeler.saldiri,
               &birlikler.insan_imparatorlugubirlik.piyadeler.savunma,
               &birlikler.insan_imparatorlugubirlik.piyadeler.maksimumsaglik,
               &birlikler.insan_imparatorlugubirlik.piyadeler.kritik_sans},
    (double *[]){&birlikler.insan_imparatorlugubirlik.okcular.saldiri,
               &birlikler.insan_imparatorlugubirlik.okcular.savunma,
               &birlikler.insan_imparatorlugubirlik.okcular.maksimumsaglik,
               &birlikler.insan_imparatorlugubirlik.okcular.kritik_sans},
    (double *[]){&birlikler.insan_imparatorlugubirlik.suvariler.saldiri,
               &birlikler.insan_imparatorlugubirlik.suvariler.savunma,
               &birlikler.insan_imparatorlugubirlik.suvariler.maksimumsaglik,
               &birlikler.insan_imparatorlugubirlik.suvariler.kritik_sans},
    (double *[]){&birlikler.insan_imparatorlugubirlik.kusatma_makineleri.saldiri,
               &birlikler.insan_imparatorlugubirlik.kusatma_makineleri.savunma,
               &birlikler.insan_imparatorlugubirlik.kusatma_makineleri.maksimumsaglik,
               &birlikler.insan_imparatorlugubirlik.kusatma_makineleri.kritik_sans}
};

for (int j = 0; j < 8; j++) {
    char *imlec = strstr(json_unittypesstr, birlikAnahtarlar[j]); // Sirasi ile karakterleri ara
    if (imlec) {
        imlec = strstr(imlec, "{");
        if (imlec) {
            imlec++;

            for (int i = 0; i < 4; i++) {
                char *anahtar = strstr(imlec, unittypesanahtarlar[i]); // Anahtar ile aynı olsun
                if (anahtar) {
                    anahtar = strstr(anahtar, ":");
                    if (anahtar) {
                        anahtar += 1;
                        while (*anahtar == ' ') {
                            anahtar++;
                        }

                        if (*anahtar >= '0' && *anahtar <= '9') {
                            *degerler[j][i] = atoi(anahtar);
                        }
                    }
                }
            }
        }
    }
}


    free(json_unittypesstr); // Dinamik olarak ayirdigin alani serbest birak.


}

void heroes_readparse(){

const char *dosya_yolu = "files\\heroes.json"; // Dosya yolu belirt

    FILE *dosya = fopen(dosya_yolu, "r"); // Dosya açma
    if (dosya == NULL) {
        printf("Dosya 'files\\heroes.json' bulunamadi. Lutfen dosyanin doğru isimde ve dogru dizinde oldugundan emin olun.\n");
        return;
    }

    fseek(dosya, 0, SEEK_END); // Dosya sonuna git
    int dosya_boyut = ftell(dosya); // Boyut al
    fseek(dosya, 0, SEEK_SET); // Dosya başına geri dön


    char *json_heroesstr = malloc(dosya_boyut + 1); // Yeterli bellek ayırma +1 NULL
    if (json_heroesstr == NULL) {
        printf("Bellek ayirma hatasi\n");
        fclose(dosya);
        return;
    }

    size_t index = 0;
    int c;
    while (index < dosya_boyut) {
        c = getc(dosya);
        json_heroesstr[index++] = c;
    }
    json_heroesstr[index] = '\0'; // NULL karakter ekle

    fclose(dosya);



// JSON verilerini Parse edip structlara atma.



     const char *heroesanahtarlar[] = {
                "\"bonus_turu\"",
                "\"bonus_degeri\"",
                "\"aciklama\""
              };

  const char *kahramanlaranahtar[] = {
    "Goruk_Vahsi",
    "Thruk_Kemikkiran",
    "Vrog_Kafakiran",
    "Ugar_Zalim",
    "Alparslan",
    "Fatih_Sultan_Mehmet",
    "Mete_Han",
    "Yavuz_Sultan_Selim",
    "Tugrul_Bey"
};
char *degerler2[][3] = {
    {
        birlikler.ork_legikahraman.Goruk_Vahsi.bonus_turu,
        birlikler.ork_legikahraman.Goruk_Vahsi.bonus_degeri,
        birlikler.ork_legikahraman.Goruk_Vahsi.aciklama
    },
    {
        birlikler.ork_legikahraman.Thruk_Kemikkiran.bonus_turu,
        birlikler.ork_legikahraman.Thruk_Kemikkiran.bonus_degeri,
        birlikler.ork_legikahraman.Thruk_Kemikkiran.aciklama
    },
    {
        birlikler.ork_legikahraman.Vrog_Kafakiran.bonus_turu,
        birlikler.ork_legikahraman.Vrog_Kafakiran.bonus_degeri,
        birlikler.ork_legikahraman.Vrog_Kafakiran.aciklama
    },
    {
        birlikler.ork_legikahraman.Ugar_Zalim.bonus_turu,
        birlikler.ork_legikahraman.Ugar_Zalim.bonus_degeri,
        birlikler.ork_legikahraman.Ugar_Zalim.aciklama
    },
    {
        birlikler.Insan_imparatorluguKahraman.Alparslan.bonus_turu,
        birlikler.Insan_imparatorluguKahraman.Alparslan.bonus_degeri,
        birlikler.Insan_imparatorluguKahraman.Alparslan.aciklama
    },
    {
        birlikler.Insan_imparatorluguKahraman.Fatih_Sultan_Mehmet.bonus_turu,
        birlikler.Insan_imparatorluguKahraman.Fatih_Sultan_Mehmet.bonus_degeri,
        birlikler.Insan_imparatorluguKahraman.Fatih_Sultan_Mehmet.aciklama
    },
    {
        birlikler.Insan_imparatorluguKahraman.Mete_Han.bonus_turu,
        birlikler.Insan_imparatorluguKahraman.Mete_Han.bonus_degeri,
        birlikler.Insan_imparatorluguKahraman.Mete_Han.aciklama
    },
    {
        birlikler.Insan_imparatorluguKahraman.Yavuz_Sultan_Selim.bonus_turu,
        birlikler.Insan_imparatorluguKahraman.Yavuz_Sultan_Selim.bonus_degeri,
        birlikler.Insan_imparatorluguKahraman.Yavuz_Sultan_Selim.aciklama
    },
    {
        birlikler.Insan_imparatorluguKahraman.Tugrul_Bey.bonus_turu,
        birlikler.Insan_imparatorluguKahraman.Tugrul_Bey.bonus_degeri,
        birlikler.Insan_imparatorluguKahraman.Tugrul_Bey.aciklama
    }
};



  for(int a=0;a<9;a++){

         char *imlec2 = strstr(json_heroesstr,kahramanlaranahtar[a]);
    if (imlec2) {
        imlec2 = strstr(imlec2, "{");
        if (imlec2) {
            imlec2++; // Süslü parantezden sonra bir adım ilerle


            for (int i = 0; i < 3; i++) {
                char *anahtar = strstr(imlec2, heroesanahtarlar[i]);
                if (anahtar) {
                    anahtar = strstr(anahtar, ":");
                    if (anahtar) {
                        anahtar += 1;
                        while (*anahtar == ' ' || *anahtar == '\"') {
                            anahtar++;
                        }

                        char *son = strstr(anahtar, "\"");
                        if (son) {
                            size_t uzunluk = son - anahtar;
                            strncpy(degerler2[a][i], anahtar, uzunluk);
                            degerler2[a][i][uzunluk] = '\0'; // Null terminator ekleyin
                        }
                    }
                }
            }
        }
    }
  }

   // string olarak alinan sayilari inte cevir
    birlikler.Insan_imparatorluguKahraman.Alparslan.bonusdeger=atoi(birlikler.Insan_imparatorluguKahraman.Alparslan.bonus_degeri);
    birlikler.Insan_imparatorluguKahraman.Fatih_Sultan_Mehmet.bonusdeger=atoi(birlikler.Insan_imparatorluguKahraman.Fatih_Sultan_Mehmet.bonus_degeri);
    birlikler.Insan_imparatorluguKahraman.Mete_Han.bonusdeger=atoi(birlikler.Insan_imparatorluguKahraman.Mete_Han.bonus_degeri);
    birlikler.Insan_imparatorluguKahraman.Tugrul_Bey.bonusdeger=atoi(birlikler.Insan_imparatorluguKahraman.Tugrul_Bey.bonus_degeri);
    birlikler.Insan_imparatorluguKahraman.Yavuz_Sultan_Selim.bonusdeger=atoi(birlikler.Insan_imparatorluguKahraman.Yavuz_Sultan_Selim.bonus_degeri);
    birlikler.ork_legikahraman.Goruk_Vahsi.bonusdeger=atoi(birlikler.ork_legikahraman.Goruk_Vahsi.bonus_degeri);
    birlikler.ork_legikahraman.Thruk_Kemikkiran.bonusdeger=atoi(birlikler.ork_legikahraman.Thruk_Kemikkiran.bonus_degeri);
    birlikler.ork_legikahraman.Ugar_Zalim.bonusdeger=atoi(birlikler.ork_legikahraman.Ugar_Zalim.bonus_degeri);
    birlikler.ork_legikahraman.Vrog_Kafakiran.bonusdeger=atoi(birlikler.ork_legikahraman.Vrog_Kafakiran.bonus_degeri);



   free(json_heroesstr); // Dinamik olarak ayirdigin alani serbest birak

}


  void creatures_readparse(){

   const char *dosya_yolu = "files\\creatures.json"; // Dosya yolu belirt

    FILE *dosya = fopen(dosya_yolu, "r"); // Dosya açma
    if (dosya == NULL) {
        printf("Dosya 'files\\creatures.json' bulunamadi. Lutfen dosyanin doğru isimde ve dogru dizinde oldugundan emin olun.\n");
        return;
    }

    fseek(dosya, 0, SEEK_END); // Dosya sonuna git
    int dosya_boyut = ftell(dosya); // Boyut al
    fseek(dosya, 0, SEEK_SET); // Dosya başına geri dön


    char *json_creaturesjson = malloc(dosya_boyut + 1); // Yeterli bellek ayırma +1 NULL
    if (json_creaturesjson == NULL) {
        printf("Bellek ayirma hatasi\n");
        fclose(dosya);
        return;
    }

    size_t index = 0;
    int c;
    while (index < dosya_boyut) {
        c = getc(dosya);
        json_creaturesjson[index++] = c;
    }
    json_creaturesjson[index] = '\0'; // NULL karakter ekle

    fclose(dosya);




    // JSON verilerini Parse edip structlara atma.




  const char *creaturesanahtarlar[] = {
                "\"etki_degeri\"",
                "\"etki_turu\"",
                "\"aciklama\""
            };


const char *creatures[] = {
    "Kara_Troll",
    "Golge_Kurtlari",
    "Camur_Devleri",
    "Ates_Iblisi",
    "Makrog_Savas_Beyi",
    "Buz_Devleri",
    "Ejderha",
    "Agri_Dagi_Devleri",
    "Tepegoz",
    "Karakurt",
    "Samur"
};



char *degerler3[][3] = {
     {
        birlikler.ork_legicanavar.Kara_troll.etki_degeri,
        birlikler.ork_legicanavar.Kara_troll.etki_turu,
        birlikler.ork_legicanavar.Kara_troll.aciklama
    },
    {
        birlikler.ork_legicanavar.Golge_kurtlari.etki_degeri,
        birlikler.ork_legicanavar.Golge_kurtlari.etki_turu,
        birlikler.ork_legicanavar.Golge_kurtlari.aciklama
    },
    {
        birlikler.ork_legicanavar.Camur_devleri.etki_degeri,
        birlikler.ork_legicanavar.Camur_devleri.etki_turu,
        birlikler.ork_legicanavar.Camur_devleri.aciklama
    },
    {
        birlikler.ork_legicanavar.Ates_iblisi.etki_degeri,
        birlikler.ork_legicanavar.Ates_iblisi.etki_turu,
        birlikler.ork_legicanavar.Ates_iblisi.aciklama
    },
    {
        birlikler.ork_legicanavar.Makrog_Savas_Beyi.etki_degeri,
        birlikler.ork_legicanavar.Makrog_Savas_Beyi.etki_turu,
        birlikler.ork_legicanavar.Makrog_Savas_Beyi.aciklama
    },
    {
        birlikler.ork_legicanavar.Buz_Devleri.etki_degeri,
        birlikler.ork_legicanavar.Buz_Devleri.etki_turu,
        birlikler.ork_legicanavar.Buz_Devleri.aciklama
    },

    {
        birlikler.insan_imparatorlugucanavar.Ejderha.etki_degeri,
        birlikler.insan_imparatorlugucanavar.Ejderha.etki_turu,
        birlikler.insan_imparatorlugucanavar.Ejderha.aciklama
    },
    {
        birlikler.insan_imparatorlugucanavar.Agri_Dagi_Devleri.etki_degeri,
        birlikler.insan_imparatorlugucanavar.Agri_Dagi_Devleri.etki_turu,
        birlikler.insan_imparatorlugucanavar.Agri_Dagi_Devleri.aciklama
    },
    {
        birlikler.insan_imparatorlugucanavar.Tepegoz.etki_degeri,
        birlikler.insan_imparatorlugucanavar.Tepegoz.etki_turu,
        birlikler.insan_imparatorlugucanavar.Tepegoz.aciklama
    },
    {
        birlikler.insan_imparatorlugucanavar.Karakurt.etki_degeri,
        birlikler.insan_imparatorlugucanavar.Karakurt.etki_turu,
        birlikler.insan_imparatorlugucanavar.Karakurt.aciklama
    },
    {
        birlikler.insan_imparatorlugucanavar.Samur.etki_degeri,
        birlikler.insan_imparatorlugucanavar.Samur.etki_turu,
        birlikler.insan_imparatorlugucanavar.Samur.aciklama
    },



};


   for (int a = 0; a < 11; a++) {
    char *imlec = strstr(json_creaturesjson, creatures[a]); // Canavar için
    if (imlec) {
        imlec = strstr(imlec, "{");
        if (imlec) {
            imlec++; // Süslü parantezden sonra bir adım ilerle

            for (int i = 0; i < 3; i++) {
                char *anahtar = strstr(imlec, creaturesanahtarlar[i]);
                if (anahtar) {
                    anahtar = strstr(anahtar, ":");
                    if (anahtar) {
                        anahtar += 1;
                        while (*anahtar == ' ' || *anahtar == '\"') {
                            anahtar++;
                        }

                        char *son = strstr(anahtar, "\"");
                        if (son) {
                            size_t uzunluk = son - anahtar;
                            strncpy(degerler3[a][i], anahtar, uzunluk);
                            degerler3[a][i][uzunluk] = '\0'; // Null terminator ekleyin
                        }
                    }
                }
            }
        }
    }
}
// str ifadeleri inte cevir.

birlikler.insan_imparatorlugucanavar.Agri_Dagi_Devleri.etkideger=atoi(birlikler.insan_imparatorlugucanavar.Agri_Dagi_Devleri.etki_degeri);
birlikler.insan_imparatorlugucanavar.Ejderha.etkideger=atoi(birlikler.insan_imparatorlugucanavar.Ejderha.etki_degeri);
birlikler.insan_imparatorlugucanavar.Karakurt.etkideger=atoi(birlikler.insan_imparatorlugucanavar.Karakurt.etki_degeri);
birlikler.insan_imparatorlugucanavar.Samur.etkideger=atoi(birlikler.insan_imparatorlugucanavar.Samur.etki_degeri);
birlikler.insan_imparatorlugucanavar.Tepegoz.etkideger=atoi(birlikler.insan_imparatorlugucanavar.Tepegoz.etki_degeri);
birlikler.ork_legicanavar.Ates_iblisi.etkideger=atoi(birlikler.ork_legicanavar.Ates_iblisi.etki_degeri);
birlikler.ork_legicanavar.Buz_Devleri.etkideger=atoi(birlikler.ork_legicanavar.Buz_Devleri.etki_degeri);
birlikler.ork_legicanavar.Camur_devleri.etkideger=atoi(birlikler.ork_legicanavar.Camur_devleri.etki_degeri);
birlikler.ork_legicanavar.Golge_kurtlari.etkideger=atoi(birlikler.ork_legicanavar.Golge_kurtlari.etki_degeri);
birlikler.ork_legicanavar.Kara_troll.etkideger=atoi(birlikler.ork_legicanavar.Kara_troll.etki_degeri);
birlikler.ork_legicanavar.Makrog_Savas_Beyi.etkideger=atoi(birlikler.ork_legicanavar.Makrog_Savas_Beyi.etki_degeri);



  free(json_creaturesjson);


  }


 void research_readparse(){


const char *dosya_yolu = "files\\research.json"; // Dosya yolu belirt

    FILE *dosya = fopen(dosya_yolu, "r"); // Dosya açma
    if (dosya == NULL) {
        printf("Dosya 'files\\research.json' bulunamadi. Lutfen dosyanin doğru isimde ve dogru dizinde oldugundan emin olun.\n");
        return;
    }

    fseek(dosya, 0, SEEK_END); // Dosya sonuna git
    int dosya_boyut = ftell(dosya); // Boyut al
    fseek(dosya, 0, SEEK_SET); // Dosya başına geri dön


    char *json_researchjson = malloc(dosya_boyut + 1); // Yeterli bellek ayırma +1 NULL
    if (json_researchjson == NULL) {
        printf("Bellek ayirma hatasi\n");
        fclose(dosya);
        return;
    }


    size_t index = 0;
    int c;
    while (index < dosya_boyut) {
        c = getc(dosya);
        json_researchjson[index++] = c;
    }
    json_researchjson[index] = '\0'; // NULL karakter ekle

    fclose(dosya);




    // JSON verilerini Parse edip structlara atma.


 const char *researchanahtarlar[] = {
    "\"deger\"",
    "\"aciklama\""
};

const char *seviyeler[] = {
    "seviye_1",
    "seviye_2",
    "seviye_3"
};


char *imlecsavunma_ustaligi = strstr(json_researchjson, "savunma_ustaligi"); // savunma_ustaligi için

char *degerlerasavunmaseviye1[] = {
    birlikler.arastirmalar.savunma_ustaligi.seviye_1.deger,
    birlikler.arastirmalar.savunma_ustaligi.seviye_1.aciklama,
};

char *degerlersavunmaseviye2[] = {
    birlikler.arastirmalar.savunma_ustaligi.seviye_2.deger,
    birlikler.arastirmalar.savunma_ustaligi.seviye_2.aciklama,
};

char *degerlersavunmaseviye3[] = {
    birlikler.arastirmalar.savunma_ustaligi.seviye_3.deger,
    birlikler.arastirmalar.savunma_ustaligi.seviye_3.aciklama,
};


if (imlecsavunma_ustaligi) {
    for (int j = 0; j < 3; j++) {
        char *imlecsavunma_ustaligisev = strstr(imlecsavunma_ustaligi, seviyeler[j]);
        if (imlecsavunma_ustaligisev) {
            imlecsavunma_ustaligisev++; // "seviye_n"dan sonra bir adım ilerle
            for (int i = 0; i < 2; i++) {
                char *anahtar = strstr(imlecsavunma_ustaligisev, researchanahtarlar[i]);
                if (anahtar) {
                    anahtar = strstr(anahtar, ":");
                    if (anahtar) {
                        anahtar += 1;
                        while (*anahtar == ' ' || *anahtar == '\"') {
                            anahtar++;
                        }
                        char *son = strstr(anahtar, "\"");
                        if (son) {
                            size_t uzunluk = son - anahtar;
                            if (j == 0) {
                                strncpy(degerlerasavunmaseviye1[i], anahtar, uzunluk);
                                degerlerasavunmaseviye1[i][uzunluk] = '\0'; // Null terminator ekleyin
                            } else if (j == 1) {
                                strncpy(degerlersavunmaseviye2[i], anahtar, uzunluk);
                                degerlersavunmaseviye2[i][uzunluk] = '\0'; // Null terminator ekleyin
                            } else {
                                strncpy(degerlersavunmaseviye3[i], anahtar, uzunluk);
                                degerlersavunmaseviye3[i][uzunluk] = '\0'; // Null terminator ekleyin
                            }
                        }
                    }
                }
            }
        }
    }
}


char *imlecsaldiri_gelistirilmesi = strstr(json_researchjson, "saldiri_gelistirmesi"); // saldiri_gelistirmesi için

char *degerlersaldiriseviye1[] = {
    birlikler.arastirmalar.saldiri_gelistirilmesi.seviye_1.deger,
    birlikler.arastirmalar.saldiri_gelistirilmesi.seviye_1.aciklama,
};

char *degerlersaldiriseviye2[] = {
    birlikler.arastirmalar.saldiri_gelistirilmesi.seviye_2.deger,
    birlikler.arastirmalar.saldiri_gelistirilmesi.seviye_2.aciklama,
};

char *degerlersaldiriseviye3[] = {
    birlikler.arastirmalar.saldiri_gelistirilmesi.seviye_3.deger,
    birlikler.arastirmalar.saldiri_gelistirilmesi.seviye_3.aciklama,
};

if (imlecsaldiri_gelistirilmesi) {
    for (int j = 0; j < 3; j++) {
        char *imlecsaldiri_gelistirilmesisev = strstr(imlecsaldiri_gelistirilmesi, seviyeler[j]);
        if (imlecsaldiri_gelistirilmesisev) {
            imlecsaldiri_gelistirilmesisev++; // "seviye_n"dan sonra bir adım ilerle
            for (int i = 0; i < 2; i++) {
                char *anahtar = strstr(imlecsaldiri_gelistirilmesisev, researchanahtarlar[i]);
                if (anahtar) {
                    anahtar = strstr(anahtar, ":");
                    if (anahtar) {
                        anahtar += 1;
                        while (*anahtar == ' ' || *anahtar == '\"') {
                            anahtar++;
                        }
                        char *son = strstr(anahtar, "\"");
                        if (son) {
                            size_t uzunluk = son - anahtar;
                            if (j == 0) {
                                strncpy(degerlersaldiriseviye1[i], anahtar, uzunluk);
                                degerlersaldiriseviye1[i][uzunluk] = '\0'; // Null terminator ekleyin
                            } else if (j == 1) {
                                strncpy(degerlersaldiriseviye2[i], anahtar, uzunluk);
                                degerlersaldiriseviye2[i][uzunluk] = '\0'; // Null terminator ekleyin
                            } else {
                                strncpy(degerlersaldiriseviye3[i], anahtar, uzunluk);
                                degerlersaldiriseviye3[i][uzunluk] = '\0'; // Null terminator ekleyin
                            }
                        }
                    }
                }
            }
        }
    }
}


char *imlecelit_egitim = strstr(json_researchjson, "elit_egitim"); // elit_egitim için

char *degerlerelitseviye1[] = {
    birlikler.arastirmalar.elit_egitim.seviye_1.deger,
    birlikler.arastirmalar.elit_egitim.seviye_1.aciklama,
};

char *degerlerelitseviye2[] = {
    birlikler.arastirmalar.elit_egitim.seviye_2.deger,
    birlikler.arastirmalar.elit_egitim.seviye_2.aciklama,
};

char *degerlerelitseviye3[] = {
    birlikler.arastirmalar.elit_egitim.seviye_3.deger,
    birlikler.arastirmalar.elit_egitim.seviye_3.aciklama,
};

if (imlecelit_egitim) {
    for (int j = 0; j < 3; j++) {
        char *imlecelit_egitimsev = strstr(imlecelit_egitim, seviyeler[j]);
        if (imlecelit_egitimsev) {
            imlecelit_egitimsev++; // "seviye_n"dan sonra bir adım ilerle
            for (int i = 0; i < 2; i++) {
                char *anahtar = strstr(imlecelit_egitimsev, researchanahtarlar[i]);
                if (anahtar) {
                    anahtar = strstr(anahtar, ":");
                    if (anahtar) {
                        anahtar += 1;
                        while (*anahtar == ' ' || *anahtar == '\"') {
                            anahtar++;
                        }
                        char *son = strstr(anahtar, "\"");
                        if (son) {
                            size_t uzunluk = son - anahtar;
                            if (j == 0) {
                                strncpy(degerlerelitseviye1[i], anahtar, uzunluk);
                                degerlerelitseviye1[i][uzunluk] = '\0'; // Null terminator ekleyin
                            } else if (j == 1) {
                                strncpy(degerlerelitseviye2[i], anahtar, uzunluk);
                                degerlerelitseviye2[i][uzunluk] = '\0'; // Null terminator ekleyin
                            } else {
                                strncpy(degerlerelitseviye3[i], anahtar, uzunluk);
                                degerlerelitseviye3[i][uzunluk] = '\0'; // Null terminator ekleyin
                            }
                        }
                    }
                }
            }
        }
    }
}

char *imleckusatma_ustaligi = strstr(json_researchjson, "kusatma_ustaligi"); // kusatma_ustaligi için

char *degerlerkusatmaseviye1[] = {
    birlikler.arastirmalar.kusatma_ustaligi.seviye_1.deger,
    birlikler.arastirmalar.kusatma_ustaligi.seviye_1.aciklama,
};

char *degerlerkusatmaseviye2[] = {
    birlikler.arastirmalar.kusatma_ustaligi.seviye_2.deger,
    birlikler.arastirmalar.kusatma_ustaligi.seviye_2.aciklama,
};

char *degerlerkusatmaseviye3[] = {
    birlikler.arastirmalar.kusatma_ustaligi.seviye_3.deger,
    birlikler.arastirmalar.kusatma_ustaligi.seviye_3.aciklama,
};

if (imleckusatma_ustaligi) {
    for (int j = 0; j < 3; j++) {
        char *imleckusatma_ustaligisev = strstr(imleckusatma_ustaligi, seviyeler[j]);
        if (imleckusatma_ustaligisev) {
            imleckusatma_ustaligisev++; // "seviye_n"dan sonra bir adım ilerle
            for (int i = 0; i < 2; i++) {
                char *anahtar = strstr(imleckusatma_ustaligisev, researchanahtarlar[i]);
                if (anahtar) {
                    anahtar = strstr(anahtar, ":");
                    if (anahtar) {
                        anahtar += 1;
                        while (*anahtar == ' ' || *anahtar == '\"') {
                            anahtar++;
                        }
                        char *son = strstr(anahtar, "\"");
                        if (son) {
                            size_t uzunluk = son - anahtar;
                            if (j == 0) {
                                strncpy(degerlerkusatmaseviye1[i], anahtar, uzunluk);
                                degerlerkusatmaseviye1[i][uzunluk] = '\0'; // Null terminator ekleyin
                            } else if (j == 1) {
                                strncpy(degerlerkusatmaseviye2[i], anahtar, uzunluk);
                                degerlerkusatmaseviye2[i][uzunluk] = '\0'; // Null terminator ekleyin
                            } else {
                                strncpy(degerlerkusatmaseviye3[i], anahtar, uzunluk);
                                degerlerkusatmaseviye3[i][uzunluk] = '\0'; // Null terminator ekleyin
                            }
                        }
                    }
                }
            }
        }
    }
}
// str ifadeyi inte cevir

 birlikler.arastirmalar.elit_egitim.seviye_1.arastirmadeger=atoi( birlikler.arastirmalar.elit_egitim.seviye_1.deger);
birlikler.arastirmalar.elit_egitim.seviye_2.arastirmadeger=atoi( birlikler.arastirmalar.elit_egitim.seviye_2.deger);
birlikler.arastirmalar.elit_egitim.seviye_3.arastirmadeger=atoi( birlikler.arastirmalar.elit_egitim.seviye_3.deger);
birlikler.arastirmalar.kusatma_ustaligi.seviye_1.arastirmadeger=atoi( birlikler.arastirmalar.kusatma_ustaligi.seviye_1.deger);
birlikler.arastirmalar.kusatma_ustaligi.seviye_2.arastirmadeger=atoi( birlikler.arastirmalar.kusatma_ustaligi.seviye_2.deger);
birlikler.arastirmalar.kusatma_ustaligi.seviye_3.arastirmadeger=atoi( birlikler.arastirmalar.kusatma_ustaligi.seviye_3.deger);
 birlikler.arastirmalar.saldiri_gelistirilmesi.seviye_1.arastirmadeger=atoi( birlikler.arastirmalar.saldiri_gelistirilmesi.seviye_1.deger);
birlikler.arastirmalar.saldiri_gelistirilmesi.seviye_2.arastirmadeger=atoi( birlikler.arastirmalar.saldiri_gelistirilmesi.seviye_2.deger);
birlikler.arastirmalar.saldiri_gelistirilmesi.seviye_3.arastirmadeger=atoi( birlikler.arastirmalar.saldiri_gelistirilmesi.seviye_3.deger);
birlikler.arastirmalar.savunma_ustaligi.seviye_1.arastirmadeger=atoi( birlikler.arastirmalar.savunma_ustaligi.seviye_1.deger);
birlikler.arastirmalar.savunma_ustaligi.seviye_2.arastirmadeger=atoi( birlikler.arastirmalar.savunma_ustaligi.seviye_2.deger);
birlikler.arastirmalar.savunma_ustaligi.seviye_3.arastirmadeger=atoi( birlikler.arastirmalar.savunma_ustaligi.seviye_3.deger);



  free(json_researchjson); // dinamik olarak ayirdigin alani serbest birak.


    }



void savasmekanigi(){ // Savas mekanigini yaz


 CURL *curl;
    CURLcode res;
    char *urls[] = {
        "https://yapbenzet.org.tr/1.json",
        "https://yapbenzet.org.tr/2.json",
        "https://yapbenzet.org.tr/3.json",
        "https://yapbenzet.org.tr/4.json",
        "https://yapbenzet.org.tr/5.json",
        "https://yapbenzet.org.tr/6.json",
        "https://yapbenzet.org.tr/7.json",
        "https://yapbenzet.org.tr/8.json",
        "https://yapbenzet.org.tr/9.json",
        "https://yapbenzet.org.tr/10.json"
    };

    int secim;

    FILE *fptr;

    fptr=fopen("savas_sim.txt","w");

   if (fptr == NULL) {
        // Eğer dosya açılamazsa hata verir
        printf("Dosya acilamadi.\n");
        return 1;
    }


    printf("\n1 ile 10 arasinda bir numara secin: \n");
    scanf("%d", &secim);

    if (secim < 1 || secim > 10) {
        printf("Gecersiz numara.\n");
        return ;
    }

    // MemoryStruct ile bellekte veri tutma
    struct bellekStruct chunk;
    chunk.bellek = malloc(1);  // Başlangıçta 1 byte bellek ayır
    chunk.size = 0;            // Veri boyutu başlangıçta 0

    // libcurl'i başlat
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

     char *json_scenairo;

    if (curl) {
        // Seçilen URL'i ayarla
        curl_easy_setopt(curl, CURLOPT_URL, urls[secim - 1]);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);   // Sertifika doğrulamayı devre dışı bırak
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);   // Host doğrulamayı devre dışı bırak
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, BellegeYaz);  // Yazma fonksiyonu
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);           // Belleğe yaz

        // İsteği gönder
        res = curl_easy_perform(curl);

        // Hata kontrolü
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() başarısız: %s\n", curl_easy_strerror(res));
        } else {
            // Gelen veriyi chunk'tan json_scenairo'ya kopyala

            json_scenairo=malloc(chunk.size + 1); // Yeterli bellek ayır
            if (json_scenairo == NULL) {
                printf("Bellek ayırma hatası!\n");
            } else {
                strcpy(json_scenairo, chunk.bellek);  // chunk'tan json_scenairo'ya kopyala
            }

            // json_scenairo'yu kullanabilirsin, dosyaya kaydetmek istersen de aynı şekilde fwrite ile yazabilirsin
            // Belleği temizle

        }

        // CURL işlemini kapat
        curl_easy_cleanup(curl);
    }

    // chunk bellek tahsisini temizle
    free(chunk.bellek);

    // libcurl'i temizle
    curl_global_cleanup();





// JSON verilerini Parse edip structlara atma.


const char *seneryoAnahtarlar[] = { // Birlik degerlerini seneryodan alma
    "ork_dovusculeri",
    "mizrakcilar",
    "varg_binicileri",
    "troller",
    "piyadeler",
    "okcular",
    "suvariler",
    "kusatma_makineleri"
};


int *degersenaryo[] = {
    &birlikler.ork_legibirlik.ork_dovusculeri.askersayi,
    &birlikler.ork_legibirlik.mizrakcilar.askersayi,
    &birlikler.ork_legibirlik.varg_binicileri.askersayi,
    &birlikler.ork_legibirlik.troller.askersayi,
    &birlikler.insan_imparatorlugubirlik.piyadeler.askersayi,
    &birlikler.insan_imparatorlugubirlik.okcular.askersayi,
    &birlikler.insan_imparatorlugubirlik.suvariler.askersayi,
    &birlikler.insan_imparatorlugubirlik.kusatma_makineleri.askersayi,
};


for (int j = 0; j < 8; j++) {
    char *imlec = strstr(json_scenairo, seneryoAnahtarlar[j]);
    if (imlec) {
        imlec = strstr(imlec, ":");
        if (imlec) {
            imlec++;
            imlec++;

             if (*imlec >= '0' && *imlec <= '9') {
                 *degersenaryo[j] = atoi(imlec);
             }
        }
    }
}

fprintf(fptr,"\nSAVAS BASLANGICI:\n");
fprintf(fptr,"***********************************************************");


fprintf(fptr,"\n\nInsan imparatorlugu:\n");
fprintf(fptr,"Piyadelerin toplam saglik: %1.lf\n", birlikler.insan_imparatorlugubirlik.piyadeler.askersayi*birlikler.insan_imparatorlugubirlik.piyadeler.maksimumsaglik);
fprintf(fptr,"Okcularin toplam saglik: %1.lf\n", birlikler.insan_imparatorlugubirlik.okcular.askersayi*birlikler.insan_imparatorlugubirlik.okcular.maksimumsaglik);
fprintf(fptr," Suvarilerin toplam saglik: %1.lf\n", birlikler.insan_imparatorlugubirlik.suvariler.askersayi*birlikler.insan_imparatorlugubirlik.suvariler.maksimumsaglik);
fprintf(fptr,"Kusatma makinelerilerinin toplam saglik:%1.lf\n\n", birlikler.insan_imparatorlugubirlik.kusatma_makineleri.askersayi*birlikler.insan_imparatorlugubirlik.kusatma_makineleri.maksimumsaglik);
fprintf(fptr,"Ork legi:\n");
fprintf(fptr,"Ork dovusculerinin toplam saglik:%1.lf\n", birlikler.ork_legibirlik.ork_dovusculeri.askersayi*birlikler.ork_legibirlik.ork_dovusculeri.maksimumsaglik);
fprintf(fptr,"Mizrakcilarin toplam saglik:%1.lf\n", birlikler.ork_legibirlik.mizrakcilar.askersayi*birlikler.ork_legibirlik.mizrakcilar.maksimumsaglik);
fprintf(fptr,"Varg binicilerinin toplam saglik: %1.lf\n", birlikler.ork_legibirlik.varg_binicileri.askersayi*birlikler.ork_legibirlik.varg_binicileri.maksimumsaglik);
fprintf(fptr,"Trollerin toplam saglik:%1.lf\n", birlikler.ork_legibirlik.troller.askersayi*birlikler.ork_legibirlik.troller.maksimumsaglik);


SavasVerileri savasveri; // İLK BASTAKİ GUC HESAPLA



 kalanpiyade=birlikler.insan_imparatorlugubirlik.piyadeler.askersayi;
 kalanokcu=birlikler.insan_imparatorlugubirlik.okcular.askersayi;
 kalansuvari=birlikler.insan_imparatorlugubirlik.suvariler.askersayi;
 kalankusatmamakineleri=birlikler.insan_imparatorlugubirlik.kusatma_makineleri.askersayi;

 kalanorkdovusculeri=birlikler.ork_legibirlik.ork_dovusculeri.askersayi;
 kalanmizrakcilar=birlikler.ork_legibirlik.mizrakcilar.askersayi;
 kalanvargbinicileri=birlikler.ork_legibirlik.varg_binicileri.askersayi;
 kalantroller=birlikler.ork_legibirlik.troller.askersayi;



 // İNSAN

  //insan birliklerin saldiri gucleri bul(birlik sayisi * birligin saldiri gucu)
savasveri.saldiriguc.piyadesaldirigucu=birlikler.insan_imparatorlugubirlik.piyadeler.saldiri*kalanpiyade;
savasveri.saldiriguc.okcusaldirigucu=birlikler.insan_imparatorlugubirlik.okcular.saldiri*kalanokcu;
savasveri.saldiriguc.suvarisaldirigucu=birlikler.insan_imparatorlugubirlik.suvariler.saldiri*kalansuvari;
savasveri.saldiriguc.kusatmamakinelerisaldirigucu=birlikler.insan_imparatorlugubirlik.kusatma_makineleri.saldiri*kalankusatmamakineleri;





//   Ork leglerinin savunma gucleri (birlik sayisi * birligin savunma gucu)
savasveri.savunmaguc.orkdovusculerisavunmagucu=birlikler.ork_legibirlik.ork_dovusculeri.savunma*kalanorkdovusculeri;
savasveri.savunmaguc.mizrakcilarsavunmagucu=birlikler.ork_legibirlik.mizrakcilar.savunma*kalanmizrakcilar;
savasveri.savunmaguc.vargbinicilerisavunmagucu=birlikler.ork_legibirlik.varg_binicileri.savunma*kalanvargbinicileri;
savasveri.savunmaguc.trollersavunmagucu=birlikler.ork_legibirlik.troller.savunma*kalantroller;





// Ork leglerinin saldiri gucleri (birlik sayisi * birligin saldiri gucu)
savasveri.saldiriguc.orkdovusculerisaldirigucu=birlikler.ork_legibirlik.ork_dovusculeri.saldiri*kalanorkdovusculeri;
savasveri.saldiriguc.mizrakcilarsaldirigucu=birlikler.ork_legibirlik.mizrakcilar.saldiri*kalanmizrakcilar;
savasveri.saldiriguc.vargbinicilerisaldirigucu=birlikler.ork_legibirlik.varg_binicileri.saldiri*kalanvargbinicileri;
savasveri.saldiriguc.trollersaldirigucu=birlikler.ork_legibirlik.troller.saldiri*kalantroller;

//insan birliklerin savunma gucleri (birlik sayisi * birligin savunma gucu)
savasveri.savunmaguc.piyadesavunmagucu=birlikler.insan_imparatorlugubirlik.piyadeler.savunma*kalanpiyade;
savasveri.savunmaguc.okcusavunmagucu=birlikler.insan_imparatorlugubirlik.okcular.savunma*kalanokcu;
savasveri.savunmaguc.suvarisavunmagucu=birlikler.insan_imparatorlugubirlik.suvariler.savunma*kalansuvari;
savasveri.savunmaguc.kusatmamakinelerisavunmagucu=birlikler.insan_imparatorlugubirlik.kusatma_makineleri.savunma*kalankusatmamakineleri;


//Kritik Sans
double sayacpiyadekritik=100/birlikler.insan_imparatorlugubirlik.piyadeler.kritik_sans;
double sayacokcukritik=100/birlikler.insan_imparatorlugubirlik.okcular.kritik_sans;
double sayacsuvarikritik=100/birlikler.insan_imparatorlugubirlik.suvariler.kritik_sans;
double sayacorkdovuscukritik=100/birlikler.ork_legibirlik.ork_dovusculeri.kritik_sans;
double sayacmizrakci=100/birlikler.ork_legibirlik.mizrakcilar.kritik_sans;
double sayactrollerkritik=100/birlikler.ork_legibirlik.troller.kritik_sans;
double sayacvargbinicikritik=100/birlikler.ork_legibirlik.varg_binicileri.kritik_sans;


sayacpiyadekritik=floor(sayacpiyadekritik);
sayacokcukritik=floor(sayacokcukritik);
sayacsuvarikritik=floor(sayacsuvarikritik);
sayacorkdovuscukritik=floor(sayacorkdovuscukritik);
sayacmizrakci=floor(sayacmizrakci);
sayactrollerkritik=floor(sayactrollerkritik);
sayacvargbinicikritik=floor(sayacvargbinicikritik);




double toplaminsanimpsaldirigucu; // Toplam insan saldiri

double toplamorksavunmagucu; // Toplam ork savunma

double toplaminsansavunmagucu; // Toplam insan savunma

double toplamorksaldirigucu; // Toplam ork saldiri

double nethasarinsan; // Toplam insan net hasar

double nethasarork; // Toplam net hasar ork

int adim=1;

fprintf(fptr,"\n\n***************************************************************************");

while (!((kalanpiyade <= 0 && kalanokcu <= 0 && kalansuvari <= 0 && kalankusatmamakineleri <= 0) ||(kalanorkdovusculeri <= 0 && kalanmizrakcilar <= 0 && kalanvargbinicileri <= 0 && kalantroller <= 0))){
// İLK ADİM

  fprintf(fptr,"\n\n%d.adim\n\n",adim);


const char *seneryokahraman[] = { // Kahraman degerlerini seneryodan alma
    "Alparslan",
    "Fatih_Sultan_Mehmet",
    "Mete_Han",
    "Yavuz_Sultan_Selim",
    "Tugrul_Bey",
    "Goruk_Vahsi",
    "Thruk_Kemikkiran",
    "Vrog_Kafakiran",
    "Ugar_Zalim"
};


savasveri.saldiriguc.piyadesaldirigucu=birlikler.insan_imparatorlugubirlik.piyadeler.saldiri*kalanpiyade;
savasveri.saldiriguc.okcusaldirigucu=birlikler.insan_imparatorlugubirlik.okcular.saldiri*kalanokcu;
savasveri.saldiriguc.suvarisaldirigucu=birlikler.insan_imparatorlugubirlik.suvariler.saldiri*kalansuvari;
savasveri.saldiriguc.kusatmamakinelerisaldirigucu=birlikler.insan_imparatorlugubirlik.kusatma_makineleri.saldiri*kalankusatmamakineleri;

savasveri.savunmaguc.orkdovusculerisavunmagucu=birlikler.ork_legibirlik.ork_dovusculeri.savunma*kalanorkdovusculeri;
savasveri.savunmaguc.mizrakcilarsavunmagucu=birlikler.ork_legibirlik.mizrakcilar.savunma*kalanmizrakcilar;
savasveri.savunmaguc.vargbinicilerisavunmagucu=birlikler.ork_legibirlik.varg_binicileri.savunma*kalanvargbinicileri;
savasveri.savunmaguc.trollersavunmagucu=birlikler.ork_legibirlik.troller.savunma*kalantroller;


savasveri.saldiriguc.orkdovusculerisaldirigucu=birlikler.ork_legibirlik.ork_dovusculeri.saldiri*kalanorkdovusculeri;
savasveri.saldiriguc.mizrakcilarsaldirigucu=birlikler.ork_legibirlik.mizrakcilar.saldiri*kalanmizrakcilar;
savasveri.saldiriguc.vargbinicilerisaldirigucu=birlikler.ork_legibirlik.varg_binicileri.saldiri*kalanvargbinicileri;
savasveri.saldiriguc.trollersaldirigucu=birlikler.ork_legibirlik.troller.saldiri*kalantroller;

 savasveri.savunmaguc.piyadesavunmagucu=birlikler.insan_imparatorlugubirlik.piyadeler.savunma*kalanpiyade;
 savasveri.savunmaguc.okcusavunmagucu=birlikler.insan_imparatorlugubirlik.okcular.savunma*kalanokcu;
 savasveri.savunmaguc.suvarisavunmagucu=birlikler.insan_imparatorlugubirlik.suvariler.savunma*kalansuvari;
 savasveri.savunmaguc.kusatmamakinelerisavunmagucu=birlikler.insan_imparatorlugubirlik.kusatma_makineleri.savunma*kalankusatmamakineleri;



if(adim%5==0){

   savasveri.saldiriguc.kusatmamakinelerisaldirigucu=savasveri.saldiriguc.kusatmamakinelerisaldirigucu*0.9;
    savasveri.saldiriguc.mizrakcilarsaldirigucu=savasveri.saldiriguc.mizrakcilarsaldirigucu*0.9;
     savasveri.saldiriguc.okcusaldirigucu=savasveri.saldiriguc.okcusaldirigucu*0.9;
    savasveri.saldiriguc.orkdovusculerisaldirigucu=savasveri.saldiriguc.orkdovusculerisaldirigucu*0.9;

    savasveri.saldiriguc.piyadesaldirigucu=savasveri.saldiriguc.piyadesaldirigucu*0.9;
    savasveri.saldiriguc.suvarisaldirigucu=savasveri.saldiriguc.suvarisaldirigucu*0.9;
     savasveri.saldiriguc.trollersaldirigucu=savasveri.saldiriguc.trollersaldirigucu*0.9;
    savasveri.saldiriguc.vargbinicilerisaldirigucu=savasveri.saldiriguc.vargbinicilerisaldirigucu*0.9;


    savasveri.savunmaguc.kusatmamakinelerisavunmagucu=savasveri.savunmaguc.kusatmamakinelerisavunmagucu*0.9;
    savasveri.savunmaguc.mizrakcilarsavunmagucu=savasveri.savunmaguc.mizrakcilarsavunmagucu*0.9;
     savasveri.savunmaguc.okcusavunmagucu=savasveri.savunmaguc.okcusavunmagucu*0.9;
    savasveri.savunmaguc.orkdovusculerisavunmagucu=savasveri.savunmaguc.orkdovusculerisavunmagucu*0.9;

    savasveri.savunmaguc.piyadesavunmagucu=savasveri.savunmaguc.piyadesavunmagucu*0.9;
    savasveri.savunmaguc.suvarisavunmagucu=savasveri.savunmaguc.suvarisavunmagucu*0.9;
     savasveri.savunmaguc.trollersavunmagucu=savasveri.savunmaguc.trollersavunmagucu*0.9;
    savasveri.savunmaguc.vargbinicilerisavunmagucu=savasveri.savunmaguc.vargbinicilerisavunmagucu*0.9;

}




if(sayacsuvarikritik==adim){
 savasveri.saldiriguc.suvarisaldirigucu=savasveri.saldiriguc.suvarisaldirigucu*1.5;

}

if(sayacpiyadekritik==adim){

 savasveri.saldiriguc.piyadesaldirigucu=savasveri.saldiriguc.piyadesaldirigucu*1.5;

}

if(sayacokcukritik==adim){

 savasveri.saldiriguc.okcusaldirigucu=savasveri.saldiriguc.okcusaldirigucu*1.5;

}


if(sayacorkdovuscukritik==adim){

 savasveri.saldiriguc.orkdovusculerisaldirigucu=savasveri.saldiriguc.orkdovusculerisaldirigucu*1.5;

}

if(sayacmizrakci==adim){

 savasveri.saldiriguc.mizrakcilarsaldirigucu=savasveri.saldiriguc.mizrakcilarsaldirigucu*1.5;

}

if(sayacvargbinicikritik==adim){

 savasveri.saldiriguc.vargbinicilerisaldirigucu=savasveri.saldiriguc.vargbinicilerisaldirigucu*1.5;

}

if(sayactrollerkritik==adim){

 savasveri.saldiriguc.trollersaldirigucu=savasveri.saldiriguc.trollersaldirigucu*1.5;

}





// KAHRAMAN VERİLERİ CEK



   char *deger = strstr(json_scenairo, seneryokahraman[0]); // ALPARSLAN ARA

   if(deger){
        gelenkahramanalparslan=1;

        if(strstr(birlikler.Insan_imparatorluguKahraman.Alparslan.aciklama,"piyade")){
    savasveri.savunmaguc.piyadesavunmagucu=savasveri.savunmaguc.piyadesavunmagucu+(savasveri.savunmaguc.piyadesavunmagucu*birlikler.Insan_imparatorluguKahraman.Alparslan.bonusdeger/100);


        }
    }

     char *deger1 = strstr(json_scenairo, seneryokahraman[1]); // FATİH ARA
    if(deger1){
    gelenkahramanfatih=1;

      if(strstr(birlikler.Insan_imparatorluguKahraman.Fatih_Sultan_Mehmet.aciklama,"kusatma")){

    savasveri.saldiriguc.kusatmamakinelerisaldirigucu=savasveri.saldiriguc.kusatmamakinelerisaldirigucu+(savasveri.saldiriguc.kusatmamakinelerisaldirigucu*birlikler.Insan_imparatorluguKahraman.Fatih_Sultan_Mehmet.bonusdeger/100);
        }

    }

     char *deger2 = strstr(json_scenairo, seneryokahraman[2]); // Metehan
    if(deger2){
            gelenkahramanmetehan=1;

     if(strstr(birlikler.Insan_imparatorluguKahraman.Mete_Han.aciklama,"okcu")){
    savasveri.savunmaguc.okcusavunmagucu=savasveri.savunmaguc.okcusavunmagucu+(savasveri.savunmaguc.okcusavunmagucu*birlikler.Insan_imparatorluguKahraman.Mete_Han.bonusdeger/100);
        }

    }

    char *deger3 = strstr(json_scenairo, seneryokahraman[3]); // Yavuz
    if(deger3){
      gelenkahramanyavuz=1;

     if(strstr(birlikler.Insan_imparatorluguKahraman.Yavuz_Sultan_Selim.aciklama,"suvari")){


    sayacsuvarikritik=100/(birlikler.insan_imparatorlugubirlik.suvariler.kritik_sans+birlikler.Insan_imparatorluguKahraman.Yavuz_Sultan_Selim.bonusdeger);



        }

    }

   char *deger4 = strstr(json_scenairo, seneryokahraman[4]); // TUGRUL BEY
    if(deger4){
     gelenkahramantugrul=1;
      if(strstr(birlikler.Insan_imparatorluguKahraman.Tugrul_Bey.aciklama,"okcu")){
    savasveri.saldiriguc.okcusaldirigucu=savasveri.saldiriguc.okcusaldirigucu+(savasveri.saldiriguc.okcusaldirigucu*birlikler.Insan_imparatorluguKahraman.Tugrul_Bey.bonusdeger/100);
        }

    }

    char *deger5 = strstr(json_scenairo, seneryokahraman[5]); // GORUKVAHSİ
    if(deger5){
    gelenkahramangorukvahsi=1;
      if(strstr(birlikler.ork_legikahraman.Goruk_Vahsi.aciklama,"ork")){
    savasveri.saldiriguc.orkdovusculerisaldirigucu=savasveri.saldiriguc.orkdovusculerisaldirigucu+(savasveri.saldiriguc.orkdovusculerisaldirigucu*birlikler.ork_legikahraman.Goruk_Vahsi.bonusdeger/100);
        }

    }

    char *deger6 = strstr(json_scenairo, seneryokahraman[6]); // THRUKKEMİKKİRAN
    if(deger6){
      gelenkahramanthrukkemikkiran=1;
      if(strstr(birlikler.ork_legikahraman.Thruk_Kemikkiran.aciklama,"trol")){
    savasveri.savunmaguc.trollersavunmagucu=savasveri.savunmaguc.trollersavunmagucu+(savasveri.savunmaguc.trollersavunmagucu*birlikler.ork_legikahraman.Thruk_Kemikkiran.bonusdeger/100);
        }

    }

    char *deger7 = strstr(json_scenairo, seneryokahraman[7]); // VROGKAFAKİRAN
    if(deger7){
     gelenkahramanvrogkafakiran=1;
      if(strstr(birlikler.ork_legikahraman.Vrog_Kafakiran.aciklama,"varg")){
    savasveri.kritikvurushasar.vargbinicilerikritikvurus=savasveri.kritikvurushasar.vargbinicilerikritikvurus+(savasveri.kritikvurushasar.vargbinicilerikritikvurus*birlikler.ork_legikahraman.Vrog_Kafakiran.bonusdeger/100);
        }

    }

      char *deger8 = strstr(json_scenairo, seneryokahraman[8]); // UGARZALİM
    if(deger8){
    gelenkahramanugarzalim=1;
      if(strstr(birlikler.ork_legikahraman.Ugar_Zalim.aciklama,"tum")){
    savasveri.savunmaguc.trollersavunmagucu=savasveri.savunmaguc.trollersavunmagucu+(savasveri.savunmaguc.trollersavunmagucu*birlikler.ork_legikahraman.Ugar_Zalim.bonusdeger/100);
    savasveri.savunmaguc.orkdovusculerisavunmagucu=savasveri.savunmaguc.orkdovusculerisavunmagucu+(savasveri.savunmaguc.orkdovusculerisavunmagucu*birlikler.ork_legikahraman.Ugar_Zalim.bonusdeger/100);
    savasveri.savunmaguc.mizrakcilarsavunmagucu=savasveri.savunmaguc.mizrakcilarsavunmagucu+(savasveri.savunmaguc.mizrakcilarsavunmagucu*birlikler.ork_legikahraman.Ugar_Zalim.bonusdeger/100);
    savasveri.savunmaguc.vargbinicilerisavunmagucu=savasveri.savunmaguc.vargbinicilerisavunmagucu+(savasveri.savunmaguc.vargbinicilerisavunmagucu*birlikler.ork_legikahraman.Ugar_Zalim.bonusdeger/100);
        }

    }



  // CANAVAR VERİLERİ CEK



const char *seneryocanavar[] = { // Canavar degerlerini seneryodan alma
    "Ejderha",
    "Agri_Dagi_Devleri",
    "Tepegoz",
    "Karakurt",
    "Samur",
    "Kara_Troll",
    "Golge_Kurtlari",
    "Camur_Devleri",
    "Ates_Iblisi",
    "Makrog_Savas_Beyi",
    "Buz_Devleri",
};



   char *deger9 = strstr(json_scenairo, seneryocanavar[0]); // EJDERHA ARA

   if(deger9){
        gelencanavarejderha=1;
        if(strstr(birlikler.insan_imparatorlugucanavar.Ejderha.aciklama,"piyade")){

    savasveri.saldiriguc.piyadesaldirigucu=savasveri.saldiriguc.piyadesaldirigucu+(savasveri.saldiriguc.piyadesaldirigucu*birlikler.insan_imparatorlugucanavar.Ejderha.etkideger/100);
        }
    }

     char *deger10 = strstr(json_scenairo, seneryocanavar[1]); // Agri_Dagi_Devleri
    if(deger10){
            gelencanavaragridagidevi=1;


      if(strstr(birlikler.insan_imparatorlugucanavar.Agri_Dagi_Devleri.aciklama,"suvari")){

    savasveri.savunmaguc.suvarisavunmagucu=savasveri.savunmaguc.suvarisavunmagucu+(savasveri.savunmaguc.suvarisavunmagucu*birlikler.insan_imparatorlugucanavar.Agri_Dagi_Devleri.etkideger/100);
        }

    }



     char *deger11 = strstr(json_scenairo, seneryocanavar[2]); // Tepegoz
    if(deger11){
     gelencanavartepegoz=1;

     if(strstr(birlikler.insan_imparatorlugucanavar.Tepegoz.aciklama,"okcu")){
    savasveri.savunmaguc.piyadesavunmagucu=savasveri.savunmaguc.piyadesavunmagucu+(savasveri.savunmaguc.piyadesavunmagucu*birlikler.insan_imparatorlugucanavar.Tepegoz.etkideger/100);
        }

    }

    char *deger12 = strstr(json_scenairo, seneryocanavar[3]); // Karakurt
    if(deger12){
    gelencanavarkarakurt=1;
     if(strstr(birlikler.insan_imparatorlugucanavar.Karakurt.aciklama,"okcu")){

         sayacokcukritik=100/(birlikler.insan_imparatorlugubirlik.okcular.kritik_sans+birlikler.insan_imparatorlugucanavar.Karakurt.etkideger);



    }
    }

   char *deger13 = strstr(json_scenairo, seneryocanavar[4]); // Samur
    if(deger13){
     gelencanavarsamur=1;
      if(strstr(birlikler.insan_imparatorlugucanavar.Samur.aciklama,"piyade")){
    savasveri.savunmaguc.piyadesavunmagucu=savasveri.savunmaguc.piyadesavunmagucu+(savasveri.savunmaguc.piyadesavunmagucu*birlikler.insan_imparatorlugucanavar.Samur.etkideger/100);
        }

    }

    char *deger14 = strstr(json_scenairo, seneryocanavar[5]); // Kara_Troll
    if(deger14){
     gelencanavarkaratroll=1;
      if(strstr(birlikler.ork_legicanavar.Kara_troll.aciklama,"trol")){
    savasveri.saldiriguc.trollersaldirigucu=savasveri.saldiriguc.trollersaldirigucu+(savasveri.saldiriguc.orkdovusculerisaldirigucu*birlikler.ork_legicanavar.Kara_troll.etkideger/100);
        }

    }

    char *deger15 = strstr(json_scenairo, seneryocanavar[6]); // "Golge_Kurtlari"
    if(deger15){
    gelencanavargolgekurtlari=1;
      if(strstr(birlikler.ork_legicanavar.Golge_kurtlari.aciklama,"varg")){
    savasveri.savunmaguc.vargbinicilerisavunmagucu=savasveri.savunmaguc.vargbinicilerisavunmagucu+(savasveri.savunmaguc.vargbinicilerisavunmagucu*birlikler.ork_legicanavar.Golge_kurtlari.etkideger/100);
        }

    }

    char *deger16 = strstr(json_scenairo, seneryocanavar[7]); // "Camur_Devleri"
    if(deger16){
   gelencanavarcamurdevleri=1;
      if(strstr(birlikler.ork_legicanavar.Camur_devleri.aciklama,"ork")){
    savasveri.savunmaguc.orkdovusculerisavunmagucu=savasveri.savunmaguc.orkdovusculerisavunmagucu+(savasveri.savunmaguc.orkdovusculerisavunmagucu*birlikler.ork_legicanavar.Camur_devleri.etkideger/100);
        }

    }

      char *deger17 = strstr(json_scenairo, seneryocanavar[8]); // Ates_Iblisi
    if(deger17){
   gelencanavaratesiblisi=1;

      if(strstr(birlikler.ork_legicanavar.Ates_iblisi.aciklama,"varg")){

    savasveri.saldiriguc.vargbinicilerisaldirigucu=savasveri.saldiriguc.vargbinicilerisaldirigucu+(savasveri.saldiriguc.vargbinicilerisaldirigucu*birlikler.ork_legicanavar.Ates_iblisi.etkideger/100);
        }

    }

    char *deger18 = strstr(json_scenairo, seneryocanavar[9]); // Makrog_Savas_Beyi
    if(deger18){
     gelencanavarmakrogsavasbeyi=1;
      if(strstr(birlikler.ork_legicanavar.Makrog_Savas_Beyi.aciklama,"trol")){
    savasveri.savunmaguc.trollersavunmagucu=savasveri.savunmaguc.trollersavunmagucu+(savasveri.savunmaguc.trollersavunmagucu*birlikler.ork_legicanavar.Makrog_Savas_Beyi.etkideger/100);
        }

    }

      char *deger19 = strstr(json_scenairo, seneryocanavar[10]); // Buz_Devleri
    if(deger19){
    gelencanavarbuzdevleri=1;
      if(strstr(birlikler.ork_legicanavar.Buz_Devleri.aciklama,"mizrakci")){
    savasveri.savunmaguc.mizrakcilarsavunmagucu=savasveri.savunmaguc.mizrakcilarsavunmagucu+(savasveri.savunmaguc.mizrakcilarsavunmagucu*birlikler.ork_legicanavar.Buz_Devleri.etkideger/100);
        }

    }


// ARASTİRMA VERİLERİ CEK



    char *imlecork = strstr(json_scenairo, "ork_legi");
if (imlecork) {
    imlecork = strstr(imlecork, "arastirma_seviyesi");
    if (imlecork) {
        imlecork = strstr(imlecork, "saldiri_gelistirmesi");
        if (imlecork) {
            imlecork = strstr(imlecork, ":"); // ':' karakterine ulaş
            if (imlecork) {
                imlecork++; // ':' işaretinin hemen sonrasına git
                while (*imlecork == ' ')
                 imlecork++; // Boşlukları atla
                if (*imlecork >= '0' && *imlecork <= '9') {
                    orksaldiriarastirma = atoi(imlecork);

                }
            }
        }
    }
}

char *imlecork2 = strstr(json_scenairo, "ork_legi");
if (imlecork2) {
    imlecork2 = strstr(imlecork2, "arastirma_seviyesi");
    if (imlecork2) {
        imlecork2 = strstr(imlecork2, "savunma_ustaligi");
        if (imlecork2) {
            imlecork2 = strstr(imlecork2, ":"); // ':' karakterine ulaş
            if (imlecork2) {
                imlecork2++; // ':' işaretinin hemen sonrasına git
                while (*imlecork2 == ' ')
                imlecork2++; // Boşlukları atla
                if (*imlecork2 >= '0' && *imlecork2 <= '9') {
                    orksavunmaarastirma = atoi(imlecork2);
                }
            }
        }
    }
}


   char *imlecork3 = strstr(json_scenairo, "ork_legi");
if (imlecork3) {
    imlecork3 = strstr(imlecork3, "arastirma_seviyesi");
    if (imlecork3) {
        imlecork3 = strstr(imlecork3, "elit_egitim");
        if (imlecork3) {
            imlecork3 = strstr(imlecork3, ":"); // ':' karakterine ulaş
            if (imlecork3) {
                imlecork3++; // ':' işaretinin hemen sonrasına git
                while (*imlecork3 == ' ')
                 imlecork3++; // Boşlukları atla
                if (*imlecork3 >= '0' && *imlecork3 <= '9') {
                    orkelitarastirma = atoi(imlecork3);

                }
            }
        }
    }
}



     char *imlecork4 = strstr(json_scenairo, "insan_imparatorlugu");
if (imlecork4) {
    imlecork4 = strstr(imlecork4, "arastirma_seviyesi");
    if (imlecork4) {
        imlecork4 = strstr(imlecork4, "saldiri_gelistirmesi");
        if (imlecork4) {
            imlecork4 = strstr(imlecork4, ":"); // ':' karakterine ulaş
            if (imlecork4) {
                imlecork4++; // ':' işaretinin hemen sonrasına git
                while (*imlecork4 == ' ') imlecork4++; // Boşlukları atla
                if (*imlecork4 >= '0' && *imlecork4 <= '9') {
                    insansaldiriarastirma = atoi(imlecork4);

                }
            }
        }
    }
}



 char *imlecork5 = strstr(json_scenairo, "insan_imparatorlugu");
if (imlecork5) {
    imlecork5 = strstr(imlecork5, "arastirma_seviyesi");
    if (imlecork5) {
        imlecork5 = strstr(imlecork5, "savunma_ustaligi");
        if (imlecork5) {
            imlecork5 = strstr(imlecork5, ":"); // ':' karakterine ulaş
            if (imlecork5) {
                imlecork5++; // ':' işaretinin hemen sonrasına git
                while (*imlecork5 == ' ')
                 imlecork5++; // Boşlukları atla
                if (*imlecork5 >= '0' && *imlecork5 <= '9') {
                    insansavunmaarastirma = atoi(imlecork5);

                }
            }
        }
    }
}


      char *imlecork6 = strstr(json_scenairo, "insan_imparatorlugu");
if (imlecork6) {
    imlecork6 = strstr(imlecork6, "arastirma_seviyesi");
    if (imlecork6) {
        imlecork6 = strstr(imlecork6, "elit_egitim");
        if (imlecork6) {
            imlecork6 = strstr(imlecork6, ":"); // ':' karakterine ulaş
            if (imlecork6) {
                imlecork6++; // ':' işaretinin hemen sonrasına git
                while (*imlecork6 == ' ')
                 imlecork6++; // Boşlukları atla
                if (*imlecork6 >= '0' && *imlecork6 <= '9') {
                    insanelitarastirma = atoi(imlecork6);

                }
            }
        }
    }
}


         char *imlecork7 = strstr(json_scenairo, "insan_imparatorlugu");
if (imlecork7) {
    imlecork7 = strstr(imlecork7, "arastirma_seviyesi");
    if (imlecork7) {
        imlecork7 = strstr(imlecork7,  "kusatma_ustaligi");
        if (imlecork7) {
            imlecork7 = strstr(imlecork7, ":"); // ':' karakterine ulaş
            if (imlecork7) {
                imlecork7++; // ':' işaretinin hemen sonrasına git
                while (*imlecork7 == ' ')
                 imlecork7++; // Boşlukları atla
                if (*imlecork7 >= '0' && *imlecork7 <= '9') {
                    insankusatmaarastirma = atoi(imlecork7);

                }
            }
        }
    }
}






if(insansaldiriarastirma==1){
  if(strstr(birlikler.arastirmalar.saldiri_gelistirilmesi.seviye_1.aciklama,"tum")){

   toplaminsanimpsaldirigucu=toplaminsanimpsaldirigucu+(toplaminsanimpsaldirigucu*birlikler.arastirmalar.saldiri_gelistirilmesi.seviye_1.arastirmadeger/100);
  }

 }

if(insansaldiriarastirma==2){
  if(strstr(birlikler.arastirmalar.saldiri_gelistirilmesi.seviye_2.aciklama,"tum")){

  toplaminsanimpsaldirigucu=toplaminsanimpsaldirigucu+(toplaminsanimpsaldirigucu*birlikler.arastirmalar.saldiri_gelistirilmesi.seviye_2.arastirmadeger/100);
  }

 }

if(insansaldiriarastirma==3){
  if(strstr(birlikler.arastirmalar.saldiri_gelistirilmesi.seviye_3.aciklama,"tum")){

   toplaminsanimpsaldirigucu=toplaminsanimpsaldirigucu+(toplaminsanimpsaldirigucu*birlikler.arastirmalar.saldiri_gelistirilmesi.seviye_3.arastirmadeger/100);
  }

 }


if(insansavunmaarastirma==1){
  if(strstr(birlikler.arastirmalar.saldiri_gelistirilmesi.seviye_1.aciklama,"tum")){

   toplaminsansavunmagucu=toplaminsansavunmagucu+(toplaminsansavunmagucu*birlikler.arastirmalar.savunma_ustaligi.seviye_1.arastirmadeger/100);
  }

 }

if(insansavunmaarastirma==2){
  if(strstr(birlikler.arastirmalar.saldiri_gelistirilmesi.seviye_2.aciklama,"tum")){

  toplaminsansavunmagucu=toplaminsansavunmagucu+(toplaminsansavunmagucu*birlikler.arastirmalar.savunma_ustaligi.seviye_2.arastirmadeger/100);

  }

 }

if(insansavunmaarastirma==3){
  if(strstr(birlikler.arastirmalar.saldiri_gelistirilmesi.seviye_3.aciklama,"tum")){

   toplaminsansavunmagucu=toplaminsansavunmagucu+(toplaminsansavunmagucu*birlikler.arastirmalar.savunma_ustaligi.seviye_2.arastirmadeger/100);
  }

 }



if(insanelitarastirma==1){
  if(strstr(birlikler.arastirmalar.elit_egitim.seviye_1.aciklama,"tum")){

    sayacpiyadekritik=100/(birlikler.insan_imparatorlugubirlik.piyadeler.kritik_sans+birlikler.arastirmalar.elit_egitim.seviye_1.arastirmadeger);
    sayacokcukritik=100/(birlikler.insan_imparatorlugubirlik.okcular.kritik_sans+birlikler.arastirmalar.elit_egitim.seviye_1.arastirmadeger);
    sayacsuvarikritik=100/(birlikler.insan_imparatorlugubirlik.suvariler.kritik_sans+birlikler.arastirmalar.elit_egitim.seviye_1.arastirmadeger);


  }

 }

if(insanelitarastirma==2){
  if(strstr(birlikler.arastirmalar.elit_egitim.seviye_2.aciklama,"tum")){

  sayacpiyadekritik=100/(birlikler.insan_imparatorlugubirlik.piyadeler.kritik_sans+birlikler.arastirmalar.elit_egitim.seviye_2.arastirmadeger);
    sayacokcukritik=100/(birlikler.insan_imparatorlugubirlik.okcular.kritik_sans+birlikler.arastirmalar.elit_egitim.seviye_2.arastirmadeger);
    sayacsuvarikritik=100/(birlikler.insan_imparatorlugubirlik.suvariler.kritik_sans+birlikler.arastirmalar.elit_egitim.seviye_2.arastirmadeger);


  }

 }

if(insanelitarastirma==3){
  if(strstr(birlikler.arastirmalar.elit_egitim.seviye_3.aciklama,"tum")){

 sayacpiyadekritik=100/(birlikler.insan_imparatorlugubirlik.piyadeler.kritik_sans+birlikler.arastirmalar.elit_egitim.seviye_3.arastirmadeger);
    sayacokcukritik=100/(birlikler.insan_imparatorlugubirlik.okcular.kritik_sans+birlikler.arastirmalar.elit_egitim.seviye_3.arastirmadeger);
    sayacsuvarikritik=100/(birlikler.insan_imparatorlugubirlik.suvariler.kritik_sans+birlikler.arastirmalar.elit_egitim.seviye_3.arastirmadeger);



  }

 }



if(insankusatmaarastirma==1){
  if(strstr(birlikler.arastirmalar.kusatma_ustaligi.seviye_1.aciklama,"kusatma")){

   savasveri.saldiriguc.kusatmamakinelerisaldirigucu= savasveri.saldiriguc.kusatmamakinelerisaldirigucu+( savasveri.saldiriguc.kusatmamakinelerisaldirigucu*birlikler.arastirmalar.kusatma_ustaligi.seviye_1.arastirmadeger/100);
  }

 }

if(insansavunmaarastirma==2){
  if(strstr(birlikler.arastirmalar.kusatma_ustaligi.seviye_2.aciklama,"kusatma")){

   savasveri.saldiriguc.kusatmamakinelerisaldirigucu= savasveri.saldiriguc.kusatmamakinelerisaldirigucu+( savasveri.saldiriguc.kusatmamakinelerisaldirigucu*birlikler.arastirmalar.kusatma_ustaligi.seviye_2.arastirmadeger/100);

  }

 }


if(insansavunmaarastirma==3){
  if(strstr(birlikler.arastirmalar.kusatma_ustaligi.seviye_3.aciklama,"kusatma")){


   savasveri.saldiriguc.kusatmamakinelerisaldirigucu= savasveri.saldiriguc.kusatmamakinelerisaldirigucu+( savasveri.saldiriguc.kusatmamakinelerisaldirigucu*birlikler.arastirmalar.kusatma_ustaligi.seviye_3.arastirmadeger/100);
  }

 }




if(orksaldiriarastirma==1){
  if(strstr(birlikler.arastirmalar.saldiri_gelistirilmesi.seviye_1.aciklama,"tum")){

   toplamorksaldirigucu= toplamorksaldirigucu+(toplamorksaldirigucu*birlikler.arastirmalar.saldiri_gelistirilmesi.seviye_1.arastirmadeger/100);
  }

 }

if(orksaldiriarastirma==2){
  if(strstr(birlikler.arastirmalar.saldiri_gelistirilmesi.seviye_2.aciklama,"tum")){

   toplamorksaldirigucu= toplamorksaldirigucu+( toplamorksaldirigucu*birlikler.arastirmalar.saldiri_gelistirilmesi.seviye_2.arastirmadeger/100);
  }

 }

if(orksaldiriarastirma==3){
  if(strstr(birlikler.arastirmalar.saldiri_gelistirilmesi.seviye_3.aciklama,"tum")){

    toplamorksaldirigucu= toplamorksaldirigucu+( toplamorksaldirigucu*birlikler.arastirmalar.saldiri_gelistirilmesi.seviye_3.arastirmadeger/100);
  }

 }


if(orksavunmaarastirma==1){
  if(strstr(birlikler.arastirmalar.savunma_ustaligi.seviye_1.aciklama,"tum")){

   toplamorksavunmagucu= toplamorksavunmagucu+(toplamorksaldirigucu*birlikler.arastirmalar.savunma_ustaligi.seviye_1.arastirmadeger/100);
  }

 }

if(orksavunmaarastirma==2){
  if(strstr(birlikler.arastirmalar.savunma_ustaligi.seviye_2.aciklama,"tum")){

   toplamorksavunmagucu= toplamorksavunmagucu+(toplamorksaldirigucu*birlikler.arastirmalar.savunma_ustaligi.seviye_2.arastirmadeger/100);
  }

 }

if(orksavunmaarastirma==3){
  if(strstr(birlikler.arastirmalar.savunma_ustaligi.seviye_3.aciklama,"tum")){

    toplamorksavunmagucu= toplamorksavunmagucu+( toplamorksavunmagucu*birlikler.arastirmalar.savunma_ustaligi.seviye_3.arastirmadeger/100);
  }

 }




if(orkelitarastirma==1){
  if(strstr(birlikler.arastirmalar.elit_egitim.seviye_1.aciklama,"tum")){


sayacorkdovuscukritik=100/(birlikler.ork_legibirlik.ork_dovusculeri.kritik_sans+birlikler.arastirmalar.elit_egitim.seviye_1.arastirmadeger);
sayacmizrakci=100/(birlikler.ork_legibirlik.mizrakcilar.kritik_sans+birlikler.arastirmalar.elit_egitim.seviye_1.arastirmadeger);
sayactrollerkritik=100/(birlikler.ork_legibirlik.troller.kritik_sans+birlikler.arastirmalar.elit_egitim.seviye_1.arastirmadeger);
sayacvargbinicikritik=100/(birlikler.ork_legibirlik.varg_binicileri.kritik_sans+birlikler.arastirmalar.elit_egitim.seviye_1.arastirmadeger);




  }

 }

if(orkelitarastirma==2){
  if(strstr(birlikler.arastirmalar.elit_egitim.seviye_2.aciklama,"tum")){

  sayacorkdovuscukritik=100/(birlikler.ork_legibirlik.ork_dovusculeri.kritik_sans+birlikler.arastirmalar.elit_egitim.seviye_2.arastirmadeger);
sayacmizrakci=100/(birlikler.ork_legibirlik.mizrakcilar.kritik_sans+birlikler.arastirmalar.elit_egitim.seviye_2.arastirmadeger);
sayactrollerkritik=100/(birlikler.ork_legibirlik.troller.kritik_sans+birlikler.arastirmalar.elit_egitim.seviye_2.arastirmadeger);
sayacvargbinicikritik=100/(birlikler.ork_legibirlik.varg_binicileri.kritik_sans+birlikler.arastirmalar.elit_egitim.seviye_2.arastirmadeger);


  }

 }

if(orkelitarastirma==3){
  if(strstr(birlikler.arastirmalar.elit_egitim.seviye_3.aciklama,"tum")){

sayacorkdovuscukritik=100/(birlikler.ork_legibirlik.ork_dovusculeri.kritik_sans+birlikler.arastirmalar.elit_egitim.seviye_3.arastirmadeger);
sayacmizrakci=100/(birlikler.ork_legibirlik.mizrakcilar.kritik_sans+birlikler.arastirmalar.elit_egitim.seviye_3.arastirmadeger);
sayactrollerkritik=100/(birlikler.ork_legibirlik.troller.kritik_sans+birlikler.arastirmalar.elit_egitim.seviye_3.arastirmadeger);
sayacvargbinicikritik=100/(birlikler.ork_legibirlik.varg_binicileri.kritik_sans+birlikler.arastirmalar.elit_egitim.seviye_3.arastirmadeger);

  }

 }


sayacpiyadekritik=floor(sayacpiyadekritik);
sayacokcukritik=floor(sayacokcukritik);
sayacsuvarikritik=floor(sayacsuvarikritik);
sayacorkdovuscukritik=floor(sayacorkdovuscukritik);
sayacmizrakci=floor(sayacmizrakci);
sayactrollerkritik=floor(sayactrollerkritik);
sayacvargbinicikritik=floor(sayacvargbinicikritik);



if(sayacsuvarikritik==adim){
 savasveri.saldiriguc.suvarisaldirigucu=savasveri.saldiriguc.suvarisaldirigucu*1.5;

}

if(sayacpiyadekritik==adim){

 savasveri.saldiriguc.piyadesaldirigucu=savasveri.saldiriguc.piyadesaldirigucu*1.5;

}

if(sayacokcukritik==adim){

 savasveri.saldiriguc.okcusaldirigucu=savasveri.saldiriguc.okcusaldirigucu*1.5;

}


if(sayacorkdovuscukritik==adim){

 savasveri.saldiriguc.orkdovusculerisaldirigucu=savasveri.saldiriguc.orkdovusculerisaldirigucu*1.5;

}

if(sayacmizrakci==adim){

 savasveri.saldiriguc.mizrakcilarsaldirigucu=savasveri.saldiriguc.mizrakcilarsaldirigucu*1.5;

}

if(sayacvargbinicikritik==adim){

 savasveri.saldiriguc.vargbinicilerisaldirigucu=savasveri.saldiriguc.vargbinicilerisaldirigucu*1.5;

}

if(sayactrollerkritik==adim){

 savasveri.saldiriguc.trollersaldirigucu=savasveri.saldiriguc.trollersaldirigucu*1.5;

}


toplaminsanimpsaldirigucu=savasveri.saldiriguc.piyadesaldirigucu+savasveri.saldiriguc.okcusaldirigucu+savasveri.saldiriguc.suvarisaldirigucu+savasveri.saldiriguc.kusatmamakinelerisaldirigucu; // her bir turda insan imp. toplam saldiri gucu(bonussuz)
toplamorksavunmagucu=savasveri.savunmaguc.orkdovusculerisavunmagucu+savasveri.savunmaguc.mizrakcilarsavunmagucu+savasveri.savunmaguc.vargbinicilerisavunmagucu+savasveri.savunmaguc.trollersavunmagucu;
toplaminsansavunmagucu=savasveri.savunmaguc.piyadesavunmagucu+savasveri.savunmaguc.okcusavunmagucu+savasveri.savunmaguc.suvarisavunmagucu+savasveri.savunmaguc.kusatmamakinelerisavunmagucu;
toplamorksaldirigucu=savasveri.saldiriguc.orkdovusculerisaldirigucu+savasveri.saldiriguc.mizrakcilarsaldirigucu+savasveri.saldiriguc.vargbinicilerisaldirigucu+savasveri.saldiriguc.trollersaldirigucu;




  fprintf(fptr,"INSAN SALDIRI:\n\n");

  fprintf(fptr,"Toplam insan saldiri gucu: %1.lf\n",toplaminsanimpsaldirigucu);
  fprintf(fptr,"Toplam ork savunma gucu: %1.lf\n",toplamorksavunmagucu);

nethasarinsan=toplaminsanimpsaldirigucu*(1-(toplamorksavunmagucu/toplaminsanimpsaldirigucu));

if(toplaminsanimpsaldirigucu<toplamorksavunmagucu){
   nethasarinsan=0;
}



  fprintf(fptr,"insanlarin orka net hasari: %1.lf\n",nethasarinsan); // ilk turda insanin orka verecegi hasar.


double orkdovusculerihasar=nethasarinsan*(savasveri.savunmaguc.orkdovusculerisavunmagucu/toplamorksavunmagucu); // ork dovuscu kayip sayi
double kayipsayiorkdovuscu=orkdovusculerihasar/birlikler.ork_legibirlik.ork_dovusculeri.maksimumsaglik;



double mizrakcilarhasar=nethasarinsan*(savasveri.savunmaguc.mizrakcilarsavunmagucu/toplamorksavunmagucu); // mizrakci kayip sayi
double kayipsayimizrakci=mizrakcilarhasar/birlikler.ork_legibirlik.mizrakcilar.maksimumsaglik;


double vargbinicilerihasar=nethasarinsan*(savasveri.savunmaguc.vargbinicilerisavunmagucu/toplamorksavunmagucu); // varg binici kayip sayi
double kayipsayivargbinici=vargbinicilerihasar/birlikler.ork_legibirlik.varg_binicileri.maksimumsaglik;

double trollerhasar=nethasarinsan*(savasveri.savunmaguc.trollersavunmagucu/toplamorksavunmagucu); // troller kayip sayi
double kayipsayitrol=trollerhasar/birlikler.ork_legibirlik.troller.maksimumsaglik;




if(kalanorkdovusculeri-kayipsayiorkdovuscu<=0){ // HELLL YES

    kayipsayiorkdovuscu=kalanorkdovusculeri;
}
if(kalanmizrakcilar-kayipsayimizrakci<=0){ // HELLL YES

    kayipsayimizrakci=kalanmizrakcilar;
}
if(kalanvargbinicileri-kayipsayivargbinici<=0){ // HELLL YES

    kayipsayivargbinici=kalanvargbinicileri;
}
if(kalantroller-kayipsayitrol<=0){ // HELLL YES

    kayipsayitrol=kalantroller;
}


 kalanorkdovusculeri=kalanorkdovusculeri-kayipsayiorkdovuscu;
 kalanmizrakcilar=kalanmizrakcilar-kayipsayimizrakci;
 kalanvargbinicileri=kalanvargbinicileri-kayipsayivargbinici;
 kalantroller=kalantroller-kayipsayitrol;


if(kalanorkdovusculeri<=0){

    kalanorkdovusculeri=0;

}

if(kalanmizrakcilar<=0){

    kalanmizrakcilar=0;

}

if(kalanvargbinicileri<=0){

    kalanvargbinicileri=0;

}


if(kalantroller<=0){

    kalantroller=0;

}




// Sira orklarda
fprintf(fptr,"\n\nORK SALDIRI:\n\n");



// ORKLAR VURUR


fprintf(fptr,"\nToplam ork saldiri gucu: %1.lf",toplamorksaldirigucu);


  fprintf(fptr,"\nToplam insan savunma gucu: %1.lf",toplaminsansavunmagucu);

nethasarork=toplamorksaldirigucu*(1-(toplaminsansavunmagucu/toplamorksaldirigucu));

if(toplaminsansavunmagucu>toplamorksaldirigucu){

   nethasarork=0;


}



  fprintf(fptr,"\n Orklarin insanlara yaptigi net hasar: %1.lf",nethasarork); // ilk turda orkun insana verecegi hasar


double piyadelerhasar=nethasarork*(savasveri.savunmaguc.piyadesavunmagucu/toplaminsansavunmagucu); // piyade kayip sayi
double kayipsayipiyade=piyadelerhasar/birlikler.insan_imparatorlugubirlik.piyadeler.maksimumsaglik;

double okcularhasar=nethasarork*(savasveri.savunmaguc.okcusavunmagucu/toplaminsansavunmagucu); // okcu kayip sayi
double kayipsayiokcu=okcularhasar/birlikler.insan_imparatorlugubirlik.okcular.maksimumsaglik;

double suvarilerhasar=nethasarork*(savasveri.savunmaguc.suvarisavunmagucu/toplaminsansavunmagucu); // suvariler kayip sayi
double kayipsayisuvari=suvarilerhasar/birlikler.insan_imparatorlugubirlik.suvariler.maksimumsaglik;

double kusatmamakinelerihasar=nethasarork*(savasveri.savunmaguc.kusatmamakinelerisavunmagucu/toplaminsansavunmagucu); // kusatma makineleri kayip sayi
double kayipsayikusatmamakineleri=kusatmamakinelerihasar/birlikler.insan_imparatorlugubirlik.kusatma_makineleri.maksimumsaglik;

if(kalanpiyade-kayipsayipiyade<=0){

    kayipsayipiyade=kalanpiyade;
}
if(kalanokcu-kayipsayiokcu<=0){ // HELLL YES

    kayipsayiokcu=kalanokcu;
}
if(kalanmizrakcilar-kayipsayimizrakci<=0){ // HELLL YES

    kayipsayimizrakci=kalanmizrakcilar;
}
if(kalansuvari-kayipsayisuvari<=0){ // HELLL YES

    kayipsayisuvari=kalansuvari;
}
if(kalankusatmamakineleri-kayipsayikusatmamakineleri<=0){ // HELLL YES

    kayipsayikusatmamakineleri=kalankusatmamakineleri;
}
kalanpiyade=kalanpiyade-kayipsayipiyade;
 kalanokcu=kalanokcu-kayipsayiokcu;
 kalansuvari=kalansuvari-kayipsayisuvari;
 kalankusatmamakineleri=kalankusatmamakineleri-kayipsayikusatmamakineleri;

if(kalanpiyade<=0){

    kalanpiyade=0;
}
if(kalanokcu<=0){

    kalanokcu=0;
}
if(kalansuvari<=0){

    kalansuvari=0;
}
if(kalankusatmamakineleri<=0){

    kalankusatmamakineleri=0;

}

   fprintf(fptr,"\n\n%d.turun sonunda:\n\n",adim);
  fprintf(fptr,"\n Ork dovusculerinin kalan cani %1.lf  Ork dovusculerinin kayip cani %1.lf\n",kalanorkdovusculeri*birlikler.ork_legibirlik.ork_dovusculeri.maksimumsaglik,kayipsayiorkdovuscu*birlikler.ork_legibirlik.ork_dovusculeri.maksimumsaglik);
 fprintf(fptr,"Mizrakcilarin kalan cani %1.lf  Mizrakcilarin kayip cani %1.lf\n",kalanmizrakcilar*birlikler.ork_legibirlik.mizrakcilar.maksimumsaglik,kayipsayimizrakci*birlikler.ork_legibirlik.mizrakcilar.maksimumsaglik);
 fprintf(fptr,"Varg binicilerinin kalan cani %1.lf  vargbinicilerin kayip cani %1.lf\n",kalanvargbinicileri*birlikler.ork_legibirlik.varg_binicileri.maksimumsaglik,kayipsayivargbinici*birlikler.ork_legibirlik.varg_binicileri.maksimumsaglik);
 fprintf(fptr,"Trollerin kalan cani %1.lf  trollerin Kayip cani %1.lf\n\n",kalantroller*birlikler.ork_legibirlik.troller.maksimumsaglik,kayipsayitrol*birlikler.ork_legibirlik.troller.maksimumsaglik);
  fprintf(fptr,"\n\nPiyadelerin kalan cani %1.lf  piyadelerin kayip cani %1.lf \n",kalanpiyade*birlikler.insan_imparatorlugubirlik.piyadeler.maksimumsaglik,kayipsayipiyade*birlikler.insan_imparatorlugubirlik.piyadeler.maksimumsaglik);
 fprintf(fptr,"Okcularin kalan cani %1.lf  okcularin kayip cani %1.lf\n",kalanokcu*birlikler.insan_imparatorlugubirlik.okcular.maksimumsaglik,kayipsayiokcu*birlikler.insan_imparatorlugubirlik.okcular.maksimumsaglik);
  fprintf(fptr,"Suvarilerin kalan cani %1.lf  suvarilerin kayip cani %1.lf\n",kalansuvari*birlikler.insan_imparatorlugubirlik.suvariler.maksimumsaglik,kayipsayisuvari*birlikler.insan_imparatorlugubirlik.suvariler.maksimumsaglik);
  fprintf(fptr,"Kusatma makinelerinin kalan cani %1.lf  kusatma makinelerinin kayip cani %1.lf\n\n",kalankusatmamakineleri*birlikler.insan_imparatorlugubirlik.kusatma_makineleri.maksimumsaglik,kayipsayikusatmamakineleri*birlikler.insan_imparatorlugubirlik.suvariler.maksimumsaglik);
  fprintf(fptr,"***************************************************************************");


if(kalanpiyade==0 && kalanokcu==0 && kalansuvari==0 && kalankusatmamakineleri==0){
    fprintf(fptr,"\n\nORKLAR KAZANDI\n");
    fprintf(fptr,"\n%d adimda bitti\n",adim);
    savassonuc=2; // iki ise orklar kazandi

     if(birlikler.ork_legibirlik.mizrakcilar.askersayi>0){

    fprintf(fptr,"\n kalan mizrakcilarin saglik yuzdesi %.1lf%%\n",((double)kalanmizrakcilar/birlikler.ork_legibirlik.mizrakcilar.askersayi)*100);

    }

     if(birlikler.ork_legibirlik.ork_dovusculeri.askersayi>0){

    fprintf(fptr,"\n kalan orkdovusculerinin saglik yuzdesi %.1lf%%\n",((double)kalanorkdovusculeri/birlikler.ork_legibirlik.ork_dovusculeri.askersayi)*100);

    }
     if(birlikler.ork_legibirlik.troller.askersayi>0){

    fprintf(fptr,"\n kalan trollerin saglik yuzdesi %.1lf%%\n",((double)kalantroller/birlikler.ork_legibirlik.troller.askersayi)*100);

    }

     if(birlikler.ork_legibirlik.varg_binicileri.askersayi>0){

    fprintf(fptr,"\n kalan vargbinicilerinin saglik yuzdesi %.1lf%%\n",((double)kalanvargbinicileri/birlikler.ork_legibirlik.varg_binicileri.askersayi)*100);

    }
}

if(kalanmizrakcilar==0 && kalantroller==0 && kalanorkdovusculeri==0 && kalanvargbinicileri==0){


    fprintf(fptr,"\n\nINSANLAR KAZANDI\n");
    fprintf(fptr,"\n%d adimda bitti\n",adim);
    savassonuc=1; // 1 ise insan kazandi


    if(birlikler.insan_imparatorlugubirlik.piyadeler.askersayi>0){

    fprintf(fptr,"\n kalan piyadelerin saglik yuzdesi %.1lf%%\n",((double)kalanpiyade/birlikler.insan_imparatorlugubirlik.piyadeler.askersayi)*100);
    }

     if(birlikler.insan_imparatorlugubirlik.okcular.askersayi>0){

    fprintf(fptr,"\n kalan okcularin saglik yuzdesi %.1lf%%\n",((double)kalanokcu/birlikler.insan_imparatorlugubirlik.okcular.askersayi)*100);
    }

     if(birlikler.insan_imparatorlugubirlik.suvariler.askersayi>0){

    fprintf(fptr,"\n kalan suvarilerin saglik yuzdesi %.1lf%%\n",((double)kalansuvari/birlikler.insan_imparatorlugubirlik.suvariler.askersayi)*100);
    }

     if(birlikler.insan_imparatorlugubirlik.kusatma_makineleri.askersayi>0){

    fprintf(fptr,"\n kalan kusatmamakinelerinin saglik yuzdesi %.1lf%%\n",((double)kalankusatmamakineleri/birlikler.insan_imparatorlugubirlik.kusatma_makineleri.askersayi)*100);

    }
}
adim++; // sayaci arttir

}

 fclose(fptr);
free(json_scenairo);

}
void drawHealthBar(Unit *unit, double x, double y) {
    // Sağlık oranını double olarak hesapla
    double healthRatio = unit->health / unit->maxHealth;

    // Tam can barı (arkaplan)
    DrawRectangle((int)x, (int)(y - 10), HucreBoyutu, 5, RED);

    // Can barının dolu kısmı
    DrawRectangle((int)x, (int)(y - 10), (int)(HucreBoyutu * healthRatio), 5, GREEN);
}

void drawText(const char *text, int x, int y) {
    DrawText(text, x, y, 20, WHITE);
}

void drawGrid() {
    for (int i = 0; i <= IzgaraBoyutu; i++) {
        DrawLine(0, i * HucreBoyutu, IzgaraBoyutu * HucreBoyutu, i * HucreBoyutu, BLACK); // Yatay çizgiler
        DrawLine(i * HucreBoyutu, 0, i * HucreBoyutu, IzgaraBoyutu * HucreBoyutu, BLACK); // Dikey çizgiler
    }
}

int main() {
// unit_types.json dosyasını oku, parse et ve structlara ata
    unittypes_readparse();

// heroes.json dosyasını oku, parse et ve structlara ata (AMA STRİNG HALİNDE ALDİM)
   heroes_readparse();

// creatures.json dosyasını oku, parse et ve structlara ata (AMA STRİNG HALİNDE ALDİM)
    creatures_readparse();

// research.json dosyasını oku, parse et ve structlara ata (AMA STRİNG HALİNDE ALDİM)
    research_readparse();

   savasmekanigi();


  if(birlikler.insan_imparatorlugubirlik.piyadeler.askersayi>0){
             piyadeilkgorselsayi=birlikler.insan_imparatorlugubirlik.piyadeler.askersayi;


  }

  if(birlikler.insan_imparatorlugubirlik.okcular.askersayi>0){
             okcuilkgorselsayi=birlikler.insan_imparatorlugubirlik.okcular.askersayi;



  }

  if(birlikler.insan_imparatorlugubirlik.suvariler.askersayi>0){
             suvariilkgorselsayi=birlikler.insan_imparatorlugubirlik.suvariler.askersayi;


  }

   if(birlikler.insan_imparatorlugubirlik.kusatma_makineleri.askersayi>0){
             kusatmailkgorselsayi=birlikler.insan_imparatorlugubirlik.kusatma_makineleri.askersayi;


  }


    if(birlikler.ork_legibirlik.ork_dovusculeri.askersayi>0){
             orkilkgorselsayi=birlikler.ork_legibirlik.ork_dovusculeri.askersayi;


  }
   if(birlikler.ork_legibirlik.mizrakcilar.askersayi>0){
             mizrakciilkgorselsayi=birlikler.ork_legibirlik.mizrakcilar.askersayi;


  }

  if(birlikler.ork_legibirlik.varg_binicileri.askersayi>0){
             vargilkgorselsayi=birlikler.ork_legibirlik.varg_binicileri.askersayi;


  }

   if(birlikler.ork_legibirlik.troller.askersayi>0){
             trolilkgorselsayi=birlikler.ork_legibirlik.troller.askersayi;


  }
  int insanaskersayidizi[4]={ // insan sayilarini iceren dizi
  piyadeilkgorselsayi,
  suvariilkgorselsayi,
  okcuilkgorselsayi,
  kusatmailkgorselsayi

  };
  int orkaskersayidizi[4]={ // ork sayilarini iceren dizi
  orkilkgorselsayi,
  mizrakciilkgorselsayi,
  vargilkgorselsayi,
  trolilkgorselsayi

  };

const int EkranGenisligi = 896;
    const int EkranYuksekligi = 700;
    InitWindow(EkranGenisligi, EkranYuksekligi, "Savas Simulasyonu");

         // Ses cihazını başlat
    InitAudioDevice();

    // Müzik dosyasını yükleyin
    Music music = LoadMusicStream("savasmuzigi.wav");

    // Müzik çalmaya başlasın
    PlayMusicStream(music);
    // Arka plan resmi ilk kisim
    Texture2D background = LoadTexture("map1.png");
    if (background.id == 0) {
        printf("Arka plan resmi yüklenemedi!\n");
        CloseWindow();
        return -1;
    }
    // İkinci ekran için arka plan resmi
Texture2D background2 = LoadTexture("map1.png");  // İkinci ekran için farklı bir görsel
if (background2.id == 0) {
    printf("İkinci arka plan resmi yüklenemedi!\n");
    CloseWindow();
    return -1;
}
    // Birlikler için PNG dosyalarını yükle ve asker sayısını belirle
    Unit humanUnits[4] = {
        {250, 250, piyadeilkgorselsayi, LoadTexture("piyade.png")},       // 100 asker
        {250, 250, suvariilkgorselsayi, LoadTexture("suvari.png")},        // 75 asker
        {250, 250, okcuilkgorselsayi, LoadTexture("okcu.png")},          // 50 asker
        {250, 250, kusatmailkgorselsayi, LoadTexture("kusatma_mak.png")}    // 30 asker
    };

    Unit orcUnits[4] = {
        {250, 250, orkilkgorselsayi, LoadTexture("org_dovuscu.png")},  // 100 asker
        {250, 250, mizrakciilkgorselsayi, LoadTexture("mizrakci.png")},      // 60 asker
        {250, 250, vargilkgorselsayi, LoadTexture("varg_binici.png")},   // 90 asker
        {250, 250, trolilkgorselsayi, LoadTexture("troll.png")}          // 40 asker
    };
    Texture2D humanHero[5];
     humanHero[0] = LoadTexture("alparslan.png");
     humanHero[1] = LoadTexture("fatih_sultan_mehmet.png");
     humanHero[2] = LoadTexture("Mete_Han.png");
     humanHero[3] = LoadTexture("Yavuz_Sultan_Selim.png");
     humanHero[4] = LoadTexture("Tugrul_Bey.png");

    Texture2D orcHero[4];
     orcHero[0] = LoadTexture("goruk_vahsi.png");
     orcHero[1] = LoadTexture("thruk_kemikkiran.png");
     orcHero[2] = LoadTexture("vrog_kafakiran.png");
     orcHero[3] = LoadTexture("ugar_zalim.png");

     Texture2D humanCreature[5];
     humanCreature[0] = LoadTexture("ejderha.png");
     humanCreature[1] = LoadTexture("Agri_Dagi_Devleri.png");
     humanCreature[2] = LoadTexture("tepegoz.png");
     humanCreature[3] = LoadTexture("Karakurt.png");
     humanCreature[4] = LoadTexture("samur.png");

     Texture2D orcCreature[6];
     orcCreature[0] = LoadTexture("Kara_Troll.png");
     orcCreature[1] = LoadTexture("Golge_Kurtlari.png");
     orcCreature[2] = LoadTexture("Camur_Devleri.png");
     orcCreature[3] = LoadTexture("Ates_Iblisi.png");
     orcCreature[4] = LoadTexture("Makrog_Savas_Beyi.png");
     orcCreature[5] = LoadTexture("Buz_Devleri.png");


     Unit humanUnits2[4] = {
        {piyadeilkgorselsayi,kalanpiyade,piyadeilkgorselsayi, LoadTexture("piyade.png")},       // 100 asker
        {suvariilkgorselsayi,kalansuvari, suvariilkgorselsayi, LoadTexture("suvari.png")},        // 75 asker
        {okcuilkgorselsayi, kalanokcu, okcuilkgorselsayi, LoadTexture("okcu.png")},          // 50 asker
        {kusatmailkgorselsayi, kalankusatmamakineleri, kusatmailkgorselsayi, LoadTexture("kusatma_mak.png")}    // 30 asker
    };

    Unit orcUnits2[4] = {
        {orkilkgorselsayi,kalanorkdovusculeri, orkilkgorselsayi, LoadTexture("org_dovuscu.png")},  // 100 asker
        {mizrakciilkgorselsayi,kalanmizrakcilar, mizrakciilkgorselsayi, LoadTexture("mizrakci.png")},      // 60 asker
        {vargilkgorselsayi, kalanvargbinicileri, vargilkgorselsayi, LoadTexture("varg_binici.png")},   // 90 asker
        {trolilkgorselsayi, kalantroller, trolilkgorselsayi, LoadTexture("troll.png")}          // 40 asker
    };


    SetTargetFPS(60);  // 60 FPS ile sınırla

    float scales[] = {0.15f, 0.3f, 0.12f, 0.13f, 0.25f, 0.2f, 0.1f, 0.3f}; // gorsellestirme icin

   bool isSecondScreen = false;  // İkinci ekran kontrolü
   bool enterabasma = false;  // Kullanıcı "Enter" tuşuna bastı mı?
   float gecenzaman = 0;       // Zaman takipçisi

    // Oyun döngüsü
    while (!WindowShouldClose()) {

         UpdateMusicStream(music);
             if (IsKeyPressed(KEY_ENTER) && !enterabasma) {
        enterabasma = true;  // Enter'a basıldığında true yap
        gecenzaman = 0;       // Zaman sayacını sıfırla
    }

    if (enterabasma) {
        gecenzaman += GetFrameTime();  // Zamanı takip et

        if (gecenzaman >= 3.0f) {
            isSecondScreen = true;  // 3 saniye sonra ikinci ekrana geç
        }
    }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Arka planı ve ızgarayı çiz


         if (!isSecondScreen) {


        DrawTexture(background, 0, 0, WHITE);
        drawGrid();

        // Birlikleri yerleştir ve sağlık barlarını çiz
        for (int i = 0; i < 4; i++) {
    // İnsan birlikleri için sağlık barı ve asker sayısı
    if(insanaskersayidizi[i] <= 100 && insanaskersayidizi[i] > 0){
        drawHealthBar(&humanUnits[i], (5 - i) * HucreBoyutu, 0 * HucreBoyutu + 70);
        DrawText(TextFormat("%d", humanUnits[i].soldierCount), (5 - i) * HucreBoyutu + 2, 0 * HucreBoyutu + 2, 20, WHITE);
        DrawTextureEx(humanUnits[i].texture, (Vector2){ (5 - i) * HucreBoyutu + 5, 0 * HucreBoyutu }, 0.0f, scales[i], WHITE);
    }

    if(insanaskersayidizi[i] > 100){
        int kat = insanaskersayidizi[i] / 100;
        int kalan = insanaskersayidizi[i] % 100;

        for(int a = 0; a < kat; a++){
            drawHealthBar(&humanUnits[i], (5 - i) * HucreBoyutu, a * HucreBoyutu + 70);
            DrawText("100", (5 - i) * HucreBoyutu + 2, a * HucreBoyutu + 2, 20, WHITE);
             DrawTextureEx(humanUnits[i].texture, (Vector2){ (5 - i) * HucreBoyutu + 5, a * HucreBoyutu }, 0.0f, scales[i], WHITE);
        }

        // Eğer kalan asker varsa, ekstra bir sağlık barı ve metin çiz
        if (kalan > 0) {
            drawHealthBar(&humanUnits[i], (5 - i) * HucreBoyutu, kat * HucreBoyutu + 70);
            DrawText(TextFormat("%d", kalan), (5 - i) * HucreBoyutu + 2, kat * HucreBoyutu + 2, 20, WHITE);
             DrawTextureEx(humanUnits[i].texture, (Vector2){ (5 - i) * HucreBoyutu + 5, kat * HucreBoyutu }, 0.0f, scales[i], WHITE);
        }
    }

     // İnsan birlikleri için sağlık barı ve asker sayısı
    if(orkaskersayidizi[i] <= 100 && orkaskersayidizi[i] > 0){
        drawHealthBar(&orcUnits[i], (8+i) * HucreBoyutu, 0 * HucreBoyutu + 70);
        DrawText(TextFormat("%d", orcUnits[i].soldierCount),(8+i) * HucreBoyutu + 2, 0 * HucreBoyutu + 2, 20, WHITE);
        DrawTextureEx(orcUnits[i].texture, (Vector2){ (8 + i) * HucreBoyutu, 0 * HucreBoyutu + 10 }, 0.0f, scales[i + 4], WHITE);
    }

    if(orkaskersayidizi[i] > 100){
        int kat2 = orkaskersayidizi[i] / 100;
        int kalan2 = orkaskersayidizi[i] % 100;

        for(int a = 0; a < kat2; a++){
            drawHealthBar(&humanUnits[i],(8+i) * HucreBoyutu, a * HucreBoyutu + 70);
            DrawText("100", (8+i) * HucreBoyutu + 2, a * HucreBoyutu + 2, 20, WHITE);
            DrawTextureEx(orcUnits[i].texture, (Vector2){ (8 + i) * HucreBoyutu, a * HucreBoyutu + 10 }, 0.0f, scales[i + 4], WHITE);
        }

        // Eğer kalan asker varsa, ekstra bir sağlık barı ve metin çiz
        if (kalan2 > 0) {
            drawHealthBar(&humanUnits[i], (8+i) * HucreBoyutu, kat2 * HucreBoyutu + 70);
            DrawText(TextFormat("%d", kalan2), (8+i) * HucreBoyutu + 2, kat2 * HucreBoyutu + 2, 20, WHITE);
            DrawTextureEx(orcUnits[i].texture, (Vector2){ (8 + i) * HucreBoyutu, kat2 * HucreBoyutu + 10 }, 0.0f, scales[i + 4], WHITE);

    }

 }

        }
          // savas baslangcinda insan kahraman ve canavarlari

        if(gelenkahramanalparslan==1){
          DrawTextureEx(humanHero[0], (Vector2){ 0 * HucreBoyutu, 2 * HucreBoyutu + 10 }, 1.0f, scales[4]+0.4, WHITE);
        }
        if(gelenkahramanfatih==1){
         DrawTextureEx(humanHero[1], (Vector2){ 0 * HucreBoyutu, 2 * HucreBoyutu + 10 }, 1.0f, scales[4]+0.4, WHITE);
        }
        if(gelenkahramanmetehan==1){
          DrawTextureEx(humanHero[2], (Vector2){ 0 * HucreBoyutu, 2 * HucreBoyutu + 10 }, 0.0f, scales[4]+0.4, WHITE);
        }
        if(gelenkahramanyavuz==1){
          DrawTextureEx(humanHero[3], (Vector2){ 0 * HucreBoyutu, 2 * HucreBoyutu + 10 }, 0.0f, scales[4]+0.4, WHITE);
        }
        if(gelenkahramantugrul==1){
       DrawTextureEx(humanHero[4], (Vector2){ 0 * HucreBoyutu, 0 * HucreBoyutu  }, 1.0f, scales[4]+0.4, WHITE);
        }
        if(gelencanavarejderha==1){
        DrawTextureEx(humanCreature[0], (Vector2){ 0 * HucreBoyutu, 6 * HucreBoyutu + 10 }, 1.0f, scales[4]+0.4, WHITE);
        }
        if(gelencanavaragridagidevi==1){
        DrawTextureEx(humanCreature[1], (Vector2){ 0 * HucreBoyutu-15, 6 * HucreBoyutu + 10 }, 1.0f, scales[4]+0.1, WHITE);
        }
        if(gelencanavartepegoz==1){
        DrawTextureEx(humanCreature[2], (Vector2){ 0 * HucreBoyutu-20, 6 * HucreBoyutu + 10 }, 1.0f, scales[4]+0.2, WHITE);
        }
        if(gelencanavarkarakurt==1){
        DrawTextureEx(humanCreature[3], (Vector2){ 0 * HucreBoyutu-30, 6 * HucreBoyutu + 10 }, 1.0f, scales[4]+0.08, WHITE);
        }
        if(gelencanavarsamur==1){
         DrawTextureEx(humanCreature[4], (Vector2){ 0 * HucreBoyutu, 6 * HucreBoyutu + 10 }, 1.0f, scales[4]+0.4, WHITE);
        }


        // savas baslangcinda ork kahraman ve canavarlari

        if(gelenkahramangorukvahsi==1){
          DrawTextureEx(orcHero[0], (Vector2){ 12 * HucreBoyutu-20, 2 * HucreBoyutu + 10 }, 1.0f, scales[4]+0.06, WHITE);
        }
        if(gelenkahramanthrukkemikkiran==1){
         DrawTextureEx(orcHero[1], (Vector2){ 12 * HucreBoyutu-40, 2 * HucreBoyutu + 10 }, 1.0f, scales[4]+0.2, WHITE);
        }
        if(gelenkahramanvrogkafakiran==1){
          DrawTextureEx(orcHero[2], (Vector2){ 12 * HucreBoyutu-10, 2 * HucreBoyutu + 10 }, 0.0f, scales[4]+0.04, WHITE);
        }
        if(gelenkahramanugarzalim==1){
          DrawTextureEx(orcHero[3], (Vector2){ 12 * HucreBoyutu-10, 0 * HucreBoyutu + 10 }, 0.0f, scales[4]+0.04, WHITE);
        }

        if(gelencanavarkaratroll==1){
        DrawTextureEx(orcCreature[0], (Vector2){ 12 * HucreBoyutu-30, 6 * HucreBoyutu+10 }, 1.0f, scales[4]+0.08, WHITE);
        }
        if(gelencanavargolgekurtlari==1){
        DrawTextureEx(orcCreature[1], (Vector2){ 12 * HucreBoyutu-30, 6 * HucreBoyutu + 10 }, 1.0f, scales[4]+0.05, WHITE);
        }
        if(gelencanavarcamurdevleri==1){
        DrawTextureEx(orcCreature[2], (Vector2){ 12 * HucreBoyutu-10, 6 * HucreBoyutu + 10 }, 1.0f, scales[4]+0.05, WHITE);
        }
        if(gelencanavaratesiblisi==1){
        DrawTextureEx(orcCreature[3], (Vector2){ 12 * HucreBoyutu-20, 6 * HucreBoyutu + 10 }, 1.0f, scales[4]+0.08, WHITE);
        }
        if(gelencanavarmakrogsavasbeyi==1){
         DrawTextureEx(orcCreature[4], (Vector2){ 12 * HucreBoyutu-20, 6 * HucreBoyutu + 10 }, 1.0f, scales[4]+0.08, WHITE);
        }
        if(gelencanavarbuzdevleri==1){
         DrawTextureEx(orcCreature[5], (Vector2){ 12 * HucreBoyutu-20, 6 * HucreBoyutu + 10 }, 1.0f, scales[4]+0.1, WHITE);
        }

         }

         else{

            DrawTexture(background2, 0, 0, WHITE);
            drawGrid();

                   for (int i = 0; i < 4; i++) {
    // İnsan birlikleri için sağlık barı ve asker sayısı
    if(savassonuc==1){


          // Beyaz gölge (arka plan)
DrawText("Insan Imparatorlugu Kazandi!", EkranGenisligi / 3 - MeasureText("Insan Kazandi!", 40) / 2 + 2, EkranYuksekligi - 52, 40, WHITE);

// Asıl metin (siyah ve daha belirgin)
DrawText("Insan Imparatorlugu Kazandi!", EkranGenisligi / 3 - MeasureText("Insan Kazandi!", 40) / 2, EkranYuksekligi - 50, 40, BLACK);



    if(insanaskersayidizi[i] <= 100 && insanaskersayidizi[i] > 0){
        drawHealthBar(&humanUnits2[i], (5 - i) * HucreBoyutu, 0 * HucreBoyutu + 70);
        DrawText(TextFormat("%d", humanUnits[i].soldierCount), (5 - i) * HucreBoyutu + 2, 0 * HucreBoyutu + 2, 20, WHITE);
        DrawTextureEx(humanUnits[i].texture, (Vector2){ (5 - i) * HucreBoyutu + 5, 0 * HucreBoyutu }, 0.0f, scales[i], WHITE);
    }

    if(insanaskersayidizi[i] > 100){
        int kat = insanaskersayidizi[i] / 100;
        int kalan = insanaskersayidizi[i] % 100;

        for(int a = 0; a < kat; a++){
            drawHealthBar(&humanUnits2[i], (5 - i) * HucreBoyutu, a * HucreBoyutu + 70);
            DrawText("100", (5 - i) * HucreBoyutu + 2, a * HucreBoyutu + 2, 20, WHITE);
             DrawTextureEx(humanUnits[i].texture, (Vector2){ (5 - i) * HucreBoyutu + 5, a * HucreBoyutu }, 0.0f, scales[i], WHITE);
        }

        // Eğer kalan asker varsa, ekstra bir sağlık barı ve metin çiz
        if (kalan > 0) {
            drawHealthBar(&humanUnits2[i], (5 - i) * HucreBoyutu, kat * HucreBoyutu + 70);
            DrawText(TextFormat("%d", kalan), (5 - i) * HucreBoyutu + 2, kat * HucreBoyutu + 2, 20, BLACK);
             DrawTextureEx(humanUnits[i].texture, (Vector2){ (5 - i) * HucreBoyutu + 5, kat * HucreBoyutu }, 0.0f, scales[i], WHITE);
        }
    }
      if(gelenkahramanalparslan==1){
          DrawTextureEx(humanHero[0], (Vector2){ 0 * HucreBoyutu, 2 * HucreBoyutu + 10 }, 1.0f, scales[4]+0.4, WHITE);

        }
        if(gelenkahramanfatih==1){
         DrawTextureEx(humanHero[1], (Vector2){ 0 * HucreBoyutu, 2 * HucreBoyutu + 10 }, 1.0f, scales[4]+0.4, WHITE);

        }
        if(gelenkahramanmetehan==1){
          DrawTextureEx(humanHero[2], (Vector2){ 0 * HucreBoyutu, 2 * HucreBoyutu + 10 }, 0.0f, scales[4]+0.4, WHITE);

        }
        if(gelenkahramanyavuz==1){
          DrawTextureEx(humanHero[3], (Vector2){ 0 * HucreBoyutu, 2 * HucreBoyutu + 10 }, 0.0f, scales[4]+0.4, WHITE);

        }
        if(gelenkahramantugrul==1){
       DrawTextureEx(humanHero[4], (Vector2){ 0 * HucreBoyutu, 0 * HucreBoyutu  }, 1.0f, scales[4]+0.4, WHITE);

        }
        if(gelencanavarejderha==1){
        DrawTextureEx(humanCreature[0], (Vector2){ 0 * HucreBoyutu, 6 * HucreBoyutu + 10 }, 1.0f, scales[4]+0.4, WHITE);

        }
        if(gelencanavaragridagidevi==1){
        DrawTextureEx(humanCreature[1], (Vector2){ 0 * HucreBoyutu-15, 6 * HucreBoyutu + 10 }, 1.0f, scales[4]+0.1, WHITE);
        }
        if(gelencanavartepegoz==1){
        DrawTextureEx(humanCreature[2], (Vector2){ 0 * HucreBoyutu-20, 6 * HucreBoyutu + 10 }, 1.0f, scales[4]+0.2, WHITE);
        }
        if(gelencanavarkarakurt==1){
        DrawTextureEx(humanCreature[3], (Vector2){ 0 * HucreBoyutu-30, 6 * HucreBoyutu + 10 }, 1.0f, scales[4]+0.08, WHITE);
        }
        if(gelencanavarsamur==1){
         DrawTextureEx(humanCreature[4], (Vector2){ 0 * HucreBoyutu, 6 * HucreBoyutu + 10 }, 1.0f, scales[4]+0.4, WHITE);
        }
    }
     // İnsan birlikleri için sağlık barı ve asker sayısı

     if(savassonuc==2){ //orklar kazanirsa


          // Beyaz gölge (arka plan)
DrawText("Ork Legi Kazandi!", EkranGenisligi / 2 - MeasureText("Orklar Kazandi!", 40) / 2 + 2, EkranYuksekligi - 52, 40,BLACK);

// Asıl metin (siyah ve daha belirgin)
DrawText("Ork Legi Kazandi!", EkranGenisligi / 2 - MeasureText("Orklar Kazandi!", 40) / 2, EkranYuksekligi - 50, 40, BLACK);









    if(orkaskersayidizi[i]<= 100 && orkaskersayidizi[i] > 0){
        drawHealthBar(&orcUnits2[i], (8+i) * HucreBoyutu, 0 * HucreBoyutu + 70);
        DrawText(TextFormat("%d", orcUnits[i].soldierCount),(8+i) * HucreBoyutu + 2, 0 * HucreBoyutu + 2, 20, WHITE);
        DrawTextureEx(orcUnits[i].texture, (Vector2){ (8 + i) * HucreBoyutu, 0 * HucreBoyutu + 10 }, 0.0f, scales[i + 4], WHITE);
    }

    if(orkaskersayidizi[i] > 100){
        int kat2 = orkaskersayidizi[i] / 100;
        int kalan2 = orkaskersayidizi[i] % 100;

        for(int a = 0; a < kat2; a++){
            drawHealthBar(&orcUnits2[i],(8+i) * HucreBoyutu, a * HucreBoyutu + 70);
            DrawText("100", (8+i) * HucreBoyutu + 2, a * HucreBoyutu + 2, 20, WHITE);
            DrawTextureEx(orcUnits[i].texture, (Vector2){ (8 + i) * HucreBoyutu, a * HucreBoyutu + 10 }, 0.0f, scales[i + 4], WHITE);
        }

        // Eğer kalan asker varsa, ekstra bir sağlık barı ve metin çiz
        if (kalan2 > 0) {
            drawHealthBar(&orcUnits2[i], (8+i) * HucreBoyutu, kat2 * HucreBoyutu + 70);
            DrawText(TextFormat("%d", kalan2), (8+i) * HucreBoyutu + 2, kat2 * HucreBoyutu + 2, 20, WHITE);
            DrawTextureEx(orcUnits[i].texture, (Vector2){ (8 + i) * HucreBoyutu, kat2 * HucreBoyutu + 10 }, 0.0f, scales[i + 4], WHITE);

    }
 }
       // savas sonunda sayet ork kazanirsa ork kahraman ve canavarlari

        if(gelenkahramangorukvahsi==1){
          DrawTextureEx(orcHero[0], (Vector2){ 12 * HucreBoyutu-20, 2 * HucreBoyutu +10 }, 1.0f, scales[4]+0.06, WHITE);
        }
        if(gelenkahramanthrukkemikkiran==1){
         DrawTextureEx(orcHero[1], (Vector2){ 12 * HucreBoyutu-40, 2 * HucreBoyutu + 10 }, 1.0f, scales[4]+0.2, WHITE);
        }
        if(gelenkahramanvrogkafakiran==1){
          DrawTextureEx(orcHero[2], (Vector2){ 12 * HucreBoyutu-10, 2 * HucreBoyutu + 10 }, 0.0f, scales[4]+0.04, WHITE);
        }
        if(gelenkahramanugarzalim==1){
          DrawTextureEx(orcHero[3], (Vector2){ 12 * HucreBoyutu-10, 0 * HucreBoyutu + 10 }, 0.0f, scales[4]+0.04, WHITE);
        }

        if(gelencanavarkaratroll==1){
        DrawTextureEx(orcCreature[0], (Vector2){ 12 * HucreBoyutu-30, 6 * HucreBoyutu + 10 }, 1.0f, scales[4]+0.08, WHITE);
        }
        if(gelencanavargolgekurtlari==1){
        DrawTextureEx(orcCreature[1], (Vector2){ 12 * HucreBoyutu-30, 6 * HucreBoyutu + 10 }, 1.0f, scales[4]+0.05, WHITE);
        }
        if(gelencanavarcamurdevleri==1){
        DrawTextureEx(orcCreature[2], (Vector2){ 12 * HucreBoyutu-10, 6 * HucreBoyutu + 10 }, 1.0f, scales[4]+0.05, WHITE);
        }
        if(gelencanavaratesiblisi==1){
        DrawTextureEx(orcCreature[3], (Vector2){ 12 * HucreBoyutu-20, 6 * HucreBoyutu + 10 }, 1.0f, scales[4]+0.08, WHITE);
        }
        if(gelencanavarmakrogsavasbeyi==1){
         DrawTextureEx(orcCreature[4], (Vector2){ 12 * HucreBoyutu-30, 6 * HucreBoyutu + 10 }, 1.0f, scales[4]+0.08, WHITE);
        }
        if(gelencanavarbuzdevleri==1){
         DrawTextureEx(orcCreature[5], (Vector2){ 12 * HucreBoyutu-20, 6 * HucreBoyutu + 10 }, 1.0f, scales[4]+0.1, WHITE);
        }

     }

 }
}
        EndDrawing();
    }
    // Temizleme
    UnloadMusicStream(music);
    CloseAudioDevice();

    // Bellek temizliği
    for (int i = 0; i < 4; i++) {
        UnloadTexture(humanUnits[i].texture);
        UnloadTexture(orcUnits[i].texture);
          UnloadTexture(humanUnits2[i].texture);
        UnloadTexture(orcUnits2[i].texture);

    }
    UnloadTexture(background);
    UnloadTexture(background2);
    CloseWindow();
    return 0;
}

