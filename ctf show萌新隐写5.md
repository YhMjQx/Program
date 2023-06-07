# ctf show萌新隐写5

![image-20230607215422495](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230607215422495.png)

这个题目，点击下载flag.txt

![image-20230607215741255](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230607215741255.png)

```中文
䴀娀圀䜀䌀娀娀䤀一䈀儀圀㘀堀㌀䬀一䘀㈀嘀㘀夀吀嘀䰀㔀㐀圀㘀㌀吀䠀䰀㔀刀䐀䜀䴀匀㜀䘀䔀㴀㴀㴀㴀㴀㴀\\=。=//
```

这是一串中文，但事实上这种文字适合unicode编码结合在一起的，[这是因为这种文字是Unicode编码](https://www.cnblogs.com/fdgmy/p/14138368.html)[1](https://www.cnblogs.com/fdgmy/p/14138368.html)[。Unicode编码是一种字符编码，它将所有语言的字符都进行了统一编码，使得不同语言之间的字符可以互相转换](https://blog.csdn.net/m0_68517352/article/details/124671163)[2](https://blog.csdn.net/m0_68517352/article/details/124671163)[。Unicode编码中，每个字符都有一个唯一的编号，这个编号就是这个字符的Unicode码点。而“䴀娀圀䜀䌀娀娀䤀一䈀儀圀㘀堀㌀䬀一䘀㈀嘀㘀夀吀嘀”这种文字是由多个Unicode码点组合而成的](https://www.cnblogs.com/fdgmy/p/14138368.html)[1](https://www.cnblogs.com/fdgmy/p/14138368.html)。

Unicode编码是一种国际标准字符集，它将世界上大部分的文字系统进行了整理、编码，使得电脑可以用更为简单的方式来呈现和处理文字。Unicode编码解决了各国间编码格式不兼容的问题，运用在内存处理中。UTF-8 编码是一种可变长编码，是 Unicode 编码根据一套规则转换而来的，运用在传输和存储中。[1](https://bing.com/search?q=Unicode编码的用途)

[Unicode编码的应用场景很广泛，比如在计算机上保存文件时，可以保存成Unicode编码，无论是全球哪种文字，只需要保存文件的时候，保存成Unicode编码就可以被其他电脑正常解释。](https://zhuanlan.zhihu.com/p/427488961)[2](https://zhuanlan.zhihu.com/p/427488961)

这是关于unicode编码的一些细节，只需要记住文字编码和unicode结合在一起就好，于是，我们将上面的这串中文进行转Unicode

![image-20230607223828367](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230607223828367.png)

转出之后就会有

\u4d00\u5a00\u5700\u4700\u4300\u5a00\u5a00\u4900\u4e00\u4200\u5100\u5700\u3600\u5800\u3300\u4b00\u4e00\u4600\u3200\u5600\u3600\u5900\u5400\u5600\u4c00\u3500\u3400\u5700\u3600\u3300\u5400\u4800\u4c00\u3500\u5200\u4400\u4700\u4d00\u5300\u3700\u4600\u4500\u3d00\u3d00\u3d00\u3d00\u3d00\u3d00\u005c\u005c\u003d\u3002\u003d\u002f\u002f

![image-20230607224300174](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230607224300174.png)

这串字符就是unicode编码，我需要将其进行base16转换，将其直接base16解码

![image-20230607224845680](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230607224845680.png)

但至于为什么可以直接对Unicode编码进行base16解码我就不知道了，网上还有人说可以用hex解码，这个我也不知道..............，然后我问了AI，他是这样回答我的

Unicode编码是一种字符编码方式，它将世界上大部分的文字系统进行了整理、编码，使得电脑可以用更为简单的方式来呈现和处理文字。Unicode编码解决了各国间编码格式不兼容的问题，运用在内存处理中。UTF-8 编码是一种可变长编码，是 Unicode 编码根据一套规则转换而来的，运用在传输和存储中。

Base16是一种十六进制编码方式，它将二进制数据转换为16进制数据。Unicode编码中的字符可以直接转换为16进制数据，因此可以直接对Unicode编码进行Base16解码。

也就是说相当于直接对Unicode编码中的字符转换为十六进制编码。

那么好，我们来看看十六进制的字符串

MZWGCZZINBQW6X3KNF2V6YTVL54W63THL5RDGMS7FE======\\=0=//

仔细看看这段字符串，发现是base32

![image-20230607225409266](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230607225409266.png)

所以我们对这段字符串进行base32解码

解码前，先将字符串后面的======\\=0=/删掉，再解码

![image-20230607225717985](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230607225717985.png)

最终的得到flag(hao_jiu_bu_yong_b32_)，提交并正确

