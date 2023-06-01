# CTF show萌新密码1

点开题目

![image-20230601170238134](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230601170238134.png)

给了一串密文，题目下方给了一个3，我们目前猜测3是代表3层加密的意思

观察这串密文

base6的编码范围是（数字0~9和字母A~F）

base32的编码范围是(字母A-Z和数字2-7)

base64的编码范围是（字母 A-Z 、 a-z 、 数字 0-9 ）

1.第一步：

```
53316C6B5A6A42684D3256695A44566A4E47526A4D5459774C5556375A6D49324D32566C4D4449354F4749345A6A526B4F48303D
```

这串密文首先一看大概能知道是base16编码，毕竟只有A~F和0~9，那么我们就尝试base16解码，会得到

```
S1lkZjBhM2ViZDVjNGRjMTYwLUV7ZmI2M2VlMDI5OGI4ZjRkOH0=
```

2.第二步：

再观察这串密文，是由字母字母 A-Z 、 a-z 、 数字 0-9组成的，说明是base64编码，可不是base32编码哦，base32编码可不包含数字0。接下来就对这串密文进行base64解码会得到

`KYdf0a3ebd5c4dc160-E{fb63ee0298b8f4d8}`

3.第三步

乍一看，还想着解密呢，，但是发现不仅有数字有字母还有其他字符，再联想题目，说明这是一个栅栏密码，在想着题目中给的3，猜想要三次解密，那么这最后一次会不会是栅栏密码解密，去尝试一下

![image-20230601172227123](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230601172227123.png)

便得到了最终结果。