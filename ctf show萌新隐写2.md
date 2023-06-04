# CTF  show萌新隐写2

!(C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230604143407208.png)

什么是隐写术呢？看节下来的链接

[https://blog.csdn.net/weixin_44505035/article/details/115028722#:~:text=%E4%BB%80%E4%B9%88%E6%98%AF%E9%9A%90%E5%86%99%E6%9C%AF%3F%20%E9%9A%90%E5%86%99%E6%9C%AF,%28Steganography%29%2C%E5%8E%9F%E6%9C%AC%E6%98%AF%E7%89%B9%E9%87%8C%E7%89%B9%E7%B1%B3%E4%B9%8C%E6%96%AF%E7%9A%84%E4%B8%80%E6%9C%AC%E8%AE%B2%E8%BF%B0%E5%AF%86%E7%A0%81%E5%AD%A6%E7%9A%84%E8%91%97%E4%BD%9C.%20%E4%BD%86%E6%98%AF%E7%8E%B0%E5%9C%A8%E5%B9%BF%E4%B9%89%E4%B8%8A%E7%9A%84%E9%9A%90%E5%86%99%E6%9C%AF%E6%98%AF%E4%B8%80%E9%97%A8%E5%85%B3%E4%BA%8E%E4%BF%A1%E6%81%AF%E9%9A%90%E8%97%8F%E7%9A%84%E6%8A%80%E5%B7%A7%E7%9A%84%E5%AD%A6%E7%A7%91.%E5%B9%BF%E6%B3%9B%E7%9A%84%E7%94%A8%E4%BA%8ECTF%E6%AF%94%E8%B5%9B.%20%E8%80%8C%E6%89%80%E8%B0%93%E4%BF%A1%E6%81%AF%E9%9A%90%E8%97%8F%E6%8C%87%E7%9A%84%E6%98%AF%E4%B8%8D%E8%AE%A9%E9%99%A4%E9%A2%84%E6%9C%9F%E7%9A%84%E6%8E%A5%E6%94%B6%E8%80%85%E4%B9%8B%E5%A4%96%E7%9A%84%E4%BB%BB%E4%BD%95%E4%BA%BA%E7%9F%A5%E6%99%93%E4%BF%A1%E6%81%AF%E7%9A%84%E4%BC%A0%E9%80%92%E4%BA%8B%E4%BB%B6%E6%88%96%E8%80%85%E4%BF%A1%E6%81%AF%E7%9A%84%E5%86%85%E5%AE%B9%E3%80%82]: 

## 第一步：

![image-20230604144101635](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230604144101635.png)

直接按照他给的信息下载这个文件。下载好了，就会出现以下界面

![image-20230604144025474](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230604144025474.png)

告诉我们需要密码

## 第二步：

揣测密码是什么形式的，这样我们才可以破解密码，看题目给的提示：“文件安主任喜欢用生日做密码，而且还是个90后”说明了大概的密码形式

也就是19000000 - 20000000

## 第三步：

**爆破密码**

在ARCHPR中打开文件

![image-20230604144825783](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230604144825783.png)

![image-20230604144817389](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230604144817389.png)

直接爆破就可以得到这个文件的口令

用这个口令打开flag.txt这个文件就可以得到flag