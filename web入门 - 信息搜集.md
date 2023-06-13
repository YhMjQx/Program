# web1

![image-20230611203804268](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230611203804268.png)

![image-20230611203834082](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230611203834082.png)

![image-20230611203839033](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230611203839033.png)

题目中也说了是查看源代码的题目，于是进来之后就直接Ctrl+U查看源代码就好了

# web2

![image-20230611204432712](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230611204432712.png)

这个题目是什么意思呢？？？

![image-20230611204453418](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230611204453418.png)

点进题目链接之后，告诉我无法查看源代码

但是！！！

我用了Ctrl+U之后，还是查看到了源代码

![image-20230611204643536](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230611204643536.png)

还有一种情况看题目，

![image-20230611204739742](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230611204739742.png)

通过在url头部添加view-source:

这个方法也是查看源代码的一种方式

![image-20230611205024599](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230611205024599.png)

[URL是Uniform Resource Locator的缩写，它是Web中的一个核心概念。URL是浏览器用来检索Web上公布的任何资源的机制。URL代表着统一资源定位符，它是Web上标准资源的地址。每个文件都有一个唯一的URL，它包含的信息指出文件的位置以及浏览器应该如何处理它。](https://developer.mozilla.org/zh-CN/docs/Learn/Common_questions/Web_mechanics/What_is_a_URL)[1](https://developer.mozilla.org/zh-CN/docs/Learn/Common_questions/Web_mechanics/What_is_a_URL)

但是这又是一种不懂得情况了，如果我在查看的时候添加了url就会是这样的源代码，我不懂，里面也没有flag

![image-20230611205305927](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230611205305927.png)

# web3

尝试了一下，Ctrl+U获取源代码失败

那么我就F12

发现这里面的源代码也的确看不到什么，然后在晚上看了看方法，说是在F12中的网络中

![image-20230611220300505](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230611220300505.png)

然后就找到了flag

![image-20230611220040921](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230611220040921.png)

[CTF Show中的flag藏在根目录下的一个文件中，读取文件内容接口过关。进入页面后，只有一句话“where is the flag?”。按照以往的经验，线索肯定就藏在前端页面的源代码中。右键检查或者按F12，进入开发者模式，或者直接右键查看网页源代码，源码的注释中提示了cmd，是在暗示我们利用代码执行漏洞。传入cmd参数，验证一下代码执行漏洞。成功显示出php信息，说明存在代码执行漏洞。接下来遍历目录glob()函数可以查找文件，返回一个文件数组，常配合通配符来遍历目录。可以看到目录下有两个文件，盲猜这个名字特殊的文件里面就有flag](https://developer.aliyun.com/article/848959)[1](https://developer.aliyun.com/article/848959)[2](https://blog.csdn.net/qq_51439282/article/details/120707741)[3](https://blog.csdn.net/miuzzx/article/details/104372662).

[代码执行漏洞是指应用程序本身过滤不严，用户可以通过请求将代码注入到应用中执行。](https://blog.csdn.net/weixin_45007073/article/details/113038152)[1](https://blog.csdn.net/weixin_45007073/article/details/113038152)[ 代码执行漏洞是调用系统命令的漏洞，命令执行漏洞是直接调用系统命令，又称为 os 命令执行漏洞。](https://www.cnblogs.com/backlion/p/9479159.html)[2](https://www.cnblogs.com/backlion/p/9479159.html)[ 代码执行漏洞是由于服务器对危险函数过滤不严导致用户输入的一些字符串可以被转换成代码来执行，从而造成代码执行漏洞。](https://juejin.cn/post/7111327575623860260)[3](https://juejin.cn/post/7111327575623860260)

## web3的第二种解法：

利用burp进行抓包，然后看返回包

![image-20230613230628349](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230613230628349.png)

由于我的edge浏览器无法使用bp代理，于是我将

![image-20230613230904507](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230613230904507.png)

这个页面的网页放在火狐中区抓包，我的火狐可以使用bp抓包

![image-20230613231017167](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230613231017167.png)

看到这个页面说明已经抓包成功了，现在就要进行返回包操作

![image-20230613231103072](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230613231103072.png)

Ctrl+R，发送给Repeater

![image-20230613231215086](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230613231215086.png)

点击放包

![image-20230613231439995](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230613231439995.png)

然后进入重发器，点击发送，就可以找到flag了