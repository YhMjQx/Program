# CTF show萌新杂项11



![image-20230606185657043](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230606185657043.png)

这是这个题目中给的链接中的工具

![image-20230606185639583](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230606185639583.png)

使用方法先将图片保存在桌面，然后用Open jpeg打开桌面上的这个图片，然后用seek保存一个文件我在这里将其命名为bp.txt

![image-20230606190017928](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230606190017928.png)

![image-20230606190029253](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230606190029253.png)

但是这个文件打开发现全是乱码，但是注意看还是能看到NG两个字母，我们就才踏实png文件吧，于是我们退出去，把文件后缀命名png得到

![image-20230606190148127](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230606190148127.png)

这个二维码，于是我们就可以用QR - research来对这个二维码进行解码，可以看到，结果结果会有一段字符串

![image-20230606190304824](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230606190304824.png)

ZmxhZ3vmiJjnpZ7lvZLmnaXlj5HnjrDoh6rlt7HlhL/lrZDlnKjliLfpopjvvIzkuIDmgJLkuYvkuIvlj6zllKQxMOS4h+WwhuWjq+adpeaKpeS7h30=

仔细观察这个字符串，a - z  A - Z   +  =  /

说明这串字符串时base64，于是我们将其进行base64解码就得到了flag

![image-20230606190439718](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230606190439718.png)