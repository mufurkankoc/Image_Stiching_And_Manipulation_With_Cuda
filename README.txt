# ImageStitching

-Bu proje, yüklenen 2 görüntünün panorama görüntüsünü elde etme ve kaydetme üzerine çalışmaktadır. Gpu çalıştırıcı olarak Cuda tercih edilmiştir.
-İçerisinde örnek olarak 2 adet örnek giriş görüntüsü, 2 adet çıkış örneği bulunmaktadır(-Panoramik çıktı -Cuda ile manipülasyonlu çıktı)
-Projede görüntü birleştirme aşamaları CPU üzerinde yapılıp çıktı görüntüsü üzerinde Cuda ile GPU üzerinde renk değerleri üzerinde 10 birim artış yapılmıştır. 
 
-Proje dosyası içerisinde yapılan aşamaların görselleri ve hata raporları mevcuttur.

## Kurulum

Projeni çalışabilmesi için Visual Studio, Cmake, Opencv ve CudaRuntime kurulu olması gerekli optimizasyonların yapılması gerekmektedir.

Kurulum talimatları: (Makefile dosyası daha sonra yüklenecektir)

1. Visual Studio IDE'sini, Cmake, Opencv 4.5.5 ve Cuda 11.8 yüklenip uygulama kurulumları sağlanır. 
2. Cmake ile dosya yolu olarak opencv klasörü belirtilir, cuda çalışması için gerekli flag'ler için seçim sağlanır ve "Generate" edilir.
3. Tamamlanmasını ardından Open Project butonuna basılır, Release mod aktifken ALL_BUILD ve INSTALL dosyaları build edilir.


## Kullanım

Proje terminal üzerinden 2 adet giriş görüntü ve 1 çıkış yolu verilerek yürütülür.

Örnek kullanım talimatları:

1. Terminali başlatın ve repo içerisinde bulunan ImageStitching.exe dosyasının bulunduğu konuma geçiş sağlayın 
	(Örn: PS C:\Users\HP\source\repos\ImageStitching\x64\Release> )
2. Burada örnekte tarif edilen biçimde input ve output girişi sağlayın.
	(Örn: ./ImageStitching -i lotus1.jpg lotus2.jpg -o output.jpg)		
3. Çıktıları kaydedin ve sonuçları görüntüleyin veya .




## Lisans

Herhangi bir lisans bulunmamaktadır.



## İletişim

Muhammed Furkan KOÇ
koc.furkan@gmail.com
