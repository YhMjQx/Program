# ctf show萌新隐写6

![image-20230607232452160](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230607232452160.png)

还是按步骤先把这个文件下下来，发现这竟然是个音频，好家伙，打开仔细一听，竟然藏有摩斯电码，那么我们就有了思路：

1.将文件放进audacity，解出隐藏的摩斯音频

![image-20230607233024332](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230607233024332.png)

2.将解出的morse音频解码，写成morse电码

3.对写出的morse电码进行解码

![image-20230607233100551](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230607233100551.png)

先尝试看看字符串，因为其中含有0感觉是base64编码，于是我进行base64解码，发现无果，于是我就尝试将字符串写入flag{MUZIKISG00D}提交成功