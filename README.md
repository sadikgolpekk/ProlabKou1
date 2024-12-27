# Strateji Oyunu: İnsan İmparatorlukları ve Ork Lejyonları Arasındaki Savaş

Bu proje, insan imparatorlukları ve ork lejyonları arasındaki savaş mekaniklerini simüle eden bir strateji oyunudur. C programlama dili kullanılarak geliştirilmiştir ve JSON dosyalarından alınan verilerle zenginleştirilmiştir. Projede savaş mekaniği, ızgara tabanlı bir haritada görselleştirilmiş ve birimlerin performansı, kahramanlar ve canavarların etkileri ile detaylandırılmıştır.

---

## İçerik

- [Projenin Amacı](#projenin-amacı)
- [Kullanılan Yöntemler](#kullanılan-yöntemler)
- [Görselleştirme Teknikleri](#görselleştirme-teknikleri)
- [Deneysel Sonuçlar](#deneysel-sonuçlar)
- [Sonuç ve Katkılar](#sonuç-ve-katkılar)
- [Kaynaklar](#kaynaklar)

---

## Projenin Amacı

Strateji oyunları, sadece eğlence değil aynı zamanda düşünme ve planlama yeteneklerini geliştirmek için de önemli bir araçtır. Bu projede, savaş mekaniklerinin anlaşılmasını sağlamak ve görsel olarak zengin bir deneyim sunmak için bir oyun geliştirilmiştir. Projede şu özellikler yer almaktadır:

- İnsan ve ork birimlerinin detaylı savaş mekaniği
- Kahraman ve canavar etkileri
- Araştırma seviyelerinin savaş üzerindeki etkileri
- Yorgunluk faktörünün simülasyonu

---

## Kullanılan Yöntemler

Proje, C dilinde geliştirilmiş olup JSON dosyalarının manuel ayrıştırılması ile çalışır. Kullanılan yöntemler:

1. **Birim Özelliklerinin İşlenmesi**:
   - İnsan ve ork birimlerinin saldırı, savunma ve sağlık özellikleri JSON dosyalarından alınmıştır.

2. **Kahraman ve Canavar Bonusları**:
   - Kahramanların ve canavarların birimlere olan etkileri belirlenmiştir.

3. **Araştırma Seviyeleri**:
   - Araştırmalar birimlerin gücünü artırmak için kullanılmıştır.

4. **Savaş Mekaniği**:
   - Savaşın başlangıcı ve sonu görselleştirilmiş, yorgunluk ve kritik vuruş faktörleri hesaplanmıştır.

---

## Görselleştirme Teknikleri

Savaş alanı, 14x11 boyutlarında bir ızgara yapısında raylib kütüphanesi kullanılarak görselleştirilmiştir. Her hücreye maksimum 100 asker yerleştirilebilmekte ve fazla birlikler bir altındaki boş hücreye aktarılmaktadır.

- **Görselleştirme Süreci**:
  - Visual Studio Code geliştirme ortamı olarak kullanılmıştır.
  - Görselleştirme sırasında savaşın başlangıç ve bitiş durumları ayrı ayrı gösterilmiştir.

---

## Deneysel Sonuçlar

Simülasyon farklı senaryolarla test edilmiştir. Örnek bir senaryoda:

- **Başlangıç Durumu**: İnsan ve ork birimleri, kahramanlar ve canavarlar ile birlikte savaşa başlar.
- **Sonuç**: Kazanan tarafın birimleri kalan sağlıklarıyla gösterilirken, kaybeden tarafın tüm birimleri yok olur.

Deneysel aşamada alınan geri bildirimler, oyun dengesi üzerinde yapılan iyileştirmelere katkı sağlamıştır.

---

## Sonuç ve Katkılar

Bu proje, strateji oyunu geliştirme sürecinde karşılaşılan zorlukları ve çözümleri ele almıştır. JSON dosyalarının manuel ayrıştırılması, savaş mekaniğinin detaylandırılması ve görselleştirme süreçleri ile aşağıdaki kazanımlar elde edilmiştir:

- JSON verileriyle çalışma deneyimi
- Görselleştirme teknikleri hakkında bilgi
- Kod optimizasyonu ve proje yönetimi deneyimi

---

## Kaynaklar

- [JSON](https://www.json.org/json-en.html): JSON dosyalarının genel yapısını anlamak için.
- [Curl](https://curl.se/): İnternetten veri çekme işlemleri için.
- [Raylib](https://www.raylib.com/): Görselleştirme kütüphanesi.
- [Stack Overflow](https://stackoverflow.com/): Kodlama sorunlarına yönelik çözümler.
- [Artbreeder](https://www.artbreeder.com/): Görsellerin oluşturulması.
- Çağatay Altıntopaç: Proje için özgün müzik sağladı.

---

Proje ekibi:
- **Sadık Gölpek**: Savaş mekaniği ve JSON verilerinin işlenmesi.
- **Abdullah Önder**: Görselleştirme ve optimizasyon.
