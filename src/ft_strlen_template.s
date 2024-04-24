section .text
; section .text, aşağıdaki kodumuzun programın yürütülebilir kısmında çalışacağını belirtir. .text bölümü genellikle CPU tarafında yürütülen kodu içerir
global _ft_strlen
; _ft_strlen isimli fonksiyonun diğer dosyalardan ve modüllerden erişebilir olduğunu belirtir. Yani bu, _ft_strlen fonksiyonunun
; global bir foksiyon olduğunu ifade eder. Bu sayede, bu fonksiyon başka Assembly veya C dosyalarında çağırılabilir.

_ft_strlen:
; Assembly dilinde bir fonksiyonun tanımlanmasının başlangıcını belirtir. Bu satır, _ft_strlen isimli bir fonksiyonun tanımlanacağını belirtir.
; kısacası etiket tanımlaması olarak adlandırılır.