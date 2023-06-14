# ImageStitching

-Bu proje, yüklenen 2 görüntünün panorama görüntüsünü elde etme ve kaydetme üzerine çalışmaktadır. Gpu çalıştırıcı olarak Cuda tercih edilmiştir.
-İçerisinde örnek olarak 2 adet örnek giriş görüntüsü, 2 adet çıkış örneği bulunmaktadır(-Panoramik çıktı -Cuda ile manipülasyonlu çıktı)
-Projede ister olarak belirtilen 4. ve 5. aşamaların GPU üzerinde yapılması işlemi başarılı sonuçlanmamıştır. Bu aşamalar CPU üzerinde yapılıp çıktı görüntüsü üzerinde Cuda ile GPU üzerinde renk değerleri üzerinde 10 birim artış yapılmıştır. 
-Bu aşama projenin isteri olmayıp, Cuda ile GPU üzerinde işlem yapabileceğimi göstermesi adına yapılmış sembolik bir evredir. 
-Proje dosyası içerisinde yapılan aşamaların görselleri ve hata raporları mevcuttur.

## Kurulum

Projeni çalışabilmesi için Visual Studio, Cmake, Opencv ve CudaRuntime kurulu olması gerekli optimizasyonların yapılması gerekmektedir.

Kurulum talimatları:

1. Visual Studio IDE'sini, Cmake, Opencv 4.5.5 ve Cuda 11.8 yüklenip uygulama kurulumları sağlanır. 
2. Cmake ile dosya yolu olarak opencv klasörü belirtilir, cuda çalışması için gerekli flag'ler için seçim sağlanır ve "Generate" edilir.
3. Tamamlanmasını ardından Open Project butonuna basılır, Release mod aktifken ALL_BUILD ve INSTALL dosyaları build edilir.
4. CUDA 11.8 Runtime ile oluşturulan projeler için;
	- C/C++ / Genel / Ek dizinler içerisine Opencv "include" yolu verilir
	- Bağlayıcı / Genel /Ek kitaplık dizinleri içerisine Opencv "lib" yolu verilir
	- Bağlayıcı / Giriş / Ek bağımlılıklar içerisine eklenir ;
		opencv_core470.lib
		opencv_highgui470.lib
		opencv_imgcodecs470.lib
		opencv_calib3d470.lib
		opencv_imgproc470.lib
		opencv_features2d470.lib
		opencv_xfeatures2d470.lib
		cudart_static.lib
		kernel32.lib
		user32.lib
		gdi32.lib
		winspool.lib
		comdlg32.lib
		advapi32.lib
		shell32.lib
		ole32.lib
		oleaut32.lib
		uuid.lib
		odbc32.lib
		odbccp32.lib
5. Çalışma derlenir.


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